#include "WSTAG295.h"
#include "m2c.h"
#include "WSTAG295_auto.h"
#include "WSTAG295_data.h"

void func_800A5DE0(u8 *o, s32 *w) {
    s32 a;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        if (D_8004B370[0] == 0x21) {
            {
                u8 *f = (u8 *)&D_80048ABC;
                if ((*(s32 (**)(s32, s32))(f + 0x10))(0x1C39, 0) && (*(s32 (**)(s32, s32))(f + 0x10))(0x4057, 1) && (*(s32 (**)(s32, s32))(f + 0x10))(0x4058, 0)) { a = 0x37B; goto call; }
            }
            {
                u8 *f = (u8 *)&D_80048ABC;
                if ((*(s32 (**)(s32, s32))(f + 0x10))(0x1C39, 0) && (*(s32 (**)(s32, s32))(f + 0x10))(0x4058, 1)) {
                    a = 0x37C;
                call:
                    w[0] = func_800853F8(a);
                }
            }
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5EE0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6D44)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5F3C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x1C1A, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x404D, 1);
}

void func_800A5F88(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4058, 1);
}

void func_800A5FB4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4059, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG295/nonmatchings/WSTAG295", func_800A5FE0);
