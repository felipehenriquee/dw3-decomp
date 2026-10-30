#include "STDWTITL.h"
#include "m2c.h"
#include "STDWTITL_auto.h"
#include "STDWTITL_data.h"

void func_80082D70(u8 *o, u8 **w) {
    struct {
        u8 pad0[0x24];
        void (*fn24)(s32, s32);
        u8 pad28[4];
        void (*fn2C)(s32);
        u8 pad30[8];
    } g;
    u8 *t;
    u8 *x;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        t = (u8 *)D_8004DE10;
        (*(void (**)(void))(t + 0x150))();
        (*(void (**)(s32))(t + 0x154))(0xA000);
        (*(void (**)(s32, s32, s32, s32))(t + 0x174))(0x140, 0xF0, 0, 0);
        func_8001FFA8(&g);
        g.fn24(0x280, 0);
        g.fn2C(((s32 (*)(s32))D_80044F5C[0])(0x8A60001));
        x = (*(u8 *(**)(u8 *, s32, s32))(t + 0x16C))(D_80087C4C, 2, 0x100);
        (*(void (**)(u8 *, s32, s32, s32))(x + 0x12C))(x, 0x1F, 0x1F, 0x1F);
        w[0] = (u8 *)func_8008483C();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

Obj *func_80082E9C(void) {
    return func_80014504(func_80082D70, 0x50, 4);
}

void func_80082EC8(u8 *o, u8 **w) {
    s16 r[4];
    u8 *t;
    u8 *x;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        switch ((u8)((s32 (*)(void))D_8004B438[0])()) {
        case 0:
            t = (u8 *)D_8004DE10;
            (*(void (**)(void))(t + 0x150))();
            (*(void (**)(s32))(t + 0x154))(0x14000);
            (*(void (**)(s32, s32, s32, s32))(t + 0x174))(0x140, 0xF0, 0, 0);
            r[0] = 0;
            r[1] = 0;
            r[2] = 0x140;
            r[3] = 0xF0;
            x = (*(u8 *(**)(s16 *, s32, s32))(t + 0x16C))(r, 2, 0x1000);
            (*(void (**)(u8 *, s32, s32, s32))(x + 0x12C))(x, 0, 0, 0);
            w[0] = (u8 *)func_8008497C();
            break;
        case 13:
            w[2] = (u8 *)func_80082E9C();
            break;
        default:
            w[1] = func_80083F48((u8)((s32 (*)(void))D_8004B438[0])() - 1);
            break;
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

Obj *func_80083028(void) {
    return func_80014504(func_80082EC8, 0x50, 0xC);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083054);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800831E8);

void func_800833AC(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

Obj *func_800833E4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800831E8, 0x7C, 0);
    M2C_FIELD(temp_v0, void (**)(void *), 0x78) = func_800833AC;
    M2C_FIELD(temp_v0, s32 *, 0x68) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x6C) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_80083438(void) {
    ResetGraph(1);
    ClearImage2(&D_80087C90, 0, 0, 0);
    DrawSync(0);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083478);

/* posiciona o CD em pos e le em velocidade dupla ate conseguir */
void func_80083500(s32 pos) {
    u8 mode = 0x80;

    do {
        while (CdControl(2, pos, 0) == 0) {
        }
        while (CdControl(0xE, &mode, 0) == 0) {
        }
    } while (CdRead2(0x1E0) == 0);
}

void func_80083568(s32 arg0, M2C_UNK arg1) {
    func_8008714C(0);
    func_800873E8(arg1);
    StSetRing(D_8008924C, 0x20);
    StSetStream(1, 1, -1, 0, 0);
    func_80083500(arg0);
}

u32 *func_800835D4(DecEnv *dec) {
    u32 *addr;
    StHeader *sector;
    s32 cnt = 2000;
    while (StGetNext(&addr, (u32 **)&sector) != 0) {
        if (--cnt == 0) {
            return 0;
        }
    }
    if (sector->frameCount >= (u32)D_8008926C[0]) {
        D_80089264 = 1;
    }
    if (D_80087C88 != sector->width || D_80087C8C != sector->height) {
        func_80083438();
        D_80087C88 = sector->width;
        D_80087C8C = sector->height;
    }
    dec->rect[0].w = dec->rect[1].w = D_80087C88 * 3 / 2;
    dec->rect[0].h = dec->rect[1].h = D_80087C8C;
    dec->slice.h = D_80087C8C;
    return addr;
}

s32 func_800836D8(DecEnv *dec) {
    s32 cnt = 2000;
    u32 *next;
    s32 t;
    s32 *tb;
    while ((next = func_800835D4(dec)) == 0) {
        if (--cnt == 0) {
            return -1;
        }
    }
    tb = D_80089250;
    t = tb[0];
    dec->vlcid = dec->vlcid == 0;
    func_8008780C(next, dec->vlcbuf[dec->vlcid], t);
    StFreeRing(next);
    return 0;
}

void func_80083760(void) {
    SRect snap;
    s32 id;
    if (D_80081454[0] != 0) {
        StCdInterrupt();
        D_80081454[0] = 0;
    }
    id = D_80089214.imgid;
    snap = D_80089214.slice;
    D_80089214.imgid = D_80089214.imgid ? 0 : 1;
    D_80089214.slice.x += D_80089214.slice.w;
    if (D_80089214.rectid != 0) {
        snap.x += 480;
    }
    snap.y = 36;
    if (D_80089214.slice.x < D_80089214.rect[D_80089214.rectid].x + D_80089214.rect[D_80089214.rectid].w) {
        func_80087320(D_80089214.imgbuf[D_80089214.imgid], D_80089214.slice.w * D_80089214.slice.h / 2);
    } else {
        D_80089214.isdone = 1;
        D_80089214.rectid = D_80089214.rectid == 0;
        D_80089214.slice.x = D_80089214.rect[D_80089214.rectid].x;
        D_80089214.slice.y = D_80089214.rect[D_80089214.rectid].y;
    }
    DrawSync(0);
    LoadImage(&snap, D_80089214.imgbuf[id]);
}

void func_800838B0(TitlBlink *o) {
    volatile s32 c = 0x800000;
    while (o->done == 0) {
        c--;
        if (c == 0) {
            o->done = 1;
            o->sel = o->sel == 0;
            o->x = o->pt[o->sel].x;
            o->y = o->pt[o->sel].y;
        }
    }
    o->done = 0;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083944);

Obj *func_80083C70(s32 a, s32 b) {
    Obj *o = func_80014504(func_80083944, 0x54, 0);

    D_80089268[0] = a;
    D_8008926C[0] = b;
    return o;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083CC0);

u8 *func_80083F48(s32 arg0) {
    u8 *o = (u8 *)func_80014504(func_80083CC0, 0x58, 4);
    *(s32 *)(o + 0x50) = arg0;
    return o;
}

void func_80083F80(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        void (*fn88)(s32);
        u8 pad8C[0xA0 - 0x8C];
    } g;
    func_8001F648(&g);
    if (*(s32 *)(o + 0x5C) != 0) {
        g.fn7C(*(s32 *)(o + 0x60), 0);
        g.fn74(0x280, 0x100);
        g.fn78(0, 0x1F0);
        g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80088234), 2, 0x31, 0x79);
        func_8001F648(&g);
    }
    g.fn7C(*(s32 *)(o + 0x60), 0);
    g.fn74(0x280, 0x100);
    g.fn88(*(s32 *)(o + 0x58));
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80088234), 4, 0x25, 0x72);
}

