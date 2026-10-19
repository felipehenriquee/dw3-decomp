"""Reaproveita funcoes ja decompiladas em funcoes pendentes identicas.

Uso: python3 -I tools/propagate.py [alvo ...]

Precisa do asm de todas as funcoes (splat com disassemble_all: as ja
decompiladas ficam em .../matchings/). A "forma" de uma funcao e o asm
normalizado: enderecos e nomes de simbolos viram marcadores numerados
pela ordem em que aparecem. Uma funcao pendente com a mesma forma de uma
ja decompilada recebe o C dela com os simbolos trocados na mesma ordem.

O C candidato e compilado e comparado; os que batem sao gravados em
build/autodecomp/<alvo>/results.json e integrados com o
`tools/autodecomp.py <alvo> --apply` (que confere com o make).
"""
import glob
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

SYM = re.compile(r'\b(?:func|D|jtbl)_[0-9A-F]{8}\b')
LBL = re.compile(r'\.L[0-9A-F]{8}\b')


def targets():
    return ['main'] + sorted(os.path.basename(p)[:-2]
                             for p in glob.glob(os.path.join(R, 'src/ovl/*.c')))


def shape(path):
    """(forma, simbolos em ordem) de um .s de funcao."""
    lines, syms, lbls = [], [], {}
    for ln in open(path):
        m = re.match(r'\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/\s*(.*)', ln)
        if m:
            txt = m.group(1)
        elif re.match(r'\s*/\* [0-9A-F]+ [0-9A-F]+ \*/\s*(.*)', ln):
            txt = re.match(r'\s*/\* [0-9A-F]+ [0-9A-F]+ \*/\s*(.*)', ln).group(1)
        elif re.match(r'\s*(jlabel|\.L)', ln):
            txt = ln.strip()
        elif ln.startswith(('.section', 'dlabel', 'glabel')):
            txt = ln.split()[0]
        else:
            continue

        def sub_sym(m):
            s = m.group()
            if s not in syms:
                syms.append(s)
            return '@%d' % syms.index(s)

        def sub_lbl(m):
            return '%%%d' % lbls.setdefault(m.group(), len(lbls))
        txt = SYM.sub(sub_sym, txt)
        txt = LBL.sub(sub_lbl, txt)
        lines.append(' '.join(txt.split()))
    return '\n'.join(lines), syms


def c_function(src, fn):
    m = re.search(r'^[^\n;{}]*\b%s\([^;{]*\)\s*\{.*?^\}' % fn, src, re.S | re.M)
    return m.group() if m else None


def decl_of(T, sym):
    """Declaracao de um simbolo de dados vista pelo alvo T, ou None."""
    for p in (T.data, T.auto, T.hdr):
        if os.path.exists(T.p(p)):
            for ln in open(T.p(p)):
                if re.search(r'\b%s\b' % sym, ln) and ln.startswith('extern'):
                    return ln.strip()
    return None


def build_index():
    """forma -> (alvo, funcao, simbolos) das funcoes ja em C. O asm vem de
    .../matchings/ (splat com disassemble_all) ou, enquanto nao houve um
    novo split, do proprio .../nonmatchings/."""
    index = {}
    for t in targets():
        T = Target(t)
        src = open(T.p(T.src)).read()
        for d in (T.asm.replace('/nonmatchings/', '/matchings/'), T.asm):
            d = T.p(d)
            if not os.path.isdir(d):
                continue
            for f in sorted(os.listdir(d)):
                if not f.startswith('func_') or not f.endswith('.s'):
                    continue
                fn = f[:-2]
                if T.include_line(fn) in src:
                    continue
                if not re.search(r'\b%s\([^;{]*\)\s*\{' % fn, src):
                    continue
                sh, syms = shape(os.path.join(d, f))
                index.setdefault(sh, (t, fn, syms))
    return index


