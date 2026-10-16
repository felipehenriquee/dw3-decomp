"""Decompilacao automatica: m2c -> gcc 2.8.1 -> compara com o original.

Uso:
  python3 -I tools/autodecomp.py <nome> [func_X ...]     testa
  python3 -I tools/autodecomp.py <nome> --apply          integra as que bateram

<nome>: main (EXE) ou um overlay. Usa src/<nome>.c, include/<nome>.h,
include/<nome>_auto.h (tools/gen_ctx.py), include/<nome>_data.h e
asm/nonmatchings/<nome>/. Resultados em build/autodecomp/<nome>/.

Para cada funcao, o tipo de cada simbolo de dados que ela usa (fora do
$gp) e escolhido por busca: o m2c recebe um tipo candidato no contexto,
o C e compilado com a mesma declaracao e comparado com o original.
Comeca pelo tipo ja fixado em <nome>_data.h (se houver) e troca um
simbolo por vez enquanto o numero de instrucoes diferentes cair.

No --apply, as funcoes que bateram entram no .c no lugar do INCLUDE_ASM.
Simbolos novos ganham em <nome>_data.h o tipo que a funcao usou; se o
simbolo ja tinha outro tipo, o codigo da funcao e reescrito com casts.
O `make` confere o sha1; se falhar, o lote e dividido ao meio ate achar
as funcoes que quebram (vao para failed.txt).
"""
import json
import multiprocessing
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import arity  # noqa: E402
import cc_cmp  # noqa: E402
from proj import Target, apply_lock  # noqa: E402

R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
M2C = os.path.join(R, '.venv/bin/m2c')

# tipos candidatos para um simbolo de dados: (base, forma)
# forma: 'a' array sem tamanho, 's' escalar, 'o' struct opaca
# (array primeiro: o codigo original parece usar arrays/structs; escalar
# com NOT_GP faz o gcc gravar via $at)
CANDIDATES = [('s32', 'a'), ('struct opaque', 'o'), ('u8', 'a'),
              ('s32', 's'), ('u16', 'a'), ('s16', 'a'), ('s8', 'a'),
              ('u16', 's'), ('s16', 's'), ('u8', 's'), ('s8', 's')]
# variantes de opcoes do m2c
VARIANTS = [[], ['--void']]
MAX_ROUNDS = 2


def target(name):
    """(binario, vram, offset no arquivo, G)"""
    t = Target(name)
    return (t.bin, t.vram, t.off, t.G)


def run(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, cwd=R, **kw)


def pending(name):
    src = open(os.path.join(R, Target(name).src)).read()
    return re.findall(r'^INCLUDE_ASM\("[^"]+", (\w+)\);', src, re.M)


# ---------------------------------------------------------------- tipos

def decl(sym, t, for_m2c=False):
    base, form = t
    if form == 'a':
        return 'extern %s %s[];' % (base, sym)
    if form == 'o':
        return 'extern struct opaque %s;' % sym
    return 'extern %s %s%s;' % (base, sym, '' if for_m2c else ' NOT_GP')


def parse_decl(line):
    """'extern u8 D_X[];' -> ('D_X', ('u8', 'a'))."""
    m = re.match(r'extern (struct opaque|[\w ]+?) (D_[0-9A-F]{8})(\[\])?'
                 r'(?: NOT_GP)?;', line.strip())
    if not m:
        return None
    base, sym, arr = m.groups()
    if base == 'struct opaque':
        return sym, ('struct opaque', 'o')
    return sym, (base, 'a' if arr else 's')


def canonical(name):
    out = {}
    p = os.path.join(R, Target(name).data)
    if os.path.exists(p):
        for ln in open(p):
            d = parse_decl(ln)
            if d:
                out[d[0]] = d[1]
    return out


def rewrite(code, sym, want, have):
    """Reescreve o uso de sym no codigo gerado com o tipo `want` para
    funcionar com a declaracao `have`."""
    if want == have:
        return code
    base, form = want
    if form == 'o':
        rep = '((struct opaque *)&%s)' % sym
        return re.sub(r'&\s*\b%s\b' % sym, rep, code)
    if form == 'a':
        rep = '((%s *)&%s)' % (base, sym)
    else:
        rep = '(*(%s *)&%s)' % (base, sym)
    return re.sub(r'(?<![\w&])\b%s\b' % sym, rep, code)


# ------------------------------------------------------------- simbolos

