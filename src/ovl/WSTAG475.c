#include "WSTAG475.h"
#include "m2c.h"
#include "WSTAG475_auto.h"
#include "WSTAG475_data.h"

INCLUDE_ASM("asm/ovl/WSTAG475/nonmatchings/WSTAG475", func_800A5DE0);

void *func_800A5F88(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6C10)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG475/nonmatchings/WSTAG475", func_800A5FE4);

INCLUDE_ASM("asm/ovl/WSTAG475/nonmatchings/WSTAG475", func_800A6010);

INCLUDE_ASM("asm/ovl/WSTAG475/nonmatchings/WSTAG475", func_800A6048);
