#include "WSTAG615.h"
#include "m2c.h"
#include "WSTAG615_auto.h"
#include "WSTAG615_data.h"

void func_800A5DE4(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (D_8004B370[0] == 18
            && (*(s32 (**)(s32, s32))((u8 *)&D_80048ABC + 0x10))(0x4039, 1) != 0) {
            w[0] = func_800853F8(0x213);
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5E78(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7468)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5ED4(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4039, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

void func_800A5F20(void) {
    *D_8004B370 = 0x13;
}

INCLUDE_ASM("asm/ovl/WSTAG615/nonmatchings/WSTAG615", func_800A5F30);
