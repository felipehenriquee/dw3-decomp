#include "WSTAG305.h"
#include "m2c.h"
#include "WSTAG305_auto.h"
#include "WSTAG305_data.h"

INCLUDE_ASM("asm/ovl/WSTAG305/nonmatchings/WSTAG305", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG305/nonmatchings/WSTAG305", func_800A5EB8);

void func_800A6018(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x335)) {
        M2C_FIELD(arg0, s16 *, 0x50) = ((s16 (*)(M2C_UNK)) *D_80055C48)(0xA0042FCB);
        M2C_FIELD(arg0, s16 *, 0x58) = 0;
        M2C_FIELD(arg0, u16 *, 0x5A) = (u16) *D_800A7FFE;
        M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x2C)(arg0, 1);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG305/nonmatchings/WSTAG305", func_800A6084);

INCLUDE_ASM("asm/ovl/WSTAG305/nonmatchings/WSTAG305", func_800A60B4);

INCLUDE_ASM("asm/ovl/WSTAG305/nonmatchings/WSTAG305", func_800A63A8);

void func_800A6404(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x1C0D, 1);
}

void func_800A6430(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x1C0E, 1);
}

void func_800A645C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x1C36, 0);
}

void func_800A6488(void) {
    *D_8004B370 = 0x17;
}

void func_800A6498(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4057, 1);
}

void func_800A64C4(void) {
    *D_8004B370 = 0x22;
}

void func_800A64D4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x1C39, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG305/nonmatchings/WSTAG305", func_800A6500);

void func_800A6510(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4069, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG305/nonmatchings/WSTAG305", func_800A653C);
