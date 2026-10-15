#include "WSTAG220.h"
#include "m2c.h"
#include "WSTAG220_auto.h"
#include "WSTAG220_data.h"

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A5E74);

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A6430);

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A645C);

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A6A18);

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A6A44);

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A7000);

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A702C);

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A7074);

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A70D0);

void func_800A7230(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A72C4);
