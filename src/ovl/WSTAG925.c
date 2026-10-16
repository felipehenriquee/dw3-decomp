#include "WSTAG925.h"
#include "m2c.h"
#include "WSTAG925_auto.h"
#include "WSTAG925_data.h"

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A5DE0);

void *func_800A5E64(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A65B8)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A5EC0);

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A5F0C);

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A6000);

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A60D8);

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A6110);

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A639C);