def data_syms(asm_txt):
    local = set(re.findall(r'^\s*(?:glabel|dlabel|jlabel)\s+(\w+)', asm_txt,
                           re.M))
    syms = set(re.findall(r'%(?:hi|lo)\((D_[0-9A-F]{8})', asm_txt))
    return sorted(syms - local)


def _balanced(code, i):
    """Indice logo depois do ')' que fecha o '(' em code[i-1]."""
    depth = 1
    while i < len(code) and depth:
        if code[i] == '(':
            depth += 1
        elif code[i] == ')':
            depth -= 1
        i += 1
    return i


def _first_arg_split(inner):
    depth = 0
    for k, c in enumerate(inner):
        if c in '([':
            depth += 1
        elif c in ')]':
            depth -= 1
        elif c == ',' and depth == 0:
            return inner[:k].strip(), inner[k + 1:]
    return inner.strip(), None


def add_self_args(code, globals_=True, methods=True):
    """Variantes para argumentos repassados que o m2c perde em chamadas
    indiretas: (globals_) poe arg0 como 1o argumento de chamadas por
    ponteiro global; (methods) poe o proprio objeto como 1o argumento de
    M2C_FIELD(obj, ...)(...). Os tipos de ponteiro viram (*)() para
    aceitar o argumento a mais."""
    out, i = [], 0
    pat = re.compile(r'M2C_FIELD\(|\(\*\([^()]*\(\*\*\)\([^()]*\)\)&D_[0-9A-F]{8}\)')
    while True:
        m = pat.search(code, i)
        if not m:
            out.append(code[i:])
            break
        out.append(code[i:m.start()])
        if m.group().startswith('M2C_FIELD('):
            end = _balanced(code, m.end())
            call = code[m.start():end]
            if methods and code[end:end + 1] == '(' and '(**)' in call:
                obj, _ = _first_arg_split(code[m.end():end - 1])
                call = re.sub(r'\(\*\*\)\([^()]*\)', '(**)()', call)
                aend = _balanced(code, end + 1)
                args = code[end + 1:aend - 1].strip()
                first, _ = _first_arg_split(args) if args else ('', None)
                if first != obj:
                    args = obj + (', ' + args if args else '')
                out.append(call + '(' + args + ')')
                i = aend
                continue
            out.append(call)
            i = end
            continue
        # chamada por ponteiro global
        txt = re.sub(r'\(\*\*\)\([^()]*\)', '(**)()', m.group())
        if globals_ and code[m.end():m.end() + 1] == '(':
            aend = _balanced(code, m.end() + 1)
            args = code[m.end() + 1:aend - 1].strip()
            first, _ = _first_arg_split(args) if args else ('', None)
            if first != 'arg0':
                args = 'arg0' + (', ' + args if args else '')
            out.append(txt + '(' + args + ')')
            i = aend
            continue
        out.append(txt)
        i = m.end()
    return ''.join(out)


def fix_params(code):
    """Se o corpo usa argN, a assinatura precisa de arg0..argN (o m2c omite
    parametros que a funcao so repassa; sem eles argN cai no registrador
    errado)."""
    m = re.search(r'^([^\n;{}]*?\b\w+)\(([^()]*)\)\s*\{', code, re.M)
    if not m:
        return code
    params = [x.strip() for x in m.group(2).split(',') if x.strip()]
    if params == ['void']:
        params = []
    have = {}
    for prm in params:
        mm = re.search(r'\barg(\d+)$', prm)
        if not mm:
            return code
        have[int(mm.group(1))] = prm
    used = [int(x) for x in re.findall(r'\barg(\d+)\b', code[m.end():])]
    top = max(used + list(have)) if (used or have) else -1
    if top < 0 or all(i in have for i in range(top + 1)):
        return code
    new = ', '.join(have.get(i, 's32 arg%d' % i) for i in range(top + 1))
    return code[:m.start(2)] + new + code[m.end(2):]


def flatten_fields(code):
    """Variante: M2C_FIELD((A + B), T, off) -> (*(T)((s8 *)(A) + (B) + off))."""
    out, i = [], 0
    while True:
        k = code.find('M2C_FIELD((', i)
        if k < 0:
            out.append(code[i:])
            break
        out.append(code[i:k])
        end = _balanced(code, k + len('M2C_FIELD('))
        inner = code[k + len('M2C_FIELD('):end - 1]
        first, rest = _first_arg_split(inner)
        parts = rest.split(',') if rest else []
        if (rest and first.startswith('(') and first.endswith(')') and
                len(parts) >= 2):
            expr = first[1:-1]
            depth, cut = 0, -1
            for j, ch in enumerate(expr):
                if ch in '([':
                    depth += 1
                elif ch in ')]':
                    depth -= 1
                elif ch == '+' and depth == 0:
                    cut = j
                    break
            if cut > 0:
                a, b = expr[:cut].strip(), expr[cut + 1:].strip()
                typ = ','.join(parts[:-1]).strip()
                off = parts[-1].strip()
                out.append('(*(%s)((s8 *)(%s) + (%s) + (%s)))'
                           % (typ, a, b, off))
                i = end
                continue
        out.append(code[k:end])
        i = end
    return ''.join(out)