void func_800840A8(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (*(s32 *)(o + 0x50) == 0) {
            *(s32 *)(o + 0x5C) = 0;
            (*(void (**)(u8 *))(o + 0x38))(o);
        } else {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
        }
        break;
    case 1:
        switch (*(s32 *)(o + 0x10)) {
        case 0:
        default:
            return;
        case 1:
            *(s32 *)(o + 0x54) = 0;
            (*(void (**)(u8 *))(o + 0x3C))(o);
        case 2:
            *(s32 *)(o + 0x58) = D_80087D40[*(s32 *)(o + 0x54)];
            if (++*(s32 *)(o + 0x54) >= 12) {
                (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
            }
            break;
        }
        func_80083F80(o);
        break;
    case 2:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s32 *)(o + 0x58) = 11;
            *(s32 *)(o + 0x5C) = 1;
            (*(void (**)(u8 *))(o + 0x3C))(o);
        }
        func_80083F80(o);
        break;
    case 3:
        break;
    }
}

void func_800841E0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

Obj *func_80084218(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800840A8, 0x74, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x70) = func_800841E0;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_8008426C(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        void (*fn88)(s32);
        u8 pad8C[0xA0 - 0x8C];
    } g;
    func_8001F648(&g);
    if (*(s32 *)(o + 0x5C) != 0) {
        g.fn7C(*(s32 *)(o + 0x60), 0);
        g.fn74(0x280, 0x100);
        g.fn78(0, 0x1F0);
        g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80088234), 2, 0xFD, 0x64);
        func_8001F648(&g);
    }
    if (*(s32 *)(o + 0x58) != -1) {
        g.fn7C(*(s32 *)(o + 0x60), 0);
        g.fn74(0x280, 0x100);
        g.fn88(*(s32 *)(o + 0x58));
        g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80088234), 4, 0xF3, 0x5A);
    }
}

