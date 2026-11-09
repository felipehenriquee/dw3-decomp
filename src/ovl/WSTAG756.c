#include "WSTAG756.h"
#include "m2c.h"
#include "WSTAG756_auto.h"
#include "WSTAG756_data.h"

void func_800A5DE4(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        if (D_8004B370[0] == 0xD && ((s32 (*)(s32, s32))D_80048ACC[0])(0x1C0D, 1)) {
            w[0] = func_800853F8(0x160);
        } else if (D_8004B370[0] == 0x23 && ((s32 (*)(s32, s32))D_80048ACC[0])(0x405B, 1)) {
            w[0] = func_800853F8(0x38F);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5EA0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6B50)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5EFC(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x405B, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

void func_800A5F48(void) {
    *D_8004B370 = 0x24;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x8019, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG756/nonmatchings/WSTAG756", func_800A5F80);