def fix_code(code):
    """Ajustes na saida do m2c."""
    code = fix_params(code)
    # constante que nao cabe no tipo com sinal (ex.: s8 = 0x80 vira -128)
    def unsign(m):
        t, v = m.group(2), int(m.group(4), 16)
        if (t == 's8' and v >= 0x80) or (t == 's16' and v >= 0x8000):
            return m.group(1) + 'u' + t[1:] + m.group(3) + m.group(4)
        return m.group(0)
    code = re.sub(r'(M2C_FIELD\([^;]*?, )(s8|s16)( \*, [^;]*?\) = )(0x[0-9A-F]+)\b',
                  unsign, code)
    # chamada pela primeira entrada de uma tabela de ponteiros de funcao:
    # o m2c escreve D_X(...), mas D_X e dado
    return re.sub(r'(?<![\w&.>])(D_[0-9A-F]{8})\(', r'(*(s32 (**)())&\1)(',
                  code)


# ------------------------------------------------------------- contexto

def make_base(name, work):
    """Prepara o contexto base do m2c (headers preprocessados, sem os
    dados fora do $gp)."""
    os.makedirs(work, exist_ok=True)
    T = Target(name)
    stub = os.path.join(work, 'ctx_in.c')
    with open(stub, 'w') as f:
        f.write('#include "%s"\n#include "m2c.h"\n#include "%s"\n'
                % (T.p(T.hdr), T.p(T.auto)))
    out = run([os.path.join(R, 'tools/old-gcc/2.8.1/cpp'), '-P',
               '-I' + os.path.join(R, 'include'), '-DM2CTX', stub])
    # prototipos com a aridade estimada pelo asm do chamado (so para o
    # m2c): sem isso ele perde argumentos repassados sem mudanca
    ar = arity.arities(name)

    def proto(m):
        n = ar.get(m.group(2))
        if not n:
            return m.group(0)
        return '%s %s(%s);' % (m.group(1), m.group(2), ', '.join(['s32'] * n))
    text = re.sub(r'^(s32) (\w+)\(\);$', proto, out.stdout, flags=re.M)
    ctx = os.path.join(work, 'ctx.h')
    open(ctx, 'w').write(text)
    return ctx


def rodata_files(name):
    d = os.path.join(R, Target(name).asm)
    return [os.path.join(d, f) for f in sorted(os.listdir(d))
            if not f.startswith('func_') and f.endswith('.s')]


