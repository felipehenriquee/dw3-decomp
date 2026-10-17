#include "WSTAG805.h"
#include "m2c.h"
#include "WSTAG805_auto.h"
#include "WSTAG805_data.h"

INCLUDE_ASM("asm/ovl/WSTAG805/nonmatchings/WSTAG805", func_800A5DE4);

void func_800A5F64(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x335)) {
        M2C_FIELD(arg0, s16 *, 0x50) = 0;
        M2C_FIELD(arg0, s16 *, 0x52) = 0;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG805/nonmatchings/WSTAG805", func_800A5F9C);

INCLUDE_ASM("asm/ovl/WSTAG805/nonmatchings/WSTAG805", func_800A5FCC);

INCLUDE_ASM("asm/ovl/WSTAG805/nonmatchings/WSTAG805", func_800A60CC);

void func_800A63C4(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x35B)) {
        ((M2C_UNK (*)(M2C_UNK)) *D_80055C48)(0x340004);
        M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG805/nonmatchings/WSTAG805", func_800A641C);

INCLUDE_ASM("asm/ovl/WSTAG805/nonmatchings/WSTAG805", func_800A644C);

s32 func_800A65A0(s32 x, s32 y, s32 w, s32 h) {
    s16 r[4];
    u8 *o = (*(u8 *(**)(s32))&D_8004DF8C)(0x1002);

    (*(void (**)(u8 *, s16 *))(o + 0x128))(o, r);
    if (x + w < r[0]) {
        return 0;
    }
    if (r[0] + r[2] < x) {
        return 0;
    }
    if (y + h < r[1]) {
        return 0;
    }
    return r[1] + r[3] >= y;
}

INCLUDE_ASM("asm/ovl/WSTAG805/nonmatchings/WSTAG805", func_800A6664);

INCLUDE_ASM("asm/ovl/WSTAG805/nonmatchings/WSTAG805", func_800A6724);

void func_800A6990(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6724, 0x84, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg2;
}

INCLUDE_ASM("asm/ovl/WSTAG805/nonmatchings/WSTAG805", func_800A69E8);

void *func_800A6B44(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A69E8, 0x54, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7758)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG805/nonmatchings/WSTAG805", func_800A6BA0);

void func_800A6BEC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x8AF0, 1);
}

void func_800A6C18(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4065, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG805/nonmatchings/WSTAG805", func_800A6C44);
