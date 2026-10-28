#include "FIGHTSTG.h"
#include "m2c.h"
#include "FIGHTSTG_auto.h"
#include "FIGHTSTG_data.h"

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800832D0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800835F4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80083854);

void func_800839C0(u8 *o) {
    s32 i;
    Elem84 *e = *(Elem84 **)(o + 0x54);
    for (i = 0; i < *(s32 *)(o + 0x50); i++, e++) {
        e->b[0] = e->a[0];
        e->b[1] = e->a[1];
        e->b[2] = e->a[2];
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80083A54);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80083C30);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80083E0C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80084464);

void func_800844F8(u8 *o, s32 k, s32 v) {
    s32 i = 0;
    s32 off = i;
    u8 *e = *(u8 **)(o + 0x24) + k * 4;

    for (; i < 2; i++, off += 0xC) {
        if (*(s32 *)(*(u8 **)(o + 0x64) + off + 0x34) != 0 && k != 0) {
            *(s32 *)(*(u8 **)(e + 4) + 0x50) = v;
        }
    }
}

s32 func_80084554(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x7C);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80084560);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80084790);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800847C4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800847F4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80084A54);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80084BC0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80084E0C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80085000);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80085110);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80085958);

void func_80085F3C(u8 *o, s32 id, S32x8 *p) {
    u8 *e = ((u8 *(*)(s32))D_8004DF8C[0])(id);
    (*(void (**)(u8 *, void *, u8 *))(e + 0x150))(e, func_80085110, o);
    *(S32x8 *)(o + 0x84) = *p;
}

void func_80085FD4(u8 *o, s32 id, S32x8 *p) {
    u8 *e = ((u8 *(*)(s32))D_8004DF8C[0])(id);
    (*(void (**)(u8 *, void *, u8 *))(e + 0x150))(e, func_80085958, o);
    *(S32x8 *)(o + 0x84) = *p;
}

void func_8008606C(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        if (*(s32 *)(o + 0x78) != 0) {
            ((void (*)(s32))D_8004B5EC[0])(*(s32 *)(o + 0x78));
        }
        if (*(s32 *)(o + 0x7C) != 0) {
            ((void (*)(s32))D_8004B5EC[0])(*(s32 *)(o + 0x7C));
        }
        if (*(s32 *)(o + 0x80) != 0) {
            ((void (*)(s32))D_8004B5EC[0])(*(s32 *)(o + 0x80));
        }
        break;
    }
}

u8 *func_8008610C(s32 a, Pair32 p) {
    u8 *o = (u8 *)func_80014504(func_8008606C, 0xAC, 0);
    u8 *f = (u8 *)D_80044B38;
    *(s32 *)(o + 0x5C) = a;
    *(s32 *)(o + 0x60) = (*(s32 (**)(s32, s32))(f + 0x428))(0, a);
    *(s32 *)(o + 0x64) = (*(s32 (**)(s32, s32))(f + 0x428))(1, a);
    *(s32 *)(o + 0x68) = (*(s32 (**)(s32, s32))(f + 0x428))(2, a);
    *(s32 *)(o + 0x6C) = (*(s32 (**)(s32, s32))(f + 0x428))(5, a);
    *(Pair32 *)(o + 0x70) = p;
    *(void **)(o + 0xA4) = func_80085F3C;
    *(void **)(o + 0xA8) = func_80085FD4;
    return o;
}

void func_800861F4(u8 *o, u8 **w) {
    u8 c[8];
    u8 *f = (u8 *)D_800A469C;
    u8 *p;
    (*(void (**)(u8 *, u8 *, s32, u8 *))(f + 4))(o + 0xB4, o + 0xBC, *(s32 *)(o + 0xA4), o + 0xC4);
    c[0] = o[0xC4];
    c[1] = o[0xC6];
    c[2] = o[0xC8];
    (*(void (**)(u8 *, s32, u8 *))(*w + 0x262C))(*w, 1, c);
    (*(void (**)(u8 *, u8 *, s32, u8 *))(f + 4))(o + 0xCC, o + 0xD4, *(s32 *)(o + 0xA4), o + 0xDC);
    p = ((u8 *(*)(s32))D_8004DF8C[0])(0x1000);
    if (*(s32 *)(o + 0xDC) != 0 || *(s16 *)(o + 0xE0) != 0) {
        (*(void (**)(u8 *, s32, s32, s32))(p + 0x12C))(p, o[0xDC], o[0xDE], o[0xE0]);
    } else {
        (*(void (**)(u8 *, s32, s32, s32))(p + 0x12C))(p, 1, 1, 1);
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80086304);

void func_800868C0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x50);
    if (temp_v0 != arg1) {
        M2C_FIELD(arg0, s32 *, 0x54) = temp_v0;
        M2C_FIELD(arg0, s32 *, 0x50) = arg1;
        M2C_FIELD(arg0, s32 *, 0xB0) = arg2;
        M2C_FIELD(arg0, s32 *, 0xAC) = arg3;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

s32 func_80086904(void) {
    return (((s32 (*)()) D_8004DC0C)() % 27) + 1;
}

s16 func_8008695C(s32 arg0) {
    return M2C_FIELD(((arg0 * 0x58) + ((s32 (*)(M2C_UNK)) D_80044F4C)(0x1CB)), s16 *, 6);
}

u8 *func_800869A8(s32 a, s32 b) {
    u8 *o = func_800143DC(func_80086304, 0xEC, 4, 0x15);

    *(void **)(o + 0xE8) = func_800868C0;
    *(s32 *)(o + 0x50) = a;
    *(s32 *)(o + 0xAC) = b;
    return o;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80086A00);

void *func_80087000(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80086A00, 0x68, 0xC);
    M2C_FIELD(temp_v0, s32 *, 4) = arg0;
    if (arg1 != 0) {
        M2C_FIELD(temp_v0, s32 *, 8) = 0x10;
    } else {
        M2C_FIELD(temp_v0, s32 *, 8) = 0;
    }
    M2C_FIELD(temp_v0, s32 *, 0x64) = arg2;
    return temp_v0;
}

void func_80087070(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (((s32 (*)(void))D_8004B43C[0])() != 0) {
            ((void (*)(s32))D_80055D34[0])(0x209);
            D_80042B28[0] = func_80086904();
            w[0] = func_800A7A60();
        } else {
            ((void (*)(s32))D_80055D34[0])(0x208);
            w[0] = func_800A9FF0();
        }
        ((void (*)(s32))D_800A4548[0])(0);
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        ((void (*)(void))D_800A4544[0])();
        break;
    case 2:
    case 3:
        break;
    }
}

