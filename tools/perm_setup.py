"""Prepara diretorios do decomp-permuter (tools/decomp-permuter).

Uso:
  python3 -I tools/perm_setup.py <nome> <func> [arq.c]
      cria build/perm/<func>/ a partir de arq.c (ou do melhor rascunho do
      tools/autodecomp.py)
  python3 -I tools/perm_setup.py <nome> --near N
      cria para todas as funcoes pendentes que o autodecomp deixou a no
      maximo N instrucoes do original

Depois: tools/decomp-permuter/permuter.py -j8 --stop-on-zero build/perm/<func>
"""
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import autodecomp as ad  # noqa: E402
import fn as fnt  # noqa: E402

R = ad.R
OUT = os.path.join(R, 'build/perm')

COMPILE = '''#!/bin/sh
# chamado pelo permuter: compile.sh <in.c> -o <out.o>
exec "{R}/tools/cc.sh" "$1" "$3" {G}
'''


def setup(name, fn, code):
    d = os.path.join(OUT, fn)
    os.makedirs(d, exist_ok=True)
    G = ad.target(name)[3]
    # C preprocessado (o permuter nao segue #include)
    tu = os.path.join(d, 'tu.c')
    open(tu, 'w').write(fnt.tu(name, fn, code))
    pre = subprocess.run([os.path.join(R, 'tools/old-gcc/2.8.1/cpp'), '-P',
                          '-I' + os.path.join(R, 'include'), '-DM2CTX', tu],
                         capture_output=True, text=True).stdout
    # atributos de secao (NOT_GP) ficam fora do parser do permuter
    pre = re.sub(r'^(extern [^;]*__attribute__[^;]*;)$', r'PERM_IGNORE(\1)',
                 pre, flags=re.M)
    open(os.path.join(d, 'base.c'), 'w').write(pre)
    os.remove(tu)
    # alvo: o assembly original montado
    s = os.path.join(d, 'target.s')
    open(s, 'w').write('.include "macro.inc"\n.set noat\n.set noreorder\n'
                       '.section .text\n.include "%s"\n' % os.path.join(
                           R, fnt.Target(name).asm, fn + '.s'))
    r = subprocess.run(['mips-linux-gnu-as', '-I' + os.path.join(R, 'include'),
                        '-march=r3000', '-mtune=r3000', '-no-pad-sections',
                        '-EL', '-G0', '-32', '-mno-shared', '-o',
                        os.path.join(d, 'target.o'), s],
                       capture_output=True, text=True)
    if r.returncode:
        print(fn, 'erro montando o alvo:', r.stderr[-300:])
        return False
    c = os.path.join(d, 'compile.sh')
    open(c, 'w').write(COMPILE.format(R=R, G=G))
    os.chmod(c, 0o755)
    open(os.path.join(d, 'settings.toml'), 'w').write(
        'func_name = "%s"\ncompiler_type = "gcc"\n' % fn)
    return True


def main():
    name = sys.argv[1]
    if sys.argv[2] == '--near':
        n = int(sys.argv[3])
        res = json.load(open(os.path.join(R, 'build/autodecomp', name,
                                          'results.json')))
        pend = set(ad.pending(name))
        done = 0
        for f, r in sorted(res.items()):
            if f in pend and r.get('status') == 'diff' and r['ndiff'] <= n:
                done += setup(name, f, r['code'])
        print('%d diretorios em %s' % (done, OUT))
        return
    fn = sys.argv[2]
    if len(sys.argv) > 3:
        code = open(sys.argv[3]).read()
    else:
        code = json.load(open(os.path.join(R, 'build/autodecomp', name,
                                           'results.json')))[fn]['code']
    setup(name, fn, code)


if __name__ == '__main__':
    main()
