#include "WSTAG455.h"
#include "m2c.h"
#include "WSTAG455_auto.h"
#include "WSTAG455_data.h"

s16 func_800A5DE4(s16 *st, s16 *tbl, s32 depth) {
    s16 *e = tbl + st[2] * 2;
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        st[3] -= dt;
    }
    if (st[3] <= 0) {
        st[2]++;
        e += 2;
        st[3] += e[1];
        if (e[0] == 0xFF) {
            return 0xFF;
        }
        func_800A5DE4(st, tbl, depth + 1);
    }
    return e[0];
}

void func_800A5EBC(u8 *o) {
    Rec18 *q;
    Rec18 *r;
    s32 v;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s16 *)(o + 0x54) = 0;
        *(s16 *)(o + 0x56) = D_800A6378[1];
        for (q = D_80099D90; q->b[2] != 0; q++) {
            if (q->b[1] == 1) {
                *(Rec18 **)(o + 0x50) = q;
            }
        }
        break;
    case 1:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s16 *)(o + 0x54) = 0;
            *(s16 *)(o + 0x56) = D_800A6378[1];
            (*(void (**)(u8 *, s32))(o + 0x2C))(o, 1);
            ((void (*)(s32))D_80055C48[0])(0x8004213E);
        }
        r = *(Rec18 **)(o + 0x50);
        v = ((s32 (*)(s16 *, s16 *, s32))func_800A5DE4)((s16 *)(o + 0x50), D_800A6378, 0);
        if (v == 0xFF) {
            r->b[0] = 0;
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
        } else {
            r->b[0] = 1;
            r->b[4] = v;
        }
        break;
    case 2:
    case 3:
        break;
    }
}

u8 *func_800A6010(s32 link) {
    return func_800143DC(func_800A5EBC, 0x58, 0, link);
}

void func_800A6040(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (D_8004B370[0] == 14 && ((s32 (*)(s32, s32))D_80048ACC[0])(0x800E, 1) != 0) {
            w[0] = func_800853F8(0x168);
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A60D4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6040, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A70DC)();
    return temp_v0;
}

void func_800A6130(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4007, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG455/nonmatchings/WSTAG455", func_800A615C);
