#include "WSTAG756.h"
#include "m2c.h"
#include "WSTAG756_auto.h"
#include "WSTAG756_data.h"

INCLUDE_ASM("asm/ovl/WSTAG756/nonmatchings/WSTAG756", func_800A5DE4);

void *func_800A5EA0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6B50)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG756/nonmatchings/WSTAG756", func_800A5EFC);

void func_800A5F48(void) {
    *D_8004B370 = 0x24;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x8019, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG756/nonmatchings/WSTAG756", func_800A5F80);
