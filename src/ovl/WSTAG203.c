#include "WSTAG203.h"
#include "m2c.h"
#include "WSTAG203_auto.h"
#include "WSTAG203_data.h"

INCLUDE_ASM("asm/ovl/WSTAG203/nonmatchings/WSTAG203", func_800A5DE4);

void *func_800A5E2C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A69A8)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG203/nonmatchings/WSTAG203", func_800A5E88);
