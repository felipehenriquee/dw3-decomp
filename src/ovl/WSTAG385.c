#include "WSTAG385.h"
#include "m2c.h"
#include "WSTAG385_auto.h"
#include "WSTAG385_data.h"

INCLUDE_ASM("asm/ovl/WSTAG385/nonmatchings/WSTAG385", func_800A5DE4);

void *func_800A5E84(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A817C)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5EE0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x402D, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A5F2C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x402E, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8168, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG385/nonmatchings/WSTAG385", func_800A5F78);
