#include "WSTAG620.h"
#include "m2c.h"
#include "WSTAG620_auto.h"
#include "WSTAG620_data.h"

INCLUDE_ASM("asm/ovl/WSTAG620/nonmatchings/WSTAG620", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG620/nonmatchings/WSTAG620", func_800A5F00);

INCLUDE_ASM("asm/ovl/WSTAG620/nonmatchings/WSTAG620", func_800A6198);

INCLUDE_ASM("asm/ovl/WSTAG620/nonmatchings/WSTAG620", func_800A61C8);

void *func_800A6314(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A61C8, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7F38)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG620/nonmatchings/WSTAG620", func_800A6370);

void func_800A63BC(void) {
    *D_8004B370 = 0x14;
}

INCLUDE_ASM("asm/ovl/WSTAG620/nonmatchings/WSTAG620", func_800A63CC);

void func_800A6418(void) {
    *D_8004B370 = 0x15;
}

INCLUDE_ASM("asm/ovl/WSTAG620/nonmatchings/WSTAG620", func_800A6428);
