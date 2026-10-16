#include "WSTAG955.h"
#include "m2c.h"
#include "WSTAG955_auto.h"
#include "WSTAG955_data.h"

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
    ((M2C_UNK (*)()) *D_800A620C)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG955/nonmatchings/WSTAG955", func_800A5E88);
