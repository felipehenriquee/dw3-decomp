#include "FIELDSTG.h"
#include "m2c.h"
#include "FIELDSTG_auto.h"
#include "FIELDSTG_data.h"

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80083784);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800837EC);

u8 *func_80083CD8(void) {
    return func_800143DC(func_80083784, 80, 0, 813);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80083D08);

void func_80084124(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        switch (arg1) {                             /* irregular */
        case 0x348:
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
            M2C_FIELD(arg0, s16 *, 0x58) = 0;
            return;
        case 0x349:
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
            M2C_FIELD(arg0, s16 *, 0x58) = 1;
            break;
        }
    }
}

/* cria o objeto; 0x58 = flag 0x1C3D ligada */
u8 *func_80084198(s32 link) {
    u8 *o = func_800143DC(func_80083D08, 0x6C, 0, link);

    if ((*(s32 (**)(s32, s32))((u8 *)&D_80048ABC + 0x10))(0x1C3D, 1) != 0) {
        *(s16 *)(o + 0x58) = 1;
    } else {
        *(s16 *)(o + 0x58) = 0;
    }
    return o;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084200);

void func_80084804(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0;
}

void func_80084834(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 1;
}

void func_80084868(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 2;
}

void func_8008489C(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 3;
}

void func_800848D0(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 4;
}

void func_80084904(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 5;
}

void func_80084938(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 6;
}

void func_8008496C(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 7;
}

void func_800849A0(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 8;
}

void func_800849D4(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 9;
}

void func_80084A08(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0xA;
}

void func_80084A3C(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0xB;
}

void func_80084A70(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0xC;
}

void func_80084AA4(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0xD;
}

void func_80084AD8(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0xE;
}

void func_80084B0C(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0xF;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084B40);

void *func_80084D30(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80084B40, 0x58, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_80099838)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084D8C);

s32 func_80084DD0(s32 a, s16 *m, s32 *w) {
    s32 k = m[1];
    s32 x = m[2];
    s32 y = m[3];
    u8 *o;
    u8 *v;
    s32 i;
    if (k < 0x320) {
        v = (u8 *)func_80084D8C(a, k);
        if (v != NULL) {
            (*(void (**)(u8 *, s32, s32))(v + 0x148))(v, x, y);
        }
    } else {
        o = ((u8 *(*)(s32, s32, s32))D_8004B7BC)(k, -1, -1);
        if (o == NULL) {
            for (i = 0; i < 10; i++) {
                if (w[i + 4] == 0) {
                    v = (u8 *)func_80092484(k);
                    w[i + 4] = (s32)v;
                    if (v != NULL) {
                        o = v;
                    }
                    break;
                }
            }
        }
        if (o != NULL) {
            func_800924C8((s32)o, k, x, y);
        }
    }
    return 4;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084ECC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800853F8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085590);

void func_80085AC4(s32 arg0) {
    M2C_FIELD(func_80014504(func_80085590, 0x6C, 0), s32 *, 0x50) = arg0;
}

/* animacao sem laco: no fim (0xFF) para e retorna 0xFF */
s16 func_80085AFC(s16 *st, s16 *tbl, s32 depth) {
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
        func_80085AFC(st, tbl, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085BD4);

Obj *func_80085E0C(s32 arg0, s32 arg1, s16 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085BD4, 0x7C, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg1;
    M2C_FIELD(temp_v0, s16 *, 0x58) = arg2;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085E64);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085ED4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086060);

/* procura na lista (30) o objeto cujo metodo 0x244 devolve id */
u8 *func_80086284(u8 **list, s32 id) {
    s32 i;
    u8 *o;

    for (i = 0; i < 30; i++) {
        o = list[i + 1];
        if ((*(s32 (**)(u8 *))(o + 0x244))(o) == id) {
            return o;
        }
    }
    return NULL;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800862FC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086770);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800869C8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086C78);

u8 *func_80086C9C(s32 a) {
    u8 *o = func_800143DC(func_800869C8, 0x134, 0x7C, 4);

    *(s32 *)(o + 0x64) = a;
    *(void **)(o + 0x130) = func_80086C78;
    return o;
}

/* desenha a tela em blocos de 128x128 */
void func_80086CE4(s32 a, s32 b) {
    u8 *o = (*(u8 *(**)(s32))&D_8004DF8C)(a);
    s32 x, y;

    if (o != NULL) {
        for (y = 0; y < 0xF0; y += 0x80) {
            for (x = 0; x < 0x140; x += 0x80) {
                func_80086060(o, x, y, b);
            }
        }
    }
}

void func_80086D6C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x50) = ((s32 (*)()) D_8004DF98)();
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086D9C);

s32 func_80086E24(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x6C);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086E30);

