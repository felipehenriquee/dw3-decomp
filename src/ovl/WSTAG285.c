#include "WSTAG285.h"
#include "m2c.h"
#include "WSTAG285_auto.h"
#include "WSTAG285_data.h"

INCLUDE_ASM("asm/ovl/WSTAG285/nonmatchings/WSTAG285", func_800A5DE0);

void *func_800A5EAC(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6CE4)();
    return temp_v0;
}

void func_800A5F08(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4005, 0);
}

void func_800A5F34(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x1C0C, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG285/nonmatchings/WSTAG285", func_800A5F60);
