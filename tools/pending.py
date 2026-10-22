"""Lista as funcoes pendentes (ainda em asm) por tamanho.

Uso: python3 -I tools/pending.py [--skip arq] [--show N] [alvo ...]

Imprime "instrucoes alvo funcao", das menores para as maiores. Ignora os
jlabel (case de switch separados pelo splat) e o trecho de biblioteca do
STDWTITL. --skip arq: nomes de funcao (um por linha) a pular. --show N:
mostra o asm das N primeiras (como o tools/fn.py show).
"""
import glob
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import autodecomp as ad  # noqa: E402
from proj import R, Target  # noqa: E402


def main():
    args = sys.argv[1:]
    skip, show = set(), 0
    if '--skip' in args:
        i = args.index('--skip')
        skip = set(open(args[i + 1]).read().split())
        del args[i:i + 2]
    if '--show' in args:
        i = args.index('--show')
        show = int(args[i + 1])
        del args[i:i + 2]
    targets = args or ['main'] + sorted(os.path.basename(p)[:-2]
                                         for p in glob.glob(os.path.join(R, 'src/ovl/*.c')))
    rows = []
    for t in targets:
        T = Target(t)
        for fn in ad.pending(t):
            if fn in skip:
                continue
            p = T.p(T.asm + '/' + fn + '.s')
            if not os.path.exists(p):
                continue
            s = open(p).read()
            if 'glabel' not in s:
                continue
            if t == 'STDWTITL' and int(fn[5:], 16) >= 0x80087300:
                continue
            n = len(re.findall(r'^\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/', s, re.M))
            rows.append((n, t, fn))
    rows.sort()
    for n, t, fn in rows:
        print(n, t, fn)
    for n, t, fn in rows[:show]:
        print('== %s %s (%d)' % (t, fn, n))
        out = subprocess.run([sys.executable, '-I', os.path.join(R, 'tools/fn.py'), t, fn, 'show'],
                             capture_output=True, text=True).stdout
        m = re.search(r'glabel.*?endlabel[^\n]*', out, re.S)
        print(m.group() if m else out)


if __name__ == '__main__':
    main()
