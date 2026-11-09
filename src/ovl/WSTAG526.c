#include "WSTAG526.h"
#include "m2c.h"
#include "WSTAG526_auto.h"
#include "WSTAG526_data.h"

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A5DE0);

void func_800A5FF0(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x34B)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

u8 *func_800A6028(s32 arg0) {
    return func_800143DC(func_800A5DE0, 80, 48, arg0);
}

s16 func_800A6058(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A6058(st, tbl, once, depth + 1);
    }
    return e[0];
}

void func_800A6178(u8 *o) {
    Rec18 *r;
    u8 *p;
    u8 *q;
    s32 v;

    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *(s16 *)(o + 0x58) = 0;
        *(s16 *)(o + 0x5A) = D_800A76E8[1];
        *(s16 *)(o + 0x50) = 1;
        for (r = D_80099D90; r->b[2] != 0; r++) {
            if (r->b[1] == 0x15) {
                *(Rec18 **)(o + 0x54) = r;
            }
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        q = *(u8 **)(o + 0x54);
        if (*(s16 *)(o + 0x50) != 0) {
            q[0] = 1;
            q[4] = 2;
            q[9] = ((s32 (*)(u8 *, s16 *, s32, s32))func_800A6058)(o + 0x54, D_800A76E8, 0, 0);
        } else {
            q[0] = 0;
        }
        if (*(s16 *)(o + 0x50) == 2) {
            if (--*(s16 *)(o + 0x52) <= 0) {
                (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
            }
        }
        break;
    case 2:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s16 *)(o + 0x58) = 0;
            *(s16 *)(o + 0x5A) = D_800A76FC[1];
            (*(void (**)(u8 *, s32))(o + 0x2C))(o, 1);
        }
        p = *(u8 **)(o + 0x54);
        v = ((s32 (*)(u8 *, s16 *, s32, s32))func_800A6058)(o + 0x54, D_800A76FC, 1, 0);
        switch (v) {
        case 0x12C:
            p[0] = 0;
            break;
        case 0xFF:
            p[0] = 0;
            *(s16 *)(o + 0x50) = 0;
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 1);
            break;
        default:
            p[0] = 1;
            p[4] = 2;
            p[9] = v;
            break;
        }
        break;
    case 3:
        break;
    }
}

void func_800A6364(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s16 *, 0x52) = 0x96;
    }
}

u8 *func_800A6380(s32 link) {
    return func_800143DC(func_800A6178, 0x5C, 0, link);
}

Obj *func_800A63B0(void) {
    return func_80014504(func_800A6178, 0x5C, 0);
}

s16 func_800A63DC(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A63DC(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A64FC);

void func_800A67A4(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s16 *, 0x52) = 0x5A;
    }
}

u8 *func_800A67C0(s32 arg0) {
    return func_800143DC(func_800A64FC, 100, 0, arg0);
}

Obj *func_800A67F0(void) {
    return func_80014504(func_800A64FC, 0x64, 0);
}

s16 func_800A681C(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A681C(st, tbl, once, depth + 1);
    }
    return e[0];
}

void func_800A693C(u8 *o) {
    Rec18 *r;
    u8 *p;
    u8 *q;
    s32 v;

    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *(s16 *)(o + 0x50) = 1;
        for (r = D_80099D90; r->b[2] != 0; r++) {
            if (r->b[1] == 0x16) {
                *(Rec18 **)(o + 0x54) = r;
            }
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        q = *(u8 **)(o + 0x54);
        if (*(s16 *)(o + 0x50) != 0) {
            q[0] = 1;
            q[4] = 0x21;
        } else {
            q[0] = 0;
        }
        if (*(s16 *)(o + 0x50) == 2) {
            if (--*(s16 *)(o + 0x52) <= 0) {
                (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
            }
        }
        break;
    case 2:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s16 *)(o + 0x58) = 0;
            *(s16 *)(o + 0x5A) = D_800A7790[1];
            (*(void (**)(u8 *, s32))(o + 0x2C))(o, 1);
        }
        p = *(u8 **)(o + 0x54);
        v = ((s32 (*)(u8 *, s16 *, s32, s32))func_800A681C)(o + 0x54, D_800A7790, 1, 0);
        switch (v) {
        case 0x12C:
            p[0] = 0;
            break;
        case 0xFF:
            p[0] = 0;
            *(s16 *)(o + 0x50) = 0;
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 1);
            break;
        default:
            p[0] = 1;
            p[4] = v;
            p[9] = 0;
            break;
        }
        break;
    case 3:
        break;
    }
}

