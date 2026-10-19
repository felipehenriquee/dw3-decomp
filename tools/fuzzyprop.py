"""Propagacao que tambem troca constantes.

Uso: python3 -I tools/fuzzyprop.py [alvo ...]

Como o tools/propagate.py, mas a forma ignora os imediatos: uma funcao
pendente com a mesma forma de uma ja em C (a menos das constantes) recebe
o C dela com os simbolos trocados na ordem e as constantes trocadas pelo
valor (a n-esima constante do asm do modelo vira a n-esima da pendente;
valores com mais de um destino: testa as combinacoes). O resultado e compilado
e comparado; os que batem vao para o results.json e sao integrados com o
tools/autodecomp.py <alvo> --apply.
"""
import itertools
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


def remaps(code, ca, cb, limit=64):
    """Versoes do C com as constantes de ca trocadas pelas de cb. Valores
    com mais de um destino geram uma versao por combinacao (ate limit)."""
    if len(ca) != len(cb):
        return []
    dest = {}
    for x, y in zip(ca, cb):
        dest.setdefault(x, [])
        if y not in dest[x]:
            dest[x].append(y)
    toks = list(NUM.finditer(code))
    choices = []
    for m in toks:
        try:
            v = int(m.group(), 0)
        except ValueError:
            choices.append([None])
            continue
        opts = None
        for key in (v, v & 0xFFFFFFFF, v - (1 << 32) if v >= 1 << 31 else v):
            if key in dest:
                opts = dest[key]
                break
        choices.append(opts if opts else [None])
    out = []
    for combo in itertools.product(*choices):
        if len(out) >= limit:
            break
        parts, last = [], 0
        for m, nv in zip(toks, combo):
            parts.append(code[last:m.start()])
            tok = m.group()
            if nv is None or nv == int(tok, 0):
                parts.append(tok)
            else:
                parts.append('0x%X' % nv if tok.lower().startswith(('0x', '-0x')) and nv >= 0 else str(nv))
            last = m.end()
        parts.append(code[last:])
        v = ''.join(parts)
        if v not in out:
            out.append(v)
    return out


def job(args):
    tb, fb, syms_b, cb, models = args
    for ta, fa, syms_a, ca in models:
        code = pr.c_function(open(Target(ta).p(Target(ta).src)).read(), fa)
        if code is None:
            continue
        for k in range(len(remaps(code, ca, cb))):
            r = pr.candidate((tb, fb, syms_b, ta, fa, syms_a),
                             transform=lambda c, k=k: (remaps(c, ca, cb) + [None] * (k + 1))[k])
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
