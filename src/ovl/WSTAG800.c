#include "WSTAG800.h"
#include "m2c.h"
#include "WSTAG800_auto.h"
#include "WSTAG800_data.h"

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A5F00);

void func_800A6174(void *arg0, s32 arg1) {
    if (arg1 == 0x35B) {
        M2C_FIELD(arg0, s16 *, 0x50) = 1;
        M2C_FIELD(arg0, s16 *, 0x58) = 0;
        M2C_FIELD(arg0, s16 *, 0x5A) = (s16) *D_800A7612;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A61C0);

void func_800A61F0(void) {
    M2C_FIELD(func_80014504(func_800A5F00, 0x64, 0), s16 *, 0x52) = 1;
}

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6224);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6344);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6510);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6540);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6688);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6858);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6884);

void *func_800A69CC(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6884, 0x54, 0x20);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7E88)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6A28);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6B48);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6C30);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6CF4);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6F84);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6FE0);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A702C);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A7078);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A70C4);
