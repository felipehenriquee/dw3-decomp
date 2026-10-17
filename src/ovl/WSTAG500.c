#include "WSTAG500.h"
#include "m2c.h"
#include "WSTAG500_auto.h"
#include "WSTAG500_data.h"

void func_800A5DE0(void *arg0) {
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

void *func_800A5E28(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7AA0)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5E84(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x400A, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1A32, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG500/nonmatchings/WSTAG500", func_800A5ED0);
