#include "WSTAG676.h"
#include "m2c.h"
#include "WSTAG676_auto.h"
#include "WSTAG676_data.h"

void func_800A5DE0(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        if (D_8004B370[0] == 0x22 && ((s32 (*)(s32, s32))D_80048ACC[0])(0x405A, 1)) {
            w[0] = func_800853F8(0x385);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5E68(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6AD4)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5EC4(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x405A, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

void func_800A5F10(void) {
    *D_8004B370 = 0x23;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x8018, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG676/nonmatchings/WSTAG676", func_800A5F48);
