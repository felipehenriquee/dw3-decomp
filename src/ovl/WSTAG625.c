#include "WSTAG625.h"
#include "m2c.h"
#include "WSTAG625_auto.h"
#include "WSTAG625_data.h"

INCLUDE_ASM("asm/ovl/WSTAG625/nonmatchings/WSTAG625", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG625/nonmatchings/WSTAG625", func_800A5F00);

u8 *func_800A614C(s32 arg0) {
    return func_800143DC(func_800A5F00, 128, 0, arg0);
}

/* estado 0: no capitulo 21 com a flag 0x403D desligada, cria o evento */
void func_800A617C(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        if (D_8004B370[0] == 0x15
            && (*(s32 (**)(s32, s32))((u8 *)&D_80048ABC + 0x10))(0x403D, 0) != 0) {
            w[1] = func_800853F8(0x228);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A6204(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A617C, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6C8C)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A6260(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x403D, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8191, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG625/nonmatchings/WSTAG625", func_800A62AC);
