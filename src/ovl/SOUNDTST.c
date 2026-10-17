#include "SOUNDTST.h"
#include "m2c.h"
#include "SOUNDTST_auto.h"
#include "SOUNDTST_data.h"

INCLUDE_ASM("asm/ovl/SOUNDTST/nonmatchings/SOUNDTST", func_80084370);

Obj *func_80084410(void) {
    return func_80014504(func_80084370, 0x50, 4);
}

/* move o cursor *cur por d dentro de [0, n) e rola a janela *top de 8 linhas */
void func_8008443C(s32 unused, s32 d, s32 *cur, s32 *top, s32 n) {
    s32 v = *cur + d;

    if (v >= 0 && v < n) {
        *cur = v;
        if (v >= *top + 8) {
            *top = v - 7;
        }
        if (*top > *cur) {
            *top = *cur;
        }
    }
}

INCLUDE_ASM("asm/ovl/SOUNDTST/nonmatchings/SOUNDTST", func_800844A8);

INCLUDE_ASM("asm/ovl/SOUNDTST/nonmatchings/SOUNDTST", func_80084808);

INCLUDE_RODATA("asm/ovl/SOUNDTST/nonmatchings/SOUNDTST", D_80082CB0);

INCLUDE_ASM("asm/ovl/SOUNDTST/nonmatchings/SOUNDTST", func_800848BC);

INCLUDE_ASM("asm/ovl/SOUNDTST/nonmatchings/SOUNDTST", func_80084B2C);

Obj *func_80084D48(void) {
    return func_80014504(func_80084B2C, 0x74, 0x2C);
}
