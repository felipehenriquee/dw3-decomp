#include "WSTAG820.h"
#include "m2c.h"
#include "WSTAG820_auto.h"
#include "WSTAG820_data.h"

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A5EB8);

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A5FB4);

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A6008);

void *func_800A6160(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6008, 0x54, 0x14);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A76E8)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A61BC);

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A62DC);

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A63C4);

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A6488);

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A6718);

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A6774);

void func_800A67BC(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x335)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A67F4);

void func_800A6840(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4075, 1);
}

void func_800A686C(void) {
    *D_8004B370 = 0x2B;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x7401, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A68A4);
