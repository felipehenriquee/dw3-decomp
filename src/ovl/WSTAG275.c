#include "WSTAG275.h"
#include "m2c.h"
#include "WSTAG275_auto.h"
#include "WSTAG275_data.h"

void func_800A5DE4(void *arg0) {
    switch (M2C_FIELD(arg0, s32 *, 0xC)) {
    case 0:
    default:
        M2C_FIELD(arg0, void (**)(void *), 0x38)(arg0);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5E2C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6180)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG275/nonmatchings/WSTAG275", func_800A5E88);
