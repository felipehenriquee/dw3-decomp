#include "WSTAG960.h"
#include "m2c.h"
#include "WSTAG960_auto.h"
#include "WSTAG960_data.h"

INCLUDE_ASM("asm/ovl/WSTAG960/nonmatchings/WSTAG960", func_800A5DE4);

INCLUDE_ASM("asm/ovl/WSTAG960/nonmatchings/WSTAG960", func_800A5EE4);

void *func_800A5F58(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5EE4, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A63AC)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG960/nonmatchings/WSTAG960", func_800A5FB4);
