#include "WSTAG225.h"
#include "m2c.h"
#include "WSTAG225_auto.h"
#include "WSTAG225_data.h"

INCLUDE_ASM("asm/ovl/WSTAG225/nonmatchings/WSTAG225", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG225/nonmatchings/WSTAG225", func_800A5EB8);

INCLUDE_ASM("asm/ovl/WSTAG225/nonmatchings/WSTAG225", func_800A5EF0);

INCLUDE_ASM("asm/ovl/WSTAG225/nonmatchings/WSTAG225", func_800A6174);

INCLUDE_ASM("asm/ovl/WSTAG225/nonmatchings/WSTAG225", func_800A61E0);

void func_800A6210(void) {
    func_80014504(func_800A5EF0, 0x70, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG225/nonmatchings/WSTAG225", func_800A623C);

void *func_800A62B4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A623C, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6B3C)();
    return temp_v0;
}

void func_800A6310(void) {
    *D_8004B370 = 2;
}

INCLUDE_ASM("asm/ovl/WSTAG225/nonmatchings/WSTAG225", func_800A6320);