Obj *func_80087160(void) {
    return func_80014504(func_80087070, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008718C);

Obj *func_80087B84(void) {
    return func_80014504(func_8008718C, 0x6C, 0);
}

void func_80087BB0(void *arg0) {
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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087BF8);

s32 func_80087C3C(void *arg0) {
    s32 var_v1;
    void *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
loop_1:
    if (M2C_FIELD(var_a0, s32 *, 0x50) != 0) {
        var_v1 += 1;
        var_a0 += 0x4C;
        if (var_v1 >= 4) {
            return -1;
        }
        goto loop_1;
    }
    return var_v1;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087C70);

void func_80087D00(u8 *o, s32 a, s32 b, s32 c) {
    u8 **list = *(u8 ***)(o + 0x24);
    s32 k;
    Pair32 *p;
    u8 *slot;
    u8 *e;
    u8 **pp;
    func_80087C70(o);
    k = func_80087C3C(o);
    if (k == -1) {
        return;
    }
    p = ((Pair32 *(*)(s32))D_800A4570[0])(b);
    slot = o + (k * 76 + 0x50);
    pp = list + k;
    *pp = (u8 *)((s32 (*)(Pair32, Pair32, u8 *))func_80084790)(*p, D_800A2530[k], slot);
    ((void (*)(u8 *, s32))D_8004B600[0])(slot, 0x4C);
    e = o + k * 76;
    *(s32 *)(e + 0x50) = 1;
    *(s32 *)(e + 0x58) = 1;
    *(s32 *)(e + 0x64) = b;
    *(s32 *)(e + 0x54) = a;
    *(s32 *)(e + 0x84) = c;
    *(s32 *)(e + 0x8C) = 0;
    *(s32 *)(e + 0x88) = 0x1004;
}

u8 *func_80087E28(u8 *o, s32 id) {
    s32 i = func_80087BF8(o, id);

    if (i != -1) {
        return o + (i * 0x4C + 0x50);
    }
    return NULL;
}

void func_80087E7C(u8 *o, s32 id, s32 v) {
    func_80087C70(o, v);
    o += func_80087BF8(o, id) * 0x4C;
    *(s32 *)(o + 0x54) = v;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087EE4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087F38);

void func_80088024(u8 *o, s32 id, s32 v) {
    u8 *p = func_80087E28(o, id);

    if (p != NULL) {
        *(s32 *)(p + 0x18) = v;
    }
}

u8 *func_80088054(void) {
    u8 *o = (u8 *)func_800143DC(func_80087BB0, 0x19C, 0x20, 0x14);
    s32 i;
    for (i = 0; i < 4; i++) {
        *(s32 *)(o + i * 0x4C + 0x50) = 0;
    }
    *(void **)(o + 0x184) = func_80087D00;
    *(void **)(o + 0x190) = func_80087EE4;
    *(void **)(o + 0x180) = func_80087C70;
    *(void **)(o + 0x188) = func_80087E28;
    *(void **)(o + 0x18C) = func_80087E7C;
    *(void **)(o + 0x194) = func_80087F38;
    *(void **)(o + 0x198) = func_80088024;
    return o;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800880F0);

Obj *func_8008834C(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800880F0, 0x70, 8);
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg1;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80088394);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80088564);

Obj *func_80088C00(void) {
    return func_80014504(func_80088564, 0x80, 8);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80088C2C);

s32 func_80089148(u8 a) {
    u8 *t = D_800A4460;
    s32 r;
    s32 idx;
    s16 *p; u8 *e;
    idx = *(s32 *)(t + 0xC);
    t += 0x10; e = t + idx * 32;
    r = 0;
    p = ((s16 *(*)(s32))D_800A37FC[0])(*(s16 *)(e + 0x60));
    switch (a) {
    case 1:
        r = 1;
        break;
    case 2:
        r = p[5];
        break;
    case 3:
        r = p[6];
        break;
    case 4:
        r = -1;
        break;
    case 5:
        r = -2;
        break;
    case 6:
        r = -3;
        break;
    case 7:
        r = -4;
        break;
    case 8:
        r = -5;
        break;
    }
    return r;
}

void func_80089214(void) {
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008921C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800893DC);

u8 *func_8008966C(s32 a, S16x4 *p, s32 c, Pair32 *q, s32 e) {
    u8 *o = (u8 *)func_80014504(func_800893DC, 0x90, 0);
    *(s32 *)(o + 0x50) = a;
    *(S16x4 *)(o + 0x54) = *p;
    *(s32 *)(o + 0x5C) = c;
    *(Pair32 *)(o + 0x60) = *q;
    *(s32 *)(o + 0x68) = e;
    return o;
}

void func_8008970C(u8 *o, Obj **w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *(s32 *)(o + 0xA8) = 1;
        *(s32 *)(o + 0xAC) = 0x1004;
        *(s32 *)(o + 0x88) = 0;
        *(s32 *)(o + 0xB0) = 0;
        *(s16 *)(o + 0x90) = *(s16 *)(o + 0x5C);
        *(s16 *)(o + 0x92) = *(s16 *)(o + 0x5E);
        *(s16 *)(o + 0x94) = *(s16 *)(o + 0x60);
        *(s16 *)(o + 0x96) = *(s16 *)(o + 0x64);
        *(s16 *)(o + 0x98) = *(s16 *)(o + 0x66);
        *(s16 *)(o + 0x9A) = *(s16 *)(o + 0x68);
        w[0] = (Obj *)func_800847C4(*(s32 *)(o + 0x54), *(s32 *)(o + 0x58), *(s32 *)(o + 0x6C), *(s32 *)(o + 0x70), o + 0x74);
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        if (*(s32 *)(o + 0x84) != 0) {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
        }
        break;
    case 2:
    case 3:
        break;
    }
}

s32 func_800897F8(s32 id) {
    s32 *e = D_800A2550;

    while (e[0] != 0) {
        if (e[0] == id) {
            return ((s16 *)e)[3];
        }
        e += 3;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80089844);

s32 func_80089978(s32 id, s32 *a, s32 *b, Pair32 *c) {
    FtMap8 *p;
    for (p = D_800A2EA4; p->id != -1; p++) {
        if (p->id == id) {
            *a = D_800A2B74[p->idx].a;
            *b = D_800A2B74[p->idx].b;
            *c = D_800A2B74[p->idx].c;
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80089A24);

u8 *func_80089BE4(s32 id, S16x4 *p) {
    u8 *o = (u8 *)func_80014504(func_80089A24, 0x68, 0x78);
    FtMap8w *m;
    *(s32 *)(o + 0x50) = -1;
    for (m = (FtMap8w *)D_800A2EA4; m->id != -1; m++) {
        if (m->id == id) {
            *(s32 *)(o + 0x50) = id;
            *(s32 *)(o + 0x54) = m->idx;
            *(s32 *)(o + 0x58) = m->w;
            *(S16x4 *)(o + 0x5C) = *p;
        }
    }
    if (*(s32 *)(o + 0x50) == -1) {
        (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
    }
    return o;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80089CD8);

Obj *func_8008A7F4(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80089CD8, 0x74, 0x18);
    M2C_FIELD(temp_v0, s32 *, 4) = arg0;
    M2C_FIELD(temp_v0, s32 *, 8) = arg1;
    return temp_v0;
}

void func_8008A83C(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 1);
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    if (arg1 == 0) {
        M2C_FIELD(arg0, s32 *, 0x5C) = 0;
        M2C_FIELD(arg0, s32 *, 0x60) = (s32) (0xFF00 / arg2);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x5C) = 0xFF00;
    M2C_FIELD(arg0, s32 *, 0x60) = (s32) -(0xFF00 / arg2);
}

void func_8008A8C4(u8 *obj) {
    u8 *sys = D_8004DE10;
    u8 *o;
    u32 *ot;
    PolyF4 *p;
    DrMode *m;
    s32 c;

    o = (*(u8 *(**)(s32))(sys + 0x17C))(*(s32 *)(obj + 0x50));
    ot = (*(u32 *(**)(u8 *, s32))(o + 0x138))(o, *(s32 *)(obj + 0x54));
    p = (*(PolyF4 *(**)(void))(sys + 0x158))();
    ((u8 *)p)[3] = 5;
    p->code = 0x2A;
    m = (DrMode *)(p + 1);
    c = *(s32 *)(obj + 0x5C) >> 8;
    p->x0 = p->x2 = 0;
    p->y0 = p->y1 = 0;
    p->x1 = p->x3 = 320;
    p->y2 = p->y3 = 256;
    p->r0 = p->g0 = p->b0 = c;
    p->tag = (p->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    ((u8 *)m)[3] = 1;
    m->code[0] = 0xE1000245;
    m->tag = (m->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)m & 0xFFFFFF);
    (*(void (**)(void *))(sys + 0x15C))((u8 *)m + 8);
}

void func_8008AA08(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *(s32 *)(o + 0xC) = 1;
        break;
    case 1:
        if (*(s32 *)(o + 0x10) == 0) {
            break;
        }
        *(s32 *)(o + 0x5C) += *(s32 *)(o + 0x60);
        if (*(s32 *)(o + 0x58) == 0) {
            if (*(s32 *)(o + 0x5C) > 0xFF00) {
                *(s32 *)(o + 0x5C) = 0xFF00;
                *(s32 *)(o + 0xC) = 2;
            }
        } else if (*(s32 *)(o + 0x5C) < 0) {
            *(s32 *)(o + 0x5C) = 0;
            *(s32 *)(o + 0xC) = 2;
        }
    case 2:
        func_8008A8C4(o);
        break;
    case 3:
        break;
    }
}

Obj *func_8008AAAC(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008AA08, 0x68, 0);
    M2C_FIELD(temp_v0, void (**)(void *, s32, s32), 0x64) = func_8008A83C;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1006;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008AAF0);

