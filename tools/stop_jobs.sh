#!/bin/sh
# Para o autodecomp_all/autodecomp/permuter em segundo plano sem deixar
# integracao pela metade: espera a trava de integracao (proj.apply_lock)
# e mata os processos enquanto a segura.
cd "$(dirname "$0")/.." || exit 1
mkdir -p build
flock build/.apply.lock sh -c '
    for p in autodecomp_all autodecomp_reps autodecomp.py perm_batch permuter.py propagate.py; do
        pkill -f "tools/[a-z_-]*$p" 2>/dev/null
        pkill -f "decomp-permuter/$p" 2>/dev/null
    done
    sleep 1
'
ps aux | grep -E "tools/(autodecomp|perm)" | grep -v grep | wc -l
