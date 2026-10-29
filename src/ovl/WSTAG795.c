#include "WSTAG795.h"
#include "m2c.h"
#include "WSTAG795_auto.h"
#include "WSTAG795_data.h"

s16 func_800A5DE0(u8 *o, AnimEnt4 *tbl, s32 once, s32 depth) {
    AnimEnt4 *e = tbl + *(s16 *)(o + 0x4);
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        *(s16 *)(o + 0x6) -= dt;
    }
    if (*(s16 *)(o + 0x6) <= 0) {
        *(s16 *)(o + 0x4) += 1;
        e++;
        *(s16 *)(o + 0x6) += e->dur;
        if (once != 0) {
            if (e->id == 0xFF) {
                return 0xFF;
            }
        } else if (e->id == 0xFF) {
            e = tbl;
            *(s16 *)(o + 0x4) = 0;
            *(s16 *)(o + 0x6) += e->dur;
        }
        func_800A5DE0(o, tbl, once, depth + 1);
    }
    return e->id;
}

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A5F00);

void func_800A6180(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x35B)) {
        M2C_FIELD(arg0, s32 *, 0x50) = 1;
        M2C_FIELD(arg0, s16 *, 0x5C) = 0;
        M2C_FIELD(arg0, s16 *, 0x5E) = (s16) *D_800A6A2A;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

u8 *func_800A61D0(s32 arg0) {
    return func_800143DC(func_800A5F00, 104, 0, arg0);
}

Obj *func_800A6200(void) {
    Obj *o = func_80014504(func_800A5F00, 0x68, 0);
    M2C_FIELD(o, s32 *, 0x54) = 1;
    return o;
}

void func_800A6234(void) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        u8 pad7C[4];
        void (*fn80)(u8 *, s32);
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;
    Pair32 pos;
    u8 *p;
    u8 *t;
    u8 *d;
    s32 i;
    p = ((u8 *(*)(s32))D_8004DF8C[0])(0x1002);
    i = 0;
    (*(void (**)(u8 *, Pair32 *))(p + 0x11C))(p, &pos);
    func_8001F648(&g);
    g.fn80(p, 0);
    g.fn74(0x140, 0x100);
    g.fn78(0, 0x1F0);
    g.fn84(((s32 (*)(s32))D_80044B38[0x109])(0x6F60000), 1, pos.x + 0xE0, pos.y + 0x16);
    t = (u8 *)D_80044B38;
    d = (u8 *)D_80048D34;
    pos.y += 0x19;
    for (; i < 3; i++) {
        g.fn84((*(s32 (**)(s32))(t + 0x424))(0x6F60000), d[i + 0x26D4] + 2, pos.x + D_800A6A7C[i], pos.y);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A637C);

Obj *func_800A654C(void) {
    return func_80014504(func_800A637C, 0x54, 4);
}

void func_800A6578(u8 *o, Obj **w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        w[0] = (Obj *)func_800A654C();
        if (((s32 (*)(s32, s32))D_80048ACC[0])(0x4063, 0) != 0) {
            w[1] = (Obj *)func_800A61D0(0x344);
        } else {
            w[1] = (Obj *)func_800A6200();
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        if (((s32 (*)(s32, s32))D_80048ACC[0])(0x4043, 0) != 0 && D_8004B370[0] == 0x20) {
            w[2] = func_800853F8(0x33E);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A6654(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6578, 0x54, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7328)();
    return temp_v0;
}

void func_800A66B0(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4043, 1);
}

extern struct opaque D_80048ABC;
void func_800A66DC(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x1C05, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x4063, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A6728);
