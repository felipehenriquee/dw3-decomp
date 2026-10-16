#include "WSTAG376.h"
#include "m2c.h"
#include "WSTAG376_auto.h"
#include "WSTAG376_data.h"

INCLUDE_ASM("asm/ovl/WSTAG376/nonmatchings/WSTAG376", func_800A5DE4);

void *func_800A5E84(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6870)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG376/nonmatchings/WSTAG376", func_800A5EE0);

INCLUDE_ASM("asm/ovl/WSTAG376/nonmatchings/WSTAG376", func_800A5F2C);

INCLUDE_ASM("asm/ovl/WSTAG376/nonmatchings/WSTAG376", func_800A5F78);