void func_800870DC(void *arg0, s32 arg1, void *arg2) {
    M2C_FIELD(arg0, s32 *, 0x228) = arg1;
    M2C_FIELD(arg0, void **, 0x22C) = arg2;
    M2C_FIELD(arg2, M2C_UNK (**)(void *, s32, M2C_UNK), 0x7C)(arg2, M2C_FIELD(arg0, s32 *, 0x68), 0x2800);
    M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x2C)(arg0, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087130);

void func_800872C0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x70) = -1;
}

s32 func_800872CC(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x70);
}

s32 func_800872D8(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x58);
}

void func_800872E4(u8 *o) {
    u8 *x;
    s32 k;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        k = *(s32 *)(o + 0x10);
        if (k != 0 && k == *(s32 *)(o + 0xC)) {
            x = *(u8 **)(o + 0x22C);
            *(s32 *)(o + 0x230) = (*(s32 (**)(u8 *))(x + 0x78))(x);
            if (*(s32 *)(o + 0x230) != 0) {
                func_80087130(o);
                (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0);
            }
        }
        if (*(s32 *)(o + 0x54) == 0 && *(s32 *)(o + 0x6C) != 0) {
            *(s32 *)(o + 0x54) = ((s32 (*)(void))D_8004DF98)();
        }
        break;
    case 2:
        break;
    case 3:
        ((void (*)(s32))D_8004B5EC[0])(*(s32 *)(o + 0x68));
        break;
    }
}

u8 *func_800873D8(s32 a, s32 b) {
    u8 *o = (u8 *)func_80014504(func_800872E4, 0x254, 0);
    *(void **)(o + 0x234) = func_80086D9C;
    *(void **)(o + 0x23C) = func_80086E30;
    *(void **)(o + 0x240) = func_800870DC;
    *(void **)(o + 0x244) = func_800872D8;
    *(void **)(o + 0x238) = func_80086E24;
    *(void **)(o + 0x248) = func_800872CC;
    *(void **)(o + 0x24C) = func_800872C0;
    *(void **)(o + 0x250) = func_80086D6C;
    *(s32 *)(o + 0x60) = b;
    *(s32 *)(o + 0x64) = a / 2048;
    *(s32 *)(o + 0x68) = ((s32 (*)(s32, s32))D_8004B5F8[0])(a, 2);
    *(s32 *)(o + 0x70) = *(s32 *)(o + 0x58) = -1;
    *(s32 *)(o + 0x6C) = 1;
    return o;
}

void func_800874D0(u8 *o, u8 **w) {
    u8 *t;
    s32 v;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        t = D_80048D34;
        v = (*(s32 (**)(void))(t + 0x2704))();
        if (*(s32 *)(t + 0x26DC) != v) {
            *(s32 *)(t + 0x26DC) = v;
            *(s32 *)(t + 0x26D8) = 1;
            *(s32 *)(t + 0x26F8) = 0x10;
        } else {
            *(s32 *)(t + 0x26D8) = 0;
        }
        w[0] = func_8008B6A4();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

Obj *func_80087580(void) {
    return func_80014504(func_800874D0, 0x50, 0xC);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800875AC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087704);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087854);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087974);

u8 *func_80087D68(s32 a) {
    u8 *o = func_800143DC(func_80087974, 0x1C0, 8, 9);

    *(s32 *)(o + 4) = a;
    D_80099DD4[0] = 1;
    return o;
}

s32 func_80087DB0(u8 *o) {
    *(s32 *)(o + 0x68) -= (*(s32 (**)(void))&D_8004DF9C)();
    if (*(s32 *)(o + 0x68) < 0) {
        *(s32 *)(o + 0x64) += 2;
        if (D_800975C0[*(s32 *)(o + 8)][*(s32 *)(o + 0x64)] == 0xFF) {
            *(s32 *)(o + 0x64) = 0;
        }
        *(s32 *)(o + 0x68) = D_800975C0[*(s32 *)(o + 8)][*(s32 *)(o + 0x64) + 1];
    }
    return D_800975C0[*(s32 *)(o + 8)][*(s32 *)(o + 0x64)];
}

void func_80087E7C(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;
    Pair32 p;
    s32 v;
    p.x = *(s32 *)(*(u8 **)(o + 0x50) + 0x58);
    p.y = *(s32 *)(*(u8 **)(o + 0x50) + 0x5C) - (*(s32 *)(*(u8 **)(o + 0x50) + 0x64) >> 8);
    func_8001F648(&g);
    g.fn7C(0x1002, 1);
    g.fn74(0x200, 0x100);
    if (*(s32 *)(o + 0x10) == 2) {
        v = func_80087DB0(o);
        g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x1600000), v, p.x, p.y - 0x1B);
    }
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x1600000), *(s32 *)(o + 0x60) >> 2, p.x, p.y - 0x1B);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087F84);

u8 *func_80088144(s32 arg0, s32 arg1, s32 arg2) {
    u8 *o = func_800143DC(func_80087F84, 108, 0, arg2);

    *(s32 *)(o + 0x4) = arg0;
    *(s32 *)(o + 0x8) = arg1;
    return o;
}

