#include "WSTAG675.h"
#include "m2c.h"
#include "WSTAG675_auto.h"
#include "WSTAG675_data.h"

INCLUDE_ASM("asm/ovl/WSTAG675/nonmatchings/WSTAG675", func_800A5DE0);

void *func_800A5E74(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A748C)();
    return temp_v0;
}

void func_800A5ED0(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4017, 1);
}

void func_800A5EFC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x401A, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG675/nonmatchings/WSTAG675", func_800A5F28);

INCLUDE_ASM("asm/ovl/WSTAG675/nonmatchings/WSTAG675", func_800A5F88);
