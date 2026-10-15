"""Estima quantos argumentos (a0-a3) cada funcao recebe, pelo asm.

Um registrador de argumento e considerado parametro se a funcao o le
antes de escrever nele (varredura linear; aproximado, mas bom o bastante
para dar ao m2c prototipos com a aridade certa, para ele nao perder
argumentos repassados sem mudanca nos registradores).

Uso como modulo: arities(target) -> {nome: n}. Linha de comando:
  python3 -I tools/arity.py <alvo> [func ...]
"""
import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from proj import R, Target  # noqa: E402

AREG = ['$a0', '$a1', '$a2', '$a3']
INSN = re.compile(r'^\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/\s+(\S+)\s*(.*)$')
# instrucoes cujo primeiro operando e lido (nao escrito)
READ_FIRST = {'sw', 'sh', 'sb', 'swl', 'swr', 'beq', 'bne', 'beqz', 'bnez',
              'blez', 'bgtz', 'bltz', 'bgez', 'jr', 'jalr', 'mthi', 'mtlo',
              'mult', 'multu', 'div', 'divu', 'teq', 'tne', 'mtc0', 'mtc2',
              'ctc2', 'swc2'}


def arity_of(lines):
    written, read = set(), set()
    for ln in lines:
        m = INSN.match(ln)
        if not m:
            continue
        op, args = m.group(1), m.group(2)
        args = re.sub(r'/\*.*?\*/', '', args)
        ops = [a.strip() for a in args.split(',') if a.strip()]
        regs = [re.findall(r'\$\w+', o) for o in ops]
        if op in ('jal', 'jalr'):
            # depois de uma chamada, a0-a3 nao valem mais nada
            for r in (regs[0] if op == 'jalr' and regs else []):
                if r in AREG and r not in written:
                    read.add(r)
            written.update(AREG)
            continue
        if not regs:
            continue
        if op in READ_FIRST or op.startswith(('b', 's')) and op not in (
                'sll', 'srl', 'sra', 'sllv', 'srlv', 'srav', 'slt', 'sltu',
                'slti', 'sltiu', 'subu', 'sub'):
            srcs, dst = [r for g in regs for r in g], []
        else:
            dst = regs[0]
            srcs = [r for g in regs[1:] for r in g]
        for r in srcs:
            if r in AREG and r not in written:
                read.add(r)
        for r in dst:
            written.add(r)
    n = 0
    for i, r in enumerate(AREG):
        if r in read:
            n = i + 1
    return n


def split_funcs(path):
    """{nome: linhas} de um .s com uma ou mais funcoes."""
    out, cur = {}, None
    for ln in open(path):
        m = re.match(r'\s*glabel (\w+)', ln)
        if m:
            cur = m.group(1)
            out[cur] = []
            continue
        if re.match(r'\s*endlabel', ln):
            cur = None
            continue
        if cur:
            out[cur].append(ln)
    return out


_cache = {}


def arities(target):
    """Aridade das funcoes visiveis a partir do alvo: as do proprio alvo,
    as do EXE e as da PsyQ."""
    if target in _cache:
        return _cache[target]
    files = glob.glob(os.path.join(R, 'asm/psyq/**/*.s'), recursive=True)
    files += glob.glob(os.path.join(R, Target('main').asm, '*.s'))
    files += glob.glob(os.path.join(R, Target('main').asm.replace(
        'nonmatchings', 'matchings'), '*.s'))
    if target != 'main':
        T = Target(target)
        files += glob.glob(os.path.join(R, T.asm, '*.s'))
        files += glob.glob(os.path.join(R, T.asm.replace(
            'nonmatchings', 'matchings'), '*.s'))
    out = {}
    for f in files:
        for name, lines in split_funcs(f).items():
            out[name] = arity_of(lines)
    _cache[target] = out
    return out


def main():
    t = sys.argv[1]
    a = arities(t)
    names = sys.argv[2:] or sorted(a)
    for n in names:
        print(n, a.get(n))


if __name__ == '__main__':
    main()