void func_800843A4(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (*(s32 *)(o + 0x50) == 0) {
            *(s32 *)(o + 0x5C) = 0;
            (*(void (**)(u8 *))(o + 0x38))(o);
        } else {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
        }
        break;
    case 1:
        switch (*(s32 *)(o + 0x10)) {
        case 0:
        default:
            return;
        case 1:
            *(s32 *)(o + 0x58) = *(s32 *)(o + 0x54) = 0;
            (*(void (**)(u8 *))(o + 0x3C))(o);
        case 2:
            *(s32 *)(o + 0x58) = D_80087D58[*(s32 *)(o + 0x54)];
            if (*(s32 *)(o + 0x58) == -1) {
                (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
            }
            func_8008426C(o);
            *(s32 *)(o + 0x54) += 1;
            break;
        }
        break;
    case 2:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s32 *)(o + 0x58) = -1;
            *(s32 *)(o + 0x5C) = 1;
            (*(void (**)(u8 *))(o + 0x3C))(o);
        }
        func_8008426C(o);
        break;
    case 3:
        break;
    }
}

Obj *func_800844E8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800843A4, 0x74, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x70) = func_800841E0;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_8008453C(u8 *o) {
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
    s32 k = 0;
    switch (D_8005CCA8[0]) {
    case 0:
    case 1:
    case 2:
        k = 0;
        break;
    case 3:
    case 6:
        k = 2;
        break;
    case 4:
        k = 3;
        break;
    case 5:
        k = 1;
        break;
    }
    func_8001F648(&g);
    g.fn7C(0x100, 1);
    g.fn74(0x280, 0);
    g.fn88(*(s16 *)(o + 0x50));
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x8A60000), k, 0, 0);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084628);

Obj *func_8008483C(void) {
    return func_80014504(func_80084628, 0x54, 0);
}

void func_80084868(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0x10)) {
    case 0:
    default:
        w[0] = (s32)func_80086DB0((s32)o);
        (*(s32 *)(o + 0x10))++;
        break;
    case 1:
        if (w[0] == 0) {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
        }
        break;
    }
}

void func_800848EC(u8 *o, s32 a) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (((s32 (*)(void))D_80055C60[0])() == 0) {
            (*(void (**)(u8 *))(o + 0x38))(o);
            ((void (*)(void))D_80088238[0])();
        }
        break;
    case 1:
        func_80084868(o, a);
        break;
    case 2:
    case 3:
        break;
    }
}

void *func_8008497C(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800848EC, 0x58, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 2;
    ((M2C_UNK (*)(M2C_UNK)) *D_80055C54)(0x47);
    return temp_v0;
}

void func_800849D8(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;

    func_8001F648(&g);
    g.fn7C(*(s32 *)(o + 0x60), 0);
    g.fn78(0, 0x1F0);
    g.fn74(0x280, 0x100);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80088234), 1, *(s32 *)(o + 0x58), *(s32 *)(o + 0x5C));
}

void func_80084A70(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (*(s32 *)(o + 0x50) == 0) {
            *(s32 *)(o + 0x58) = 0x20F;
            *(s32 *)(o + 0x5C) = 0x22;
            (*(void (**)(u8 *))(o + 0x38))(o);
        } else {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
        }
        break;
    case 1:
        switch (*(s32 *)(o + 0x10)) {
        case 1:
            *(s32 *)(o + 0x54) = 10;
            (*(void (**)(u8 *))(o + 0x3C))(o);
        case 2:
            *(s32 *)(o + 0x58) = *(s32 *)(o + 0x54) * 32 + 0xCF;
            if ((*(s32 *)(o + 0x54))-- <= 0) {
                (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
            }
            break;
        case 0:
        default:
            return;
        }
        func_800849D8(o);
        break;
    case 2:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s32 *)(o + 0x58) = 0xCF;
            *(s32 *)(o + 0x5C) = 0x22;
            (*(void (**)(u8 *))(o + 0x3C))(o);
        }
        func_800849D8(o);
        break;
    case 3:
        break;
    }
}

void func_80084BB0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

Obj *func_80084BE8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80084A70, 0x74, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x70) = func_80084BB0;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_80084C3C(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;

    func_8001F648(&g);
    g.fn7C(*(s32 *)(o + 0x60), 0);
    g.fn78(0, 0x1F0);
    g.fn74(0x280, 0x100);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80088234), 1, *(s32 *)(o + 0x58), *(s32 *)(o + 0x5C));
}

