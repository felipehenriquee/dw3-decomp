#include "WSTAG306.h"
#include "m2c.h"
#include "WSTAG306_auto.h"
#include "WSTAG306_data.h"

s16 func_800A5DE0(s16 *st, s16 *tbl, s32 depth) {
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
        func_800A5DE0(st, tbl, depth + 1);
    }
    return e[0];
}

void func_800A5EB8(u8 *o) {
    Rec18 *r;
    Rec18 *q;
    s32 v;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        for (q = D_80099D90; q->b[2] != 0; q++) {
            if (q->b[1] == 1) {
                *(s16 *)(o + 0x58) = 0;
                *(s16 *)(o + 0x5A) = D_800A6738[1];
                *(Rec18 **)(o + 0x54) = q;
            }
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        r = *(Rec18 **)(o + 0x54);
        switch (*(s32 *)(o + 0x10)) {
        case 0:
        default:
            r->b[4] = 5;
            r->b[0] = 1;
            break;
        case 1:
            r->b[0] = 1;
            v = ((s32 (*)(s16 *, s16 *, s32))func_800A5DE0)((s16 *)(o + 0x54), D_800A6738, 0);
            if (v != 0xFF) {
                r->b[4] = v;
            } else {
                r->b[4] = 10;
                (*(void (**)(u8 *))(o + 0x3C))(o);
                ((void (*)(s32, s32))D_80055C50[0])(0xA0042FCB, *(s16 *)(o + 0x50));
            }
            break;
        case 2:
            r->b[0] = 1;
            r->b[4] = 10;
            break;
        }
        break;
    case 2:
    case 3:
        break;
    }
}

void func_800A6018(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x335)) {
        M2C_FIELD(arg0, s16 *, 0x50) = ((s16 (*)(M2C_UNK)) *D_80055C48)(0xA0042FCB);
        M2C_FIELD(arg0, s16 *, 0x58) = 0;
        M2C_FIELD(arg0, u16 *, 0x5A) = (u16) *D_800A673A;
        M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x2C)(arg0, 1);
    }
}

u8 *func_800A6084(s32 link) {
    return func_800143DC(func_800A5EB8, 0x5C, 0, link);
}

void func_800A60B4(u8 *o, Obj **w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        switch (D_8004B370[0]) {
        case 0x25:
            w[1] = func_800853F8(0x3A2);
            break;
        case 0x27:
            w[1] = func_800853F8(0x3D4);
            break;
        }
        if (D_8004B370[0] < 0x27) {
            w[0] = func_800A6084(0x353);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A6160(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A60B4, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6C18)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG306/nonmatchings/WSTAG306", func_800A61BC);
