"""Compara funcoes compiladas de um .o com os bytes originais do EXE.

Uso: python3 -I tools/cc_cmp.py <arquivo.o> <binario> func_XXXXXXXX ...
     [--vram 0x80010000] [--off 0x800]

O endereco sai do nome (func_80011DAC). --vram e --off dizem onde o
binario e carregado e o offset do inicio dele no arquivo (padrao: EXE;
overlays de nivel 1: --vram 0x80082CB0 --off 0; nivel 2: --vram
0x800A5DE0 --off 0). Campos com relocacao no .o
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


def compare(obj, exe_b, names, load=LOAD, hdr=HDR, osizes=None):
    """Devolve {nome: lista de (offset, compilado, original)} ou None se a
    funcao nao esta no .o. Lista vazia = bate. osizes: {nome: tamanho
    original}; se dado, instrucoes a mais ou a menos contam como
    diferencas."""
    text = text_bytes(obj)
    syms = symbols(obj)
    rel = relocs(obj)
    out = {}
    for name in names:
        addr = int(name.split('_')[-1], 16)
        if name not in syms:
            out[name] = None
            continue
        start, size = syms[name]
        diffs = []
        for i in range(0, size, 4):
            a = struct.unpack_from('<I', text, start + i)[0]
            o = addr - load + hdr + i
            if o + 4 > len(exe_b):
                diffs.append((i, a, None))
                continue
            b = struct.unpack_from('<I', exe_b, o)[0]
            m = ~rel.get(start + i, 0) & 0xFFFFFFFF
            if a & m != b & m:
                diffs.append((i, a, b))
        osize = (osizes or {}).get(name)
        if osize is not None:
            for i in range(size, osize, 4):
                diffs.append((i, None, None))
            for i in range(osize, size, 4):
                diffs.append((i, None, None))
        out[name] = diffs
    return out


def main():
    args = sys.argv[1:]
    load, hdr = LOAD, HDR
    if '--vram' in args:
        i = args.index('--vram')
        load = int(args[i + 1], 16)
        del args[i:i + 2]
    if '--off' in args:
        i = args.index('--off')
        hdr = int(args[i + 1], 16)
        del args[i:i + 2]
    obj, exe = args[:2]
    res = compare(obj, open(exe, 'rb').read(), args[2:], load, hdr)
    ok_all = True
    for name, diffs in res.items():
        if diffs is None:
            print('%s: nao esta no .o' % name)
            ok_all = False
        elif diffs:
            ok_all = False
            print('%s: %d instrucoes diferentes' % (name, len(diffs)))
            for i, a, b in diffs[:8]:
                print('   +%03X  compilado %08X  original %s' % (
                    i, a, '%08X' % b if b is not None else '--------'))
        else:
            print('%s: OK' % name)
    sys.exit(0 if ok_all else 1)

if __name__ == '__main__':
    main()
