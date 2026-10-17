"""Gera o C das funcoes pendentes que so chamam um construtor de objeto.

Uso: python3 -I tools/mkobj.py [alvo ...]

Forma: carrega a0..a3 com constantes/enderecos e chama func_800143DC ou
func_80014504 (eventualmente devolvendo o resultado). O C gerado e
`u8 *func_X(...) { return func_800143DC(F, n, w, l); }` (argumentos
constantes, enderecos ou parametros repassados); a funcao e
compilada e comparada, e as que batem vao para o results.json com status
'ok' (integre com tools/autodecomp.py <alvo> --apply).
"""
import json
import multiprocessing
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import autodecomp as ad  # noqa: E402
import cc_cmp  # noqa: E402
import fn as fnt  # noqa: E402
import propagate as pr  # noqa: E402
from proj import R, Target  # noqa: E402

CTORS = {'func_800143DC': 4, 'func_80014504': 3}


def parse(path):
    """Valores de a0..a3 no jal do construtor, ou None se a forma nao bate."""
    ins = []
    for ln in open(path):
        m = re.match(r'\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/\s*(\S+)\s*(.*)', ln)
        if m:
            ins.append((m.group(1), [a.strip() for a in m.group(2).split(',')] if m.group(2) else []))
    regs = {'$zero': '0', '$a0': 'arg0', '$a1': 'arg1', '$a2': 'arg2', '$a3': 'arg3'}
    ctor = None
    for k, (op, a) in enumerate(ins):
        if op == 'jal':
            if a[0] not in CTORS or ctor:
                return None
            ctor = a[0]
            # o delay slot ainda carrega um argumento
            if k + 1 < len(ins):
                op2, b = ins[k + 1]
                if not step(regs, op2, b):
                    return None
            break
        if op in ('addiu',) and a[0] == '$sp':
            continue
        if op == 'sw' and a[0] == '$ra':
            continue
        if op == 'sw' and a[1].endswith('($sp)'):
            continue
        if not step(regs, op, a):
            return None
    if not ctor:
        return None
    # depois da chamada: so gravacoes no objeto (v0) de constantes ou de
    # parametros guardados, e o epilogo
    post = []
    live = {r: v for r, v in regs.items() if r.startswith('$s')}
    live['$zero'] = '0'
    for op, a in ins[k + 2:]:
        if op in ('lw', 'nop', 'jr') or (op == 'addiu' and a[0] == '$sp'):
            continue
        if op == 'addiu' and a[1] == '$zero':
            live[a[0]] = str(int(a[2], 0))
            continue
        m = re.match(r'(-?0x[0-9A-Fa-f]+|\d+)\(\$v0\)$', a[1]) if op in ('sw', 'sh', 'sb') else None
        if m and a[0] in live:
            post.append((op, int(m.group(1), 0), live[a[0]]))
            continue
        return None
    n = CTORS[ctor]
    args = []
    for r in ('$a0', '$a1', '$a2', '$a3')[:n]:
        if r not in regs:
            return None
        args.append(regs[r])
    return ctor, args, post


def step(regs, op, a):
    if op == 'lui' and a[1].startswith('%hi('):
        regs[a[0]] = ('hi', a[1][4:-1])
        return True
    if op == 'addiu' and a[2].startswith('%lo('):
        if regs.get(a[1]) == ('hi', a[2][4:-1]):
            regs[a[0]] = a[2][4:-1]
            return True
        return False
    if op == 'addiu' and a[1] == '$zero':
        regs[a[0]] = str(int(a[2], 0))
        return True
    if op == 'ori' and a[1] == '$zero':
        regs[a[0]] = str(int(a[2], 0))
        return True
    if op in ('addu', 'or') and a[2] == '$zero' and a[1] in regs:
        regs[a[0]] = regs[a[1]]
        return True
    if op == 'nop':
        return True
    return False


def job(args):
    t, f = args
    T = Target(t)
    p = T.p(T.asm + '/' + f + '.s')
    r = parse(p)
    if not r:
        return t, f, None
    ctor, a, post = r
    used = [int(x[3:]) for x in a + [v for _, _, v in post] if x.startswith('arg')]
    params = ', '.join('s32 arg%d' % i for i in range(max(used) + 1)) if used else 'void'
    if post:
        ty = {'sw': 's32', 'sh': 's16', 'sb': 's8'}
        body = '    u8 *o = %s(%s);\n\n' % (ctor, ', '.join(a))
        body += ''.join('    *(%s *)(o + 0x%X) = %s;\n' % (ty[op], off, v)
                        for op, off, v in post)
        code = 'u8 *%s(%s) {\n%s    return o;\n}\n' % (f, params, body)
    else:
        code = 'u8 *%s(%s) {\n    return %s(%s);\n}\n' % (f, params, ctor, ', '.join(a))
    d = os.path.join(R, 'build/mkobj', t)
    os.makedirs(d, exist_ok=True)
    c, o = os.path.join(d, f + '.c'), os.path.join(d, f + '.o')
    open(c, 'w').write(fnt.tu(t, f, code))
    if os.path.exists(o):
        os.remove(o)
    rr = subprocess.run([os.path.join(R, 'tools/cc.sh'), c, o, str(T.G)],
                        capture_output=True, text=True, stdin=subprocess.DEVNULL)
    if rr.returncode or not os.path.exists(o):
        return t, f, None
    exe = open(T.p(T.bin), 'rb').read()
    try:
        diffs = cc_cmp.compare(o, exe, [f], T.vram, T.off)[f]
    except Exception:
        return t, f, None
    return t, f, code if diffs == [] else None


def main():
    ts = sys.argv[1:] or [x for x in pr.targets()]
    jobs = []
    for t in ts:
        T = Target(t)
        for f in ad.pending(t):
            p = T.p(T.asm + '/' + f + '.s')
            if os.path.exists(p) and os.path.getsize(p) < 3000:
                s = open(p).read()
                if 'func_800143DC' in s or 'func_80014504' in s:
                    jobs.append((t, f))
    print('%d candidatas' % len(jobs))
    ok = {}
    with multiprocessing.Pool(os.cpu_count()) as pool:
        for t, f, code in pool.imap_unordered(job, jobs):
            if code:
                ok.setdefault(t, {})[f] = code
    for t, fs in ok.items():
        p = os.path.join(R, 'build/autodecomp', t, 'results.json')
        os.makedirs(os.path.dirname(p), exist_ok=True)
        res = json.load(open(p)) if os.path.exists(p) else {}
        for f, code in fs.items():
            res[f] = {'status': 'ok', 'code': code, 'types': {}, 'variant': 0}
        json.dump(res, open(p, 'w'), indent=1)
    print('%d bateram em %d alvos' % (sum(len(v) for v in ok.values()), len(ok)))


if __name__ == '__main__':
    main()
