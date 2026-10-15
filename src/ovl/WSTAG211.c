#include "WSTAG211.h"
#include "m2c.h"
#include "WSTAG211_auto.h"
#include "WSTAG211_data.h"

INCLUDE_ASM("asm/ovl/WSTAG211/nonmatchings/WSTAG211", func_800A5DE4);

void *func_800A5E2C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A72EC)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG211/nonmatchings/WSTAG211", func_800A5E88);

INCLUDE_ASM("asm/ovl/WSTAG211/nonmatchings/WSTAG211", func_800A5EE8);
