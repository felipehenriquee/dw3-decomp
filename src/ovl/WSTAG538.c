#include "WSTAG538.h"
#include "m2c.h"
#include "WSTAG538_auto.h"
#include "WSTAG538_data.h"

extern struct opaque D_80048ABC;
/* estado 0: se as flags 0x407C (ligada) e 0x407D (desligada) batem, cria o evento */
void func_800A5DE0(u8 *o, s32 *w) {
    u8 *f;

    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        f = (u8 *)&D_80048ABC;
        if ((*(s32 (**)(s32, s32))(f + 0x10))(0x407C, 1) != 0
            && (*(s32 (**)(s32, s32))(f + 0x10))(0x407D, 0) != 0) {
            w[0] = func_800853F8(0x508);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5E80(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6984)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5EDC(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x407C, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A5F28(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x407D, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B00, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG538/nonmatchings/WSTAG538", func_800A5F74);
