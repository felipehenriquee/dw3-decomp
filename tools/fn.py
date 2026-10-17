"""Ferramenta para decompilar uma funcao a mao.

Uso:
  python3 -I tools/fn.py <nome> <func> show            asm + rascunho do m2c
  python3 -I tools/fn.py <nome> <func> test <arq.c>    compila e compara
  python3 -I tools/fn.py <nome> <func> apply <arq.c>   integra e roda o make

<arq.c> tem a funcao e, se precisar, typedefs e declaracoes `extern` de
dados no topo. No apply, as typedefs vao para include/types.h, as
declaracoes de simbolos D_ para include/<nome>_data.h (substituindo a
anterior) e o resto entra em src/<nome>.c no lugar do INCLUDE_ASM. Se o
make nao bater, tudo volta como estava.
"""
import json
import os
import re
import struct
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import autodecomp as ad  # noqa: E402
import cc_cmp  # noqa: E402
from proj import Target, apply_lock  # noqa: E402

R = ad.R
SCRATCH = os.path.join(R, 'build/fn')


def split_types(code):
    """Separa as typedefs (com o comentario logo acima) do resto."""
    types = []
    pat = re.compile(r'(?:/\*(?:(?!\*/).)*\*/\s*\n)?typedef\b[^;{]*'
                     r'(?:\{(?:[^{}]|\{[^{}]*\})*\}[^;]*)?;\s*\n?', re.S)
    for m in pat.finditer(code):
        types.append(m.group().strip())
    return types, pat.sub('', code)


def split_decls(code):
    """Separa as declaracoes extern de dados D_ do resto do codigo."""
    decls, rest = {}, []
    for ln in code.splitlines():
        m = re.match(r'\s*extern\b[^;(]*\b(D_[0-9A-F]{8})\b[^;(]*;\s*$', ln)
        if m:
            decls[m.group(1)] = ln.strip()
        else:
            rest.append(ln)
    return decls, '\n'.join(rest).strip() + '\n'


def tu(name, fn, code):
    types, code = split_types(code)
    decls, body = split_decls(code)
    own = re.compile(r'\b%s\s*\(' % fn)
    T = Target(name)
    auto = [ln for ln in open(T.p(T.auto)).read().splitlines()
            if not own.search(ln) and not ln.startswith('#')]
    data = []
    p = T.p(T.data)
    if os.path.exists(p):
        for ln in open(p):
            m = re.match(r'extern\b[^;]*\b(D_[0-9A-F]{8})\b', ln)
            if m and m.group(1) not in decls:
                data.append(ln.rstrip())
    return ('#include "%s"\n#include "m2c.h"\n%s\n%s\nstruct opaque;\n'
            '%s\n%s\n\n%s'
            % (T.p(T.hdr), '\n\n'.join(types), '\n'.join(auto),
               '\n'.join(data),
               '\n'.join(decls.values()), body))


def disasm(words, vram):
    b = b''.join(struct.pack('<I', w) for w in words)
    p = os.path.join(SCRATCH, 'w.bin')
    open(p, 'wb').write(b)
    out = subprocess.run(['mips-linux-gnu-objdump', '-D', '-b', 'binary',
                          '-m', 'mips:3000', '-EL', '--adjust-vma=%d' % vram,
                          p], capture_output=True, text=True).stdout
    res = []
    for ln in out.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+[0-9a-f]{8}\s+(.*)', ln)
        if m:
            res.append(m.group(2).replace('\t', ' '))
    return res


def compare_show(name, fn, obj):
    tgt = ad.target(name)
    exe = open(os.path.join(R, tgt[0]), 'rb').read()
    syms = cc_cmp.symbols(obj)
    if fn not in syms:
        print('%s nao esta no .o' % fn)
        return False
    start, size = syms[fn]
    text = cc_cmp.text_bytes(obj)
    rel = cc_cmp.relocs(obj)
    addr = int(fn.split('_')[-1], 16)
    # tamanho original: ate o proximo glabel no .s
    asm = open(Target(name).p(Target(name).asm + '/' + fn + '.s')).read()
    body = re.search(r'glabel %s\b(.*?)endlabel %s\b' % (fn, fn), asm, re.S)
    osize = 4 * len(re.findall(r'^\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/',
                               body.group(1) if body else asm, re.M))
    n = max(size, osize) // 4
    cw = [struct.unpack_from('<I', text, start + 4 * i)[0] if 4 * i < size
          else 0 for i in range(n)]
    ow = [struct.unpack_from('<I', exe, addr - tgt[1] + tgt[2] + 4 * i)[0]
          if 4 * i < osize else 0 for i in range(n)]
    cd, od = disasm(cw, addr), disasm(ow, addr)
    ndiff = 0
    for i in range(n):
        m = ~rel.get(start + 4 * i, 0) & 0xFFFFFFFF
        same = (cw[i] & m) == (ow[i] & m) and 4 * i < size and 4 * i < osize
        ndiff += not same
        print('%s %03X  %-34s %s' % (' ' if same else '*', 4 * i,
                                     cd[i] if 4 * i < size and i < len(cd) else '',
                                     od[i] if 4 * i < osize and i < len(od) else ''))
    print('%s: %s (%d/%d diferentes; tamanho %d vs %d)' % (
        fn, 'OK' if ndiff == 0 else 'DIFERENTE', ndiff, n, size, osize))
    return ndiff == 0


