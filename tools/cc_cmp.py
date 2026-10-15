"""Compara funcoes compiladas de um .o com os bytes originais do EXE.

Uso: python3 -I tools/cc_cmp.py <arquivo.o> <exe> func_XXXXXXXX ...

O endereco sai do nome (func_80011DAC). Campos com relocacao no .o
(jal, %hi, %lo) sao ignorados na comparacao. Imprime, por funcao,
OK ou as instrucoes diferentes.
"""
import os
import re
import struct
import subprocess
import sys

LOAD = 0x80010000
HDR = 0x800
CROSS = 'mips-linux-gnu-'


def run(*a):
    # LANG=C: o readelf traduz os cabecalhos que o parser procura
    return subprocess.run(a, capture_output=True, text=True, check=True,
                          env=dict(os.environ, LANG='C', LC_ALL='C')).stdout


def symbols(obj):
    out = {}
    for ln in run(CROSS + 'readelf', '-sW', obj).splitlines():
        p = ln.split()
        if len(p) == 8 and p[3] == 'FUNC':
            out[p[7]] = (int(p[1], 16), int(p[2]))
    return out


def relocs(obj):
    """Offsets em .text com relocacao -> mascara dos bits relocados."""
    out = {}
    sec = None
    for ln in run(CROSS + 'readelf', '-rW', obj).splitlines():
        m = re.match(r"Relocation section '(\S+)'", ln)
        if m:
            sec = m.group(1)
            continue
        p = ln.split()
        if sec == '.rel.text' and len(p) >= 3 and p[2].startswith('R_MIPS'):
            mask = 0x03FFFFFF if p[2] == 'R_MIPS_26' else 0xFFFF
            out[int(p[0], 16)] = mask
    return out


def text_bytes(obj):
    sh = run(CROSS + 'objdump', '-h', obj)
    for ln in sh.splitlines():
        p = ln.split()
        if len(p) > 5 and p[1] == '.text':
            size, off = int(p[2], 16), int(p[5], 16)
            return open(obj, 'rb').read()[off:off + size]
    return b''


def main():
    obj, exe = sys.argv[1:3]
    exe_b = open(exe, 'rb').read()
    text = text_bytes(obj)
    syms = symbols(obj)
    rel = relocs(obj)
    ok_all = True
    for name in sys.argv[3:]:
        addr = int(name.split('_')[-1], 16)
        if name not in syms:
            print('%s: nao esta no .o' % name)
            ok_all = False
            continue
        start, size = syms[name]
        diffs = []
        for i in range(0, size, 4):
            a = struct.unpack_from('<I', text, start + i)[0]
            b = struct.unpack_from('<I', exe_b, addr - LOAD + HDR + i)[0]
            m = ~rel.get(start + i, 0) & 0xFFFFFFFF
            if a & m != b & m:
                diffs.append((i, a, b))
        if diffs:
            ok_all = False
            print('%s: %d/%d instrucoes diferentes' % (
                name, len(diffs), size // 4))
            for i, a, b in diffs[:8]:
                print('   +%03X  compilado %08X  original %08X' % (i, a, b))
        else:
            print('%s: OK (%d instrucoes)' % (name, size // 4))
    sys.exit(0 if ok_all else 1)


if __name__ == '__main__':
    main()
