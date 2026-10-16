#include "WSTAG526.h"
#include "m2c.h"
#include "WSTAG526_auto.h"
#include "WSTAG526_data.h"

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A5DE0);

void func_800A5FF0(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x34B)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6028);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6058);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6178);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6364);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6380);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A63B0);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A63DC);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A64FC);

void func_800A67A4(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s16 *, 0x52) = 0x5A;
    }
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A67C0);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A67F0);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A681C);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A693C);

void func_800A6AF4(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s16 *, 0x52) = 0x28;
    }
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6B10);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6B40);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6B6C);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6C8C);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6CC8);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6E38);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6FB4);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A734C);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A7368);

void func_800A7398(s8 arg0, s8 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6FB4, 0x88, 0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg2;
    M2C_FIELD(temp_v0, s8 *, 0x53) = arg1;
    M2C_FIELD(temp_v0, s8 *, 0x52) = arg0;
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A73F0);

void *func_800A7460(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A73F0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7F94)();
    return temp_v0;
}

void func_800A74BC(void) {
    *D_8004B370 = 0x1E;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x8011, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A74F4);