void func_8008AE9C(u8 *o, Block3C *src) {
    *(Block3C *)(o + 0x54) = *src;
    (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008AF10);

s32 func_8008B06C(s32 arg0, s32 arg1) {
    return ((s32 (*)(M2C_UNK)) D_80044F4C)(0x1CB) + (arg1 * 0x58) + 0x18;
}

u8 *func_8008B0B8(s32 a) {
    u8 *o = func_800143DC(func_8008AAF0, 0x11C, 0, 0x13);

    *(void **)(o + 0x110) = func_8008AE9C;
    *(void **)(o + 0x114) = func_8008AF10;
    *(s32 *)(o + 0x50) = a;
    *(void **)(o + 0x118) = func_8008B06C;
    return o;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B118);

void func_8008B160(u8 *o, void *p, s32 i, s32 j) {
    struct {
        s16 x, y, w, h;
        s32 dx, dy;
    } m;
    u8 *e;
    m.x = (o + (i * 20 + j * 2))[0x6C] + *(s32 *)(o + 0x54);
    m.y = (o + (i * 20 + j * 2))[0x6D] + *(s32 *)(o + 0x58);
    e = o + i * 20;
    m.w = e[0x6A];
    m.h = e[0x6B];
    m.dx = e[0x68] + *(s32 *)(o + 0x54);
    m.dy = e[0x69] + *(s32 *)(o + 0x58);
    SetDrawMove(p, &m, m.dx, m.dy);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B200);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B508);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B630);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B66C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B674);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B67C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B684);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B68C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B694);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B69C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B7F4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008BC80);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008BEA8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C004);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C220);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C2CC);

void func_8008C454(u8 *o, u8 *w) {
    s16 *p;
    s32 a, b, k;
    p = *(s16 **)(o + 0x8C);
    a = *p++;
    *(s16 **)(o + 0x8C) = p;
    b = *p++;
    *(s16 **)(o + 0x8C) = p;
    if (a == 0x62) {
        k = *(s32 *)(o + 0x94);
        if (((FtArr58 *)o)->v[k] == 3) {
            a = 0x38;
        } else {
            a = *(s32 *)(o + 0x70);
        }
        *(s32 *)(o + 0x94) = k + 1;
    } else if (a == 0x63) {
        if (*(s32 *)(o + 0x64) == 3) {
            a = 0x38;
        } else {
            a = *(s32 *)(o + 0x70);
        }
        *(s32 *)(o + 0x94) += 1;
    }
    if (*(s32 *)(w + 0xC) == 0) {
        *(s32 *)(w + 0xC) = func_8009B774(a, b);
    }
}

/* comando de script: 0 cria (func_800930C0), 1 remove o objeto em *slot */
void func_8008C514(u8 *o, s32 *slot) {
    s16 *p = *(s16 **)(o + 0x8C);
    s32 op = *p++;
    s32 arg;

    *(s16 **)(o + 0x8C) = p;
    arg = *p++;
    *(s16 **)(o + 0x8C) = p;

    switch (op) {
    case 0:
        *slot = (s32)func_800930C0(arg);
        break;
    case 1:
        if (*slot != 0) {
            func_80093088((void *)*slot, arg);
        }
        break;
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C590);

Obj *func_8008C910(void) {
    return func_80014504(func_8008C590, 0xB4, 0x40);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C93C);

Obj *func_8008CB44(void) {
    return func_80014504(func_8008C93C, 0x54, 4);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008CB70);

void func_8008D37C(s8 arg0) {
    M2C_FIELD(func_80014504(func_8008CB70, 0x80, 4), s8 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008D3B4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008DAC0);

void func_8008EE4C(s32 arg0) {
    M2C_FIELD(func_80014504(func_8008DAC0, 0x80, 4), s32 *, 0x70) = arg0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008EE84);

Obj *func_8008F57C(s8 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008EE84, 0x8C, 4);
    M2C_FIELD(temp_v0, s8 *, 0x70) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x74) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x84) = arg2;
    return temp_v0;
}

void func_8008F5D4(s32 k, s32 slot) {
    FtE32d *tb = D_800A4470;
    Rec18 *r = &D_80042BCA[k];
    u8 *b;
    u8 *e;
    s32 i;
    s32 j;
    if (tb[slot].h0 == 0) {
        return;
    }
    i = 0;
    b = D_800A3868;
    for (; i < 6; i++) {
        j = (*(s32 (**)(s32, s32, s32))(b + 0xB0C))(D_800A3438[i], 0, slot);
        if (j >= 0) {
            *(s16 *)(b + j * 28) = 0;
        }
    }
    if (*(s16 *)&tb[slot].b[6] == 0) {
        func_800A6920(slot);
    }
    tb[slot].b[0x1A] = 0;
    *(s16 *)&tb[slot].b[6] = *(s16 *)&tb[slot].b[4];
    ((void (*)(s32, s32, s32, s32))D_800A4664[0])(0, slot, 1, r->b[0xC]);
    func_8009CC20(0, slot, 1, k);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008F714);

Obj *func_80090C44(s8 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008F714, 0x84, 4);
    M2C_FIELD(temp_v0, s8 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg1;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80090C8C);

Obj *func_80090E58(void) {
    return func_80014504(func_80090C8C, 0x70, 4);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80090E84);

Obj *func_800914EC(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80090E84, 0x80, 4);
    M2C_FIELD(temp_v0, s32 *, 0x74) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x78) = arg1;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80091534);

void func_80091B54(s8 arg0) {
    M2C_FIELD(func_80014504(func_80091534, 0x74, 4), s8 *, 0x50) = arg0;
}

void func_80091B8C(void *arg0) {
    void *temp_v0;

    RotMatrixYXZ_gte(arg0 + 0xCC, arg0 + 0x80);
    M2C_FIELD(arg0, s32 *, 0x7C) = 0;
    M2C_FIELD(arg0, void **, 0x74) = (void *) (arg0 + 0x7C);
    M2C_FIELD(arg0, s32 *, 0x94) = (s32) M2C_FIELD(arg0, s32 *, 0xD4);
    M2C_FIELD(arg0, s32 *, 0x98) = (s32) M2C_FIELD(arg0, s32 *, 0xD8);
    M2C_FIELD(arg0, s32 *, 0x9C) = (s32) M2C_FIELD(arg0, s32 *, 0xDC);
    GsSetRefView2(arg0 + 0x58);
    temp_v0 = ((void *(*)(M2C_UNK)) *D_8004DF8C)(0x1009);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, s32), 0x15C)(temp_v0, 1, M2C_FIELD(arg0, s32 *, 0x78));
    M2C_FIELD(arg0, s32 *, 0xE4) = (s32) (M2C_FIELD(arg0, s32 *, 0xE4) - 1);
}

