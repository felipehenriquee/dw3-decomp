#include "WSTAG935.h"
#include "m2c.h"
#include "WSTAG935_auto.h"
#include "WSTAG935_data.h"

INCLUDE_ASM("asm/ovl/WSTAG935/nonmatchings/WSTAG935", func_800A5E40);

INCLUDE_ASM("asm/ovl/WSTAG935/nonmatchings/WSTAG935", func_800A5E88);

INCLUDE_ASM("asm/ovl/WSTAG935/nonmatchings/WSTAG935", func_800A5EE4);

void func_800A5FD8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = 1;
    if (arg1 != 0) {
        ((void (*)(s32))D_80055C48[0])(0x40019);
        M2C_FIELD(arg0, s32 *, 4) = 0x1000 / M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 8) = 0;
    } else {
        ((void (*)(s32))D_80055C48[0])(0x4001A);
        M2C_FIELD(arg0, s32 *, 8) = 0x1000;
        M2C_FIELD(arg0, s32 *, 4) = -((0x1000 / M2C_FIELD(arg0, s32 *, 0)) * 2);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG935/nonmatchings/WSTAG935", func_800A606C);

INCLUDE_ASM("asm/ovl/WSTAG935/nonmatchings/WSTAG935", func_800A60D8);

INCLUDE_ASM("asm/ovl/WSTAG935/nonmatchings/WSTAG935", func_800A6A04);

INCLUDE_ASM("asm/ovl/WSTAG935/nonmatchings/WSTAG935", func_800A6A30);

INCLUDE_ASM("asm/ovl/WSTAG935/nonmatchings/WSTAG935", func_800A739C);