void func_80084CD4(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *(s32 *)(o + 0x58) = 0x153;
        *(s32 *)(o + 0x5C) = 0x6F;
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        switch (*(s32 *)(o + 0x10)) {
        case 1:
            *(s32 *)(o + 0x54) = 10;
            (*(void (**)(u8 *))(o + 0x3C))(o);
        case 2:
            *(s32 *)(o + 0x58) = *(s32 *)(o + 0x54) * 32 + 0x13;
            if ((*(s32 *)(o + 0x54))-- <= 0) {
                (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
            }
            break;
        case 0:
        default:
            return;
        }
        func_80084C3C(o);
        break;
    case 2:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s32 *)(o + 0x58) = 0x13;
            *(s32 *)(o + 0x5C) = 0x6F;
            (*(void (**)(u8 *))(o + 0x3C))(o);
        }
        func_80084C3C(o);
        break;
    case 3:
        break;
    }
}

Obj *func_80084DF0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80084CD4, 0x74, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x70) = func_80084BB0;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_80084E44(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;

    func_8001F648(&g);
    g.fn7C(*(s32 *)(o + 0x60), 0);
    g.fn78(0, 0x1F0);
    g.fn74(0x280, 0x100);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80088234), 0, *(s32 *)(o + 0x58), *(s32 *)(o + 0x5C));
}

void func_80084EDC(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (*(s32 *)(o + 0x50) == 0) {
            *(s32 *)(o + 0x58) = -0x12F;
            *(s32 *)(o + 0x5C) = 0x3D;
            (*(void (**)(u8 *))(o + 0x38))(o);
        } else {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
        }
        break;
    case 1:
        switch (*(s32 *)(o + 0x10)) {
        case 1:
            *(s32 *)(o + 0x54) = 10;
            (*(void (**)(u8 *))(o + 0x3C))(o);
        case 2:
            *(s32 *)(o + 0x58) = -(*(s32 *)(o + 0x54) * 320) / 10 + 0x11;
            if ((*(s32 *)(o + 0x54))-- <= 0) {
                (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
            }
            break;
        case 0:
        default:
            return;
        }
        func_80084E44(o);
        break;
    case 2:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s32 *)(o + 0x58) = 0x11;
            *(s32 *)(o + 0x5C) = 0x3D;
            (*(void (**)(u8 *))(o + 0x3C))(o);
        }
        func_80084E44(o);
        break;
    case 3:
        break;
    }
}

void func_8008503C(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

Obj *func_80085074(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80084EDC, 0x74, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x70) = func_8008503C;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_800850C8(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;

    func_8001F648(&g);
    g.fn7C(*(s32 *)(o + 0x60), 0);
    g.fn78(0, 0x1F0);
    g.fn74(0x280, 0x100);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80088234), 0, *(s32 *)(o + 0x58), *(s32 *)(o + 0x5C));
}

void func_80085160(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *(s32 *)(o + 0x58) = -0x12D;
        *(s32 *)(o + 0x5C) = 0x18;
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        switch (*(s32 *)(o + 0x10)) {
        case 1:
            *(s32 *)(o + 0x54) = 10;
            (*(void (**)(u8 *))(o + 0x3C))(o);
        case 2:
            *(s32 *)(o + 0x58) = -(*(s32 *)(o + 0x54) * 320) / 10 + 0x13;
            if ((*(s32 *)(o + 0x54))-- <= 0) {
                (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
            }
            break;
        case 0:
        default:
            return;
        }
        func_800850C8(o);
        break;
    case 2:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s32 *)(o + 0x58) = 0x13;
            *(s32 *)(o + 0x5C) = 0x18;
            (*(void (**)(u8 *))(o + 0x3C))(o);
        }
        func_800850C8(o);
        break;
    case 3:
        break;
    }
}

Obj *func_8008529C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085160, 0x74, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x70) = func_8008503C;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800852F0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085594);

void func_80085BE4(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

void func_80085C1C(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0xC);
    if (temp_v1 == 1) {
        M2C_FIELD(arg0, s16 *, 0x5A) = 2;
        M2C_FIELD(arg0, s8 *, 0x58) = (s8) temp_v1;
        M2C_FIELD(arg0, s16 *, 0x54) = 0;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 2);
    }
}

s16 func_80085C5C(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x52);
}

