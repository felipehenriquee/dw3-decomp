#include "WSTAG630.h"
#include "m2c.h"
#include "WSTAG630_auto.h"
#include "WSTAG630_data.h"

s16 func_800A5DE0(s16 *st, s16 *tbl, s32 depth) {
    s16 *e = tbl + st[0] * 2;
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        st[1] -= dt;
    }
    if (st[1] <= 0) {
        st[0]++;
        e += 2;
        st[1] += e[1];
        if (e[0] == 0xFF) {
            e = tbl;
            st[0] = 0;
            st[1] += e[1];
        }
        func_800A5DE0(st, tbl, depth + 1);
    }
    return e[0];
}

void func_800A5ED4(u8 *o) {
    Rec18 *r;
    s32 v[3];
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s16 *)(o + 0x50) = 0;
        *(s16 *)(o + 0x52) = D_800A623C[1];
        *(s16 *)(o + 0x54) = 0;
        *(s16 *)(o + 0x56) = D_800A6270[1];
        *(s16 *)(o + 0x58) = 0;
        *(s16 *)(o + 0x5A) = D_800A62A4[1];
        break;
    case 1:
        r = D_80099D90;
        v[0] = ((s32 (*)(s16 *, s16 *, s32))func_800A5DE0)((s16 *)(o + 0x50), D_800A623C, 0);
        v[1] = ((s32 (*)(s16 *, s16 *, s32))func_800A5DE0)((s16 *)(o + 0x54), D_800A6270, 0);
        v[2] = ((s32 (*)(s16 *, s16 *, s32))func_800A5DE0)((s16 *)(o + 0x58), D_800A62A4, 0);
        for (; r->b[2] != 0; r++) {
            switch (r->b[1]) {
            case 1:
                r->b[4] = v[0];
                break;
            case 2:
                r->b[4] = v[1];
                break;
            case 3:
                r->b[4] = v[2];
                break;
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}

Obj *func_800A6040(void) {
    return func_80014504(func_800A5ED4, 0x5C, 0);
}

void func_800A606C(u8 *o, Obj **out) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *out = func_800A6040();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A60D0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A606C, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6BE4)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG630/nonmatchings/WSTAG630", func_800A612C);
