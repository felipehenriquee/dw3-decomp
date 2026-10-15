#include "WSTAG210.h"
#include "m2c.h"
#include "WSTAG210_auto.h"
#include "WSTAG210_data.h"

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A5E74);

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A67E0);

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A680C);

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A6DC8);

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A6DF4);

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A73B0);

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A73DC);

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A74A4);

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A7500);

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A754C);

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A7580);

void func_800A76EC(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A7780);