def test(name, fn, path):
    os.makedirs(SCRATCH, exist_ok=True)
    c = os.path.join(SCRATCH, fn + '.c')
    o = os.path.join(SCRATCH, fn + '.o')
    open(c, "w").write(tu(name, fn, open(path).read()))
    if os.path.exists(o):
        os.remove(o)
    r = ad.run([os.path.join(R, 'tools/cc.sh'), c, o,
                str(ad.target(name)[3])], stdin=subprocess.DEVNULL)
    if r.returncode != 0 or not os.path.exists(o):
        print(r.stderr[-2000:])
        return False
    return compare_show(name, fn, o)


def apply(name, fn, path):
    if not test(name, fn, path):
        print('nao bate; nada foi alterado')
        return False
    types, code = split_types(open(path).read())
    decls, body = split_decls(code)
    T = Target(name)
    files = [T.p(T.src), T.p(T.auto), T.p(T.data), T.p('include/types.h')]
    saved = [open(f).read() for f in files]
    src = saved[0]
    line = T.include_line(fn)
    if line not in src:
        print('%s nao esta pendente em src/%s.c' % (fn, name))
        return False
    src = src.replace(line, body.strip(), 1)
    # rodata so desta funcao (strings, jump tables) que o C agora gera:
    # sai o INCLUDE_RODATA, senao ela entra duas vezes
    asm = open(T.p(T.asm + '/' + fn + '.s')).read()
    for sym in sorted(set(re.findall(r'\b((?:D|jtbl)_[0-9A-F]{8})\b', asm))):
        rl = re.search(r'^INCLUDE_RODATA\([^)]*\b%s\);\n\n?' % sym, src, re.M)
        if not rl or re.search(r'\b%s\b' % sym, body):
            continue
        others = subprocess.run(['grep', '-rlw', sym, T.p(T.asm)],
                                capture_output=True, text=True).stdout.split()
        if all(os.path.basename(o) in (fn + '.s', sym + '.s') for o in others):
            src = src.replace(rl.group(), '', 1)
    open(files[0], 'w').write(src)
    if types:
        # as typedefs vao para include/types.h (incluido por todos): os
        # prototipos gerados usam elas e o propagate.py leva o C a outros alvos
        h = saved[3]
        i = h.rindex('\n#endif')
        h = h[:i].rstrip() + '\n\n' + '\n\n'.join(types) + '\n' + h[i:]
        open(files[3], 'w').write(h)
    if decls:
        data = saved[2]
        for sym, d in decls.items():
            d = d if d.startswith('extern') else 'extern ' + d
            if re.search(r'\b%s\b' % sym, data):
                data = re.sub(r'^.*\b%s\b.*$' % sym, d, data, flags=re.M)
            else:
                data = data.replace('\n\n#endif', '\n%s\n\n#endif' % d, 1)
        open(files[2], 'w').write(data)
    ad.run([sys.executable, '-I', 'tools/gen_ctx.py', name])
    if ad.make_ok():
        print('integrada; make OK')
        return True
    for f, c in zip(files, saved):
        open(f, 'w').write(c)
    r = ad.run(['make', '-j%d' % os.cpu_count()])
    print('make falhou; revertido.\n' + (r.stdout + r.stderr)[-1500:])
    return False


def show(name, fn):
    asm = open(Target(name).p(Target(name).asm + '/' + fn + '.s')).read()
    for ln in asm.splitlines():
        m = re.match(r'\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s*(.*)',
                     ln)
        if m:
            print('  %s  %s' % (m.group(1)[-4:], m.group(2)))
        elif ln.strip() and not ln.startswith(('nonmatching', '.')):
            print(ln)
    p = os.path.join(R, 'build/autodecomp', name, 'results.json')
    if os.path.exists(p):
        r = json.load(open(p)).get(fn)
        if r and r.get('code'):
            print('\n/* m2c (%s%s) tipos: %s */' % (
                r['status'], ', %d dif' % r['ndiff'] if 'ndiff' in r else '',
                r.get('types')))
            print(r['code'])


def main():
    name, fn, cmd = sys.argv[1:4]
    if name != 'main':
        Target(name).ensure_files()
    if cmd == 'show':
        show(name, fn)
    elif cmd == 'test':
        sys.exit(0 if test(name, fn, sys.argv[4]) else 1)
    elif cmd == 'apply':
        with apply_lock():
            ok = apply(name, fn, sys.argv[4])
        sys.exit(0 if ok else 1)


if __name__ == '__main__':
    main()
