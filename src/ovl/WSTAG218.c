#include "WSTAG218.h"
#include "m2c.h"
#include "WSTAG218_auto.h"
#include "WSTAG218_data.h"

INCLUDE_ASM("asm/ovl/WSTAG218/nonmatchings/WSTAG218", func_800A5DE4);

void *func_800A5E2C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6638)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG218/nonmatchings/WSTAG218", func_800A5E88);
