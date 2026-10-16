#include "WSTAG731.h"
#include "m2c.h"
#include "WSTAG731_auto.h"
#include "WSTAG731_data.h"

INCLUDE_ASM("asm/ovl/WSTAG731/nonmatchings/WSTAG731", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG731/nonmatchings/WSTAG731", func_800A5ED4);

void func_800A5F94(void) {
    func_80014504(func_800A5ED4, 0x54, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG731/nonmatchings/WSTAG731", func_800A5FC0);

void *func_800A6024(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5FC0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6978)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG731/nonmatchings/WSTAG731", func_800A6080);
