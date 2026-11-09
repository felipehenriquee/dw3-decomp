#include "WSTAG490.h"
#include "m2c.h"
#include "WSTAG490_auto.h"
#include "WSTAG490_data.h"

void func_800A5DE4(u8 *o, s32 *w) {
    s32 a;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        {
            u8 *f = (u8 *)&D_80048ABC;
            if ((*(s32 (**)(s32, s32))(f + 0x10))(0x4025, 1) && (*(s32 (**)(s32, s32))(f + 0x10))(0x4026, 0)) { a = 0x4F4; goto call; }
        }
        {
            u8 *f = (u8 *)&D_80048ABC;
            if ((*(s32 (**)(s32, s32))(f + 0x10))(0x402F, 1) && (*(s32 (**)(s32, s32))(f + 0x10))(0x4030, 0)) {
                a = 0x4FE;
            call:
                w[0] = func_800853F8(a);
            }
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

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
