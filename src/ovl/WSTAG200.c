#include "WSTAG200.h"
#include "m2c.h"
#include "WSTAG200_auto.h"
#include "WSTAG200_data.h"

INCLUDE_ASM("asm/ovl/WSTAG200/nonmatchings/WSTAG200", func_800A5DE4);

void *func_800A5E7C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7FF0)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG200/nonmatchings/WSTAG200", func_800A5ED8);

void func_800A5F24(void) {
    *D_8004B370 = 4;
}

INCLUDE_ASM("asm/ovl/WSTAG200/nonmatchings/WSTAG200", func_800A5F34);
