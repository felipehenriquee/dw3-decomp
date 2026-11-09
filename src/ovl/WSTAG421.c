#include "WSTAG421.h"
#include "m2c.h"
#include "WSTAG421_auto.h"
#include "WSTAG421_data.h"

void func_800A5DE0(u8 *o, s32 *w) {
    s32 a;
    Rec18 *r;
    s32 c;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        c = ((s32 (*)(s32, s32))D_80048ACC[0])(0x1A0A, 1) != 0;
        for (r = D_80099D90; r->b[2] != 0; r++) {
            if (r->b[1] == 1) {
                r->b[5] = c;
            }
        }
        if (D_8004B370[0] == 0x1B) {
            {
                u8 *f = (u8 *)&D_80048ABC;
                if ((*(s32 (**)(s32, s32))(f + 0x10))(0x40A3, 1) && (*(s32 (**)(s32, s32))(f + 0x10))(0x40A7, 0)) { a = 0x2E5; goto call; }
            }
            if (((s32 (*)(s32, s32))D_80048ACC[0])(0x40A7, 1)) {
                a = 0x2E7;
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

void *func_800A5F1C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6F6C)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5F78(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x40A3, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A5FC4(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x8016, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40A7, 1);
}

void func_800A6010(void) {
    *D_8004B370 = 0x1C;
}

INCLUDE_ASM("asm/ovl/WSTAG421/nonmatchings/WSTAG421", func_800A6020);
