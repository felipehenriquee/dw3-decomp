"""Decompilacao automatica: m2c -> gcc 2.8.1 -> compara com o original.

Uso:
  python3 -I tools/autodecomp.py <nome> [func_X ...]     testa
  python3 -I tools/autodecomp.py <nome> --apply          integra as que bateram

<nome>: main (EXE) ou um overlay. Usa src/<nome>.c, include/<nome>.h,
include/<nome>_auto.h (rode tools/gen_ctx.py antes) e
asm/nonmatchings/<nome>/. Resultados em build/autodecomp/<nome>/.

No --apply, as funcoes que bateram entram no .c no lugar do INCLUDE_ASM,
o _auto.h e regerado e o `make` confere o sha1. Se o make falhar, o lote
e dividido ao meio ate achar as funcoes que quebram (essas ficam de fora
e vao para failed.txt).
"""
import json
import multiprocessing
import os
import re
import shutil
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cc_cmp  # noqa: E402

R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
M2C = os.path.join(R, '.venv/bin/m2c')

# como cada alvo e carregado: (binario, vram, offset no arquivo, G)
TARGETS = {'main': ('disc/SLES_049.36', 0x80010000, 0x800, 8)}


def target(name):
    if name in TARGETS:
        return TARGETS[name]
    vram = 0x800A5DE0 if name.startswith('W') else 0x80082CB0
    return ('disc/PRO/%s.PRO' % name, vram, 0, 0)


# variantes de opcoes do m2c, tentadas em ordem
VARIANTS = [[], ['--void']]


def run(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, cwd=R, **kw)


def pending(name):
    src = open(os.path.join(R, 'src/%s.c' % name)).read()
    return re.findall(r'^INCLUDE_ASM\("[^"]+", (\w+)\);', src, re.M)


def make_ctx(name, work):
    """Contexto para o m2c: headers preprocessados."""
    os.makedirs(work, exist_ok=True)
    stub = os.path.join(work, 'ctx_in.c')
    with open(stub, 'w') as f:
        f.write('#include "%s.h"\n#include "m2c.h"\n#include "%s_auto.h"\n'
                % (name, name))
    out = run([os.path.join(R, 'tools/old-gcc/2.8.1/cpp'), '-P',
               '-I' + os.path.join(R, 'include'), '-DM2CTX', stub])
    ctx = os.path.join(work, 'ctx.h')
    open(ctx, 'w').write(out.stdout)
    return ctx


def rodata_files(name):
    d = os.path.join(R, 'asm/nonmatchings', name)
    return [os.path.join(d, f) for f in sorted(os.listdir(d))
            if not f.startswith('func_') and f.endswith('.s')]


def try_one(job):
    name, fn, ctx, work = job
    tgt = target(name)
    exe = open(os.path.join(R, tgt[0]), 'rb').read()
    d = os.path.join(work, fn)
    os.makedirs(d, exist_ok=True)
    # contexto sem a declaracao da propria funcao
    lines = [ln for ln in open(ctx).read().splitlines()
             if not re.search(r'\b%s\s*\(' % fn, ln)]
    fctx = os.path.join(d, 'ctx.h')
    open(fctx, 'w').write('\n'.join(lines) + '\n')
    auto = open(os.path.join(R, 'include/%s_auto.h' % name)).read()
    auto = '\n'.join(ln for ln in auto.splitlines()
                     if not re.search(r'\b%s\s*\(' % fn, ln)
                     and not ln.startswith('#'))
    asm = os.path.join(R, 'asm/nonmatchings', name, fn + '.s')
    best = None
    for vi, opts in enumerate(VARIANTS):
        r = run([M2C, '-t', 'mipsel-gcc-c', '--valid-syntax',
                 '--globals=none', '--context', fctx, '-f', fn] + opts +
                [asm] + rodata_files(name))
        if r.returncode != 0 or not r.stdout.strip():
            res = {'status': 'm2c', 'err': (r.stderr or r.stdout)[-400:]}
            best = best or res
            continue
        code = r.stdout
        c = os.path.join(d, 'v%d.c' % vi)
        with open(c, 'w') as f:
            f.write('#include "%s.h"\n#include "m2c.h"\n%s\n\n%s'
                    % (name, auto, code))
        o = os.path.join(d, 'v%d.o' % vi)
        cr = run([os.path.join(R, 'tools/cc.sh'), c, o, str(tgt[3])],
                 stdin=subprocess.DEVNULL)
        if cr.returncode != 0:
            res = {'status': 'cc', 'err': cr.stderr[-400:], 'code': code}
            if not best or best['status'] == 'm2c':
                best = res
            continue
        diffs = cc_cmp.compare(o, exe, [fn], tgt[1], tgt[2])[fn]
        if diffs is None:
            res = {'status': 'cc', 'err': 'funcao nao gerada', 'code': code}
        elif not diffs:
            return fn, {'status': 'ok', 'code': code, 'variant': vi}
        else:
            res = {'status': 'diff', 'ndiff': len(diffs), 'code': code}
        if (not best or best['status'] != 'diff' or
                res.get('ndiff', 1e9) < best.get('ndiff', 1e9)):
            best = res
    return fn, best


