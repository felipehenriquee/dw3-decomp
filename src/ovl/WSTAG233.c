#include "WSTAG233.h"
#include "m2c.h"
#include "WSTAG233_auto.h"
#include "WSTAG233_data.h"

INCLUDE_ASM("asm/ovl/WSTAG233/nonmatchings/WSTAG233", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG233/nonmatchings/WSTAG233", func_800A5ED4);

void func_800A5FCC(void) {
    func_80014504(func_800A5ED4, 0x58, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG233/nonmatchings/WSTAG233", func_800A5FF8);

void *func_800A605C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5FF8, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A664C)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG233/nonmatchings/WSTAG233", func_800A60B8);
