#include "WSTAG676.h"
#include "m2c.h"
#include "WSTAG676_auto.h"
#include "WSTAG676_data.h"

INCLUDE_ASM("asm/ovl/WSTAG676/nonmatchings/WSTAG676", func_800A5DE0);

void *func_800A5E68(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6AD4)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG676/nonmatchings/WSTAG676", func_800A5EC4);

void func_800A5F10(void) {
    *D_8004B370 = 0x23;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x8018, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG676/nonmatchings/WSTAG676", func_800A5F48);
