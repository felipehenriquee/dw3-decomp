"""Procura os objetos da PsyQ no EXE usando as assinaturas do
lab313ru/psx_psyq_signatures (clonado em tools/psyq_sigs).

Uso:
  python3 -I tools/psyq_match.py <exe> <pasta sigs> versoes
      conta quantos objetos de cada versao aparecem no EXE
  python3 -I tools/psyq_match.py <exe> <pasta sigs> <versao> [--syms]
      lista os objetos encontrados; com --syms imprime as funcoes no
      formato do symbol_addrs.txt
"""
import json
import os
import re
import sys

LOAD = 0x80010000
HDR = 0x800


def load_sigs(path):
    out = []
    for fn in sorted(os.listdir(path)):
        if not fn.endswith('.json'):
            continue
        lib = fn[:-5]
        for e in json.load(open(os.path.join(path, fn))):
            out.append((lib, e))
    return out


def compile_sig(sig):
    parts = sig.split()
    if len(parts) < 16:
        return None
    rx = b''.join(b'.' if p == '??' else re.escape(bytes([int(p, 16)]))
                  for p in parts)
    return re.compile(rx, re.S), len(parts)


def find(text, sigs):
    """Devolve [(addr, lib, obj, tamanho, labels, mascarada)] sem
    sobreposicao."""
    hits = []
    for lib, e in sigs:
        c = compile_sig(e.get('sig', ''))
        if c is None:
            continue
        rx, n = c
        for m in rx.finditer(text):
            if m.start() % 4 == 0:
                hits.append((LOAD + m.start(), lib, e['name'], n,
                             e.get('labels', []), '??' in e['sig']))
    # assinaturas maiores primeiro: objetos pequenos podem aparecer
    # dentro de outros
    hits.sort(key=lambda h: -h[3])
    taken = []
    out = []
    for h in hits:
        a, b = h[0], h[0] + h[3]
        if any(a < y and x < b for x, y in taken):
            continue
        taken.append((a, b))
        out.append(h)
    # assinaturas curtas (getters de poucas instrucoes) casam com codigo
    # do jogo; so valem se encostarem em outro objeto da lib
    ends = {h[0] + h[3] for h in out if h[3] >= 32}
    starts = {h[0] for h in out if h[3] >= 32}
    out = [h for h in out
           if h[3] >= 32 or h[0] in ends or h[0] + h[3] in starts]
    return sorted(out)


SHORT = 48
LOCAL = re.compile(r'(loc|text|data|bss|sdata|sbss|rdata|stup)')


def certain(hits):
    """Marca quais casamentos sao confiaveis para dar nome.

    Stubs curtos (setters/getters de uma global) tem assinaturas iguais
    entre si: so valem se casaram uma unica vez e se um vizinho e da
    mesma lib ou se a assinatura nao tem bytes mascarados (chamadas da
    BIOS, que incluem o numero da funcao).
    """
    count = {}
    for h in hits:
        count[(h[1], h[2])] = count.get((h[1], h[2]), 0) + 1
    out = []
    for i, h in enumerate(hits):
        ok = h[3] >= SHORT
        if not ok and count[(h[1], h[2])] == 1:
            libs = {hits[k][1] for k in (i - 1, i + 1) if 0 <= k < len(hits)}
            ok = h[1] in libs or not h[5]
        out.append(ok)
    return out


def main():
    exe, root, mode = sys.argv[1:4]
    text = open(exe, 'rb').read()[HDR:]
    if mode == 'versoes':
        for v in sorted(os.listdir(root)):
            p = os.path.join(root, v)
            if not (os.path.isdir(p) and v.isdigit()):
                continue
            hits = find(text, load_sigs(p))
            print('%-5s %3d objetos  %6d bytes' % (
                v, len(hits), sum(h[3] for h in hits)))
        return
    hits = find(text, load_sigs(os.path.join(root, mode)))
    ok = certain(hits)
    if '--syms' in sys.argv:
        # formato do symbol_addrs.txt, agrupado por objeto
        print('// Funcoes da PsyQ %s identificadas por assinatura' % mode)
        print('// (python3 -I tools/psyq_match.py <exe> tools/psyq_sigs '
              '%s --syms)' % mode)
        seen = set()
        for (a, lib, obj, n, labels, _), sure in zip(hits, ok):
            if not sure:
                continue
            names = [lb for lb in labels if not LOCAL.match(lb['name'])
                     and lb['name'] not in seen]
            if not names:
                continue
            print('\n// %s %s' % (lib, obj))
            for lb in names:
                seen.add(lb['name'])
                print('%s = 0x%08X; // type:func' % (lb['name'],
                                                    a + lb['offset']))
        return
    if '--yaml' in sys.argv:
        # subsegmentos do text: um arquivo por objeto da lib
        i = sys.argv.index("--yaml")
        text_start, text_end = [int(x, 16) for x in sys.argv[i + 1:i + 3]]
        off = lambda a: a - LOAD + HDR  # noqa: E731
        prev = text_start
        used = set()
        for (a, lib, obj, n, labels, _), sure in zip(hits, ok):
            if a < text_start or a >= text_end:
                continue
            if a > prev:
                print('      - [0x%X, asm]' % off(prev))
            lib_s = lib.split('.')[0].lower()
            obj_s = obj.split('.')[0].lower()
            nm = 'psyq/' + (obj_s if lib_s == obj_s else
                            '%s/%s' % (lib_s, obj_s))
            if not sure or nm in used:
                nm = 'psyq/%s/%X' % (lib_s, off(a))
            used.add(nm)
            print('      - [0x%X, asm, %s]' % (off(a), nm))
            prev = a + n
        if prev < text_end:
            print('      - [0x%X, asm]' % off(prev))
        return
    for (a, lib, obj, n, labels, _), sure in zip(hits, ok):
        names = [lb['name'] for lb in labels if not LOCAL.match(lb['name'])]
        print('%08X-%08X %s %-16s %-12s %s' % (
            a, a + n, ' ' if sure else '?', lib, obj, ' '.join(names[:6])))


if __name__ == '__main__':
    main()
