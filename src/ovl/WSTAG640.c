#include "WSTAG640.h"
#include "m2c.h"
#include "WSTAG640_auto.h"
#include "WSTAG640_data.h"

INCLUDE_ASM("asm/ovl/WSTAG640/nonmatchings/WSTAG640", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG640/nonmatchings/WSTAG640", func_800A5ED4);

void func_800A6040(void) {
    func_80014504(func_800A5ED4, 0x5C, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG640/nonmatchings/WSTAG640", func_800A606C);

INCLUDE_ASM("asm/ovl/WSTAG640/nonmatchings/WSTAG640", func_800A616C);

void *func_800A61F4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A616C, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6B34)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG640/nonmatchings/WSTAG640", func_800A6250);