s32 func_80088190(s32 arg0) {
    return func_80088144(0, 0, arg0);
}

void func_800881B8(void *arg0, s32 arg1, M2C_UNK arg2) {
    if (arg0 != NULL) {
        switch (arg1) {                             /* irregular */
        case 0x325:
            M2C_FIELD(arg0, s32 *, 8) = 0;
            break;
        case 0x327:
            M2C_FIELD(arg0, s32 *, 8) = 1;
            break;
        case 0x326:
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
            break;
        }
        if ((arg1 == 0x325) || (arg1 == 0x327)) {
            M2C_FIELD(arg0, s32 *, 0x50) = ((s32 (*)(M2C_UNK, M2C_UNK, M2C_UNK)) D_8004B7BC)(5, arg2, -1);
        }
    }
}

s32 func_80088288(u8 *o) {
    u8 *p = *(u8 **)(o + 0x58);
    Pair32 pos;
    u32 v;
    u8 *e;
    u16 t;
    pos = *(Pair32 *)(p + 0x58);
    v = (u8)((s32 (*)(s32, Pair32 *))D_8009B708[0])(7, &pos);
    if (v == 0) {
        return 0;
    }
    *(s32 *)(o + 0x60) = v >> 5;
    *(s32 *)(o + 0x5C) = v & 0x1F;
    e = *(u8 **)(o + 0x54) + (v & 0x1F) * 24;
    *(u8 **)(o + 0x64) = e;
    t = *(u16 *)(e + 8);
    switch (t) {
    case 5: case 6: case 8: case 9: case 10: case 11: case 12: case 13: case 14:
        return 1;
    }
    return D_80097624[*(s32 *)(p + 0x60) + *(s32 *)(o + 0x60) * 8] != 0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008836C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800885D4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088888);

void func_80088A4C(s32 arg0) {
    M2C_FIELD(func_80014504(func_80088888, 0x68, 8), s32 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088A84);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088B84);

void *func_80088CA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80088B84, 0x64, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg3;
    M2C_FIELD(temp_v0, s32 *, 0x60) = ((s32 (*)(s32)) *D_80044F5C)(*D_80099DC8);
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088D38);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088EEC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089038);

Obj *func_80089490(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80089038, 0x58, 4);
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800894D8);

void func_80089548(s32 arg0) {
    D_8009B8FC = arg0;
    D_8009B8F8 = D_80099D90;
    func_800894D8();
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008957C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089610);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089700);

void func_80089B28(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s32 *)(o + 0x10) = *(s32 *)(o + 0x8);
    case 1:
        if (func_80089700(o) != 0) {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
        }
        break;
    case 2:
    case 3:
        break;
    }
}

void func_80089BA4(s32 arg0) {
    M2C_FIELD(func_80014504(func_80089B28, 0x54, 0), s32 *, 8) = arg0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089BDC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089F24);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089F7C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008A5E4);

s32 func_8008A9B0(void) {
    u8 *d = D_80048D34;

    if ((*(s32 (**)(void))(d + 0x2704))() == 0x22D) {
        return 1;
    }
    return (*(s32 (**)(void))(d + 0x2704))() == 0x2DE;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008AA10);

u8 *func_8008B6A4(void) {
    return func_800143DC(func_8008AA10, 128, 124, 7);
}

void func_8008B6D4(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    u8 *o = ((u8 *(*)(s32, s32, s32))D_8004B7BC)(7, -1, -1);
    u8 *p;
    if (o != 0) {
        *(s32 *)(o + 0x5C) = a;
        *(s32 *)(o + 0x60) = b;
        *(s32 *)(o + 0x68) = g;
        (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
        p = D_80099D80;
        *(s32 *)(p + 0x64) = c;
        *(s32 *)(p + 0x68) = d;
        *(s32 *)(p + 0x6C) = e;
    }
}

void func_8008B770(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_8008B6D4(arg0, arg1, arg2, arg3, arg4, 0);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008B798);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008BF38);

void func_8008BFA4(s32 arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(((void *(*)(M2C_UNK, M2C_UNK, M2C_UNK)) D_8004B7BC)(7, -1, -1), void **, 0x24);
    M2C_FIELD(temp_s0, s32 *, 0xC) = func_800853F8((s16) D_800978D8[arg0]);
}

void func_8008C000(void) {
    u8 *o = ((u8 *(*)(s32, s32, s32))D_8004B7BC)(7, -1, -1);
    u8 *w = *(u8 **)(o + 0x24);
    u8 *m = D_80099D80;

    *(s32 *)(m + 0x50) = 1;
    *(s32 *)(m + 0x58) = 1;
    *(s32 *)(w + 0x10) = func_80011DAC(0x1002);
    (*(void (**)(u8 *, s32))(o + 0x2C))(o, 2);
}

