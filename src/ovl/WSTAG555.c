#include "WSTAG555.h"
#include "m2c.h"
#include "WSTAG555_auto.h"
#include "WSTAG555_data.h"

INCLUDE_ASM("asm/ovl/WSTAG555/nonmatchings/WSTAG555", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG555/nonmatchings/WSTAG555", func_800A5ED4);

void func_800A6040(void) {
    func_80014504(func_800A5ED4, 0x5C, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG555/nonmatchings/WSTAG555", func_800A606C);

void *func_800A60D0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A606C, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A69C0)();
    return temp_v0;
}

void func_800A612C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x400C, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG555/nonmatchings/WSTAG555", func_800A6158);
