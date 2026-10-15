#!/bin/sh
# Roda o decomp-permuter em cada diretorio de build/perm/ (criados pelo
# tools/perm_setup.py), com tempo limite por funcao. As que chegam a
# pontuacao 0 ficam listadas em build/perm/zero.txt (revise o C antes de
# integrar: o permuter as vezes muda a semantica).
# Uso: tools/perm_batch.sh [segundos por funcao] [threads]
cd "$(dirname "$0")/.." || exit 1
T=${1:-300}
J=${2:-4}
for d in build/perm/func_*/; do
    f=$(basename "$d")
    ls "$d" | grep -q '^output-0-' && continue
    echo "== $f $(date +%T)"
    timeout "$T" .venv/bin/python tools/decomp-permuter/permuter.py \
        -j"$J" --stop-on-zero "$d" > "$d/perm.log" 2>&1
    if ls "$d" | grep -q '^output-0-'; then
        echo "$f" >> build/perm/zero.txt
        echo "   ZERO"
    else
        best=$(ls "$d" | grep '^output-' | sed 's/output-\([0-9]*\)-.*/\1/' | sort -n | head -1)
        echo "   melhor: ${best:-nenhum}"
    fi
done
echo "== fim $(date +%T)"
