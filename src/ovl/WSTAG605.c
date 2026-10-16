#include "WSTAG605.h"
#include "m2c.h"
#include "WSTAG605_auto.h"
#include "WSTAG605_data.h"

INCLUDE_ASM("asm/ovl/WSTAG605/nonmatchings/WSTAG605", func_800A5DE0);

void *func_800A5E68(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6850)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG605/nonmatchings/WSTAG605", func_800A5EC4);

INCLUDE_ASM("asm/ovl/WSTAG605/nonmatchings/WSTAG605", func_800A5EF8);

INCLUDE_ASM("asm/ovl/WSTAG605/nonmatchings/WSTAG605", func_800A5F44);
