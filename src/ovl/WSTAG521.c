#include "WSTAG521.h"
#include "m2c.h"
#include "WSTAG521_auto.h"
#include "WSTAG521_data.h"

INCLUDE_ASM("asm/ovl/WSTAG521/nonmatchings/WSTAG521", func_800A5DE0);

void *func_800A5E74(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6B5C)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG521/nonmatchings/WSTAG521", func_800A5ED0);

void func_800A5F1C(void) {
    *D_8004B370 = 0x1D;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x8017, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG521/nonmatchings/WSTAG521", func_800A5F54);
