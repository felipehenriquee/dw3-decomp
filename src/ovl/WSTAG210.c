#include "WSTAG210.h"
#include "m2c.h"
#include "WSTAG210_auto.h"
#include "WSTAG210_data.h"

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A5E74);

void func_800A67E0(void) {
    func_80014504(func_800A5E74, 0x84, 0x28);
}

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A680C);

void func_800A6DC8(void) {
    func_80014504(func_800A680C, 0x64, 0x14);
}

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A6DF4);

void func_800A73B0(void) {
    func_80014504(func_800A6DF4, 0x64, 0x14);
}

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A73DC);

void *func_800A74A4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A73DC, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800AA08C)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG210/nonmatchings/WSTAG210", func_800A7500);

void func_800A754C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x1C26, 0);
    *D_8004B370 = 0x18;
}

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