void func_8008C078(s32 a, s32 *p, s32 b) {
    u8 *o = ((u8 *(*)(s32, s32, s32))D_8004B7BC)(7, -1, -1);

    *(s32 *)(o + 0x70) = a;
    *(s32 *)(o + 0x74) = p[0];
    *(s32 *)(o + 0x78) = p[1];
    *(s32 *)(o + 0x7C) = b;
    (*(void (**)(u8 *, s32))(o + 0x2C))(o, 3);
}

s32 func_8008C0F0(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = rsin(arg0 >> 2) * arg1;
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }
    return var_v0 >> 0xC;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C130);

u8 *func_8008C610(s32 a, s32 b) {
    u8 *o = (u8 *)func_80014504(func_8008C130, 0x74, 0);
    u8 *t;
    *(s32 *)(o + 0x50) = a;
    t = D_80048D34;
    *(s32 *)(o + 0x54) = b;
    if ((*(s32 (**)(void))(t + 0x2704))() == 0x26C) {
        func_800A6024();
    }
    if ((*(s32 (**)(void))(t + 0x2704))() == 0x2D4) {
        func_800A6024();
    }
    return o;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C6B8);

Obj *func_8008C8B4(Pair32x2 v) {
    Obj *o = func_80014504(func_8008C6B8, 0x6C, 0);

    *(Pair32 *)((u8 *)o + 0x5C) = v.a;
    *(Pair32 *)((u8 *)o + 0x64) = v.b;
    return o;
}

/* sorteia uma das o[0x50] entradas (20 bytes) de o[0x54], marca e copia 8 bytes */
void func_8008C910(u8 *o) {
    s32 i = ((s32 (*)(void))D_8004DC0C)() % *(s32 *)(o + 0x50);

    D_8004B420[0] = i;
    *(s32 *)(*(u8 **)(o + 0x54) + i * 20 + 0x10) = 1;
    *(Pair32 *)(o + 0x60) = *(Pair32 *)(*(u8 **)(o + 0x54) + i * 20 + 8);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C98C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008CCC8);

u8 *func_8008CE40(s32 *pos, s32 flag) {
    u8 *o = ((u8 *(*)(s32, s32, s32))D_8004B7BC)(0xB, -1, -1);
    s32 i;
    u8 *e;
    if (o == 0) {
        return 0;
    }
    for (i = 0; i < *(s32 *)(o + 0x50); i++) {
        e = *(u8 **)(o + 0x54) + i * 20;
        if (pos[0] >= *(s32 *)(e + 8) - 10 && *(s32 *)(e + 8) + 10 >= pos[0] &&
            pos[1] >= *(s32 *)(e + 0xC) - 10 && *(s32 *)(e + 0xC) + 10 >= pos[1]) {
            if (flag != 0) {
                *(s32 *)(o + 0x58) = i;
                *(s32 *)(o + 0x5C) = 0;
            }
            return o;
        }
    }
    return 0;
}

void func_8008CF1C(void) {
    u8 *o = ((u8 *(*)(s32, s32, s32))D_8004B7BC)(0xB, -1, -1);
    s32 i;
    if (o != 0) {
        for (i = 0; i < *(s32 *)(o + 0x50); i++) {
            if (*(s32 *)(*(u8 **)(o + 0x54) + i * 20 + 8) >= 1000) {
                *(s32 *)(o + 0x58) = i;
                *(s32 *)(o + 0x5C) = 1;
                (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
            }
        }
    }
}

void func_8008CFD4(u8 *o, s32 tex) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[8];
        void (*fn80)(s32, s32);
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;

    if (*(s32 *)(o + 0xC) == 1) {
        func_8001F648(&g);
        g.fn74(0x200, 0x100);
        g.fn80(tex, 4);
        g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x1600000), *(s32 *)(o + 0x5C),
               *(s32 *)(o + 0x50), *(s32 *)(o + 0x54));
    }
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D068);

void func_8008D244(s32 arg0) {
    M2C_FIELD(func_80014504(func_8008D068, 0x64, 0), s32 *, 4) = arg0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D27C);

Obj *func_8008D744(Pair32 p) {
    Obj *o = func_80014504(func_8008D27C, 0x68, 0);

    *(Pair32 *)((u8 *)o + 0x50) = p;
    return o;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D788);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D998);

u8 *func_8008DC58(void) {
    u8 *o = func_800143DC(func_8008D998, 144, 0, 16);

    *(s16 *)(o + 0x64) = -1;
    return o;
}

void func_8008DC90(s32 a, s32 b) {
    u8 *t = D_8004B610;
    u8 *o = (*(u8 *(**)(s32, s32, s32))(t + 0x1AC))(0x10, -1, -1);
    if (o != 0) {
        *(s32 *)(o + 0x7C) = 0;
        *(s32 *)(o + 0x80) = a;
        *(s32 *)(o + 0x84) = b;
        *(s32 *)(o + 0x50) = (*(s32 (**)(s32, s32, s32))(t + 0x1AC))(5, b, -1);
        *(Pair32 *)(o + 0x68) = *(Pair32 *)(o + 0x54);
        (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0);
    }
}

