#include "WSTAG455.h"
#include "m2c.h"
#include "WSTAG455_auto.h"
#include "WSTAG455_data.h"

INCLUDE_ASM("asm/ovl/WSTAG455/nonmatchings/WSTAG455", func_800A5DE4);

INCLUDE_ASM("asm/ovl/WSTAG455/nonmatchings/WSTAG455", func_800A5EBC);

INCLUDE_ASM("asm/ovl/WSTAG455/nonmatchings/WSTAG455", func_800A6010);

INCLUDE_ASM("asm/ovl/WSTAG455/nonmatchings/WSTAG455", func_800A6040);

void *func_800A60D4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6040, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A70DC)();
    return temp_v0;
}

void func_800A6130(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4007, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG455/nonmatchings/WSTAG455", func_800A615C);
