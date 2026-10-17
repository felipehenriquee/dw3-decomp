"""Testa permutacoes da ordem de instrucoes simples de uma funcao.

Uso: python3 -I tools/stmtperm.py <alvo> <func> <arq.c> [max]

Pega o maior bloco de linhas consecutivas que sao instrucoes simples
(terminam em ';', sem chaves, mesmo recuo) dentro da funcao e testa as
permutacoes (ate max linhas, padrao 7), compilando e comparando como o
tools/fn.py test. Grava a primeira que bate em <arq.c>.ok.
"""
import itertools
import multiprocessing
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import autodecomp as ad  # noqa: E402
import cc_cmp  # noqa: E402
import fn as fnt  # noqa: E402
from proj import R, Target  # noqa: E402


def blocks(lines):
    best, cur = None, []
    for i, ln in enumerate(lines):
        simple = (ln.rstrip().endswith(';') and '{' not in ln and '}' not in ln
                  and not ln.lstrip().startswith(('return', 'extern', 'typedef'))
                  and re.match(r'\s+\S', ln) and '=' in ln)
        if simple and cur and re.match(r'\s*', ln).group() != re.match(r'\s*', lines[cur[-1]]).group():
            simple = False
        if simple:
            cur.append(i)
            if best is None or len(cur) > len(best):
                best = list(cur)
        else:
            cur = []
    return best or []


def test(args):
    t, f, text = args
    T = Target(t)
    d = os.path.join(R, 'build/stmtperm', t)
    os.makedirs(d, exist_ok=True)
    c = os.path.join(d, '%s_%d.c' % (f, os.getpid()))
    o = c[:-2] + '.o'
    open(c, 'w').write(fnt.tu(t, f, text))
    if os.path.exists(o):
        os.remove(o)
    r = subprocess.run([os.path.join(R, 'tools/cc.sh'), c, o, str(T.G)],
                       capture_output=True, text=True, stdin=subprocess.DEVNULL)
    if r.returncode or not os.path.exists(o):
        return None
    exe = open(T.p(T.bin), 'rb').read()
    try:
        return text if cc_cmp.compare(o, exe, [f], T.vram, T.off)[f] == [] else None
    except Exception:
        return None


def main():
    t, f, path = sys.argv[1:4]
    mx = int(sys.argv[4]) if len(sys.argv) > 4 else 7
    src = open(path).read()
    lines = src.split('\n')
    start = next(i for i, ln in enumerate(lines) if re.search(r'\b%s\(' % f, ln) and '{' in ln)
    blk = [i for i in blocks(lines[start:]) ][:mx]
    blk = [i + start for i in blk]
    print('%d linhas no bloco' % len(blk))
    jobs = []
    for p in itertools.permutations(blk):
        if list(p) == blk:
            continue
        new = list(lines)
        for dst, sr in zip(blk, p):
            new[dst] = lines[sr]
        jobs.append((t, f, '\n'.join(new)))
    with multiprocessing.Pool(os.cpu_count()) as pool:
        for res in pool.imap_unordered(test, jobs, chunksize=4):
            if res:
                open(path + '.ok', 'w').write(res)
                print('OK -> %s.ok' % path)
                pool.terminate()
                return
    print('nenhuma permutacao bate')


if __name__ == '__main__':
    main()
