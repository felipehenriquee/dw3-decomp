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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008610C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800861F4);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087070);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087D00);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80089148);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008970C);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80089BE4);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C454);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008F5D4);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80091C1C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80091CF4);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800922B4);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80092F7C);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009328C);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094A00);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094AD0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094C18);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80096EC8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80096FE4);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800979E4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80097AB0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80097BD8);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098D14);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009BC94);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C5E8);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009CC20);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D858);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D944);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DAAC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DB94);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DC8C);

void func_8009DD64(void) {
    s32 (*f)(s32, s32) = (s32 (*)(s32, s32))D_800A4648[0];
    u8 *d = D_800A43F4;

    if (f(d[0x20], *(s32 *)(d + 0x24)) != 0) {
        Rec18 *r = &D_80042BCA[*(s32 *)(d + 0x24)];
        d[r->b[0xA] + 0x38] = 1;
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DDD8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DEBC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DF78);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E0CC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E428);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009EADC);

u8 *func_8009EB94(s32 id) {
    u8 *b = ((u8 *(*)(s32))D_80044F4C)(0x1CC);

    return (u8 *)((*(s32 *)((u8 *)func_8009E994(id) + 0xC) - *(s32 *)b) + (s32)b);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009EBE0);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A01AC);

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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1910);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A19D8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1AA8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1C18);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1D3C);

void func_800A1E84(void) {
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1E8C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1F74);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1FE0);

Obj *func_800A246C(void) {
    return func_80014504(func_800A1FE0, 0xA4, 0);
}
