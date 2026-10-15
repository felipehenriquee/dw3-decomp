#!/bin/sh
# Roda o tools/autodecomp.py (teste + integracao) em todos os overlays com
# funcoes pendentes. Uso: tools/autodecomp_all.sh [overlay ...]
cd "$(dirname "$0")/.." || exit 1
list=${*:-$(ls src/ovl | sed 's/\.c$//')}
for n in $list; do
    grep -q '^INCLUDE_ASM' "src/ovl/$n.c" || continue
    echo "== $n $(date +%T)"
    python3 -I tools/autodecomp.py "$n" | tail -1
    python3 -I tools/autodecomp.py "$n" --apply | tail -1
done
echo "== fim $(date +%T)"
