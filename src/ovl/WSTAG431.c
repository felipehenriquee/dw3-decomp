#include "WSTAG431.h"
#include "m2c.h"
#include "WSTAG431_auto.h"
#include "WSTAG431_data.h"

void func_800A5DE0(void *arg0) {
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

void *func_800A5E28(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A68B4)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG431/nonmatchings/WSTAG431", func_800A5E84);
