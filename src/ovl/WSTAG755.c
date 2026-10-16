#include "WSTAG755.h"
#include "m2c.h"
#include "WSTAG755_auto.h"
#include "WSTAG755_data.h"

INCLUDE_ASM("asm/ovl/WSTAG755/nonmatchings/WSTAG755", func_800A5DE4);

INCLUDE_ASM("asm/ovl/WSTAG755/nonmatchings/WSTAG755", func_800A5E6C);

INCLUDE_ASM("asm/ovl/WSTAG755/nonmatchings/WSTAG755", func_800A5EC8);

void func_800A5F14(void) {
    *D_8004B370 = 0x1F;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x800C, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG755/nonmatchings/WSTAG755", func_800A5F4C);