Obj *func_80085C68(s16 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085594, 0xA8, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x9C) = func_80085BE4;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xA0) = func_80085C1C;
    M2C_FIELD(temp_v0, s16 (**)(void *), 0xA4) = func_80085C5C;
    M2C_FIELD(temp_v0, s32 *, 0x8C) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x90) = 2;
    M2C_FIELD(temp_v0, s16 *, 0x50) = arg0;
    return temp_v0;
}

s32 func_80085CD4(s32 arg0) {
    if (arg0 >= 0x1E) {
        return 0xFF;
    }
    return (((s32) (rsin((arg0 << 0xA) / 30) * 0x1E) / 4096) * 0xFF) / 30;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085D64);

void func_80085F0C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s16 *, 0x56) = 0;
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
}

s32 func_80085F38(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x50);
}

void func_80085F44(u8 *o) {
    s32 k;
    s16 n;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s16 *)(o + 0x54) = 0;
        *(s16 *)(o + 0x56) = 0;
        *(s32 *)(o + 0x50) = 0;
        break;
    case 1:
        k = *(s32 *)(o + 0x10);
        if (k != 0 && k == *(s32 *)(o + 0xC)) {
            n = *(s16 *)(o + 0x56);
            *(s16 *)(o + 0x56) = n + 1;
            *(s16 *)(o + 0x54) = func_80085CD4(n);
            if (*(s16 *)(o + 0x56) >= 30) {
                (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0);
                *(s32 *)(o + 0x50) = k;
            }
        }
        func_80085D64(*(s16 *)(o + 0x54));
        break;
    case 2:
    case 3:
        break;
    }
}

Obj *func_80086018(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085F44, 0x60, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x58) = func_80085F0C;
    M2C_FIELD(temp_v0, s32 (**)(void *), 0x5C) = func_80085F38;
    return temp_v0;
}

s32 func_8008605C(s16 *st, s16 *tbl, s32 depth) {
    s16 *e = tbl + st[0] * 2;
    if (depth == 0) {
        st[1]--;
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
        func_8008605C(st, tbl, depth + 1);
    }
    return e[0];
}

void func_80086108(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;
    u8 *t;
    func_8001F648(&g);
    g.fn7C(*(s32 *)(o + 0x7C), 0);
    g.fn78(0, 0x1F3);
    g.fn74(0x300, 0);
    t = (u8 *)D_80044B38;
    g.fn84((*(s32 (**)(s32))(t + 0x424))(0x8870000), 0, 0, 0);
    g.fn74(0x340, 0);
    g.fn84((*(s32 (**)(s32))(t + 0x424))(0x8870001), 0, 0, 0);
    g.fn74(0x380, 0);
    g.fn84((*(s32 (**)(s32))(t + 0x424))(0x8870002), 0, 0, 0);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086228);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086544);

void func_800867A8(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

Obj *func_800867E0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80086544, 0x98, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x94) = func_800867A8;
    M2C_FIELD(temp_v0, s32 *, 0x7C) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x80) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086834);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800869D0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086C70);

Obj *func_80086DB0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80086C70, 0x13C, 0x1C);
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086DF8);

void func_80086FA0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = 1;
    if (arg1 != 0) {
        ((void (*)(s32))D_80055C48[0])(0x40019);
        M2C_FIELD(arg0, s32 *, 4) = 0x1000 / M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 8) = 0;
    } else {
        ((void (*)(s32))D_80055C48[0])(0x4001A);
        M2C_FIELD(arg0, s32 *, 8) = 0x1000;
        M2C_FIELD(arg0, s32 *, 4) = -((0x1000 / M2C_FIELD(arg0, s32 *, 0)) * 2);
    }
}

s32 func_80087034(Fade *f) {
    if (f->active == 0) {
        return 1;
    }
    f->value += f->speed;
    if (f->speed > 0) {
        if (f->value > 0x1000) {
            f->value = 0x1000;
            f->active = 0;
            return 1;
        }
    } else if (f->value < 0) {
        f->value = 0;
        f->active = 0;
        return 1;
    }
    return 0;
}

void func_800870A0(Lerp *l, s32 from, s32 to, s32 n) {
  if (from != to)
  {
    l->frames = n;
    l->acc = from << 8;
    l->step = ((to - from) << 8) / l->frames;
    l->cur = from;
    l->target = to;
    l->active = 1;
  }
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800870E0);

void func_8008714C(s32 arg0) {
    if (arg0 == 0) {
        ResetCallback();
    }
    func_8008740C(arg0);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087180);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008720C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800872A4);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087320);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087340);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008737C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800873C4);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800873E8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008740C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800874FC);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008758C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087618);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800876AC);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087740);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087758);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800877DC);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008780C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087B5C);
