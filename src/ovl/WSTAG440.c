#include "WSTAG440.h"
#include "m2c.h"
#include "WSTAG440_auto.h"
#include "WSTAG440_data.h"

void func_800A5DE4(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        if (D_8004B370[0] == 6) {
            w[0] = func_800853F8(0x98);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5E50(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6D54)();
    return temp_v0;
}

void func_800A5EAC(void) {
    *D_8004B370 = 7;
}

INCLUDE_ASM("asm/ovl/WSTAG440/nonmatchings/WSTAG440", func_800A5EBC);
