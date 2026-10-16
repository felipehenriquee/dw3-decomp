#include "WSTAG480.h"
#include "m2c.h"
#include "WSTAG480_auto.h"
#include "WSTAG480_data.h"

INCLUDE_ASM("asm/ovl/WSTAG480/nonmatchings/WSTAG480", func_800A5DF8);

INCLUDE_ASM("asm/ovl/WSTAG480/nonmatchings/WSTAG480", func_800A5F84);

void func_800A6164(void) {
    func_80014504(func_800A5F84, 0x78, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG480/nonmatchings/WSTAG480", func_800A6190);

void *func_800A6230(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6190, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A81F8)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG480/nonmatchings/WSTAG480", func_800A628C);

void func_800A62D8(void) {
    *D_8004B370 = 8;
}

INCLUDE_ASM("asm/ovl/WSTAG480/nonmatchings/WSTAG480", func_800A62E8);
