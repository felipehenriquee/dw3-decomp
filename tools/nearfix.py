"""Tenta fechar funcoes que o autodecomp deixou a poucas instrucoes.

Uso: python3 -I tools/nearfix.py [max_dif] [alvo ...]

Para cada funcao pendente com status 'diff' e ndiff <= max_dif em
build/autodecomp/<alvo>/results.json, aplica variacoes no C do m2c e
compila/compara (como o tools/fn.py test). As que batem vao para o
results.json com status 'ok' (integre com tools/autodecomp.py <alvo> --apply).

Variacoes:
- base local: M2C_FIELD((X + (Y)), T, off) vira um ponteiro u8 * local
  calculado antes (o gcc mantem o offset na instrucao);
- operandos trocados em M2C_FIELD((X + (Y)), ...);
- assinatura completada com os argN que o m2c pulou.
"""
import glob
import itertools
import json
import multiprocessing
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import autodecomp as ad  # noqa: E402
import cc_cmp  # noqa: E402
import fn as fnt  # noqa: E402
from proj import R, Target  # noqa: E402

FIELD = re.compile(r'M2C_FIELD\(\((\w+) \+ \(([^()]*(?:\([^()]*\))*[^()]*)\)\), ([^,]+), ([^)]+)\)')


def bases(code):
    """Expressoes (X, Y) distintas usadas como base em M2C_FIELD."""
    seen = []
    for m in FIELD.finditer(code):
        k = (m.group(1), m.group(2))
        if k not in seen:
            seen.append(k)
    return seen


def hoist(code, keys, swap):
    """Troca as bases escolhidas por ponteiros locais declarados no inicio
    do corpo e atribuidos antes do primeiro uso (no mesmo bloco)."""
    names = {}
    for n, k in enumerate(keys):
        names[k] = 'base%d' % n

    def sub(m):
        k = (m.group(1), m.group(2))
        if k in names:
            return 'M2C_FIELD(%s, %s, %s)' % (names[k], m.group(3), m.group(4))
        if swap:
            return 'M2C_FIELD(((%s) + %s), %s, %s)' % (m.group(2), m.group(1),
                                                      m.group(3), m.group(4))
        return m.group()
    lines = code.split('\n')
    out = []
    done = set()
    for ln in lines:
        new = FIELD.sub(sub, ln)
        for k, nm in names.items():
            if nm in new and nm not in done:
                ind = re.match(r'\s*', ln).group()
                out.append('%s%s = (u8 *)%s + (%s);' % (ind, nm, k[0], k[1]))
                done.add(nm)
        out.append(new)
    code = '\n'.join(out)
    decl = ''.join('    u8 *%s;\n' % nm for nm in names.values())
    i = code.index('{\n') + 2
    return code[:i] + decl + code[i:]


def fix_sig(code):
    """Completa a assinatura com os argN que o m2c pulou (parametro sem uso
    antes de um usado)."""
    m = re.search(r'^([^\n(]*\w+)\(([^)]*)\)\s*\{', code, re.M)
    if not m or m.group(2).strip() in ('', 'void'):
        return code
    params = [p.strip() for p in m.group(2).split(',')]
    nums = {}
    for p in params:
        n = re.search(r'\barg(\d+)$', p)
        if not n:
            return code
        nums[int(n.group(1))] = p
    top = max(nums)
    if len(nums) == top + 1:
        return code
    full = [nums.get(i, 's32 arg%d' % i) for i in range(top + 1)]
    return code[:m.start(2)] + ', '.join(full) + code[m.end(2):]


def variants(code):
    fixed = fix_sig(code)
    if fixed != code:
        yield fixed
        code = fixed
    ks = bases(code)
    seen = set()
    for swap in (False, True):
        for r in range(0, min(len(ks), 3) + 1):
            for sel in itertools.combinations(ks, r):
                if not sel and not swap:
                    continue
                v = hoist(code, list(sel), swap)
                if v not in seen:
                    seen.add(v)
                    yield v


def test(job):
    t, f, code, types = job
    T = Target(t)
    d = os.path.join(R, 'build/nearfix', t)
    os.makedirs(d, exist_ok=True)
    exe = open(T.p(T.bin), 'rb').read()
    for k, v in enumerate(variants(code)):
        c = os.path.join(d, '%s_%d.c' % (f, k))
        o = c[:-2] + '.o'
        decls = '\n'.join(ad.decl(s, tt) for s, tt in (types or {}).items())
        open(c, 'w').write(fnt.tu(t, f, decls + '\n' + v))
        if os.path.exists(o):
            os.remove(o)
        r = subprocess.run([os.path.join(R, 'tools/cc.sh'), c, o, str(T.G)],
                           capture_output=True, text=True, stdin=subprocess.DEVNULL)
        if r.returncode or not os.path.exists(o):
            continue
        try:
            diffs = cc_cmp.compare(o, exe, [f], T.vram, T.off)[f]
        except Exception:
            continue
        if diffs == []:
            return t, f, v
    return t, f, None


def main():
    args = sys.argv[1:]
    mx = int(args[0]) if args and args[0].isdigit() else 9
    if args and args[0].isdigit():
        args = args[1:]
    jobs = []
    for p in sorted(glob.glob(os.path.join(R, 'build/autodecomp/*/results.json'))):
        t = p.split('/')[-2]
        if args and t not in args:
            continue
        try:
            pend = set(ad.pending(t))
        except Exception:
            continue
        for f, r in json.load(open(p)).items():
            if f in pend and r.get('status') == 'diff' and r.get('ndiff', 99) <= mx \
                    and r.get('code'):
                jobs.append((t, f, r['code'], r.get('types')))
    print('%d funcoes' % len(jobs), flush=True)
    ok = {}
    with multiprocessing.Pool(os.cpu_count()) as pool:
        for t, f, v in pool.imap_unordered(test, jobs):
            if v:
                ok.setdefault(t, {})[f] = v
                print('OK', t, f, flush=True)
    for t, fs in ok.items():
        p = os.path.join(R, 'build/autodecomp', t, 'results.json')
        res = json.load(open(p))
        for f, v in fs.items():
            res[f]['code'] = v
            res[f]['status'] = 'ok'
            res[f]['ndiff'] = 0
        json.dump(res, open(p, 'w'), indent=1)
    print('%d bateram' % sum(len(v) for v in ok.values()))


if __name__ == '__main__':
    main()
