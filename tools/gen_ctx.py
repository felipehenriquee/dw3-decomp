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
- outros dados: `extern u8 nome[];` (tamanho desconhecido: o gcc nunca
  usa $gp para eles).
Simbolos ja declarados em include/<nome>.h ou no proprio .c sao pulados.
"""
import glob
import os
import re
import sys

name = sys.argv[1]
G = int(sys.argv[2]) if len(sys.argv) > 2 else 8
SRC = 'src/%s.c' % name
MANUAL = 'include/%s.h' % name
OUT = 'include/%s_auto.h' % name
ASM = 'asm/nonmatchings/%s' % name

ident = r'[A-Za-z_][A-Za-z0-9_]*'


def strip_comments(s):
    s = re.sub(r'/\*.*?\*/', ' ', s, flags=re.S)
    return re.sub(r'//[^\n]*', ' ', s)


src = strip_comments(open(SRC).read()) if os.path.exists(SRC) else ''
manual = strip_comments(open(MANUAL).read()) if os.path.exists(MANUAL) else ''

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
    types = {WIDTH[o] for o in ops if o in WIDTH}
    if len(types) == 1 and 'addiu' not in ops:
        out.append('extern %s %s;' % (types.pop(), s))
    else:
        out.append('extern u8 %s[%d];' % (s, max(1, G)))
out += ['', '/* outros dados (tamanho desconhecido, nunca via $gp) */']
out += ['extern u8 %s[];' % s for s in sorted(datas - skip - local)]
out += ['', '#endif', '']
open(OUT, 'w').write('\n'.join(out))
print('%s: %d funcoes decompiladas, %d funcoes, %d dados gp, %d dados' % (
    OUT, len(defs), len(funcs - skip - local), len(gp_syms),
    len(datas - skip - local)))
