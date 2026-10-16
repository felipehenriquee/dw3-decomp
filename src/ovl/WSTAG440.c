#include "WSTAG440.h"
#include "m2c.h"
#include "WSTAG440_auto.h"
#include "WSTAG440_data.h"

INCLUDE_ASM("asm/ovl/WSTAG440/nonmatchings/WSTAG440", func_800A5DE4);

void *func_800A5E50(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6D54)();
    return temp_v0;
}

void func_800A5EAC(void) {
    *D_8004B370 = 7;
}

INCLUDE_ASM("asm/ovl/WSTAG440/nonmatchings/WSTAG440", func_800A5EBC);
