#include "WSTAG206.h"
#include "m2c.h"
#include "WSTAG206_auto.h"
#include "WSTAG206_data.h"

INCLUDE_ASM("asm/ovl/WSTAG206/nonmatchings/WSTAG206", func_800A5DE4);

void *func_800A5EC0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A724C)();
    return temp_v0;
}

void func_800A5F1C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x7400, 1);
}

void func_800A5F48(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40CA, 1);
}

void func_800A5F74(void) {
    *D_8004B370 = 0x25;
}

INCLUDE_ASM("asm/ovl/WSTAG206/nonmatchings/WSTAG206", func_800A5F84);