void func_8008DD40(s32 a, s32 b, s32 c) {
    u8 *o = ((u8 *(*)(s32, s32, s32))D_8004B7BC)(0x10, -1, -1);

    if (o != NULL) {
        *(s32 *)(o + 0x7C) = 0;
        *(s32 *)(o + 0x80) = a;
        *(s32 *)(o + 0x88) = b;
        *(s32 *)(o + 0x8C) = c;
        *(Pair32 *)(o + 0x68) = *(Pair32 *)(o + 0x54);
        (*(void (**)(u8 *, s32))(o + 0x2C))(o, 1);
    }
}

void func_8008DDC8(s32 arg0) {
    void *temp_v0;

    temp_v0 = ((void *(*)(M2C_UNK, M2C_UNK, M2C_UNK)) D_8004B7BC)(0x10, -1, -1);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x5C) = arg0;
    }
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008DE0C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008DFEC);

void func_8008E13C(u8 *o, s32 k) {
    if (k != 0 && D_80099DD0[0] == 0) {
        *(s32 *)(o + 0x60) = D_80097C28[k];
        if (*(s32 *)(o + 0xBC) != 0) {
            if (*(s32 *)(o + 0x10) != 2) {
                (*(void (**)(u8 *, s32))(o + 0x2C))(o, 2);
            }
        } else {
            if (*(s32 *)(o + 0x10) != 3) {
                (*(void (**)(u8 *, s32))(o + 0x2C))(o, 3);
            }
        }
        return;
    }
    if (*(s32 *)(o + 0x10) == 2) {
        (*(void (**)(u8 *, s32))(o + 0x2C))(o, 1);
    }
    if (*(s32 *)(o + 0x10) == 3) {
        (*(void (**)(u8 *, s32))(o + 0x2C))(o, 4);
    }
}

u8 *func_8008E210(s32 *pos) {
    u8 *t = D_8004B610;
    u8 *o = (*(u8 *(**)(s32, s32, s32))(t + 0x1AC))(5, -1, 1);
    s32 r;
    while (o != 0) {
        r = *(s32 *)(o + 0x80);
        if (pos[0] >= *(s32 *)(o + 0x58) - r && *(s32 *)(o + 0x58) + r >= pos[0]) {
            r >>= 1;
            if (pos[1] >= *(s32 *)(o + 0x5C) - r && *(s32 *)(o + 0x5C) + r >= pos[1]) {
                return o;
            }
        }
        o = (*(u8 *(**)(void))(t + 0x1B0))();
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008E2CC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008E45C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008E8AC);

void func_8008EA44(u8 *o) {
    s32 k = ((s32 (*)(s32))D_8004BBC8[0])(0);
    if (k & 0x10) {
        if (*(s32 *)(o + 0x10) != 0x41) {
            (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0x41);
        }
    } else if (k & 0x40) {
        if (*(s32 *)(o + 0x10) != 0x42) {
            (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0x42);
        }
    } else {
        if (*(s32 *)(o + 0x10) != 0x40) {
            (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0x40);
        }
    }
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008EAE8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008ED2C);

void func_8008EEF0(u8 *o) {
    s32 x, y, tx, ty, d, px, py;
    if (*(s32 *)(o + 0xEC) == 0) {
        return;
    }
    x = *(s32 *)(o + 0x50);
    y = *(s32 *)(o + 0x54);
    tx = *(s32 *)(o + 0xF0);
    ty = *(s32 *)(o + 0xF4);
    px = x >> 8;
    py = y >> 8;
    if ((x >> 9) != (tx >> 1) || (y >> 9) != (ty >> 1)) {
        d = 0;
        if (px < tx) {
            d = 0x20;
        } else if (tx < px) {
            d = 0x80;
        }
        if (py < ty) {
            d |= 0x40;
        } else if (ty < py) {
            d |= 0x10;
        }
        *(s32 *)(o + 0xBC) = 1;
        func_8008E13C(o, d >> 4);
    } else {
        *(s32 *)(o + 0x50) = tx << 8;
        *(s32 *)(o + 0xEC) = 0;
        *(s32 *)(o + 0x54) = *(s32 *)(o + 0xF4) << 8;
        *(s32 *)(o + 0x60) = *(s32 *)(o + 0xF8);
        (*(void (**)(u8 *, s32))(o + 0x2C))(o, 1);
    }
}

void func_8008EFD0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s32 *, 0xEC) = 1;
    M2C_FIELD(arg0, s32 *, 0xF0) = arg1;
    M2C_FIELD(arg0, s32 *, 0xF4) = arg2;
    M2C_FIELD(arg0, s32 *, 0xF8) = arg3;
}

s32 func_8008EFE8(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xEC);
}

