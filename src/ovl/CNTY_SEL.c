#include "CNTY_SEL.h"
#include "m2c.h"
#include "CNTY_SEL_auto.h"
#include "CNTY_SEL_data.h"

void func_80082CE8(u8 *o, u8 **w) {
    struct {
        u8 pad0[0x24];
        void (*fn24)(s32, s32);
        void (*fn28)(s32, s32);
        void (*fn2C)(s32);
        u8 pad30[8];
    } g;
    u8 *t;
    u8 *x;
    u8 *s;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        s = (u8 *)D_800519EC;
        if ((*(s32 (**)(void))(s + 0x4274))() == 0) {
            t = (u8 *)D_8004DE10;
            (*(void (**)(void))(t + 0x150))();
            (*(void (**)(s32))(t + 0x154))(0xA000);
            (*(void (**)(s32, s32, s32, s32))(t + 0x174))(0x140, 0xF0, 0, 0);
            func_8001FFA8(&g);
            g.fn24(0x280, 0);
            g.fn28(0, 0x1F0);
            g.fn2C(((s32 (*)(s32))D_80044F5C[0])(0x8A30001));
            x = (*(u8 *(**)(SRect *, s32, s32))(t + 0x16C))(D_800843C0, 3, 0x100);
            (*(void (**)(u8 *, s32, s32, s32))(x + 0x12C))(x, 0x1F, 0x1F, 0x1F);
            *w = (u8 *)func_80084394();
            (*(void (**)(u8 *))(o + 0x38))(o);
            (*(s32 (**)(s32))(s + 0x425C))(0x60840002);
        }
        break;
    case 1:
    case 2:
        break;
    case 3:
        ((void (*)(s32))D_80055C68[0])(0x60840002);
        break;
    }
}

/* limpa a tela, cria o objeto da selecao de pais e toca o som 0x21 */
Obj *func_80082E8C(void) {
    Obj *o;

    ClearImage2(D_800843C8, 0, 0, 0);
    o = func_80014504(func_80082CE8, 0x50, 4);
    ((void (*)(s32))D_80055C54[0])(0x21);
    return o;
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80082EF0);

/* n (0-29) para 0-254; 30 ou mais da 0xFF */
s32 func_80082FC4(s32 n) {
    if (n >= 30) {
        return 0xFF;
    }
    return n * 255 / 30;
}

void func_80083000(s32 v) {
    u8 *sys = (u8 *)D_8004DE10;
    u8 *o;
    u32 *ot;
    PolyF4 *p;
    DrMode *m;

    o = (*(u8 *(**)(s32))(sys + 0x17C))(0x100);
    ot = (*(u32 *(**)(u8 *, s32))(o + 0x138))(o, 0);
    p = (*(PolyF4 *(**)(void))(sys + 0x158))();
    ((u8 *)p)[3] = 5;
    p->b0 = v;
    p->g0 = v;
    p->r0 = v;
    p->code = 0x2A;
    p->x0 = D_800843D0.x;
    p->x1 = D_800843D0.x + D_800843D0.w;
    p->x2 = D_800843D0.x;
    p->x3 = D_800843D0.x + D_800843D0.w;
    p->y0 = D_800843D0.y;
    p->y1 = D_800843D0.y;
    p->y2 = D_800843D0.y + D_800843D0.h;
    p->y3 = D_800843D0.y + D_800843D0.h;
    m = (DrMode *)(p + 1);
    p->tag = (p->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    ((u8 *)m)[3] = 1;
    m->code[0] = 0xE1000245;
    m->tag = (m->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)m & 0xFFFFFF);
    (*(void (**)(void *))(sys + 0x15C))((u8 *)m + 8);
}

void func_80083184(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s16 *)(o + 0x50) = 0;
        break;
    case 1:
        *(s16 *)(o + 0x50) = (s16)(*(s16 *)(o + 0x50) + 1) % 192;
        func_80082EF0(o);
        break;
    case 2:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s16 *)(o + 0x52) = 0;
            *(s32 *)(o + 0x10) = 1;
        }
        *(s16 *)(o + 0x50) = (s16)(*(s16 *)(o + 0x50) + 1) % 192;
        func_80082EF0(o);
        func_80083000(func_80082FC4((*(s16 *)(o + 0x52))++));
        if (*(s16 *)(o + 0x52) >= 0x1E) {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
        }
        break;
    case 3:
        break;
    }
}

