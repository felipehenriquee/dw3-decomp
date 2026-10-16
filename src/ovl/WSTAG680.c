#include "WSTAG680.h"
#include "m2c.h"
#include "WSTAG680_auto.h"
#include "WSTAG680_data.h"

INCLUDE_ASM("asm/ovl/WSTAG680/nonmatchings/WSTAG680", func_800A5EDC);

INCLUDE_ASM("asm/ovl/WSTAG680/nonmatchings/WSTAG680", func_800A5FD8);

INCLUDE_ASM("asm/ovl/WSTAG680/nonmatchings/WSTAG680", func_800A627C);

INCLUDE_ASM("asm/ovl/WSTAG680/nonmatchings/WSTAG680", func_800A63AC);

INCLUDE_ASM("asm/ovl/WSTAG680/nonmatchings/WSTAG680", func_800A63DC);

void *func_800A6454(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A63DC, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6998)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG680/nonmatchings/WSTAG680", func_800A64B0);
