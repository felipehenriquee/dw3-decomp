#include "WSTAG545.h"
#include "m2c.h"
#include "WSTAG545_auto.h"
#include "WSTAG545_data.h"

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A5E18);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A5F20);

void func_800A6054(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5F20, 0x64, 0);
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg2;
}

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A60AC);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A6184);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A6304);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A633C);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A636C);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A648C);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A6780);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A6894);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A68C4);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A6984);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A69E0);

void func_800A6A2C(void) {
    *D_8004B370 = 0x1B;
}

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A6A3C);
