#include "WSTAG616.h"
#include "m2c.h"
#include "WSTAG616_auto.h"
#include "WSTAG616_data.h"

extern struct opaque D_80048ABC;
/* estado 0: se as flags 0x4080 (ligada) e 0x4081 (desligada) batem, cria o evento */
void func_800A5DE4(u8 *o, s32 *w) {
    u8 *f;

    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        f = (u8 *)&D_80048ABC;
        if ((*(s32 (**)(s32, s32))(f + 0x10))(0x4080, 1) != 0
            && (*(s32 (**)(s32, s32))(f + 0x10))(0x4081, 0) != 0) {
            w[0] = func_800853F8(0x50C);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5E84(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6AEC)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5EE0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4080, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A5F2C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4081, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8F42, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG616/nonmatchings/WSTAG616", func_800A5F78);
