#include "WSTAG924.h"
#include "m2c.h"
#include "WSTAG924_auto.h"
#include "WSTAG924_data.h"

INCLUDE_ASM("asm/ovl/WSTAG924/nonmatchings/WSTAG924", func_800A5E44);

INCLUDE_ASM("asm/ovl/WSTAG924/nonmatchings/WSTAG924", func_800A5E8C);

INCLUDE_ASM("asm/ovl/WSTAG924/nonmatchings/WSTAG924", func_800A5EE8);

void func_800A5FFC(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/WSTAG924/nonmatchings/WSTAG924", func_800A6090);

INCLUDE_ASM("asm/ovl/WSTAG924/nonmatchings/WSTAG924", func_800A60FC);

void func_800A6A68(void) {
    func_80014504(func_800A60FC, 0x84, 0x28);
}

INCLUDE_ASM("asm/ovl/WSTAG924/nonmatchings/WSTAG924", func_800A6A94);

INCLUDE_ASM("asm/ovl/WSTAG924/nonmatchings/WSTAG924", func_800A7400);
