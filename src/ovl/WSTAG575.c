#include "WSTAG575.h"
#include "m2c.h"
#include "WSTAG575_auto.h"
#include "WSTAG575_data.h"

INCLUDE_ASM("asm/ovl/WSTAG575/nonmatchings/WSTAG575", func_800A5DE0);

void *func_800A5E74(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A67DC)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG575/nonmatchings/WSTAG575", func_800A5ED0);

INCLUDE_ASM("asm/ovl/WSTAG575/nonmatchings/WSTAG575", func_800A5EFC);
