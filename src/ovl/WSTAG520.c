#include "WSTAG520.h"
#include "m2c.h"
#include "WSTAG520_auto.h"
#include "WSTAG520_data.h"

void func_800A5DE0(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (D_8004B370[0] == 10
            && (*(s32 (**)(s32, s32))((u8 *)&D_80048ABC + 0x10))(0x4002, 1) != 0) {
            w[0] = func_800853F8(0x105);
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
    ((M2C_UNK (*)()) *D_800A7080)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5ED0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4002, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

void func_800A5F1C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x800A, 1);
    *D_8004B370 = 0xB;
}

void func_800A5F50(void) {
    *D_8004B370 = 0x1A;
}

INCLUDE_ASM("asm/ovl/WSTAG520/nonmatchings/WSTAG520", func_800A5F60);
