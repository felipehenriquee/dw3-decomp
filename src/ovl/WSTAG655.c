#include "WSTAG655.h"
#include "m2c.h"
#include "WSTAG655_auto.h"
#include "WSTAG655_data.h"

void func_800A5DE0(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (D_8004B370[0] == 16
            && (*(s32 (**)(s32, s32))((u8 *)&D_80048ABC + 0x10))(0x403E, 1) != 0) {
            w[0] = func_800853F8(0x1AF);
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5E74(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6734)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5ED0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x403E, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

void func_800A5F1C(void) {
    *D_8004B370 = 0x11;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x800B, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG655/nonmatchings/WSTAG655", func_800A5F54);
