#include "WSTAG780.h"
#include "m2c.h"
#include "WSTAG780_auto.h"
#include "WSTAG780_data.h"

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A5EC0);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A605C);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A6130);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A61C8);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A635C);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A638C);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A6480);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A652C);

void func_800A6678(s32 arg0) {
    M2C_FIELD(func_80014504(func_800A652C, 0x60, 0), s32 *, 4) = arg0;
}

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A66B0);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A67A4);

void func_800A6914(void) {
    func_80014504(func_800A67A4, 0x60, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A6940);

void func_800A69D8(void) {
    func_80014504(func_800A6940, 0x50, 0x1C);
}

void func_800A6A04(void *arg0, void *arg1) {
    s32 temp_a3;
    s32 temp_s1;

    if (M2C_FIELD(arg0, s32 *, 0x58) != 0) {
        temp_a3 = ((s32 (*)()) *D_8004DC0C)() & 1;
        if (M2C_FIELD(arg1, s32 *, 0) == 0) {
            M2C_FIELD(arg1, s32 *, 0) = func_800A605C(0, 0, 0, temp_a3);
        }
        if (M2C_FIELD(arg1, s32 *, 0xC) == 0) {
            M2C_FIELD(arg1, s32 *, 0xC) = func_800A605C(1, 1, 0, 0);
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x5C) != 0) {
        temp_s1 = ((s32 (*)()) *D_8004DC0C)() & 1;
        if (M2C_FIELD(arg1, s32 *, 0) == 0) {
            M2C_FIELD(arg1, s32 *, 0) = func_800A605C(0, 0, 1, 0);
        }
        if (M2C_FIELD(arg1, s32 *, 0xC) == 0) {
            M2C_FIELD(arg1, s32 *, 0xC) = func_800A605C(0, 0, 1, 1);
        }
        if (M2C_FIELD(arg1, s32 *, 4) == 0) {
            M2C_FIELD(arg1, s32 *, 4) = func_800A605C(1, 0, 0, 0);
        }
        if (M2C_FIELD(arg1, s32 *, 8) == 0) {
            M2C_FIELD(arg1, s32 *, 8) = func_800A605C(0, 1, 0, temp_s1);
        }
    }
}

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A6B4C);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A6DC4);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A6F40);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A6F8C);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A6FBC);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A72B0);

void func_800A7450(void *arg0, s32 arg1) {
    if (arg1 == 0x322) {
        M2C_FIELD(arg0, s32 *, 0x50) = 2;
        M2C_FIELD(arg0, s32 *, 0x64) = 5;
        ((M2C_UNK (*)(M2C_UNK)) *D_80055C48)(0xA40006);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A749C);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A74CC);

void *func_800A75B0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A74CC, 0x54, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A9208)();
    return temp_v0;
}

void func_800A760C(void) {
    *D_8004B370 = 0;
}

void func_800A7618(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4066, 1);
}

void func_800A7644(void) {
    *D_8004B370 = 0x2D;
}

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A7654);
