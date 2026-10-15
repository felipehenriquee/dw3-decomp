"""Gera include/<nome>_auto.h: uma declaracao para cada simbolo usado pelo
codigo de um .c que ainda nao foi declarado a mao.

Uso: python3 -I tools/gen_ctx.py <nome> [G]
  <nome>: main (src/main.c, asm/nonmatchings/main) ou um overlay
  G: limite de small data (8 no EXE, 0 nos overlays)

Regras:
- funcoes definidas no .c: o prototipo vem da definicao;
- outras funcoes: `s32 nome();` (estilo antigo, aceita qualquer argumento);
- dados acessados via $gp no original: escalar do tamanho do acesso (ou
  array de ate G bytes), para o gcc tambem usar $gp;
- outros dados ficam em include/<nome>_data.h, mantido pelo
  tools/autodecomp.py (o tipo vem da primeira funcao integrada que usa).
Simbolos ja declarados em include/<nome>.h, include/<nome>_data.h ou no
proprio .c sao pulados.
"""
import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from proj import Target  # noqa: E402

name = sys.argv[1]
T = Target(name)
G = int(sys.argv[2]) if len(sys.argv) > 2 else T.G
os.chdir(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC, MANUAL, OUT, ASM = T.src, T.hdr, T.auto, T.asm

ident = r'[A-Za-z_][A-Za-z0-9_]*'


def strip_comments(s):
    s = re.sub(r'/\*.*?\*/', ' ', s, flags=re.S)
    return re.sub(r'//[^\n]*', ' ', s)


src = strip_comments(open(SRC).read()) if os.path.exists(SRC) else ''
manual = ''
for p in (MANUAL, T.data):
    if os.path.exists(p):
        manual += strip_comments(open(p).read())

# prototipos das funcoes definidas no .c
defs = {}
for m in re.finditer(r'^(%s[\s\*]+(%s)\s*\([^;{]*\))\s*\{' % (r'[A-Za-z_][\w\s\*]*?', ident),
                     src, re.M):
    sig, fn = m.group(1), m.group(2)
    if fn in ('if', 'while', 'for', 'switch'):
        continue
    defs[fn] = ' '.join(sig.split()) + ';'

# identificadores declarados a mao (main.h e topo do .c)
declared = set(re.findall(r'\b(%s)\s*(?:\[[^\]]*\])?\s*[;(,=]' % ident, manual))
declared |= set(re.findall(r'\bextern\b[^;]*?\b(%s)\s*(?:\[[^\]]*\])?\s*;' % ident, src))

funcs, datas, gp_acc, local = set(), set(), {}, set()
for f in sorted(glob.glob(os.path.join(ASM, '*.s'))):
    txt = open(f).read()
    local |= set(re.findall(r'^\s*(?:glabel|dlabel|jlabel)\s+(%s)' % ident, txt, re.M))
    for m in re.finditer(r'\bjal\s+(%s)' % ident, txt):
        funcs.add(m.group(1))
    for m in re.finditer(r'%%(?:hi|lo)\((%s)' % ident, txt):
        s = m.group(1)
        (funcs if s.startswith('func_') else datas).add(s)
    for m in re.finditer(r'\b(\w+)\s+\$\w+,\s*(?:\$gp,\s*)?%%gp_rel\((%s)\)' % ident, txt):
        gp_acc.setdefault(m.group(2), set()).add(m.group(1))

# declaracoes do _auto.h anterior para simbolos que o C usa mas cujo asm
# ja sumiu (funcao decompilada): mantidas como estavam
prev_lines = {}
if os.path.exists(OUT):
    for ln in open(OUT):
        m = re.match(r'(?:extern )?[\w ]+?\**\s*\b(%s)\s*[\[(;]' % ident, ln)
        if m and not ln.startswith(('/*', '#')):
            prev_lines[m.group(1)] = ln.rstrip()
used_in_c = set(re.findall(ident, src))
for sym, ln in prev_lines.items():
    if sym not in used_in_c or sym in funcs or sym in gp_acc or sym in defs:
        continue
    if 'gp' in ln or re.match(r'extern (s32|s16|u16|s8|u8) \w+(\[\d+\])?;$', ln):
        gp_acc[sym] = {'keep': ln}
    elif ln.startswith('s32 ') and ln.endswith('();'):
        funcs.add(sym)

datas -= set(gp_acc)
skip = declared | set(defs)
WIDTH = {'lw': 's32', 'sw': 's32', 'lh': 's16', 'lhu': 'u16', 'sh': 's16',
         'lb': 's8', 'lbu': 'u8', 'sb': 'u8'}

out = ['/* Gerado por tools/gen_ctx.py %s: nao edite. Declare a mao em %s */'
       % (name, MANUAL), '#ifndef %s_AUTO_H' % name.upper(),
       '#define %s_AUTO_H' % name.upper(), '']

out.append('/* funcoes ja decompiladas */')
out += [defs[f] for f in sorted(defs) if f not in declared]
out += ['', '/* funcoes ainda em assembly (prototipo desconhecido) */']
out += ['s32 %s();' % f for f in sorted(funcs - skip - local)
        if f not in defs]
out += ['', '/* dados acessados via $gp */']
gp_syms = sorted(gp_acc)
for s in gp_syms:
    if s in skip:
        continue
    ops = gp_acc[s]
    if isinstance(ops, dict):
        out.append(ops['keep'])
        continue
    types = {WIDTH[o] for o in ops if o in WIDTH}
    if len(types) == 1 and 'addiu' not in ops:
        out.append('extern %s %s;' % (types.pop(), s))
    else:
        out.append('extern u8 %s[%d];' % (s, max(1, G)))
out += ['', '#endif', '']
open(OUT, 'w').write('\n'.join(out))
print('%s: %d funcoes decompiladas, %d funcoes, %d dados gp' % (
    OUT, len(defs), len(funcs - skip - local), len(gp_syms)))