def test(name, funcs):
    work = os.path.join(R, 'build/autodecomp', name)
    ctx = make_ctx(name, work)
    jobs = [(name, fn, ctx, work) for fn in funcs]
    with multiprocessing.Pool(os.cpu_count()) as p:
        results = dict(p.imap_unordered(try_one, jobs))
    path = os.path.join(work, 'results.json')
    old = json.load(open(path)) if os.path.exists(path) else {}
    old.update(results)
    json.dump(old, open(path, 'w'), indent=1)
    st = {}
    for r in results.values():
        st[r['status']] = st.get(r['status'], 0) + 1
    print('%s: %d funcoes testadas: %s' % (name, len(results), st))
    near = sorted((r['ndiff'], f) for f, r in results.items()
                  if r['status'] == 'diff')
    print('mais perto:', ' '.join('%s(%d)' % (f, n) for n, f in near[:15]))
    return results


def make_ok():
    r = run(['make', '-j%d' % os.cpu_count()])
    return r.returncode == 0 and 'overlays' in r.stdout


def insert(name, codes):
    p = os.path.join(R, 'src/%s.c' % name)
    s = open(p).read()
    if '#include "m2c.h"' not in s:
        # antes do _auto.h: os prototipos gerados usam M2C_UNK
        s = s.replace('#include "%s_auto.h"\n' % name,
                      '#include "m2c.h"\n#include "%s_auto.h"\n' % name, 1)
    for fn, code in codes.items():
        line = 'INCLUDE_ASM("asm/nonmatchings/%s", %s);' % (name, fn)
        s = s.replace(line, code.strip(), 1)
    open(p, 'w').write(s)
    run([sys.executable, '-I', 'tools/gen_ctx.py', name,
         str(target(name)[3])])


def apply(name):
    work = os.path.join(R, 'build/autodecomp', name)
    res = json.load(open(os.path.join(work, 'results.json')))
    todo = {f: r['code'] for f, r in res.items()
            if r['status'] == 'ok' and f in pending(name)}
    src = os.path.join(R, 'src/%s.c' % name)
    auto = os.path.join(R, 'include/%s_auto.h' % name)
    good, bad = {}, []

    def attempt(batch):
        base_src, base_auto = open(src).read(), open(auto).read()
        insert(name, batch)
        if make_ok():
            good.update(batch)
            return
        open(src, 'w').write(base_src)
        open(auto, 'w').write(base_auto)
        if len(batch) == 1:
            bad.extend(batch)
            return
        items = sorted(batch.items())
        h = len(items) // 2
        attempt(dict(items[:h]))
        attempt(dict(items[h:]))

    if todo:
        attempt(todo)
    with open(os.path.join(work, 'failed.txt'), 'a') as f:
        for fn in bad:
            f.write(fn + '\n')
    print('%s: %d integradas, %d quebraram o make: %s' % (
        name, len(good), len(bad), ' '.join(bad)))


def main():
    name = sys.argv[1]
    if '--apply' in sys.argv:
        apply(name)
        return
    funcs = sys.argv[2:] or pending(name)
    test(name, funcs)


if __name__ == '__main__':
    main()
