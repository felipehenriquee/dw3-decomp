"""Revisao semantica: chamadas no C com menos argumentos do que o chamado
le (pela aridade estimada no asm, tools/arity.py).

Essas funcoes batem byte a byte (o argumento ja esta no registrador),
mas o C esta errado: no port para PC o chamado receberia lixo.

Uso: python3 -I tools/audit_args.py [alvo ...]
"""
import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import arity  # noqa: E402
from proj import R, Target  # noqa: E402


def calls(code):
    """(nome, nargs) de cada chamada direta a func_X/nome conhecido."""
    out = []
    for m in re.finditer(r'\b(\w+)\s*\(', code):
        name = m.group(1)
        i = m.end()
        depth, n, has = 1, 0, False
        while i < len(code) and depth:
            c = code[i]
            if c == '(':
                depth += 1
            elif c == ')':
                depth -= 1
            elif c == ',' and depth == 1:
                n += 1
            elif not c.isspace() and depth >= 1:
                has = True
            i += 1
        out.append((name, n + 1 if has else 0))
    return out


def functions(src):
    for m in re.finditer(r'^[^\n;{}#]*\b(func_[0-9A-F]{8})\(([^;{]*)\)\s*\{(.*?)^\}',
                         src, re.S | re.M):
        yield m.group(1), m.group(3)


def main():
    targets = sys.argv[1:] or ['main'] + sorted(
        os.path.basename(p)[:-2] for p in glob.glob(os.path.join(R, 'src/ovl/*.c')))
    total = 0
    for t in targets:
        T = Target(t)
        src = open(T.p(T.src)).read()
        ar = arity.arities(t)
        # aridade das funcoes ja definidas em C: o numero de parametros
        for fn, params in re.findall(r'^[^\n;{}#]*\b(func_[0-9A-F]{8})\(([^;{)]*)\)\s*\{',
                                     src, re.M):
            p = params.strip()
            ar.setdefault(fn, 0 if p in ('', 'void') else p.count(',') + 1)
        for fn, body in functions(src):
            bad = [(c, n, ar[c]) for c, n in calls(body)
                   if c in ar and ar[c] and n < ar[c]]
            for c, n, a in bad:
                total += 1
                print('%s %s: chama %s com %d arg(s), ele le %d' % (t, fn, c, n, a))
    print('%d chamadas suspeitas' % total)


if __name__ == '__main__':
    main()
