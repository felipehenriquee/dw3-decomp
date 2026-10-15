#!/bin/sh
# Compila um .c como o jogo: GCC 2.8.1 (PsyQ) + maspsx + GNU as.
# Uso: tools/cc.sh <in.c> <out.o> [G]
#   G: 8 para o EXE (usa $gp), 0 para os overlays. Padrao: 8.
# Variaveis: GCC (versao em tools/old-gcc, padrao 2.8.1),
#            ASPSX (padrao 2.86).
set -e
R=$(cd "$(dirname "$0")/.." && pwd)
G=${3:-8}
GCC=${GCC:-2.8.1}
ASPSX=${ASPSX:-2.86}
S=${2%.o}.s
"$R/tools/old-gcc/$GCC/cpp" -P -I"$R/include" -DINCLUDE_ASM_USE_MACRO_INC=1 "$1" \
    | "$R/tools/old-gcc/$GCC/cc1" -quiet -O2 -G"$G" -funsigned-char \
        -fpeephole -ffunction-cse -fpcc-struct-return -fcommon \
        -msoft-float -mgas -fgnu-linker -w > "$S"
"$R/.venv/bin/python" "$R/tools/maspsx/maspsx.py" --aspsx-version="$ASPSX" \
    --run-assembler --dont-force-G0 --gnu-as-path=mips-linux-gnu-as \
    -EL -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G"$G" -I"$R/include" \
    -o "$2" < "$S"
