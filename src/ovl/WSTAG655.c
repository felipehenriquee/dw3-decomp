#include "WSTAG655.h"
#include "m2c.h"
#include "WSTAG655_auto.h"
#include "WSTAG655_data.h"

INCLUDE_ASM("asm/ovl/WSTAG655/nonmatchings/WSTAG655", func_800A5DE0);

void *func_800A5E74(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6734)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG655/nonmatchings/WSTAG655", func_800A5ED0);

void func_800A5F1C(void) {
    *D_8004B370 = 0x11;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x800B, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG655/nonmatchings/WSTAG655", func_800A5F54);
