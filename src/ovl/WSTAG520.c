#include "WSTAG520.h"
#include "m2c.h"
#include "WSTAG520_auto.h"
#include "WSTAG520_data.h"

INCLUDE_ASM("asm/ovl/WSTAG520/nonmatchings/WSTAG520", func_800A5DE0);

void *func_800A5E74(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7080)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG520/nonmatchings/WSTAG520", func_800A5ED0);

INCLUDE_ASM("asm/ovl/WSTAG520/nonmatchings/WSTAG520", func_800A5F1C);

INCLUDE_ASM("asm/ovl/WSTAG520/nonmatchings/WSTAG520", func_800A5F50);

INCLUDE_ASM("asm/ovl/WSTAG520/nonmatchings/WSTAG520", func_800A5F60);
