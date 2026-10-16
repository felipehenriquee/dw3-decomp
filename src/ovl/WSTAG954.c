#include "WSTAG954.h"
#include "m2c.h"
#include "WSTAG954_auto.h"
#include "WSTAG954_data.h"

INCLUDE_ASM("asm/ovl/WSTAG954/nonmatchings/WSTAG954", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG954/nonmatchings/WSTAG954", func_800A5ED4);

void func_800A5FA8(void) {
    func_80014504(func_800A5ED4, 0x54, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG954/nonmatchings/WSTAG954", func_800A5FD4);

void *func_800A6038(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5FD4, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6610)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG954/nonmatchings/WSTAG954", func_800A6094);
