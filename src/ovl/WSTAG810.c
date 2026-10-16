#include "WSTAG810.h"
#include "m2c.h"
#include "WSTAG810_auto.h"
#include "WSTAG810_data.h"

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A5F00);

void func_800A6178(void *arg0, s32 arg1) {
    if (arg1 == 0x35B) {
        M2C_FIELD(arg0, s8 *, 0x50) = 1;
        M2C_FIELD(arg0, s16 *, 0x58) = 0;
        M2C_FIELD(arg0, s16 *, 0x5A) = (s16) *D_800A719E;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A61C4);

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A6200);

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A623C);

void func_800A6278(s16 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5F00, 0x68, 0);
    M2C_FIELD(temp_v0, s16 *, 0x52) = arg0;
    M2C_FIELD(temp_v0, s8 *, 0x51) = 1;
}

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A62B8);

void *func_800A6418(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A62B8, 0x54, 0x104);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7FD4)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A6474);

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A6594);

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A667C);

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A6740);

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A69D0);

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A6A2C);

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A6A90);

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A6AF8);

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A6B44);

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A6B90);

void func_800A6BDC(void) {
    *D_8004B370 = 0x29;
}

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A6BEC);