class Tester:
    def __init__(self, name, fn, base_ctx, work):
        self.name, self.fn = name, fn
        self.tgt = target(name)
        self.exe = open(os.path.join(R, self.tgt[0]), 'rb').read()
        self.d = os.path.join(work, fn)
        os.makedirs(self.d, exist_ok=True)
        self.T = Target(name)
        self.asm = os.path.join(R, self.T.asm, fn + '.s')
        asm_txt = open(self.asm).read()
        self.syms = data_syms(asm_txt)
        body = re.search(r'glabel %s\b(.*?)endlabel %s\b' % (fn, fn), asm_txt,
                         re.S)
        self.osize = 4 * len(re.findall(
            r'^\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/',
            body.group(1) if body else asm_txt, re.M))
        # simbolos com declaracao a mao no header ficam com o tipo de la
        hdr = open(self.T.p(self.T.hdr)).read()
        self.syms = [s for s in self.syms
                     if not re.search(r'^extern[^;]*\b%s\b' % s, hdr, re.M)]
        own = re.compile(r'\b%s\s*\(' % fn)
        self.base = '\n'.join(ln for ln in open(base_ctx).read().splitlines()
                              if not own.search(ln))
        auto = open(self.T.p(self.T.auto)).read()
        self.auto = '\n'.join(ln for ln in auto.splitlines()
                              if not own.search(ln) and not ln.startswith('#'))
        # declaracoes fixadas dos outros simbolos (os desta funcao entram
        # com o tipo da tentativa)
        data = self.T.p(self.T.data)
        self.data = []
        if os.path.exists(data):
            for ln in open(data):
                d = parse_decl(ln)
                if d and d[0] not in self.syms:
                    self.data.append(ln.rstrip())
        self.canon = canonical(name)
        self.n = 0

    def attempt(self, types, vi, selfargs=None):
        """Devolve (ndiff ou None se nao compilou, code, erro)."""
        self.n += 1
        tag = 'a%d' % self.n
        ctx = os.path.join(self.d, tag + '.h')
        with open(ctx, 'w') as f:
            f.write(self.base + '\nstruct opaque;\n')
            for s, t in types.items():
                f.write(decl(s, t, True) + '\n')
        r = run([M2C, '-t', 'mipsel-gcc-c', '--valid-syntax',
                 '--globals=none', '--context', ctx, '-f', self.fn] +
                VARIANTS[vi] + [self.asm] + rodata_files(self.name))
        if r.returncode != 0 or not r.stdout.strip():
            return None, None, 'm2c: ' + (r.stderr or r.stdout)[-300:]
        code = fix_code(r.stdout)
        if selfargs and selfargs[0] == 'flat':
            code = flatten_fields(code)
        elif selfargs:
            if 'arg0' not in code.split('{', 1)[0] and selfargs[0]:
                return None, None, 'sem arg0'
            code = add_self_args(code, *selfargs)
        # simbolos com tipo ja fixado: compila com a declaracao fixada e o
        # codigo reescrito com cast, exatamente como vai ficar no build
        built = code
        for s, t in types.items():
            if s in self.canon:
                built = rewrite(built, s, t, self.canon[s])
        c = os.path.join(self.d, tag + '.c')
        with open(c, 'w') as f:
            f.write('#include "%s"\n#include "m2c.h"\n%s\nstruct opaque;\n'
                    % (self.T.p(self.T.hdr), self.auto))
            f.write('\n'.join(self.data) + '\n')
            for s, t in types.items():
                f.write(decl(s, self.canon.get(s, t)) + '\n')
            f.write('\n' + built)
        o = os.path.join(self.d, tag + '.o')
        if os.path.exists(o):
            os.remove(o)
        cr = run([os.path.join(R, 'tools/cc.sh'), c, o, str(self.tgt[3])],
                 stdin=subprocess.DEVNULL)
        if cr.returncode != 0 or not os.path.exists(o):
            return None, code, 'cc: ' + cr.stderr[-300:]
        try:
            diffs = cc_cmp.compare(o, self.exe, [self.fn], self.tgt[1],
                                   self.tgt[2],
                                   {self.fn: self.osize})[self.fn]
        except subprocess.CalledProcessError:
            return None, code, 'cc: .o invalido ' + cr.stderr[-300:]
        if diffs is None:
            return None, code, 'cc: funcao nao gerada'
        return len(diffs), code, None


def score(n):
    return 1e9 if n is None else n


def try_one(job):
    name, fn, base_ctx, work, canon = job
    t = Tester(name, fn, base_ctx, work)
    types = {s: canon.get(s, CANDIDATES[0]) for s in t.syms}
    best = None
    for vi in range(len(VARIANTS)):
        n, code, err = t.attempt(types, vi)
        if best is None or score(n) < score(best[0]):
            best = (n, code, err, dict(types), vi)
        if n == 0:
            break
    n, code, err, types, vi = best
    for _ in range(MAX_ROUNDS):
        if n == 0:
            break
        improved = False
        for s in t.syms:
            for c in CANDIDATES:
                if c == types[s]:
                    continue
                trial = dict(types)
                trial[s] = c
                n2, code2, err2 = t.attempt(trial, vi)
                if score(n2) < score(n):
                    n, code, err, types = n2, code2, err2, trial
                    improved = True
                if n == 0:
                    break
            if n == 0:
                break
        if not improved:
            break
    if n != 0 and code:
        # variantes com argumentos repassados em chamadas indiretas e com
        # M2C_FIELD((base + i * N), ...) achatado
        for g, m in ((True, False), (False, True), (True, True),
                     ('flat', None)):
            n2, code2, err2 = t.attempt(types, vi, (g, m))
            if score(n2) < score(n):
                n, code, err = n2, code2, err2
            if n == 0:
                break
    res = {'types': {s: list(v) for s, v in types.items()}, 'variant': vi,
           'tries': t.n}
    if n == 0:
        res.update(status='ok', code=code)
    elif n is not None:
        res.update(status='diff', ndiff=n, code=code)
    else:
        res.update(status='cc' if code else 'm2c', err=err, code=code)
    # apaga os arquivos intermediarios das tentativas
    for f in os.listdir(t.d):
        if re.match(r'a\d+\.', f):
            os.remove(os.path.join(t.d, f))
    return fn, res


