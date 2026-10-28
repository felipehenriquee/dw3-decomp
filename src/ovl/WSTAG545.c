#include "WSTAG545.h"
#include "m2c.h"
#include "WSTAG545_auto.h"
#include "WSTAG545_data.h"

s16 func_800A5E18(u8 *o, s16 *tbl, s32 depth) {
    s16 *e = tbl + *(s16 *)(o + 0x4) * 2;
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        *(s16 *)(o + 0x6) -= dt;
    }
    if (*(s16 *)(o + 0x6) <= 0) {
        *(s16 *)(o + 0x4) += 1;
        e += 2;
        *(s16 *)(o + 0x6) += e[1];
        if (e[0] == 0xFF) {
            *(s16 *)(o + 0x4) -= 1;
            e = tbl + *(s16 *)(o + 0x4) * 2;
            *(s16 *)(o + 0x6) += e[1];
        }
        func_800A5E18(o, tbl, depth + 1);
    }
    return e[0];
}

void func_800A5F20(u8 *o) {
    Rec18 *q;
    Rec18 *r;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s16 *)(o + 0x60) = 0;
        *(s16 *)(o + 0x62) = D_800A6D24[1];
        for (q = D_80099D90; q->b[2] != 0; q++) {
            if (q->b[1] == *(s32 *)(o + 0x58)) {
                *(Rec18 **)(o + 0x5C) = q;
                q->h[5] = *(s16 *)(o + 0x50);
                q->h[6] = *(s16 *)(o + 0x54);
            }
        }
        break;
    case 1:
        (*(Rec18 **)(o + 0x5C))->b[0] = 0;
        break;
    case 2:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s16 *)(o + 0x60) = 0;
            *(s16 *)(o + 0x62) = D_800A6D24[1];
            (*(void (**)(u8 *, s32))(o + 0x2C))(o, 1);
        }
        r = *(Rec18 **)(o + 0x5C);
        r->b[0] = 1;
        r->b[4] = func_800A5E18(o + 0x5C, D_800A6D24, 0);
        break;
    case 3:
        break;
    }
}

Obj *func_800A6054(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5F20, 0x64, 0);
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg2;
    return temp_v0;
}

s16 func_800A60AC(s16 *st, s16 *tbl, s32 depth) {
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
        func_800A60AC(st, tbl, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A6184);

void func_800A6304(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x35A)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

u8 *func_800A633C(s32 link) {
    return func_800143DC(func_800A6184, 0x58, 0, link);
}

s16 func_800A636C(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        if (once) {
            if (e[0] == 0xFF) {
                return 0xFF;
            }
        } else if (e[0] == 0xFF) {
            e = tbl;
            st[2] = 0;
            st[3] += e[1];
        }
        func_800A636C(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A648C);

void func_800A6780(u8 *arg, s32 ev) {
    u8 *o = arg;
    if (o == NULL) {
        return;
    }
    if (*(s32 *)(o + 0x54) == 0) {
        ((void (*)(s32))D_80055C48[0])(0x8004474A);
    }
    switch (ev) {
    case 0x35D:
        (*(void (**)(u8 *, s32))(o + 0x2C))(o, 1);
        break;
    case 0x35E:
        (*(void (**)(u8 *, s32))(o + 0x2C))(o, 3);
        break;
    case 0x35F:
        (*(void (**)(u8 *, s32))(o + 0x2C))(o, 5);
        break;
    case 0x360:
        *(s32 *)(o + 0x50) = 1;
        break;
    case 0x361:
        *(s32 *)(o + 0x50) = 2;
        break;
    case 0x362:
        *(s32 *)(o + 0x50) = 3;
        break;
    case 0x363:
        *(s32 *)(o + 0x50) = 4;
        break;
    case 0x364:
        *(s32 *)(o + 0x50) = 5;
        break;
    }
    (*(void (**)(u8 *, s32))(o + 0x30))(o, 0);
}

u8 *func_800A6894(s32 arg0) {
    return func_800143DC(func_800A648C, 96, 20, arg0);
}

void func_800A68C4(u8 *o, Obj **w) {
    u8 *f;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        f = (u8 *)&D_80048ABC;
        if ((*(s32 (**)(s32, s32))(f + 0x10))(0x4051, 0) != 0) {
            w[0] = func_800A633C(0x34F);
        }
        if (D_8004B370[0] == 0x1A && (*(s32 (**)(s32, s32))(f + 0x10))(0x4051, 1) != 0) {
            w[2] = func_800853F8(0x2C7);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A6984(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A68C4, 0x54, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7370)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A69E0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4051, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

void func_800A6A2C(void) {
    *D_8004B370 = 0x1B;
}

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A6A3C);
