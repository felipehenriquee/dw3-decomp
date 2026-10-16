#include "WSTAG585.h"
#include "m2c.h"
#include "WSTAG585_auto.h"
#include "WSTAG585_data.h"

INCLUDE_ASM("asm/ovl/WSTAG585/nonmatchings/WSTAG585", func_800A5DE0);

void *func_800A5E88(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6400)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG585/nonmatchings/WSTAG585", func_800A5EE4);

INCLUDE_ASM("asm/ovl/WSTAG585/nonmatchings/WSTAG585", func_800A5F10);
