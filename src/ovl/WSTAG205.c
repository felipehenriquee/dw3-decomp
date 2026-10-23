#include "WSTAG205.h"
#include "m2c.h"
#include "WSTAG205_auto.h"
#include "WSTAG205_data.h"

INCLUDE_ASM("asm/ovl/WSTAG205/nonmatchings/WSTAG205", func_800A5DE4);

Obj *func_800A60B0(void) {
    return func_80014504(func_800A5DE4, 0xC8, 0);
}

void func_800A60DC(u8 *o, Obj **w) {
    u8 *f;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (D_8004B370[0] == 6) {
            f = (u8 *)&D_80048ABC;
            if ((*(s32 (**)(s32, s32))(f + 0x10))(0x4006, 1) != 0 && (*(s32 (**)(s32, s32))(f + 0x10))(0x4016, 0) != 0) {
                w[0] = func_800853F8(0x65);
            }
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A6194(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A60DC, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A79D0)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A61F0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4006, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

void func_800A623C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4016, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG205/nonmatchings/WSTAG205", func_800A6268);