Obj *func_800832D8(void) {
    return func_80014504(func_80083184, 0x54, 0);
}

s32 func_80083304(s16 *st, s16 *tbl, s32 depth) {
    s16 *e = tbl + st[0] * 2;
    s32 d = ((s32 (*)(void))D_8004DF9C[0])();
    if (d >= 5) {
        d = 4;
    }
    if (depth == 0) {
        st[1] -= d;
    }
    if (st[1] <= 0) {
        st[0]++;
        e += 2;
        st[1] += e[1];
        if (e[0] == 0xFF) {
            return 0xFF;
        }
        func_80083304(st, tbl, depth + 1);
    }
    return e[0];
}

void func_800833DC(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        void (*fn88)(s32);
        u8 pad8C[0xA0 - 0x8C];
    } g;

    func_8001F648(&g);
    g.fn7C(0x100, 1);
    g.fn74(0x280, 0);
    g.fn88(*(s16 *)(o + 0x56));
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x8A30000), *(s16 *)(o + 0x54) + 4, 0, 0);
}

void func_80083474(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x54) = arg1;
}

void func_8008347C(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        *(s32 *)(o + 0x50) += 1;
        *(s32 *)(o + 0x50) %= 32;
        *(s16 *)(o + 0x56) = *(s32 *)(o + 0x50) / 4;
        func_800833DC(o);
        break;
    case 2:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s16 *)(o + 0x58) = 0;
            *(s16 *)(o + 0x5A) = D_800843D8[1];
            *(s32 *)(o + 0x10) += 1;
        }
        *(s16 *)(o + 0x56) = func_80083304((s16 *)(o + 0x58), D_800843D8, 0);
        if (*(s16 *)(o + 0x56) != 0xFF) {
            func_800833DC(o);
        } else {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
        }
        break;
    case 3:
        break;
    }
}

void func_80083594(void) {
    M2C_FIELD(func_80014504(func_8008347C, 0x60, 0), void (**)(void *, s16), 0x5C) = func_80083474;
}

s32 func_800835CC(u8 *o, s32 k) {
    s32 t = *(s16 *)(o + 0x52);

    if (t >= D_800843EC[k].len) {
        return D_800843EC[k].to;
    }
    return D_800843EC[k].from + (D_800843EC[k].to - D_800843EC[k].from) * t / D_800843EC[k].len;
}

void func_80083630(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[4];
        void (*fn8C)(s32, s32, s32);
        u8 pad90[4];
        void (*fn94)(s32, s32);
        u8 pad98[0xA0 - 0x98];
    } g;

    func_8001F648(&g);
    g.fn7C(0x100, 1);
    g.fn74(0x280, 0);
    g.fn94(0x94, 0);
    g.fn8C(*(s16 *)(o + 0x54), *(s16 *)(o + 0x56), 0x1000);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x8A30000), 2, 0x94, 0);
}

void func_800836DC(u8 *o) {
    s16 n;
    Seg *e;
    s32 k;
    Seg *tb;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s16 *)(o + 0x54) = 0x1000;
        *(s16 *)(o + 0x56) = 0;
        *(s16 *)(o + 0x50) = 0;
        break;
    case 1:
        switch (*(s32 *)(o + 0x10)) {
        case 0:
            break;
        case 1:
            k = *(s16 *)(o + 0x50);
            n = (*(s16 *)(o + 0x52))++;
            tb = D_800843EC;
            e = &tb[k];
            if (e->len < n) {
                *(s16 *)(o + 0x50) ^= 1;
                (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0);
                *(s16 *)(o + 0x56) = e->to;
            } else {
                *(s16 *)(o + 0x56) = func_800835CC(o, k);
            }
            break;
        }
        func_80083630(o);
        break;
    case 2:
        *(s16 *)(o + 0x52) = 0;
        (*(void (**)(u8 *, s32))(o + 0x28))(o, 1);
        (*(void (**)(u8 *, s32))(o + 0x2C))(o, 1);
        func_80083630(o);
        break;
    case 3:
        break;
    }
}

Obj *func_80083804(void) {
    return func_80014504(func_800836DC, 0x58, 0);
}

/* valor do trecho k no tempo o[0x52] (interpolacao linear) */
s32 func_80083830(u8 *o, s32 k) {
    s32 t = *(s16 *)(o + 0x52);

    if (t >= D_800843FC[k].len) {
        return D_800843FC[k].to;
    }
    return D_800843FC[k].from + (D_800843FC[k].to - D_800843FC[k].from) * t / D_800843FC[k].len;
}

