#include "WSTAG480.h"
#include "m2c.h"
#include "WSTAG480_auto.h"
#include "WSTAG480_data.h"

void func_800A5DF8(u8 *o, u8 (**tbl)[4], AnimSt *st, s32 depth) {
    s32 dt;
    if (depth == 0) {
        dt = (*(s32 (**)(void))&D_8004DF9C)();
        if (dt >= 5) {
            dt = 4;
        }
        st->t -= dt;
    }
    if (st->t <= 0) {
        if (tbl[st->seq][st->frame][3] != 0) {
            st->seq++;
            st->frame = 0;
            if (tbl[st->seq] == NULL) {
                st->seq = 0;
            }
        } else {
            st->frame++;
        }
        st->t += tbl[st->seq][st->frame][1];
        func_800A5DF8(o, tbl, st, depth + 1);
    }
    if (depth == 0) {
        o[4] = tbl[st->seq][st->frame][0];
        o[9] = tbl[st->seq][st->frame][2];
    }
}

INCLUDE_ASM("asm/ovl/WSTAG480/nonmatchings/WSTAG480", func_800A5F84);

Obj *func_800A6164(void) {
    return func_80014504(func_800A5F84, 0x78, 0);
}

void func_800A6190(u8 *o, Obj **w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        w[1] = func_800A6164();
        if (D_8004B370[0] == 7 && ((s32 (*)(s32, s32))D_80048ACC[0])(0x4000, 1) != 0) {
            w[0] = func_800853F8(0xAB);
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A6230(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6190, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A81F8)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A628C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4000, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

void func_800A62D8(void) {
    *D_8004B370 = 8;
}

INCLUDE_ASM("asm/ovl/WSTAG480/nonmatchings/WSTAG480", func_800A62E8);
