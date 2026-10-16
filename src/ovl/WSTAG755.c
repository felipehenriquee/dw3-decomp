#include "WSTAG755.h"
#include "m2c.h"
#include "WSTAG755_auto.h"
#include "WSTAG755_data.h"

INCLUDE_ASM("asm/ovl/WSTAG755/nonmatchings/WSTAG755", func_800A5DE4);

void *func_800A5E6C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6A6C)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG755/nonmatchings/WSTAG755", func_800A5EC8);

void func_800A5F14(void) {
    *D_8004B370 = 0x1F;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x800C, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG755/nonmatchings/WSTAG755", func_800A5F4C);