def test(name, funcs):
    work = os.path.join(R, 'build/autodecomp', name)
    base_ctx = make_base(name, work)
    canon = canonical(name)
    jobs = [(name, fn, base_ctx, work, canon) for fn in funcs]
    # as funcoes maiores (busca mais longa) primeiro
    jobs.sort(key=lambda j: -os.path.getsize(os.path.join(
        R, Target(name).asm, j[1] + '.s')))
    with multiprocessing.Pool(os.cpu_count()) as p:
        results = dict(p.imap_unordered(try_one, jobs))
    path = os.path.join(work, 'results.json')
    old = json.load(open(path)) if os.path.exists(path) else {}
    old.update(results)
    json.dump(old, open(path, 'w'), indent=1)
    st = {}
    for r in results.values():
        st[r['status']] = st.get(r['status'], 0) + 1
    print('%s: %d funcoes testadas: %s' % (name, len(results), st))
    near = sorted((r['ndiff'], f) for f, r in results.items()
                  if r['status'] == 'diff')
    print('mais perto:', ' '.join('%s(%d)' % (f, n) for n, f in near[:15]))
    return results


# ---------------------------------------------------------------- apply

def make_ok():
    r = run(['make', '-j%d' % os.cpu_count()])
    return r.returncode == 0 and 'overlays' in r.stdout


def write_data(name, canon):
    """Grava os tipos de canon em <nome>_data.h: troca a linha de quem ja
    existe e acrescenta os novos, preservando as outras linhas."""
    p = os.path.join(R, Target(name).data)
    s = open(p).read()
    for sym, t in sorted(canon.items()):
        d = decl(sym, t)
        pat = re.compile(r'^extern [^\n;]*\b%s\b[^\n;]*;$' % sym, re.M)
        if pat.search(s):
            old = pat.search(s).group()
            if parse_decl(old) is not None and parse_decl(old)[1] != t:
                s = pat.sub(d, s, count=1)
        else:
            k = s.rindex('\n#endif')
            s = s[:k].rstrip('\n') + '\n' + d + '\n' + s[k:]
    open(p, 'w').write(s)


def insert(name, items):
    T = Target(name)
    p = os.path.join(R, T.src)
    s = open(p).read()
    canon = canonical(name)
    for fn, r in items.items():
        code = r['code']
        for sym, t in r['types'].items():
            t = tuple(t)
            if sym not in canon:
                canon[sym] = t
            code = rewrite(code, sym, t, canon[sym])
        s = s.replace(T.include_line(fn), code.strip(), 1)
    open(p, 'w').write(s)
    write_data(name, canon)
    run([sys.executable, '-I', 'tools/gen_ctx.py', name])


def apply(name):
    work = os.path.join(R, 'build/autodecomp', name)
    res = json.load(open(os.path.join(work, 'results.json')))
    todo = {f: r for f, r in res.items()
            if r['status'] == 'ok' and f in pending(name)}
    T = Target(name)
    files = [T.p(T.src), T.p(T.auto), T.p(T.data)]
    good, bad = {}, []

    def attempt(batch):
        saved = [open(f).read() for f in files]
        insert(name, batch)
        if make_ok():
            good.update(batch)
            return
        for f, c in zip(files, saved):
            open(f, 'w').write(c)
        if len(batch) == 1:
            bad.extend(batch)
            return
        items = sorted(batch.items())
        h = len(items) // 2
        attempt(dict(items[:h]))
        attempt(dict(items[h:]))

    if todo:
        with apply_lock():
            attempt(todo)
    with open(os.path.join(work, 'failed.txt'), 'a') as f:
        for fn in bad:
            f.write(fn + '\n')
    print('%s: %d integradas, %d quebraram o make: %s' % (
        name, len(good), len(bad), ' '.join(bad)))


def main():
    name = sys.argv[1]
    T = Target(name)
    if name != 'main':
        T.ensure_files()
        if not os.path.getsize(T.p(T.auto)):
            run([sys.executable, '-I', 'tools/gen_ctx.py', name])
    if '--apply' in sys.argv:
        apply(name)
        return
    funcs = sys.argv[2:] or pending(name)
    test(name, funcs)


if __name__ == '__main__':
    main()
