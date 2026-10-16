#include "WSTAG635.h"
#include "m2c.h"
#include "WSTAG635_auto.h"
#include "WSTAG635_data.h"

INCLUDE_ASM("asm/ovl/WSTAG635/nonmatchings/WSTAG635", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG635/nonmatchings/WSTAG635", func_800A5ED4);

INCLUDE_ASM("asm/ovl/WSTAG635/nonmatchings/WSTAG635", func_800A6040);

INCLUDE_ASM("asm/ovl/WSTAG635/nonmatchings/WSTAG635", func_800A606C);

INCLUDE_ASM("asm/ovl/WSTAG635/nonmatchings/WSTAG635", func_800A616C);

void *func_800A61F4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A616C, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6FB4)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG635/nonmatchings/WSTAG635", func_800A6250);