void func_800A6AF4(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s16 *, 0x52) = 0x28;
    }
}

u8 *func_800A6B10(s32 link) {
    return func_800143DC(func_800A693C, 0x5C, 0, link);
}

Obj *func_800A6B40(void) {
    return func_80014504(func_800A693C, 0x5C, 0);
}

s16 func_800A6B6C(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A6B6C(st, tbl, once, depth + 1);
    }
    return e[0];
}

s32 func_800A6C8C(void *arg0, s32 arg1) {
    s32 var_a1;
    s32 var_a2;

    var_a2 = M2C_FIELD(arg0, s16 *, 0x6C) - M2C_FIELD(arg0, s32 *, 0x5C);
    var_a1 = M2C_FIELD(arg0, s16 *, 0x6E) - M2C_FIELD(arg0, s32 *, 0x60);
    if (var_a2 < 0) {
        var_a2 = -var_a2;
    }
    if (var_a1 < 0) {
        var_a1 = -var_a1;
    }
    return arg1 < (var_a2 + var_a1);
}

s32 func_800A6CC8(s32 x, s32 y) {
    s32 r = 0;
    s32 t = 0;
    s32 q;
    s32 i;

    if (x <= 0 && y >= 0) q = 0;
    else if (x >= 0 && y >= 0) q = 0x40;
    else if (x >= 0 && y <= 0) q = 0x80;
    else if (x <= 0 && y <= 0) q = 0xC0;
    else q = 0;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if (x == y) return q | 0x20;
    if (y < x) t = (y * 0xFFFF) / x;
    else if (x < y) t = (x * 0xFFFF) / y;
    for (i = 0; i <= 32; i++) {
        if (t >= D_800A7874[i] && t <= D_800A7874[i + 1]) {
            switch (q) {
            case 0:
            case 0x80:
                if (y < x) r = i;
                else if (x < y) r = 0x40 - i;
                return r + q;
            case 0x40:
            case 0xC0:
                if (y < x) r = 0x40 - i;
                else if (x < y) r = i;
                return r + q;
            }
        }
    }
    return 0xFF;
}

void func_800A6E38(u8 *o) {
    s32 a, b;
    *(s16 *)(o + 0x70) += (*(s32 (**)(void))&D_8004DF9C)();
    if (*(s16 *)(o + 0x72) < *(s16 *)(o + 0x70)) {
        if (func_800A6C8C(o, 0x1E) != 0) {
            *(s16 *)(o + 0x76) = ((func_800A6CC8(*(s32 *)(o + 0x5C) - *(s16 *)(o + 0x6C), *(s32 *)(o + 0x60) - *(s16 *)(o + 0x6E)) - 0x40) * 0x10) & 0xFFF;
        } else {
            *(s16 *)(o + 0x76) = (((s32 (*)(void))D_8004DC0C[0])() & 0xFF) * 0x10;
        }
        *(s16 *)(o + 0x70) -= *(s16 *)(o + 0x72);
        *(s16 *)(o + 0x70) -= 7 - (((s32 (*)(void))D_8004DC0C[0])() & 0xF);
    }
    a = rsin(*(s16 *)(o + 0x76)) * *(s16 *)(o + 0x74) / 4096;
    b = rcos(*(s16 *)(o + 0x76)) * *(s16 *)(o + 0x74) / 4096;
    *(s32 *)(o + 0x64) += a;
    *(s32 *)(o + 0x68) += b;
    *(s16 *)(o + 0x6C) = *(s32 *)(o + 0x64) >> 8;
    *(s16 *)(o + 0x6E) = *(s32 *)(o + 0x68) >> 8;
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6FB4);

void func_800A734C(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s32 *, 0x58) = 0x3C;
    }
}

u8 *func_800A7368(s32 arg0) {
    return func_800143DC(func_800A6FB4, 136, 0, arg0);
}

Obj *func_800A7398(s8 arg0, s8 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6FB4, 0x88, 0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg2;
    M2C_FIELD(temp_v0, s8 *, 0x53) = arg1;
    M2C_FIELD(temp_v0, s8 *, 0x52) = arg0;
    return temp_v0;
}

void func_800A73F0(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        if (D_8004B370[0] < 30) {
            w[0] = func_800A6028(0x33D);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A7460(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A73F0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7F94)();
    return temp_v0;
}

void func_800A74BC(void) {
    *D_8004B370 = 0x1E;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x8011, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A74F4);
