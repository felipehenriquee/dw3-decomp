#include "WSTAG949.h"
#include "m2c.h"
#include "WSTAG949_auto.h"
#include "WSTAG949_data.h"

INCLUDE_ASM("asm/ovl/WSTAG949/nonmatchings/WSTAG949", func_800A5DE4);

void func_800A5F38(void) {
    func_80014504(func_800A5DE4, 0x50, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG949/nonmatchings/WSTAG949", func_800A5F64);

void *func_800A5FC8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5F64, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A664C)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG949/nonmatchings/WSTAG949", func_800A6024);
