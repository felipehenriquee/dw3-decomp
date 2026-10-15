import struct, os, sys

# Valida uma base: dos jal cujo alvo cai dentro do próprio overlay,
# quantos acertam um prólogo de função?
root = sys.argv[1]
p = os.path.join(root, 'AAA', 'PRO')
exe = open(os.path.join(root, 'SLES_049.36'), 'rb').read()[0x800:]
EB = 0x80010000

def stats(f, base):
    b = open(os.path.join(p, f), 'rb').read()
    w = struct.unpack_from('<%dI' % (len(b) // 4), b)
    prolog = {base + i * 4 for i, x in enumerate(w) if (x & 0xFFFF8000) == 0x27BD8000}
    jals = [0x80000000 | ((x & 0x03FFFFFF) << 2) for x in w if (x >> 26) == 3]
    inside = [t for t in jals if base <= t < base + len(b)]
    hit = sum(t in prolog for t in inside)
    lower = [t for t in jals if t < base]
    above = [t for t in jals if t >= base + len(b)]
    return len(jals), len(inside), hit, len(lower), len(above)

tier1 = [f for f in sorted(os.listdir(p)) if not f.startswith('W')]
tier2 = [f for f in sorted(os.listdir(p)) if f.startswith('W')]
for name, files, base in [('nivel1', tier1, 0x80082CB0), ('nivel2', tier2, 0x800A5DE0)]:
    tot = [0] * 5
    bad = []
    for f in files:
        s = stats(f, base)
        tot = [a + b for a, b in zip(tot, s)]
        if s[1] and s[2] < s[1]:
            bad.append((f, s))
    print(name, '%08x' % base, 'arqs=%d jal=%d dentro=%d acertos=%d abaixo=%d acima=%d' % ((len(files),) + tuple(tot)))
    print('  divergentes:', bad[:8])
    print('  arquivos:', files if name == 'nivel1' else '%d WSTAG/WFIGHT' % len(files))

# o que o EXE tem a partir de 0x800A5DE0?
o = 0x800A5DE0 - EB
print('EXE @800a5de0:', exe[o:o + 32].hex())
nz = next((i for i in range(o, len(exe)) if exe[i]), None)
print('EXE text end %08x' % (EB + len(exe)))
