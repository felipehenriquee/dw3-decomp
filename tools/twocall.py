"""Gera o C das funcoes pendentes que so fazem N chamadas seguidas
D_80048ABC.fn(K, n) (forma comum nos WSTAG e na FIELDSTG: liga/desliga
flags do mapa). Grava como ok no results.json; integre com
tools/autodecomp.py <alvo> --apply.

Uso: python3 -I tools/twocall.py
"""
import glob
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import autodecomp as ad  # noqa: E402
import propagate as pr  # noqa: E402
from proj import R, Target  # noqa: E402

HEAD = ['addiu $sp, $sp, K', 'addiu $a0, $zero, K', 'sw $s0, K($sp)',
        'lui $s0, %hi(D_80048ABC)', 'addiu $s0, $s0, %lo(D_80048ABC)',
        'sw $ra, K($sp)', 'lw $v0, K($s0)', 'nop', 'jalr $v0', 'addiu $a1, $zero, K']
MID = ['addiu $a0, $zero, K', 'lw $v0, K($s0)', 'nop', 'jalr $v0', 'addiu $a1, $zero, K']
TAIL = ['lw $ra, K($sp)', 'lw $s0, K($sp)', 'jr $ra', 'addiu $sp, $sp, K']


def parse(path):
    ins = [re.sub(r'\s+', ' ', m.group(1)).strip()
           for m in re.finditer(r'/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/\s*(.*)', open(path).read())]
    norm = [re.sub(r'-?0x[0-9A-F]+', 'K', i).replace('ori $a0, $zero, K', 'addiu $a0, $zero, K')
            .replace('ori $a1, $zero, K', 'addiu $a1, $zero, K').replace('addu $a1, $zero, $zero', 'addiu $a1, $zero, K')
            for i in ins]
    if norm[:10] != HEAD or norm[-4:] != TAIL:
        return None
    body = norm[10:-4]
    if len(body) % 5 or any(body[i:i + 5] != MID for i in range(0, len(body), 5)):
        return None
    calls = []
    pos = [(1, 6, 9)] + [(10 + 5 * j, 11 + 5 * j, 14 + 5 * j) for j in range(len(body) // 5)]
    for ia0, ilw, ia1 in pos:
        k = int(re.search(r'(0x[0-9A-F]+)$', ins[ia0]).group(1), 16)
        off = int(re.search(r'(0x[0-9A-F]+)\(', ins[ilw]).group(1), 16)
        m = re.search(r'(0x[0-9A-F]+)$', ins[ia1])
        calls.append((off, k, int(m.group(1), 16) if m else 0))
    return calls


def main():
    out = {}
    for t in pr.targets():
        if t == 'main':
            continue
        T = Target(t)
        for fn in ad.pending(t):
            p = T.p(T.asm + '/' + fn + '.s')
            if not os.path.exists(p):
                continue
            calls = parse(p)
            if not calls or len(calls) < 2:
                continue
            body = ''.join('    (*(void (**)(s32, s32))(f + 0x%X))(0x%X, %d);\n' % c for c in calls)
            out.setdefault(t, {})[fn] = ('extern struct opaque D_80048ABC;\nvoid %s(void) {\n'
                                         '    u8 *f = (u8 *)&D_80048ABC;\n\n%s}\n' % (fn, body))
    n = 0
    for t, fs in out.items():
        p = os.path.join(R, 'build/autodecomp', t, 'results.json')
        os.makedirs(os.path.dirname(p), exist_ok=True)
        res = json.load(open(p)) if os.path.exists(p) else {}
        for fn, code in fs.items():
            res[fn] = {'status': 'ok', 'code': code, 'types': {}, 'variant': 0}
            n += 1
        json.dump(res, open(p, 'w'), indent=1)
    print('%d geradas em %d alvos' % (n, len(out)))


if __name__ == '__main__':
    main()