void func_8008EFF4(void *arg0) {
    M2C_FIELD(arg0, s32 (**)(s32), 0x108) = func_8008EEF0;
}

void func_8008F004(void *arg0) {
    u32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u32 *, 8);
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, s32 (**)(s32), 0x108) = func_8008E8AC;
        M2C_FIELD(arg0, s32 *, 0xBC) = 0;
        return;
    case 1:
        M2C_FIELD(arg0, s32 (**)(s32), 0x108) = NULL;
        return;
    case 2:
    case 4:
    case 8:
        M2C_FIELD(arg0, s32 (**)(s32), 0x108) = func_8008EAE8;
        /* fallthrough */
    default:
        return;
    }
}

void func_8008F064(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x108) = 0;
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 5);
    M2C_FIELD(arg0, s32 *, 0x60) = arg1;
}

void func_8008F0A4(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x10) != 0x4F) {
        M2C_FIELD(arg0, s32 *, 0x108) = 0;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 0x4F);
        M2C_FIELD(arg0, s32 *, 0x60) = arg1;
    }
}

void func_8008F0F0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x10) == 0x4F) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 0x50);
    }
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F128);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F1D4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F280);

void func_8008F304(u8 *o, s32 v, Pair32 pos) {
    s32 i;
    u8 *f;
    u8 *x;
    u8 *q;
    Pair32 p;
    D_80099DD8[0] = 1;
    *(s32 *)(o + 0x108) = 0;
    (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0x48);
    f = D_8004B610;
    *(s32 *)(o + 0x60) = v;
    for (i = 0; i < 3; i++) {
        x = (*(u8 *(**)(s32, s32, s32))(f + 0x1AC))(5, -1, D_80097CA8[i]);
        if (x != 0) {
            *(s32 *)(x + 0x60) = v;
        }
    }
    q = *(u8 **)(o + 0x24);
    p.x = *(s32 *)(o + 0x58) + pos.x;
    p.y = *(s32 *)(o + 0x5C) + pos.y;
    *(Obj **)(q + 8) = func_8008D744(p);
}

void func_8008F3E4(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x108) = 0;
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    *D_80099DD8 = 1;
    func_8008C078(arg2, (s32) (arg0 + 0x58), arg1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F44C);

void func_8008F4B4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xA0) = arg1;
    M2C_FIELD(arg0, s32 *, 0xCC) = 0;
    M2C_FIELD(arg0, s32 *, 0xD0) = 0;
    M2C_FIELD(arg0, s32 *, 0xE8) = 0;
}

void func_8008F4C8(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0xEC) = 0;
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 0);
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
    func_8008F4B4(arg0, arg1);
}

s32 func_8008F520(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xE8);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F52C);

void func_8008F9B8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x60) = arg1;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F9C0);

void func_8008FD60(void *arg0) {
    M2C_FIELD(arg0, s32 (**)(s32), 0x108) = func_8008E8AC;
    M2C_FIELD(arg0, s32 *, 0x90) = 0;
}

void func_8008FD74(u8 *o, s32 a, s32 b) {
    s32 t;
    if (*(s32 *)(o + 8) != 0) {
        return;
    }
    if (a != 0) {
        t = *(s32 *)(o + 0x18);
        if ((t & 7) == 0) {
            switch (*(s32 *)(o + 4)) {
            default:
                ((void (*)(s32))D_80055C48)(0x8004583C);
                break;
            case 0x146:
                if ((t & 0x1F) == 0) {
                    ((void (*)(s32))D_80055C48)(0x80045FCB);
                }
                break;
            case 0x147:
                break;
            }
            if (b != 0) {
                ((void (*)(void))D_8009B6A0[0])();
            }
        }
    } else if ((*(s32 *)(o + 0x18) & 0x1F) == 0) {
        ((void (*)(s32))D_80055C48)(0x8004583C);
    }
    *(s32 *)(o + 0x18) += 1;
}

void func_8008FE68(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 8) == 0) {
        if (!(M2C_FIELD(arg0, s32 *, 0x18) & 0xF)) {
            ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x800458BD);
        }
        M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) + 1);
    }
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008FED0);

/* liga a rotina func_8008ED2C nos 3 objetos de tipo 5 da tabela */
void func_80090E70(void) {
    s32 i = 0;
    u8 *sys = D_8004B610;
    void *fn = func_8008ED2C;
    s32 *id = D_80097CB4;
    u8 *o;

    for (; i < 3; i++, id++) {
        o = (*(u8 *(**)(s32, s32, s32))(sys + 0x1AC))(5, -1, *id);
        if (o != NULL) {
            *(void **)(o + 0x108) = fn;
        }
    }
}

void func_80090EF0(void) {
    s32 i = 0;
    u8 *sys = D_8004B610;
    void *fn = func_8008EAE8;
    s32 *id = D_80097CC0;
    u8 *o;

    for (; i < 3; i++, id++) {
        o = (*(u8 *(**)(s32, s32, s32))(sys + 0x1AC))(5, -1, *id);
        if (o != NULL) {
            *(void **)(o + 0x108) = fn;
        }
    }
}