void func_80091C1C(u8 *o) {
    u8 *p = ((u8 *(*)(s32))D_800A4570[0])(*(s32 *)(o + 0x50));
    s32 k = 6;
    s16 *e;
    s32 v;
    if (*(s32 *)(*(u8 **)(o + 0x54) + 0x18) != 0) {
        k = 7;
    }
    e = (s16 *)(p + k * 6);
    *(s32 *)(o + 0x58) = e[0xD];
    *(s32 *)(o + 0x5C) = -e[0xE];
    *(s32 *)(o + 0x60) = -e[0xF];
    *(s32 *)(o + 0x64) = e[0x31];
    *(s32 *)(o + 0x68) = -e[0x32];
    *(s32 *)(o + 0x6C) = -e[0x33];
    v = ((FtArrAA *)p)->a[k];
    *(s16 *)(o + 0xCC) = 0;
    *(s16 *)(o + 0xCE) = 0;
    *(s16 *)(o + 0xD0) = 0;
    *(s32 *)(o + 0xD4) = 0;
    *(s32 *)(o + 0xD8) = 0;
    *(s32 *)(o + 0xDC) = 0;
    *(s32 *)(o + 0x78) = v;
}

void func_80091CF4(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
    case 1:
        switch (*(s32 *)(o + 0x14)) {
        case 0:
        default:
            if (((s32 (*)(s32))D_8004DF8C[0])(0x1009) != 0) {
                func_80091C1C(o);
                *(s32 *)(o + 0xE4) = 2;
                (*(void (**)(u8 *))(o + 0x40))(o);
            }
            break;
        case 1:
            break;
        }
        if (*(s32 *)(o + 0xE4) != 0) {
            func_80091B8C(o);
        }
        break;
    case 2:
    case 3:
        break;
    }
}

Obj *func_80091DAC(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80091CF4, 0xE8, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg1;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80091DF4);

void func_80092244(u8 *o, Block34 *src) {
    *(Block34 *)(o + 0x54) = *src;
    *(s32 *)(o + 0xF0) = 0x1000;
    (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
}

void func_800922B4(u8 *o, Block34 *a, Block34 *b, s32 n) {
    if (a != NULL) {
        *(Block34 *)(o + 0xBC) = *a;
    } else {
        *(Block34 *)(o + 0xBC) = *(Block34 *)(o + 0x54);
    }
    *(Block34 *)(o + 0x88) = *b;
    *(s32 *)(o + 0xF4) = 0x100000 / n;
    *(s32 *)(o + 0xF0) = 0;
    (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800923B4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009257C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80092618);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80092684);

u8 *func_80092D50(void) {
    return func_800143DC(func_80092684, 108, 28, 14);
}

void func_80092D80(s32 arg0) {
    void *temp_v0;

    temp_v0 = ((void *(*)(M2C_UNK, M2C_UNK, M2C_UNK)) D_8004B7BC)(0xE, -1, -1);
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0xC) == 1)) {
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s32), 0x2C)(temp_v0, arg0);
    }
}

s32 func_80092DE4(void) {
    return M2C_FIELD(((void *(*)(M2C_UNK, M2C_UNK, M2C_UNK)) D_8004B7BC)(0xE, -1, -1), s32 *, 0x10) != 0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80092E18);

void func_80092F7C(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s32 *)(o + 0x54) = 0;
    case 1:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s32 *)(o + 0x54) += *(s32 *)(o + 0x50) * ((s32 (*)(void))D_8004DF9C[0])();
            if (*(s32 *)(o + 0x54) >= 0xFF) {
                *(s32 *)(o + 0x54) = 0xFF;
                (*(void (**)(u8 *))(o + 0x3C))(o);
            }
        }
        break;
    case 2:
        *(s32 *)(o + 0x54) -= *(s32 *)(o + 0x50) * ((s32 (*)(void))D_8004DF9C[0])();
        if (*(s32 *)(o + 0x54) < 0) {
            *(s32 *)(o + 0x54) = 0;
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
        }
        break;
    case 3:
        break;
    }
    func_80092E18(o);
}

void func_80093088(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) (0xFF / arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
}

Obj *func_800930C0(s32 n) {
    Obj *o = func_80014504(func_80092F7C, 0x58, 0);

    o->unk50 = 0xFF / n;
    return o;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093108);

void func_8009328C(FtLerp *o) {
    s32 s;
    if (o->on != 0) {
        o->t += ((s32 (*)(void))D_8004DF9C[0])();
        if (o->t >= o->dur) {
            o->on = 0;
            o->from = o->cur = o->to;
        } else {
            s = rsin((o->t << 10) / o->dur) * o->dur / 4096;
            o->cur = o->from + (o->to - o->from) * s / o->dur;
        }
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093364);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800934F0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093A74);

Obj *func_80093CC8(void) {
    return func_80014504(func_80093A74, 0x88, 0x14);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093CF4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093E44);

void func_80093F9C(s32 arg0, s32 *arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80093E44, 0x58, 0x1C);
    M2C_FIELD(temp_v0, s32 **, 0x54) = arg1;
    *arg1 = -1;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

void func_80093FEC(void) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        s32 unk78;
        void (*fn7C)(s32, s32);
        s32 unk80;
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;

    func_8001F648(&g);
    g.fn7C(0x1005, 0);
    g.fn74(0x200, 0);
    g.fn84((*(s32 (**)(s32))((u8 *)&D_80044F4C + 0x10))(0x4550000), 10, 0xF6, 0x4A);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094064);

Obj *func_8009426C(void) {
    return func_80014504(func_80094064, 0x58, 8);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094298);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094478);

/* cria o objeto ligado a *p, guardando o valor antigo */
Obj *func_8009482C(s32 *p) {
    Obj *o = func_80014504(func_80094478, 0x74, 0x1C);

    o->unk50 = (s32)p;
    o->unk54 = *p;
    *p = -1;
    return o;
}

void func_80094878(void) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;
    s32 t = ((s32 (*)(s32))D_80044F5C[0])(0x4550000);

    func_8001F648(&g);
    g.fn7C(0x1005, 1);
    g.fn74(0x200, 0);
    if (((s32 (*)(void))D_8004DF98)() & 0x10) {
        g.fn84(t, 0x1F, 0x18, 0xAB);
        g.fn84(t, 0x20, 0x48, 0xAB);
    }
}

void func_8009492C(s32 arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_s1 = ((s32 (*)(s32)) D_80044F4C)(*D_8005CCA8 + 0x7F);
    temp_v0 = func_8001AE38(0x1005, 3, 0x22, 0xAB);
    M2C_FIELD(arg1, s32 *, 4) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, s32, M2C_UNK), 0x114)(temp_v0, temp_s1, 0x11);
    temp_a0 = M2C_FIELD(arg1, s32 *, 4);
    M2C_FIELD(temp_a0, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_a0, 2);
    temp_v0_2 = func_8001AE38(0x1005, 3, 0x38, 0xAB);
    M2C_FIELD(arg1, s32 *, 8) = temp_v0_2;
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s32, s32, M2C_UNK), 0x114)(temp_v0_2, temp_s1, 0x12);
    temp_a0_2 = M2C_FIELD(arg1, s32 *, 8);
    M2C_FIELD(temp_a0_2, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_a0_2, 2);
}

void func_80094A00(void) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;
    u8 *f;
    s32 t;

    func_8001F648(&g);
    g.fn7C(0x1005, 1);
    f = (u8 *)D_80044B38;
    t = (*(s32 (**)(s32))(f + 0x424))(0x2860000);
    g.fn74(0x140, 0);
    g.fn84(t, 0x23, 0x18, 0x51);
    t = (*(s32 (**)(s32))(f + 0x424))(0x4550000);
    g.fn74(0x200, 0);
    g.fn84(t, 0x25, 0x10, 0x4A);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094AD0);

