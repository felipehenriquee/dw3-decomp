#include "WSTAG750.h"
#include "m2c.h"
#include "WSTAG750_auto.h"
#include "WSTAG750_data.h"

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A5EB8);

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A5EF0);

void func_800A6170(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x335)) {
        M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(D_800A7258, s16 *, 0);
        M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(D_800A7258, s16 *, 2);
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A61C0);

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A61F0);

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A6424);

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A6480);

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A65A0);

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A6688);

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A674C);

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A69DC);

void func_800A6A38(void) {
    *D_8004B370 = 0x20;
}

void func_800A6A48(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4048, 1);
}

void func_800A6A74(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4047, 1);
}

void func_800A6AA0(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4062, 1);
}

void func_800A6ACC(void) {
    *D_8004B370 = 0x21;
}

void func_800A6ADC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x7C0A, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A6B08);
