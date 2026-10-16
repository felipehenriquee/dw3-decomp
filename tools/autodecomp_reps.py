"""Autodecomp so em um representante de cada forma de funcao pendente.

Uso: python3 -I tools/autodecomp_reps.py [--retest] [prefixo ...]
     (padrao: WSTAG; --retest testa de novo funcoes ja testadas)

Os overlays de mapa repetem muito codigo: agrupa as funcoes pendentes pela
forma (asm normalizado, ver tools/propagate.py), roda o
tools/autodecomp.py em um representante de cada grupo, integra as que
batem e depois o tools/propagate.py leva o C para as copias.
"""
import collections
import glob
import json
import multiprocessing
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import autodecomp as ad  # noqa: E402
import propagate  # noqa: E402
from proj import R, Target  # noqa: E402


def main():
    args = [a for a in sys.argv[1:] if a != '--retest']
    retest = '--retest' in sys.argv
    prefixes = args or ['WSTAG']
    targets = sorted({os.path.basename(p)[:-2] for pre in prefixes for p in
                      glob.glob(os.path.join(R, 'src/ovl/%s*.c' % pre))})
    groups = collections.OrderedDict()
    for t in targets:
        T = Target(t)
        T.ensure_files()
        for fn in ad.pending(t):
            p = T.p(T.asm + '/' + fn + '.s')
            if os.path.exists(p):
                groups.setdefault(propagate.shape(p)[0], []).append((t, fn))
    reps = collections.defaultdict(list)
    for members in groups.values():
        t, fn = members[0]
        reps[t].append(fn)
    total = sum(len(v) for v in groups.values())
    print('%d funcoes pendentes, %d formas, representantes em %d overlays'
          % (total, len(groups), len(reps)), flush=True)
    # um Pool so para os representantes de todos os overlays
    jobs = []
    for t in sorted(reps):
        T = Target(t)
        if not os.path.getsize(T.p(T.auto)):
            subprocess.run([sys.executable, '-I', 'tools/gen_ctx.py', t],
                           cwd=R, capture_output=True)
        work = os.path.join(R, 'build/autodecomp', t)
        base = ad.make_base(t, work)
        canon = ad.canonical(t)
        rp = os.path.join(work, 'results.json')
        done = json.load(open(rp)) if os.path.exists(rp) else {}
        jobs += [(t, fn, base, work, canon) for fn in reps[t]
                 if retest or fn not in done]
    print('%d testes' % len(jobs), flush=True)
    results = collections.defaultdict(dict)
    with multiprocessing.Pool(os.cpu_count()) as pool:
        for k, (job, (fn, r)) in enumerate(zip(jobs, pool.imap(ad.try_one, jobs))):
            results[job[0]][fn] = r
            if k % 50 == 0:
                print('  %d/%d' % (k, len(jobs)), flush=True)
    for t, res in sorted(results.items()):
        path = os.path.join(R, 'build/autodecomp', t, 'results.json')
        old = json.load(open(path)) if os.path.exists(path) else {}
        old.update(res)
        json.dump(old, open(path, 'w'), indent=1)
        if any(r['status'] == 'ok' for r in res.values()):
            ad.apply(t)
            sys.stdout.flush()
    print('== propagando', flush=True)
    subprocess.run([sys.executable, '-I', 'tools/propagate.py'] + targets,
                   cwd=R)


if __name__ == '__main__':
    main()
