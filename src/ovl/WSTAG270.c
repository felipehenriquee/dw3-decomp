#include "WSTAG270.h"
#include "m2c.h"
#include "WSTAG270_auto.h"
#include "WSTAG270_data.h"

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A5E40);

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A63FC);

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A6428);

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A69E4);

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A6A10);

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A6A58);

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A6AB4);

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A6B14);

void func_800A6C08(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A6C9C);
