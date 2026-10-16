#include "WSTAG325.h"
#include "m2c.h"
#include "WSTAG325_auto.h"
#include "WSTAG325_data.h"

INCLUDE_ASM("asm/ovl/WSTAG325/nonmatchings/WSTAG325", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG325/nonmatchings/WSTAG325", func_800A5F60);

void func_800A5F90(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x35A)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG325/nonmatchings/WSTAG325", func_800A5FC8);

INCLUDE_ASM("asm/ovl/WSTAG325/nonmatchings/WSTAG325", func_800A6068);

INCLUDE_ASM("asm/ovl/WSTAG325/nonmatchings/WSTAG325", func_800A60C4);

INCLUDE_ASM("asm/ovl/WSTAG325/nonmatchings/WSTAG325", func_800A6110);

void func_800A615C(void) {
    *D_8004B370 = 0x16;
}

INCLUDE_ASM("asm/ovl/WSTAG325/nonmatchings/WSTAG325", func_800A616C);
