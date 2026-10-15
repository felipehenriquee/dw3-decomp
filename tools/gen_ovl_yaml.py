"""Gera um yaml do splat para cada overlay .PRO em config/ovl/.

Uso: python3 -I tools/gen_ovl_yaml.py <pasta PRO> [arquivo.PRO ...]

Arquivos que ja existem nao sao sobrescritos (podem ter sido ajustados a
mao); apague o yaml para regera-lo.
"""
import hashlib
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ovl_bounds import bounds, vram_of  # noqa: E402

OUT = 'config/ovl'

HEADER = """\
name: {name}
sha1: {sha1}
options:
  basename: {name}
  target_path: disc/PRO/{name}.PRO
  elf_path: build/ovl/{name}.elf
  base_path: ../..
  platform: psx
  compiler: PSYQ
  asm_path: asm/ovl/{name}
  asset_path: assets/ovl/{name}
  ld_script_path: linker/ovl/{name}.ld
  ld_dependencies: True
  find_file_boundaries: False
  gp_value: 0x8005CB50
  o_as_suffix: True
  use_legacy_include_asm: False
  # os arquivos de include/ vem do split do EXE
  generate_asm_macros_files: False
  section_order: [".rodata", ".text", ".data", ".bss"]
  symbol_addrs_path: [symbol_addrs.txt]
  reloc_addrs_path: [reloc_addrs.txt]
  undefined_funcs_auto_path: linker/ovl/{name}.undefined_funcs_auto.txt
  undefined_syms_auto_path: linker/ovl/{name}.undefined_syms_auto.txt
  subalign: {subalign}
  ld_align_section_vram_end: False
  ld_align_segment_vram_end: False
  string_encoding: ASCII
  data_string_encoding: ASCII
  rodata_string_guesser_level: 2
  data_string_guesser_level: 2
segments:
"""


def segments(name, b):
    size = len(b)
    vram = vram_of(name)
    r = bounds(b, vram)
    if r is None:
        # so dados: vai inteiro como binario
        return ('  - name: {n}\n    type: bin\n    start: 0x0\n'
                '    vram: 0x{v:08X}\n  - [0x{s:X}]\n').format(
                    n=name, v=vram, s=size)
    ts, te = r
    subs = []
    if ts > 0:
        subs.append('[0x0, rodata]')
    subs.append('[0x%X, asm]' % ts)
    tail = size & ~3
    if te < tail:
        subs.append('[0x%X, data]' % te)
    if tail < size:
        # o spimdisasm descarta bytes que nao fecham uma palavra
        subs.append('[0x%X, bin]' % tail)
    out = ('  - name: {n}\n    type: code\n    start: 0x0\n'
           '    vram: 0x{v:08X}\n    subsegments:\n').format(n=name, v=vram)
    out += ''.join('      - %s\n' % s for s in subs)
    out += '  - [0x%X]\n' % size
    return out


def main():
    d = sys.argv[1]
    names = sys.argv[2:] or sorted(os.listdir(d))
    os.makedirs(OUT, exist_ok=True)
    for fn in names:
        name = os.path.splitext(fn)[0]
        path = os.path.join(OUT, name + '.yaml')
        if os.path.exists(path):
            continue
        b = open(os.path.join(d, fn), 'rb').read()
        with open(path, 'w') as f:
            # SUBALIGN(2) alinha as .bss vazias depois de uma cauda de
            # tamanho impar e o linker acrescenta 1 byte
            f.write(HEADER.format(name=name,
                                  sha1=hashlib.sha1(b).hexdigest(),
                                  subalign=1 if len(b) % 2 else 2))
            f.write(segments(name, b))


if __name__ == '__main__':
    main()
