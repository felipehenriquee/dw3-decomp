#include "SOUNDTST.h"
#include "m2c.h"
#include "SOUNDTST_auto.h"
#include "SOUNDTST_data.h"

void func_80084370(u8 *o, Obj **w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        w[0] = func_80084D48();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        if (((s32 (*)(s32))D_8004BBC4[0])(0) & 8) {
            ((void (*)(s32, s32))D_8004B440[0])(0x1500, 0);
            (*(void (**)(u8 *))(o + 0x38))(o);
        }
        break;
    case 2:
    case 3:
        break;
    }
}

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
