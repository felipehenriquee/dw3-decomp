"""Propagacao que tambem troca constantes.

Uso: python3 -I tools/fuzzyprop.py [alvo ...]

Como o tools/propagate.py, mas a forma ignora os imediatos: uma funcao
pendente com a mesma forma de uma ja em C (a menos das constantes) recebe
o C dela com os simbolos trocados na ordem e as constantes trocadas pelo
valor (a n-esima constante do asm do modelo vira a n-esima da pendente;
valores com mapeamento ambiguo ficam como estao). O resultado e compilado
e comparado; os que batem vao para o results.json e sao integrados com o
tools/autodecomp.py <alvo> --apply.
"""
import multiprocessing
import os
import re
import subprocess
import sys
import json

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import autodecomp as ad  # noqa: E402
import propagate as pr  # noqa: E402
from proj import R, Target  # noqa: E402

NUM = re.compile(r'(?<![\w$%])-?0x[0-9A-Fa-f]+|(?<![\w$%.])-?\b\d+\b')


def fuzzy(path):
    sh, syms = pr.shape(path)
    consts = [int(x, 0) for x in NUM.findall(sh)]
    return NUM.sub('K', sh), syms, consts


def build_index():
    idx = {}
    for t in pr.targets():
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
                if T.include_line(fn) in src or not re.search(r'\b%s\([^;{]*\)\s*\{' % fn, src):
                    continue
                fz, syms, consts = fuzzy(os.path.join(d, f))
                idx.setdefault(fz, []).append((t, fn, syms, consts))
    return idx


def remap_consts(code, ca, cb):
    if len(ca) != len(cb):
        return None
    m = {}
    bad = set()
    for a, b in zip(ca, cb):
        if a in m and m[a] != b:
            bad.add(a)
        m[a] = b
    m = {a: b for a, b in m.items() if a != b and a not in bad}
    if not m:
        return code

    def sub(x):
        tok = x.group()
        try:
            v = int(tok, 0)
        except ValueError:
            return tok
        for key in (v, v & 0xFFFFFFFF, v - (1 << 32) if v >= 1 << 31 else v):
            if key in m:
                nv = m[key]
                return ('0x%X' % nv if tok.lower().startswith(('0x', '-0x')) and nv >= 0 else str(nv))
        return tok
    return NUM.sub(sub, code)


def job(args):
    tb, fb, syms_b, cb, models = args
    for ta, fa, syms_a, ca in models:
        r = pr.candidate((tb, fb, syms_b, ta, fa, syms_a), transform=lambda c: remap_consts(c, ca, cb))
        if r[2]:
            return r
    return tb, fb, None


def main():
    wanted = sys.argv[1:] or pr.targets()
    idx = build_index()
    jobs = []
    for t in wanted:
        T = Target(t)
        for fn in ad.pending(t):
            p = T.p(T.asm + '/' + fn + '.s')
            if not os.path.exists(p):
                continue
            fz, syms, consts = fuzzy(p)
            if fz in idx:
                jobs.append((t, fn, syms, consts, idx[fz][:3]))
    print('%d pendentes com forma (sem constantes) conhecida' % len(jobs), flush=True)
    per = {}
    with multiprocessing.Pool(os.cpu_count()) as pool:
        for t, fn, r in pool.imap_unordered(job, jobs):
            if r:
                per.setdefault(t, {})[fn] = r
    print('%d bateram' % sum(len(v) for v in per.values()), flush=True)
    for t, items in sorted(per.items()):
        path = os.path.join(R, 'build/autodecomp', t, 'results.json')
        os.makedirs(os.path.dirname(path), exist_ok=True)
        old = json.load(open(path)) if os.path.exists(path) else {}
        old.update(items)
        json.dump(old, open(path, 'w'), indent=1)
        r = subprocess.run([sys.executable, '-I', 'tools/autodecomp.py', t, '--apply'],
                           capture_output=True, text=True, cwd=R)
        print(r.stdout.strip().splitlines()[-1] if r.stdout.strip() else '%s: erro' % t, flush=True)


if __name__ == '__main__':
    main()
