#include "WSTAG490.h"
#include "m2c.h"
#include "WSTAG490_auto.h"
#include "WSTAG490_data.h"

INCLUDE_ASM("asm/ovl/WSTAG490/nonmatchings/WSTAG490", func_800A5DE4);

void *func_800A5EC8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6F24)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG490/nonmatchings/WSTAG490", func_800A5F24);

INCLUDE_ASM("asm/ovl/WSTAG490/nonmatchings/WSTAG490", func_800A5F70);

INCLUDE_ASM("asm/ovl/WSTAG490/nonmatchings/WSTAG490", func_800A5FBC);

INCLUDE_ASM("asm/ovl/WSTAG490/nonmatchings/WSTAG490", func_800A6008);

INCLUDE_ASM("asm/ovl/WSTAG490/nonmatchings/WSTAG490", func_800A6054);
