"""Estima os limites rodata/text/data de cada overlay .PRO.

Uso: python3 -I tools/ovl_bounds.py <pasta PRO> [arquivo.PRO ...]

O layout dos overlays e o mesmo do EXE: rodata (jump tables e strings),
depois o text, depois os dados.
- inicio do text: menor alvo de jal interno ou primeiro prologo
  (addiu sp,sp,-N); se antes dele houver funcoes folha (terminam em
  jr ra) depois do ultimo ponteiro da rodata, o inicio recua ate elas.
- fim do text: depois do ultimo 'jr ra' + delay slot.
"""
import os
import struct
import sys

LVL1 = 0x80082CB0
LVL2 = 0x800A5DE0
JR_RA = 0x03E00008


def vram_of(name):
    return LVL2 if name.startswith('W') else LVL1


def bounds(b, vram):
    """Devolve (text_start, text_end) em offsets do arquivo, ou None."""
    n = len(b) // 4
    w = struct.unpack_from('<%dI' % n, b)
    end_addr = vram + len(b)
    jr = [i * 4 for i, x in enumerate(w) if x == JR_RA]
    if not jr:
        return None
    text_end = jr[-1] + 8
    starts = set()
    for i, x in enumerate(w):
        if (x & 0xFFFF8000) == 0x27BD8000:
            starts.add(i * 4)
        if (x >> 26) == 3:
            t = 0x80000000 | ((x & 0x03FFFFFF) << 2)
            if vram <= t < end_addr:
                starts.add(t - vram)
    first = min(s for s in starts if s < text_end)
    # o ultimo ponteiro para dentro do overlay antes do text marca o fim
    # das jump tables: o text nao pode comecar antes dele
    last_ptr = -4
    for k in range(0, first, 4):
        if vram <= w[k // 4] < end_addr:
            last_ptr = k
    # o 'jr ra' mais antigo entre last_ptr e first pertence a uma funcao
    # folha; ela comeca depois do 'jr ra' anterior ou do fim da rodata
    text_start = first
    for k in range(first - 8, last_ptr, -4):
        if w[k // 4] == JR_RA:
            p = k - 4
            while p > last_ptr and w[p // 4] != JR_RA:
                p -= 4
            text_start = p + 8 if p > last_ptr else last_ptr + 4
    return text_start, text_end


def main():
    d = sys.argv[1]
    names = sys.argv[2:] or sorted(os.listdir(d))
    for nm in names:
        b = open(os.path.join(d, nm), 'rb').read()
        v = vram_of(nm)
        r = bounds(b, v)
        if r is None:
            print('%-14s %6x %08x sem-codigo' % (nm, len(b), v))
        else:
            print('%-14s %6x %08x text %6x-%6x' % ((nm, len(b), v) + r))


if __name__ == '__main__':
    main()