def candidate(job, transform=None):
    """Testa o C de A (renomeado) na funcao pendente B. transform(code)
    ajusta o C depois da troca de simbolos (None: nao serve)."""
    tb, fb, syms_b, ta, fa, syms_a = job
    Ta, Tb = Target(ta), Target(tb)
    code = c_function(open(Ta.p(Ta.src)).read(), fa)
    if code is None or len(syms_a) != len(syms_b):
        return tb, fb, None
    ren = dict(zip(syms_a, syms_b))
    ren[fa] = fb
    code = SYM.sub(lambda m: ren.get(m.group(), m.group()), code)
    if transform:
        code = transform(code)
        if code is None:
            return tb, fb, None
    # tipos dos dados: os que A usava
    types, decls = {}, []
    for sa, sb in zip(syms_a, syms_b):
        if not sb.startswith('D_'):
            continue
        d = decl_of(Ta, sa)
        if d is None:
            continue
        d = re.sub(r'\b%s\b' % sa, sb, d)
        pd = ad.parse_decl(d)
        if pd:
            types[sb] = list(pd[1])
            decls.append(d)
        else:
            return tb, fb, None
    # dados usados pelo C que nao aparecem no asm com o mesmo nome (ex.:
    # &D_X + 0x10 no C, D_X+0x10 com outro nome no asm): mesma declaracao
    for s in sorted(set(re.findall(r'\bD_[0-9A-F]{8}\b', code)) - set(syms_b)):
        if decl_of(Tb, s) is None:
            d = decl_of(Ta, s)
            if d is None:
                return tb, fb, None
            pd = ad.parse_decl(d)
            if pd:
                types[s] = list(pd[1])
            decls.append(d)
    full = '\n'.join(decls) + '\n' + code
    d = os.path.join(R, 'build/propagate', tb)
    os.makedirs(d, exist_ok=True)
    c, o = os.path.join(d, fb + '.c'), os.path.join(d, fb + '.o')
    if os.path.exists(o):
        os.remove(o)
    open(c, 'w').write(fnt.tu(tb, fb, full))
    r = subprocess.run([os.path.join(R, 'tools/cc.sh'), c, o, str(Tb.G)],
                       capture_output=True, text=True, stdin=subprocess.DEVNULL)
    if r.returncode != 0 or not os.path.exists(o):
        return tb, fb, None
    exe = open(Tb.p(Tb.bin), 'rb').read()
    try:
        diffs = cc_cmp.compare(o, exe, [fb], Tb.vram, Tb.off)[fb]
    except subprocess.CalledProcessError:
        return tb, fb, None
    if diffs != []:
        return tb, fb, None
    return tb, fb, {'status': 'ok', 'code': code, 'types': types,
                    'variant': 0, 'from': '%s:%s' % (ta, fa)}


def main():
    wanted = sys.argv[1:] or targets()
    index = build_index()
    print('%d formas ja decompiladas' % len(index))
    jobs = []
    for t in wanted:
        T = Target(t)
        if t != 'main':
            T.ensure_files()
        for fn in ad.pending(t):
            p = T.p(T.asm + '/' + fn + '.s')
            if not os.path.exists(p):
                continue
            sh, syms = shape(p)
            if sh in index:
                ta, fa, sa = index[sh]
                jobs.append((t, fn, syms, ta, fa, sa))
    print('%d funcoes pendentes com forma conhecida' % len(jobs))
    with multiprocessing.Pool(os.cpu_count()) as p:
        res = p.map(candidate, jobs)
    per = {}
    for t, fn, r in res:
        if r:
            per.setdefault(t, {})[fn] = r
    print('%d bateram' % sum(len(v) for v in per.values()))
    for t, items in sorted(per.items()):
        path = os.path.join(R, 'build/autodecomp', t, 'results.json')
        os.makedirs(os.path.dirname(path), exist_ok=True)
        old = json.load(open(path)) if os.path.exists(path) else {}
        old.update(items)
        json.dump(old, open(path, 'w'), indent=1)
        r = subprocess.run([sys.executable, '-I', 'tools/autodecomp.py', t,
                            '--apply'], capture_output=True, text=True, cwd=R)
        print(r.stdout.strip().splitlines()[-1] if r.stdout.strip() else
              '%s: erro %s' % (t, r.stderr[-300:]))


if __name__ == '__main__':
    main()
