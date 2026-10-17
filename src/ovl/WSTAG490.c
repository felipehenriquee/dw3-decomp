#include "WSTAG490.h"
#include "m2c.h"
#include "WSTAG490_auto.h"
#include "WSTAG490_data.h"

INCLUDE_ASM("asm/ovl/WSTAG490/nonmatchings/WSTAG490", func_800A5DE4);

void *func_800A5EC8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6F24)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5F24(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4025, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A5F70(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4026, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8022, 1);
}

extern struct opaque D_80048ABC;
void func_800A5FBC(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x402F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7401, 1);
}

extern struct opaque D_80048ABC;
void func_800A6008(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4030, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x818B, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG490/nonmatchings/WSTAG490", func_800A6054);
