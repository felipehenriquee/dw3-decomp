#include "WSTAG219.h"
#include "m2c.h"
#include "WSTAG219_auto.h"
#include "WSTAG219_data.h"

INCLUDE_ASM("asm/ovl/WSTAG219/nonmatchings/WSTAG219", func_800A5DE4);

void *func_800A5E2C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A64A8)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG219/nonmatchings/WSTAG219", func_800A5E88);
