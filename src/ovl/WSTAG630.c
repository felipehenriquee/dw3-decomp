#include "WSTAG630.h"
#include "m2c.h"
#include "WSTAG630_auto.h"
#include "WSTAG630_data.h"

INCLUDE_ASM("asm/ovl/WSTAG630/nonmatchings/WSTAG630", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG630/nonmatchings/WSTAG630", func_800A5ED4);

INCLUDE_ASM("asm/ovl/WSTAG630/nonmatchings/WSTAG630", func_800A6040);

INCLUDE_ASM("asm/ovl/WSTAG630/nonmatchings/WSTAG630", func_800A606C);

void *func_800A60D0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A606C, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6BE4)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG630/nonmatchings/WSTAG630", func_800A612C);
