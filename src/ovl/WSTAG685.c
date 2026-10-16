#include "WSTAG685.h"
#include "m2c.h"
#include "WSTAG685_auto.h"
#include "WSTAG685_data.h"

INCLUDE_ASM("asm/ovl/WSTAG685/nonmatchings/WSTAG685", func_800A5DE0);

void *func_800A5E58(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6C40)();
    return temp_v0;
}

void func_800A5EB4(void) {
    *D_8004B370 = 0x10;
}

void func_800A5EC4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4020, 1);
}

void func_800A5EF0(void) {
    *D_8004B370 = 0x19;
}

INCLUDE_ASM("asm/ovl/WSTAG685/nonmatchings/WSTAG685", func_800A5F00);
