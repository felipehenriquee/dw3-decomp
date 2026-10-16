#include "WSTAG537.h"
#include "m2c.h"
#include "WSTAG537_auto.h"
#include "WSTAG537_data.h"

INCLUDE_ASM("asm/ovl/WSTAG537/nonmatchings/WSTAG537", func_800A5DE0);

void *func_800A5E88(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A71F0)();
    return temp_v0;
}

void func_800A5EE4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x400B, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG537/nonmatchings/WSTAG537", func_800A5F10);

INCLUDE_ASM("asm/ovl/WSTAG537/nonmatchings/WSTAG537", func_800A5F5C);

INCLUDE_ASM("asm/ovl/WSTAG537/nonmatchings/WSTAG537", func_800A5FA8);