void func_80094C18(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;
    s32 i;
    s32 y;
    s32 t;
    s32 v;
    func_8001F648(&g);
    g.fn7C(0x1005, 1);
    t = ((s32 (*)(s32))D_80044F5C[0])(0x2860000);
    g.fn74(0x140, 0);
    for (i = 0, y = 0x51; i < 6; y += 14, i++) {
        v = *(s32 *)(o + i * 4 + 0xD4) & 0x1FFF;
        if (v != 0) {
            g.fn84(t, D_80042BDC[v - 1].b[4] + 0x37, 0x18, y);
        }
    }
    t = ((s32 (*)(s32))D_80044F5C[0])(0x4550000);
    g.fn74(0x200, 0);
    g.fn84(t, 0x26, 0x10, 0x4A);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094D50);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094F08);

Obj *func_800953E4(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80094F08, 0xEC, 0x60);
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg2;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009543C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009563C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800957B4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800959B0);

/* cria o objeto ligado a *p (marca -1 ate ele responder) */
Obj *func_80095E00(s32 *p) {
    Obj *o = func_80014504(func_800959B0, 0x390, 0x34);

    o->unk50 = (s32)p;
    *p = -1;
    return o;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80095E40);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80096048);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80096314);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800967A0);

/* cria o objeto ligado a *p (marca -1 ate ele responder) */
Obj *func_80096E88(s32 *p) {
    Obj *o = func_80014504(func_800967A0, 0xD8, 0x40);

    o->unk50 = (s32)p;
    *p = -1;
    return o;
}

s32 func_80096EC8(u8 *o, s32 k, s32 m) {
    u8 *t = D_80048D34;
    s32 h;
    u8 *q;
    s32 c;
    s32 n;
    s32 i;
    FtE32d *tb;
    (*(s32 (**)(s32))(t + 0x2718))(k);
    h = (*(s32 (**)(s32))(t + 0x2718))(m);
    tb = &D_800A4470[k];
    q = ((u8 *(*)(s32))D_8005CCA0[0])(tb->h0);
    c = q[0x3D];
    n = (*(s32 (**)(s32, u8 *))(t + 0x2738))(h, o + 0x7C);
    if (n <= 0 || c == 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (*(s16 *)(o + 0x7C + i * 2) == D_8003EF5C[c - 1].id) {
            return c;
        }
    }
    return 0;
}

void func_80096FE4(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;
    s32 t, i, y;

    func_8001F648(&g);
    g.fn7C(0x1005, 1);
    t = ((s32 (*)(s32))D_80044F5C[0])(0x4550000);
    g.fn74(0x200, 0);
    for (i = 0; i < *(s32 *)(o + 0x64); i++) {
        if (((s32 *)(o + 0x74))[i] != 0) {
            g.fn84(t, 0x30, 0x5A, i * 0x1F + 0x45);
        }
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800970C0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800972C8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80097498);

void func_80097984(s32 *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80097498, 0x88, 0x50);
    M2C_FIELD(temp_v0, s32 **, 0x50) = arg0;
    *arg0 = -1;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg2;
}

void func_800979E4(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;
    s32 t = ((s32 (*)(s32))D_80044F5C[0])(0x4550000);

    func_8001F648(&g);
    g.fn7C(0x1005, 1);
    g.fn74(0x200, 0);
    g.fn84(t, 0x2B, 0xA7, 0x8F);
    if (*(s32 *)(o + 0x7C) != 0) {
        g.fn84(t, 2, 0xA7, 0xB8);
        g.fn84(t, 0x29, 0xA3, 0x21);
    }
}

void func_80097AB0(s32 a, u8 **w) {
    s32 i;
    for (i = 0; i < 4; i++) {
        w[i + 4] = (u8 *)func_8001AE38(0x1005, 1, 0xBB, (s16)(i * 19 + 0x92));
    }
    w[12] = (u8 *)func_8001AE38(0x1005, 1, 0xAB, 0x92);
    w[8] = (u8 *)func_8001AE38(0x1005, 1, 0xBB, 0xA5);
    w[9] = (u8 *)func_8001AE38(0x1005, 1, 0xBB, 0xB8);
    w[10] = (u8 *)func_8001AE38(0x1005, 3, 0x10E, 0xBA);
    w[11] = (u8 *)func_8001AE38(0x1005, 3, 0x133, 0xBA);
    for (i = 0; i < 4; i++) {
        w[i + 13] = (u8 *)func_8001AE38(0x1005, 3, *(s16 *)(D_800A35D4 + i * 4), 0x39);
    }
}

void func_80097BD8(u8 *o, u8 **w, s32 on) {
    u8 *t;
    u8 *x;
    u8 *p;
    s32 v;
    s32 i;
    if (on != 0) {
        for (i = 0; i < *(s32 *)(o + 0x70); i++) {
            p = ((u8 *(*)(s32))D_8005CCA0[0])(*(s16 *)(o + 0x68 + i * 2));
            if (p != NULL) {
                t = (u8 *)D_80044B38;
                v = (*(s32 (**)(s32))(t + 0x414))(D_8005CCA8[0] + 0x4E);
                x = w[i + 4];
                (*(void (**)(u8 *, s32, s32))(x + 0x114))(x, v, p[0x55]);
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            x = w[i + 4];
            if (x != NULL) {
                (*(void (**)(u8 *, s32))(x + 0x144))(x, (u8)on);
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80097CFC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800980E4);

void *func_80098884(s32 *arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800980E4, 0x84, 0x44);
    M2C_FIELD(temp_v0, s32 **, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = (s32) *arg0;
    M2C_FIELD(temp_v0, s32 *, 0x60) = ((s32 (*)(s32)) *D_8004B44C)(*arg0);
    *arg0 = -1;
    return temp_v0;
}

void func_800988FC(s32 arg0, s32 arg1) {
    M2C_FIELD(func_80098884(arg0), s32 *, 0x80) = arg1;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098924);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098A84);

void func_80098C9C(u8 *o, s32 a) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        func_80098924(o);
        func_80098A84(o, a);
        break;
    case 2:
    case 3:
        break;
    }
}

void func_80098D14(s32 a, u8 **w, s32 c, s32 d) {
    u8 *t;
    s16 *p;
    s32 v;
    FtE32d *e;
    if (c == 0) {
        t = D_80048D34;
        v = (*(s32 (**)(s32))(t + 0x2750))((*(s32 (**)(s32))(t + 0x2718))(d));
        (*(void (**)(u8 *, s32, s32, s32))(*w + 0x120))(*w, v, -1, 1);
    } else {
        e = &D_800A44D0[d];
        p = ((s16 *(*)(s32))D_800A37FC[0])(e->h0);
        v = ((s32 (*)(s32))D_80044F4C)(D_8005CCA8[0] + 0x4E);
        (*(void (**)(u8 *, s32, s32, s32))(*w + 0x120))(*w, v, p[3], 1);
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098DE0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098E9C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098F08);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098F74);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098FE0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80099048);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800990A0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800990E8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80099140);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80099588);

void func_8009A254(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 4;
    M2C_FIELD(arg0, s32 *, 0x98) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = ((s32 (*)()) D_8004DF98)();
}

Obj *func_8009A298(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80098C9C, 0xB4, 8);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xAC) = func_80099588;
    M2C_FIELD(temp_v0, void (**)(void *), 0xB0) = func_8009A254;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009A2DC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009A3B4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009A514);

void func_8009A6BC(s32 unused, u8 *w, s32 flag) {
    u8 *d;

    if (flag == 0) {
        d = D_80048D34;
        (*(void (**)(u8 *, s32, s32, s32))(*(u8 **)(w + 4) + 0x120))(*(u8 **)(w + 4),
            (*(s32 (**)(s32))(d + 0x2750))((*(s32 (**)(s32))(d + 0x2718))(D_800A4468)), -1, 1);
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009A734);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009A898);

void func_8009AB74(s32 *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8009A898, 0xC4, 0x1C);
    M2C_FIELD(temp_v0, s32 **, 0x58) = arg0;
    *arg0 = -1;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x60) = arg2;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009ABD8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009ADD4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009AF4C);

