#include "WSTAG580.h"
#include "m2c.h"
#include "WSTAG580_auto.h"
#include "WSTAG580_data.h"

INCLUDE_ASM("asm/ovl/WSTAG580/nonmatchings/WSTAG580", func_800A5DE0);

void *func_800A5EA8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7368)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG580/nonmatchings/WSTAG580", func_800A5F04);

INCLUDE_ASM("asm/ovl/WSTAG580/nonmatchings/WSTAG580", func_800A5F50);

INCLUDE_ASM("asm/ovl/WSTAG580/nonmatchings/WSTAG580", func_800A5F9C);

INCLUDE_ASM("asm/ovl/WSTAG580/nonmatchings/WSTAG580", func_800A5FE8);

INCLUDE_ASM("asm/ovl/WSTAG580/nonmatchings/WSTAG580", func_800A6034);

INCLUDE_ASM("asm/ovl/WSTAG580/nonmatchings/WSTAG580", func_800A6080);

void func_800A60CC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4038, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG580/nonmatchings/WSTAG580", func_800A60F8);
