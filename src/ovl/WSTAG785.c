#include "WSTAG785.h"
#include "m2c.h"
#include "WSTAG785_auto.h"
#include "WSTAG785_data.h"

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A5DE4);

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A5F04);

void func_800A61A4(void) {
    M2C_FIELD(func_80014504(func_800A5F04, 0x6C, 0), s32 *, 0x50) = 1;
}

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A61D8);

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A6208);

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A62B4);

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A6510);

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A6540);

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A660C);

void *func_800A66B0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A660C, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A75D8)();
    return temp_v0;
}

void func_800A670C(void) {
    *D_8004B370 = 1;
}

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A671C);