Obj *func_8009B0C8(Block32 *src) {
    Obj *o = func_80014504(func_8009AF4C, 0xA8, 0);

    *(Block32 *)((u8 *)o + 0x58) = *src;
    return o;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B13C);

void func_8009B460(void *arg0, s32 arg1, s32 arg2) {
    void *temp_s0;
    void *temp_v0;

    temp_v0 = func_80014504(func_8009B13C, 0x70, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg1;
    M2C_FIELD(temp_v0, void **, 0x5C) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0x64) = (s32) M2C_FIELD(arg0, s16 *, 0x1E);
    temp_s0 = ((arg1 - 1) * 8) + D_800A365C;
    M2C_FIELD(temp_v0, s32 *, 0x60) = (s32) M2C_FIELD(temp_s0, s32 *, 0);
    M2C_FIELD(temp_v0, s32 *, 0x68) = (s32) M2C_FIELD(temp_s0, s32 *, 4);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B4EC);

u8 *func_8009B650(u8 *a, S16x3 *b, s32 n) {
    u8 *o = (u8 *)func_80014504(func_8009B4EC, 0x68, 0);
    *(u8 **)(o + 0x50) = a;
    *(S16x3 *)(o + 0x5A) = *b;
    *(S16x3 *)(o + 0x54) = *(S16x3 *)(a + 0x1C);
    *(s32 *)(o + 0x60) = 0;
    *(s32 *)(o + 0x64) = 0x1000 / n;
    return o;
}

void func_8009B6E4(void *arg0) {
    s32 temp_v1;
    s32 temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0xC);
    if (temp_v1 >= 0) {
        if (temp_v1 >= 2) {
            if (temp_v1 >= 4) {
                goto block_3;
            }
        } else {
            goto block_4;
        }
    } else {
block_3:
block_4:
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x58) - D_800A4464;
        M2C_FIELD(arg0, s32 *, 0x58) = temp_v1_2;
        if (temp_v1_2 <= 0) {
            ((M2C_UNK (*)(s32, s16)) D_80055C50)(M2C_FIELD(arg0, s32 *, 0x50), M2C_FIELD(arg0, s16 *, 0x54));
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 3);
        }
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B774);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B864);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B8D0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B930);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B9D0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009BA4C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009BBA8);

s8 func_8009BC14(s8 a) {
    u8 *d = D_800A3868;
    s8 r;

    d[0xAF2] = a;
    r = func_8009BBA8(0);
    d[0xAF3] = r;
    return r;
}

s8 func_8009BC54(void) {
    u8 *d = D_800A3868;
    s8 r = func_8009BBA8(((s8 *)d)[0xAF3] + 1);

    d[0xAF3] = r;
    return r;
}

s32 func_8009BC94(s32 a, u8 b, s32 c) {
    u8 *d = D_800A3868;
    u8 *e;
    d[0xAF2] = a;
    d[0xAF3] = func_8009BBA8(0);
    while (*(s8 *)(d + 0xAF3) >= 0) {
        if (((FtEnt28 *)d)[*(s8 *)(d + 0xAF3)].f4 == b && ((FtEnt28 *)d)[*(s8 *)(d + 0xAF3)].f8 == c) {
            break;
        }
        d[0xAF3] = func_8009BBA8(*(s8 *)(d + 0xAF3) + 1);
    }
    return D_800A435B;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009BD44);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009BDA4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C330);

void func_8009C4BC(s32 arg0) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 2;
    M2C_FIELD(&D_800A4780, s32 *, 4) = arg0;
    M2C_FIELD(&D_800A4780, s32 *, 8) = -1;
    func_8009B930(&D_800A4780);
}

void func_8009C4F8(s32 arg0) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 3;
    M2C_FIELD(&D_800A4780, s32 *, 4) = arg0;
    M2C_FIELD(&D_800A4780, s32 *, 8) = -1;
    func_8009B930(&D_800A4780);
}

void func_8009C534(u8 arg0) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 1;
    M2C_FIELD(&D_800A4780, s32 *, 4) = 1;
    M2C_FIELD(&D_800A4780, s32 *, 8) = -1;
    *D_800A435C = arg0;
    func_8009B9D0(&D_800A4780);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C578);

void func_8009C5E8(u8 a) {
    s32 k = a != 0;
    s32 i = func_8009BC94(5, a, k);
    s32 v = func_8009BDA4(a, 2);
    s32 *m;
    u8 *e;
    u8 *t;
    if (i >= 0) {
        e = D_800A3868 + i * 28;
        *(s16 *)(e + 2) = v;
    } else {
        m = &D_800A4780;
        m[0] = 5;
        t = D_800A4460;
        m[1] = v;
        m[2] = a;
        m[3] = *(s32 *)(t + k * 4 + 8);
        m[4] = 0xBD;
        func_8009B930(m);
    }
}

void func_8009C6A4(u8 a, s32 b, s32 c) {
    s32 i = func_8009BC94(6, a, b);
    s32 *m;
    u8 *e;
    if (i >= 0) {
        e = D_800A3868 + i * 28;
        *(s32 *)(e + 0xC) = 0xBD;
    } else {
        m = &D_800A4780;
        m[0] = 6;
        m[1] = 1000;
        m[2] = a;
        m[3] = b;
        m[4] = c;
        func_8009B930(m);
    }
}

void func_8009C740(s32 v) {
    u8 *d = D_800A3868;
    s32 i;
    s32 *m;

    d[0xAF2] = 7;
    i = func_8009BBA8(0);
    if (v > 0x7FFF) {
        v = 0x7FFF;
    }
    if (i >= 0) {
        *(s16 *)(d + i * 28 + 2) = v;
    } else {
        m = &D_800A4780;
        m[0] = 7;
        m[1] = v;
        m[2] = -1;
        func_8009B930(m);
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C7D4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C8B0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C9C0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009CB10);

void func_8009CC20(u8 a, s32 b, s32 k, s32 flag) {
    s32 i = func_8009BC94(D_800A43E0[k], a, b);
    s32 v;
    s32 *m;
    u8 *e;
    if (flag != 0) {
        v = func_8009BDA4(a, 12);
    } else {
        v = func_8009BDA4(a, 8);
    }
    if (i >= 0) {
        e = D_800A3868; *(s16 *)(e + i * 28 + 2) = v;
    } else {
        m = &D_800A4780;
        m[0] = D_800A43E0[k];
        m[1] = v;
        m[2] = a;
        m[3] = b;
        m[4] = k;
        func_8009B930(m);
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009CD1C);

void func_8009CE84(s32 v) {
    s32 *d = &D_800A4780;

    d[0] = 8;
    d[1] = 0x7FFF;
    d[2] = 0;
    d[3] = D_800A4468;
    d[4] = v;
    func_8009B930(d);
}

void func_8009CED0(void) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 0x12;
    M2C_FIELD(&D_800A4780, s32 *, 4) = 0;
    func_8009B930(&D_800A4780);
}

void func_8009CF00(s32 arg0) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 0x13;
    M2C_FIELD(&D_800A4780, s32 *, 4) = func_8009BDA4(0, arg0 + 3);
    M2C_FIELD(&D_800A4780, s32 *, 8) = 0;
    M2C_FIELD(&D_800A4780, s32 *, 0xC) = (s32) D_800A4468;
    func_8009B930(&D_800A4780);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009CF54);

void func_8009CFB0(void) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 0x15;
    M2C_FIELD(&D_800A4780, s32 *, 4) = 1;
    M2C_FIELD(&D_800A4780, s32 *, 8) = 0;
    M2C_FIELD(&D_800A4780, s32 *, 0xC) = (s32) D_800A4468;
    func_8009B9D0(&D_800A4780);
}

