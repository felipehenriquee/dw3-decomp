import struct, os, sys, collections

# Estima o endereço de carga de cada overlay .PRO: a base certa faz os
# alvos de 'jal' internos caírem em prólogos de função (addiu sp,sp,-N).
p = sys.argv[1]
res = {}
for f in sorted(os.listdir(p)):
    b = open(os.path.join(p, f), 'rb').read()
    n = len(b) // 4
    w = struct.unpack_from('<%dI' % n, b)
    prolog = [i * 4 for i, x in enumerate(w) if (x & 0xFFFF8000) == 0x27BD8000]
    jals = [0x80000000 | ((x & 0x03FFFFFF) << 2) for x in w if (x >> 26) == 3]
    votes = collections.Counter()
    for t in jals:
        for off in prolog:
            base = t - off
            if 0x80010000 <= base <= 0x80100000:
                votes[base] += 1
    if votes:
        (base, score), = votes.most_common(1)
        res[f] = (base, score, len(jals), len(b))
    else:
        res[f] = (None, 0, len(jals), len(b))

by_base = collections.defaultdict(list)
for f, v in res.items():
    by_base[v[0]].append((f,) + v[1:])
for base in sorted(by_base, key=lambda x: x or 0):
    items = by_base[base]
    mx = max(i[3] for i in items)
    print('%s  %3d arq  maior=%6x  fim=%s  ex: %s' % (
        '%08x' % base if base else '????????', len(items), mx,
        '%08x' % (base + mx) if base else '-',
        ', '.join('%s(%d/%d)' % (i[0], i[1], i[2]) for i in items[:5])))
