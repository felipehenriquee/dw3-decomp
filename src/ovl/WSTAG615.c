#include "WSTAG615.h"
#include "m2c.h"
#include "WSTAG615_auto.h"
#include "WSTAG615_data.h"

INCLUDE_ASM("asm/ovl/WSTAG615/nonmatchings/WSTAG615", func_800A5DE4);

void *func_800A5E78(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7468)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG615/nonmatchings/WSTAG615", func_800A5ED4);

void func_800A5F20(void) {
    *D_8004B370 = 0x13;
}

INCLUDE_ASM("asm/ovl/WSTAG615/nonmatchings/WSTAG615", func_800A5F30);
