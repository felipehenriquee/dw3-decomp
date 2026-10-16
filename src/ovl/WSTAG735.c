#include "WSTAG735.h"
#include "m2c.h"
#include "WSTAG735_auto.h"
#include "WSTAG735_data.h"

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A5DE0);

void *func_800A5EE4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 0x2C);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A736C)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A5F40);

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A6060);

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A6148);

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A620C);

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A649C);

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A64F8);

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A6544);

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A6590);
