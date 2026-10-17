#include "WSTAG450.h"
#include "m2c.h"
#include "WSTAG450_auto.h"
#include "WSTAG450_data.h"

INCLUDE_ASM("asm/ovl/WSTAG450/nonmatchings/WSTAG450", func_800A5DE4);

void *func_800A5E84(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7AD4)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5EE0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4031, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7401, 1);
}

extern struct opaque D_80048ABC;
void func_800A5F2C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4032, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8023, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG450/nonmatchings/WSTAG450", func_800A5F78);
