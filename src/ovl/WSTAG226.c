#include "WSTAG226.h"
#include "m2c.h"
#include "WSTAG226_auto.h"
#include "WSTAG226_data.h"

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A5EB8);

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A5EF0);

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A6164);

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A61CC);

void func_800A61FC(void) {
    func_80014504(func_800A5EF0, 0x70, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A6228);

void *func_800A62C8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6228, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6D88)();
    return temp_v0;
}

void func_800A6324(void) {
    *D_8004B370 = 0x26;
}

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A6334);
