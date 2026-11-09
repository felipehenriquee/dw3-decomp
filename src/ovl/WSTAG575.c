#include "WSTAG575.h"
#include "m2c.h"
#include "WSTAG575_auto.h"
#include "WSTAG575_data.h"

void func_800A5DE0(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (D_8004B370[0] == 0x10 && ((s32 (*)(s32, s32))D_80048ACC[0])(0x40A2, 0)) {
            w[0] = func_800853F8(0x1A6);
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
    ((M2C_UNK (*)()) *D_800A67DC)();
    return temp_v0;
}

void func_800A5ED0(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40A2, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG575/nonmatchings/WSTAG575", func_800A5EFC);
