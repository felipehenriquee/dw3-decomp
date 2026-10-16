#include "WSTAG538.h"
#include "m2c.h"
#include "WSTAG538_auto.h"
#include "WSTAG538_data.h"

INCLUDE_ASM("asm/ovl/WSTAG538/nonmatchings/WSTAG538", func_800A5DE0);

void *func_800A5E80(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6984)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG538/nonmatchings/WSTAG538", func_800A5EDC);

INCLUDE_ASM("asm/ovl/WSTAG538/nonmatchings/WSTAG538", func_800A5F28);

INCLUDE_ASM("asm/ovl/WSTAG538/nonmatchings/WSTAG538", func_800A5F74);
