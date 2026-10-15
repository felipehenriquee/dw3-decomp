#include "WSTAG937.h"
#include "m2c.h"
#include "WSTAG937_auto.h"
#include "WSTAG937_data.h"

INCLUDE_ASM("asm/ovl/WSTAG937/nonmatchings/WSTAG937", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG937/nonmatchings/WSTAG937", func_800A5E28);

INCLUDE_ASM("asm/ovl/WSTAG937/nonmatchings/WSTAG937", func_800A5E84);

void func_800A5F6C(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/WSTAG937/nonmatchings/WSTAG937", func_800A6000);
