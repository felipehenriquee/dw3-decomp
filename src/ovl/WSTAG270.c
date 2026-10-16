#include "WSTAG270.h"
#include "m2c.h"
#include "WSTAG270_auto.h"
#include "WSTAG270_data.h"

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A5E40);

void func_800A63FC(void) {
    func_80014504(func_800A5E40, 0x64, 0x14);
}

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A6428);

void func_800A69E4(void) {
    func_80014504(func_800A6428, 0x64, 0x14);
}

void func_800A6A10(void *arg0) {
    switch (M2C_FIELD(arg0, s32 *, 0xC)) {
    case 0:
    default:
        M2C_FIELD(arg0, void (**)(void *), 0x38)(arg0);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A6A58(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6A10, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A87A4)();
    return temp_v0;
}

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