void func_80090F70(void *arg0, void *arg1) {
    void *temp_a2;

    temp_a2 = (M2C_FIELD(arg0, s32 *, 0x60) * 8) + D_80097CCC;
    M2C_FIELD(arg1, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0x58) + M2C_FIELD(temp_a2, s32 *, 0));
    M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 0x5C) + M2C_FIELD(temp_a2, s32 *, 4));
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80090FB0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8009116C);

extern struct opaque D_80048ABC;
void func_800915A0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x707E, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B19, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x400, 1);
}

s32 func_80091600(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x400, 1);
}

extern struct opaque D_80048ABC;
void func_8009162C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x707E, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B1F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x401, 1);
}

s32 func_8009168C(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x401, 1);
}

extern struct opaque D_80048ABC;
void func_800916B8(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x707F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B1A, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x402, 1);
}

s32 func_80091718(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x402, 1);
}

extern struct opaque D_80048ABC;
void func_80091744(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x707F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B20, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x403, 1);
}

s32 func_800917A4(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x403, 1);
}

extern struct opaque D_80048ABC;
void func_800917D0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7080, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8489, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x404, 1);
}

s32 func_80091830(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x404, 1);
}

extern struct opaque D_80048ABC;
void func_8009185C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7080, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8495, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x405, 1);
}

s32 func_800918BC(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x405, 1);
}

extern struct opaque D_80048ABC;
void func_800918E8(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7081, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x847C, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x406, 1);
}

s32 func_80091948(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x406, 1);
}

extern struct opaque D_80048ABC;
void func_80091974(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7081, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8462, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x407, 1);
}

s32 func_800919D4(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x407, 1);
}

extern struct opaque D_80048ABC;
void func_80091A00(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7082, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8ADE, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x408, 1);
}

s32 func_80091A60(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x408, 1);
}

extern struct opaque D_80048ABC;
void func_80091A8C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7082, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8AE8, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x409, 1);
}

s32 func_80091AEC(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x409, 1);
}

extern struct opaque D_80048ABC;
void func_80091B18(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7083, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8AF4, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40A, 1);
}

s32 func_80091B78(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40A, 1);
}

extern struct opaque D_80048ABC;
void func_80091BA4(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7083, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8AF3, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40B, 1);
}

s32 func_80091C04(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40B, 1);
}

extern struct opaque D_80048ABC;
void func_80091C30(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7084, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B01, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40C, 1);
}

s32 func_80091C90(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40C, 1);
}

extern struct opaque D_80048ABC;
void func_80091CBC(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7085, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B0D, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40D, 1);
}

s32 func_80091D1C(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40D, 1);
}

extern struct opaque D_80048ABC;
void func_80091D48(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7086, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B02, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40E, 1);
}

s32 func_80091DA8(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40E, 1);
}

extern struct opaque D_80048ABC;
void func_80091DD4(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7087, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B0F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40F, 1);
}

s32 func_80091E34(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40F, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80091E60);

void func_80091FDC(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = 1;
    if (arg1 != 0) {
        ((void (*)(s32))((s32 *)&D_80055C48)[0])(0x40019);
        M2C_FIELD(arg0, s32 *, 4) = 0x1000 / M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 8) = 0;
    } else {
        ((void (*)(s32))((s32 *)&D_80055C48)[0])(0x4001A);
        M2C_FIELD(arg0, s32 *, 8) = 0x1000;
        M2C_FIELD(arg0, s32 *, 4) = -((0x1000 / M2C_FIELD(arg0, s32 *, 0)) * 2);
    }
}

/* passo de um fade: soma p[1] em p[2] ate 0x1000 (subindo) ou 0 (descendo);
   retorna 1 quando termina */
s32 func_80092070(s32 *p) {
    s32 v;

    if (p[3] == 0) {
        return 1;
    }
    p[2] = v = p[2] + p[1];
    if (p[1] > 0) {
        if (v > 0x1000) {
            p[2] = 0x1000;
            p[3] = 0;
            return 1;
        }
    } else if (v < 0) {
        p[2] = 0;
        p[3] = 0;
        return 1;
    }
    return 0;
}

s32 func_800920DC(s32 arg0) {
    return (&D_80099E00)[arg0];
}

u8 func_800920F8(s32 arg0) {
    return D_8009A458[arg0];
}

void func_80092110(void) {
    s32 *p;
    s32 k;
    if (D_8004B370[0] != 0x2D) {
        p = D_8009A884;
    } else {
        p = D_8009A5F0;
    }
    k = ((s32 (*)(void))D_8004B438[0])();
    ((void (*)(u8 *, s32))D_8004B600)(D_80099D80, 0x64);
    do {
        if (p[0] == k) {
            *(s32 *)(D_80099D80) = p[1];
            *(s32 *)(D_80099D80 + 4) = p[2];
            goto end;
        }
        p += 3;
    } while (p[0] != 0);
end:
    if (p[0] == 0) {
        while (1) {
        }
    }
}