void func_8009CFF4(void) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 0x16;
    M2C_FIELD(&D_800A4780, s32 *, 4) = 1;
    M2C_FIELD(&D_800A4780, s32 *, 8) = 0;
    M2C_FIELD(&D_800A4780, s32 *, 0xC) = (s32) D_800A4468;
    func_8009B9D0(&D_800A4780);
}

void func_8009D038(void) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 0x17;
    M2C_FIELD(&D_800A4780, s32 *, 4) = 1;
    func_8009B9D0(&D_800A4780);
}

void func_8009D06C(void) {
    s32 *d = &D_800A4780;
    u8 *p;
    u8 *f;

    d[0] = 0x18;
    d[1] = 0xBB8;
    func_8009B930(d);
    p = ((u8 *(*)(s32))D_800A37FC[0])(0x1D3);
    f = D_800A4460;
    f[0xDB] = 1;
    *(s16 *)(f + 0x82) = -*(s16 *)(p + 0x10) >> 1;
    *(s16 *)(f + 0x86) = -*(s16 *)(p + 0x12) >> 1;
}

/* marca o slot livre (de 28 bytes) devolvido pela rotina 0xB04 */
void func_8009D0EC(void) {
    u8 *d = D_800A3868;
    s32 i = (*(s32 (**)(s32))(d + 0xB04))(0x18);

    if (i >= 0) {
        *(s16 *)(d + i * 28 + 2) = 1;
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D140);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D1DC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D2C4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D3AC);

void func_8009D470(void) {
    u8 *d = D_800A43F4;

    if (((s32 (*)(s32, s32))D_800A4634[0])(d[0x20], *(s32 *)(d + 0x24)) != 0) {
        d[0x3E] = 1;
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D4B8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D61C);

void func_8009D72C(void) {
    u8 *d = D_800A43F4;
    Rec18 *r = &D_80042BCA[*(s32 *)(d + 0x24)];
    u8 v = r->b[0xA];

    d[v + 0x38] = v;
}

void func_8009D768(void) {
    u8 *d = D_800A43F4;
    Rec18 *r = &D_80042BCA[*(s32 *)(d + 0x24)];
    u8 v = r->b[0xA];

    d[v + 0x38] = v;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D7A4);

void func_8009D858(void) {
    u8 *s = D_800A43F4; s32 *q;
    s32 m = 0x10;
    s32 *t;
    u8 c;
    u8 k;
    Rec18 *r;
    c = s[0x20];
    k = c != 0;
    if (k || D_80042B62[0] == 0) {
        q = (s32 *)D_800A4460; t = q + (1 - k);
        r = &D_80042BCA[*(s32 *)(s + 0x24)];
        ((void (*)(s32, s32, s32, s32))D_800A4664[0])((u8)(m - c), t[2], 0, -r->b[0xC]);
        func_8009CC20((u8)(m - s[0x20]), t[2], 0, *(s32 *)(s + 0x24));
        s[r->b[0xA] + 0x38] = r->b[0xC];
    }
}

void func_8009D944(void) {
    u8 *s = D_800A43F4;
    s32 m = 0x10;
    s32 *t;
    u8 c;
    s32 k;
    Rec18 *r;
    c = s[0x20];
    k = (c == 0) & 1;
    t = (s32 *)D_800A4460 + k;
    r = &D_80042BCA[*(s32 *)(s + 0x24)];
    ((void (*)(s32, s32, s32, s32))D_800A4664[0])((u8)(m - c), t[2], 1, -r->b[0xC]);
    func_8009CC20((u8)(m - s[0x20]), t[2], 1, *(s32 *)(s + 0x24));
    s[r->b[0xA] + 0x38] = r->b[0xC];
}

void func_8009DA0C(void) {
    u8 *t = D_800A4460;
    u8 *s;
    u8 *e;
    s32 idx;
    Rec18 *r;
    idx = *(s32 *)(t + 8);
    t += 0x10;
    e = t + idx * 32;
    s = D_800A43F4;
    r = &D_80042BCA[*(s32 *)(s + 0x24)];
    if (*(s16 *)(e + 0xC) != 0) {
        *(s32 *)(s + 0x2C) = *(s16 *)(e + 0xA) * r->b[0xC] / 128;
        if (*(s16 *)(e + 0xC) < *(s32 *)(s + 0x2C)) {
            *(s32 *)(s + 0x2C) = *(s16 *)(e + 0xC);
        }
        s[r->b[0xA] + 0x38] = s[0x2C];
    }
}

void func_8009DAAC(void) {
    s32 k;
    u8 *s;
    u8 *t;
    u8 *p;
    Rec18 *r;
    k = ((s32 (*)(void))D_8004DC0C)() % 2;
    s = D_800A43F4;
    if (((s32 (*)(s32, s32))D_800A4644[0])(s[0x20], *(s32 *)(s + 0x24)) != 0) {
        r = &D_80042BCA[*(s32 *)(s + 0x24)];
        t = D_80048D34;
        p = (*(u8 *(**)(s32))(t + 0x2750))((*(s32 (**)(s32))(t + 0x2718))(D_800A4468));
        ((FtArr42 *)p)->a[k] += r->b[0xC];
        s[r->b[0xA] + 0x38] = 1 << k;
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DB94);

void func_8009DC8C(void) {
    u8 *s = D_800A43F4;
    u8 *t;
    Rec18 *r;
    u8 *p;
    s32 i;
    r = &D_80042BCA[*(s32 *)(s + 0x24)];
    t = D_80048D34;
    p = (*(u8 *(**)(s32))(t + 0x2750))((*(s32 (**)(s32))(t + 0x2718))(D_800A4468));
    if (((s32 (*)(s32, s32))D_800A4644[0])(s[0x20], *(s32 *)(s + 0x24)) != 0) {
        for (i = 0; i < 3; i++) {
            *(s16 *)(p + i * 2 + 0x42) += r->b[0xC];
        }
        D_800A43F4[r->b[0xA] + 0x38] = 7;
    }
}

void func_8009DD64(void) {
    s32 (*f)(s32, s32) = (s32 (*)(s32, s32))D_800A4648[0];
    u8 *d = D_800A43F4;

    if (f(d[0x20], *(s32 *)(d + 0x24)) != 0) {
        Rec18 *r = &D_80042BCA[*(s32 *)(d + 0x24)];
        d[r->b[0xA] + 0x38] = 1;
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DDD8);

void func_8009DEBC(void) {
    u8 *s;
    u8 *f;
    u8 *q;
    Rec18 *r;
    if (D_800A4536 == 2) {
        q = D_800A43F4;
        r = &D_80042BCA[*(s32 *)(q + 0x24)];
        q[r->b[0xA] + 0x38] = 1;
    } else {
        s = D_800A43F4;
        f = D_800A4580;
        s[0x30] = (*(s32 (**)(s32, s32))(f + 0x9C))(s[0x20], *(s32 *)(s + 0x24));
        *(s16 *)(s + 0x36) += 1;
        *(s32 *)(s + 0x28) = (*(s32 (**)(s32, s32))(f + 0x84))(s[0x20], *(s32 *)(s + 0x24));
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DF78);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E0CC);

void func_8009E428(void) {
    u8 *p = (u8 *)D_800A453C;
    u8 *q;
    s32 v;
    switch (*(s32 *)p) {
    case 0:
    default:
        *(s32 *)(p - 0xD8) = ((s32 (*)(void))D_8004DF9C[0])();
        break;
    case 1:
        *(s32 *)(p - 0xD8) = 0;
        break;
    case 2:
        v = ((s32 (*)(void))D_8004DF9C[0])();
        q = p - 0xDC;
        *(s32 *)(q + 4) = 0;
        *(s32 *)(p + 4) += v;
        while (*(s32 *)(p + 4) >= 5) {
            *(s32 *)(q + 4) += 1;
            *(s32 *)(p + 4) -= 4;
        }
        break;
    case 3:
        *(s32 *)(p - 0xD8) = ((s32 (*)(void))D_8004DF9C[0])() * 2;
        break;
    }
}

void func_8009E510(s32 v) {
    u8 *p = D_800A4460;

    *(s32 *)(p + 0xDC) = v;
    *(s32 *)(p + 0xE0) = 0;
    func_8009E428();
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E53C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E77C);

s32 func_8009E950(s32 a, s32 b, s32 c, s32 d) {
    return func_8009E77C(a, b, c, d, 0);
}

s32 func_8009E970(s32 a, s32 b, s32 c, s32 d) {
    return func_8009E77C(a, b, c, d, 1);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E994);

void func_8009EADC(s32 i) {
    u8 *b = ((u8 *(*)(s32))D_80044F4C)(0x1CC);
    FtCard4 *e = (FtCard4 *)(b + *(s32 *)(b + 4)) + i;
    u8 *ta = b + *(s32 *)(b + 8);
    u8 *tb = b + *(s32 *)(b + 0xC);
    FtCardCur *d = &D_800A4558;
    s32 idx;
    d->id = e->id;
    idx = e->idx;
    d->idx = idx;
    d->kind = e->kind;
    d->isB = e->kind >= 0x3A;
    if (d->isB == 0) {
        d->p14 = d->p10 = ta + idx * 0xC4;
    } else {
        d->p14 = d->p10 = tb + idx * 72;
    }
}

u8 *func_8009EB94(s32 id) {
    u8 *b = ((u8 *(*)(s32))D_80044F4C)(0x1CC);

    return (u8 *)((*(s32 *)((u8 *)func_8009E994(id) + 0xC) - *(s32 *)b) + (s32)b);
}

void func_8009EBE0(s32 m, s32 *pmin, s32 *pmax) {
    u8 *b = ((u8 *(*)(s32))D_80044F4C)(0x1CC);
    u8 *p = b + *(s32 *)(b + 4);
    s32 mn = 0xFF;
    s32 mx = 0;
    s32 i = 0;
    s32 t;
    for (; *(s16 *)p != 0; p += 4, i++) {
        t = p[3] >= 0x3A;
        if (t == m) {
            if (i < mn) {
                mn = i;
            }
            if (mx < i) {
                mx = i;
            }
        }
    }
    *pmin = mn;
    *pmax = mx;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009EC94);

s32 func_8009F644(s32 a, s32 i) {
    if (D_800A4530.n < 2) {
        return 0;
    }
    if (i == D_800A4530.n) {
        return a * D_800A4530.k / 128;
    }
    if (D_800A4670[i] == D_800A4530.n) {
        return -(a * D_800A4530.k / 256);
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009F6DC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009F97C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009FAB4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009FE1C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009FF40);

s32 func_800A0108(u8 side, s32 k) {
    Rec18 *r;
    s16 *m;
    s32 v;
    if (side == 0) {
        func_8009EC94(0, 1, D_800A4468);
    } else {
        func_8009EC94(0x10, 1, D_800A446C);
    }
    m = &D_800A4588;
    r = &D_80042BCA[k];
    v = r->h[1] * 64 + *m * r->h[1] / 8;
    if (v >= 10000) {
        v = 9999;
    }
    return v;
}

s32 func_800A01AC(u8 side, s32 k, s32 crit) {
    u8 *e;
    s32 m;
    s32 v;
    if (side == 0) {
        e = (u8 *)&D_800A4470[k];
    } else {
        e = (u8 *)&D_800A44D0[k];
    }
    if (crit != 0) {
        m = ((s32 (*)(void))D_8004DC0C)() % 9 + 8;
        m = *(s16 *)(e + 6) * m;
    } else {
        m = ((s32 (*)(void))D_8004DC0C)() % 5 + 4;
        m = *(s16 *)(e + 6) * *&m;
    }
    v = m / 128;
    if (v >= 10000) {
        v = 9999;
    }
    return v;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A02AC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0514);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A06AC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A08C8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0A18);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0B98);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0D00);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0E68);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0FAC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1114);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1308);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A13C0);

