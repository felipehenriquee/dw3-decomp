#include "WSTAG926.h"
#include "m2c.h"
#include "WSTAG926_auto.h"
#include "WSTAG926_data.h"

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

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A63F8)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG926/nonmatchings/WSTAG926", func_800A5E84);

void func_800A5F70(u8 *o) {
    Rec18 *r;
    u8 *x;
    Rec18 *q;
    u8 c;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        for (q = D_80099D90; q->b[2] != 0; q++) {
            c = q->b[1];
            if (c == 1) {
                *(Rec18 **)(o + 0x50) = q;
                q->h[6]--;
                q->b[0] = c;
            }
        }
        *(s32 *)(o + 0x54) = 0;
        break;
    case 1:
        r = *(Rec18 **)(o + 0x50);
        x = ((u8 *(*)(s32, s32, s32))D_8004B7BC)(5, -1, 0);
        r->h[6]++;
        *(s32 *)(o + 0x54) += 1;
        *(s32 *)(x + 0x54) += 0x100;
        if (*(s32 *)(o + 0x54) >= 150) {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
        }
        break;
    case 2:
    case 3:
        break;
    }
}

u8 *func_800A609C(s32 link) {
    return func_800143DC(func_800A5F70, 0x58, 0, link);
}
