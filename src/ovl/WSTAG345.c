#include "WSTAG345.h"
#include "m2c.h"
#include "WSTAG345_auto.h"
#include "WSTAG345_data.h"

void func_800A5DE4(void *arg0) {
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

void *func_800A5E2C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6F0C)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5E88(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x1C07, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1A22, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG345/nonmatchings/WSTAG345", func_800A5ED4);