s32 func_800A1458(s32 unused, s32 k) {
    Rec18 *r;
    u8 *t = D_800A4460;
    s32 lim;
    u8 *s;
    func_8009EC94(0, 0, *(s32 *)(t + 8));
    func_8009EC94(0x10, 1, *(s32 *)(t + 0xC));
    s = D_800A4580;
    r = &D_80042BCA[k];
    lim = r->b[0xB] + (*(s16 *)(s + 8) - *(s16 *)(s + 0x48)) / 8;
    return (((s32 (*)(void))D_8004DC0C)() & 0x7F) < lim;
}

/* sorteio: (rand & 0x7F) < chance da entrada k */
s32 func_800A1508(s32 unused, s32 k) {
    Rec18 *r = &D_80042BCA[k];
    s32 c = r->b[0xB];

    return (((s32 (*)(void))D_8004DC0C)() & 0x7F) < c;
}

/* sorteio: (rand & 0x7F) < chance da entrada k */
s32 func_800A1558(s32 unused, s32 k) {
    Rec18 *r = &D_80042BCA[k];
    s32 c = r->b[0xB];

    return (((s32 (*)(void))D_8004DC0C)() & 0x7F) < c;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A15A8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1608);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A17C8);

s32 func_800A1910(u8 side) {
    u8 *s;
    u8 *t;
    s32 k, lim;
    if (side == 0) {
        func_8009EC94(0, 0, D_800A4468);
    } else {
        func_8009EC94(0x10, 0, D_800A446C);
    }
    s = D_800A45C0;
    k = side != 0;
    t = D_800A4460;
    lim = *(u8 *)(t + (k * 3 + *(s32 *)(t + k * 4 + 8)) * 32 + 0x2F) - (*(s16 *)(s + 0x1E) + *(s16 *)(s + 0x12)) / 8;
    return (((s32 (*)(void))D_8004DC0C)() & 0x7F) < lim;
}

s32 func_800A19D8(u8 side) {
    u8 *s;
    u8 *t;
    s32 k, lim;
    if (side == 0) {
        func_8009EC94(0, 0, D_800A4468);
    } else {
        func_8009EC94(0x10, 0, D_800A446C);
    }
    s = D_800A45C0;
    k = side != 0;
    t = D_800A4460;
    lim = *(u8 *)(t + (k * 3 + *(s32 *)(t + k * 4 + 8)) * 32 + 0x2D) - (*(s16 *)(s + 0x1C) + *(s16 *)(s + 0x14)) / 8;
    if (lim < 0x20) {
        lim = 0x20;
    }
    return (((s32 (*)(void))D_8004DC0C)() & 0x7F) < lim;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1AA8);

s32 func_800A1C18(s32 x) {
    u8 *t = D_800A4460;
    s32 idx = *(s32 *)(t + 8);
    s32 r;
    s32 q;
    u8 *f;
    u8 *p;
    s32 i;
    s16 h;
    t = t - -(idx * 32);
    q = x * 100 / *(s16 *)(t + 0x16);
    r = q * q / 20;
    f = D_80048D34;
    p = (*(u8 *(**)(s32))(f + 0x2750))((*(s32 (**)(s32))(f + 0x2718))(idx));
    p += 0x3C8;
    for (i = 0; i < 2; i++) {
        h = *(s16 *)(p + i * 2);
        if (h == 0x149) {
            r += r / 5;
        } else if (h == 0x14A) {
            r += r * 4 / 10;
        }
    }
    if (r > 1000) {
        r = 1000;
    }
    return r;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1D3C);

void func_800A1E84(void) {
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1E8C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1F74);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1FE0);

Obj *func_800A246C(void) {
    return func_80014504(func_800A1FE0, 0xA4, 0);
}
