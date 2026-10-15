#include "WSTAG923.h"
#include "m2c.h"
#include "WSTAG923_auto.h"
#include "WSTAG923_data.h"

INCLUDE_ASM("asm/ovl/WSTAG923/nonmatchings/WSTAG923", func_800A5DE4);

INCLUDE_ASM("asm/ovl/WSTAG923/nonmatchings/WSTAG923", func_800A5E2C);

INCLUDE_ASM("asm/ovl/WSTAG923/nonmatchings/WSTAG923", func_800A5E88);

void func_800A5FA0(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/WSTAG923/nonmatchings/WSTAG923", func_800A6034);