void func_80083894(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[4];
        void (*fn8C)(s32, s32, s32);
        u8 pad90[4];
        void (*fn94)(s32, s32);
        u8 pad98[0xA0 - 0x98];
    } g;

    func_8001F648(&g);
    g.fn7C(0x100, 1);
    g.fn74(0x280, 0);
    g.fn94(0x140, 0x14);
    g.fn8C(*(s16 *)(o + 0x54), *(s16 *)(o + 0x56), 0x1000);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x8A30000), 1, 0x140, 0x14);
}

void func_80083940(u8 *o) {
    s16 n;
    Seg *e;
    s32 k;
    Seg *tb;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s16 *)(o + 0x56) = 0x1000;
        *(s16 *)(o + 0x54) = 0;
        *(s16 *)(o + 0x50) = 0;
        break;
    case 1:
        switch (*(s32 *)(o + 0x10)) {
        case 0:
            break;
        case 1:
            k = *(s16 *)(o + 0x50);
            n = (*(s16 *)(o + 0x52))++;
            tb = D_800843FC;
            e = &tb[k];
            if (e->len < n) {
                *(s16 *)(o + 0x50) ^= 1;
                (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0);
                *(s16 *)(o + 0x54) = e->to;
            } else {
                *(s16 *)(o + 0x54) = func_80083830(o, k);
            }
            break;
        }
        func_80083894(o);
        break;
    case 2:
        *(s16 *)(o + 0x52) = 0;
        (*(void (**)(u8 *, s32))(o + 0x28))(o, 1);
        (*(void (**)(u8 *, s32))(o + 0x2C))(o, 1);
        func_80083894(o);
        break;
    case 3:
        break;
    }
}

Obj *func_80083A68(void) {
    return func_80014504(func_80083940, 0x58, 0);
}

/* valor do trecho k no tempo o[0x52] (interpolacao linear) */
s32 func_80083A94(u8 *o, s32 k) {
    s32 t = *(s16 *)(o + 0x52);

    if (t >= D_8008440C[k].len) {
        return D_8008440C[k].to;
    }
    return D_8008440C[k].from + (D_8008440C[k].to - D_8008440C[k].from) * t / D_8008440C[k].len;
}

void func_80083B00(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[4];
        void (*fn8C)(s32, s32, s32);
        u8 pad90[4];
        void (*fn94)(s32, s32);
        u8 pad98[0xA0 - 0x98];
    } g;

    func_8001F648(&g);
    g.fn7C(0x100, 1);
    g.fn74(0x280, 0);
    g.fn78(0, 0x1F0);
    g.fn94(0, 0x9E);
    g.fn8C(*(s16 *)(o + 0x54), *(s16 *)(o + 0x56), 0x1000);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x8A30000), 3, 0, 0x9E);
}

void func_80083BC0(u8 *o) {
    s16 n;
    Seg12 *e;
    s32 k;
    Seg12 *tb;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s16 *)(o + 0x56) = 0x1000;
        *(s16 *)(o + 0x54) = 0;
        *(s16 *)(o + 0x50) = 0;
        break;
    case 1:
        switch (*(s32 *)(o + 0x10)) {
        case 0:
            break;
        case 1:
            k = *(s16 *)(o + 0x50);
            n = (*(s16 *)(o + 0x52))++;
            tb = D_8008440C;
            e = &tb[k];
            if (e->len < n) {
                *(s16 *)(o + 0x50) ^= 1;
                (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0);
                *(s16 *)(o + 0x54) = e->to;
            } else {
                *(s16 *)(o + 0x54) = func_80083A94(o, k);
            }
            break;
        }
        func_80083B00(o);
        break;
    case 2:
        *(s16 *)(o + 0x52) = 0;
        (*(void (**)(u8 *, s32))(o + 0x28))(o, 1);
        (*(void (**)(u8 *, s32))(o + 0x2C))(o, 1);
        func_80083B00(o);
        break;
    case 3:
        break;
    }
}

Obj *func_80083CEC(void) {
    return func_80014504(func_80083BC0, 0x58, 0);
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083D18);

Obj *func_80084394(void) {
    return func_80014504(func_80083D18, 0x54, 0x14);
}
