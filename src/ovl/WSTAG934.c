#include "WSTAG934.h"
#include "m2c.h"
#include "WSTAG934_auto.h"
#include "WSTAG934_data.h"

INCLUDE_ASM("asm/ovl/WSTAG934/nonmatchings/WSTAG934", func_800A5DFC);

void func_800A6218(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        switch (arg1) {                             /* irregular */
        case 0x348:
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
            M2C_FIELD(arg0, s16 *, 0x58) = 0;
            return;
        case 0x349:
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
            M2C_FIELD(arg0, s16 *, 0x58) = 1;
            break;
        }
    }
}

INCLUDE_ASM("asm/ovl/WSTAG934/nonmatchings/WSTAG934", func_800A628C);

INCLUDE_ASM("asm/ovl/WSTAG934/nonmatchings/WSTAG934", func_800A62F4);

void *func_800A633C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A62F4, 0x58, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6870)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG934/nonmatchings/WSTAG934", func_800A6398);

void func_800A64B8(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/WSTAG934/nonmatchings/WSTAG934", func_800A654C);
