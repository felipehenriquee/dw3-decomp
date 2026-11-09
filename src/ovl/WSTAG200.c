#include "WSTAG200.h"
#include "m2c.h"
#include "WSTAG200_auto.h"
#include "WSTAG200_data.h"

void func_800A5DE4(u8 *o, s32 *w) {
    s32 a;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (D_8004B370[0] == 3) {
            a = ((s32 (*)(s32, s32))D_80048ACC[0])(0x400D, 0) ? 0x32 : 0x34;
            w[0] = func_800853F8(a);
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5E7C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7FF0)();
    return temp_v0;
}

void func_800A5ED8(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x400D, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7401, 1);
}

void func_800A5F24(void) {
    *D_8004B370 = 4;
}

INCLUDE_ASM("asm/ovl/WSTAG200/nonmatchings/WSTAG200", func_800A5F34);