/* procura entre as 30 entradas (0x1C bytes) a de id */
u8 *func_800921E4(u8 *e, s32 id) {
    s32 i;

    for (i = 0; i < 30; i++, e += 0x1C) {
        if (*(s32 *)(e + 4) == id) {
            return e;
        }
    }
    return NULL;
}

s32 func_80092214(void) {
    return ((M2C_UNK (*)(s32 *, M2C_UNK)) D_8004B600)(&D_8009B3C4, 8);
}

/* procura o objeto de tipo 5 com id */
u8 *func_80092244(s32 id) {
    return ((u8 *(*)(s32, s32, s32))D_8004B7BC)(5, id, -1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092274);

void func_80092304(s32 id, s32 *count) {
    u8 *o = func_80092244(id);

    if ((*(s32 (**)(u8 *))(o + 0x138))(o) != 0) {
        (*count)++;
    }
}

void func_80092350(s32 id, s32 *count) {
    u8 *o = func_80092244(id);

    if ((*(s32 (**)(u8 *))(o + 0x140))(o) == 0) {
        (*count)++;
    }
}

/* torna p relativo a posicao do objeto 0x1002 */
void func_8009239C(s32 *p) {
    s32 v[2];
    u8 *o = (*(u8 *(**)(s32))&D_8004DF8C)(0x1002);

    (*(void (**)(u8 *, s32 *))(o + 0x11C))(o, v);
    p[0] -= v[0];
    p[1] -= v[1];
}

/* limpa 0x10C do objeto 1 (ou do 2, se o 1 nao existe) */
void func_80092408(void) {
    u8 *o = func_80092244(1);

    if (o == NULL) {
        o = func_80092244(2);
    }
    *(s32 *)(o + 0x10C) = 0;
}

/* procura id na tabela de 12 bytes (0 termina) */
s32 *func_8009243C(s32 id) {
    s32 *e = D_8009B3E8;

    while (e[0] != 0) {
        if (e[0] == id) {
            return e;
        }
        e += 3;
    }
    return NULL;
}

s32 func_80092484(s32 arg0) {
    s32 var_v1;
    void *temp_v0;

    temp_v0 = func_8009243C(arg0);
    var_v1 = 0;
    if (temp_v0 != NULL) {
        var_v1 = M2C_FIELD(temp_v0, s32 (**)(s32), 4)(arg0);
    }
    return var_v1;
}

void func_800924C8(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK (*temp_v0_2)(s32, M2C_UNK, M2C_UNK);
    void *temp_v0;

    temp_v0 = func_8009243C(arg1);
    if (temp_v0 != NULL) {
        temp_v0_2 = M2C_FIELD(temp_v0, M2C_UNK (**)(s32, M2C_UNK, M2C_UNK), 8);
        if (temp_v0_2 != NULL) {
            temp_v0_2(arg0, arg2, arg3);
        }
    }
}

void func_8009252C(void) {
    s32 temp_a0;

    temp_a0 = ((s32 (*)()) D_8004DC0C)() % 2304;
    if (temp_a0 < 0x100) {
        D_80048D64 = temp_a0;
        return;
    }
    D_80048D64 = (s32) (temp_a0 + 0x100) / 2;
}

void func_800925A8(void) {
    u8 *o = ((u8 *(*)(s32, s32, s32))D_8004B7BC)(5, -1, 0);
    Pair32 pos;
    s32 k;
    s32 r;
    s32 *e;
    pos = *(Pair32 *)(o + 0x58);
    k = (u8)((s32 (*)(s32, Pair32 *))D_8009B708[0])(4, &pos) - 1;
    r = ((s32 (*)(void))D_8004DC0C)() & 7;
    e = ((FdSet4 *)((FdTbl *)D_80099DA0[0])->s[k])->e[r];
    D_80042B1C[3] = e[1];
    D_80042B1C[5] = e[2];
    func_8008B798(e[0]);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092664);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800927A0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800927FC);

void func_800928CC(s32 arg0, s32 arg1) {
    (&D_8009B6C4)[arg0] = arg1;
}

void func_800928E4(s32 v) {
    u8 *d = D_80048D34;

    if (*(s32 *)(d + 0x26D8) != 0) {
        *(s32 *)(d + 0x26E0) = v;
    }
}

void func_80092908(s32 arg0) {
    D_8004B414 = arg0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092914);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092A90);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092CA0);

/* out = tabela[k] * s / 4096 (dois valores) */
void func_80092DA0(s32 unused, s32 s, s32 k, s32 *out) {
    s32 *t = D_8009B724;
    s32 *e = t + k * 2;

    out[0] = e[0] * s / 4096;
    out[1] = e[1] * s / 4096;
}
