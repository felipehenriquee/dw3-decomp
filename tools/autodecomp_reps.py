"""Autodecomp so em um representante de cada forma de funcao pendente.

Uso: python3 -I tools/autodecomp_reps.py [prefixo]   (padrao: WSTAG)

Os overlays de mapa repetem muito codigo: agrupa as funcoes pendentes pela
forma (asm normalizado, ver tools/propagate.py), roda o
tools/autodecomp.py em um representante de cada grupo, integra as que
batem e depois o tools/propagate.py leva o C para as copias.
"""
import collections
import glob
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import autodecomp as ad  # noqa: E402
import propagate  # noqa: E402
from proj import R, Target  # noqa: E402


def main():
    prefix = sys.argv[1] if len(sys.argv) > 1 else 'WSTAG'
    targets = sorted(os.path.basename(p)[:-2] for p in
                     glob.glob(os.path.join(R, 'src/ovl/%s*.c' % prefix)))
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
    for t in sorted(reps):
        T = Target(t)
        if not os.path.getsize(T.p(T.auto)):
            subprocess.run([sys.executable, '-I', 'tools/gen_ctx.py', t],
                           cwd=R, capture_output=True)
        res = ad.test(t, reps[t])
        if any(r['status'] == 'ok' for r in res.values()):
            ad.apply(t)
        sys.stdout.flush()
    print('== propagando', flush=True)
    subprocess.run([sys.executable, '-I', 'tools/propagate.py'] + targets,
                   cwd=R)


if __name__ == '__main__':
    main()
