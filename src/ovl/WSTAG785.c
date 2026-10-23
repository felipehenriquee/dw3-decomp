#include "WSTAG785.h"
#include "m2c.h"
#include "WSTAG785_auto.h"
#include "WSTAG785_data.h"

s16 func_800A5DE4(s16 *st, s16 *tbl, s32 once, s32 depth) {
    s16 *e = tbl + st[0] * 2;
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        st[1] -= dt;
    }
    if (st[1] <= 0) {
        st[0]++;
        e += 2;
        st[1] += e[1];
        if (once) {
            if (e[0] == 0xFF) {
                return 0xFF;
            }
        } else if (e[0] == 0xFF) {
            e = tbl;
            st[0] = 0;
            st[1] += e[1];
        }
        func_800A5DE4(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A5F04);

Obj *func_800A61A4(void) {
    Obj *o = func_80014504(func_800A5F04, 0x6C, 0);
    M2C_FIELD(o, s32 *, 0x50) = 1;
    return o;
}

u8 *func_800A61D8(s32 arg0) {
    return func_800143DC(func_800A5F04, 108, 0, arg0);
}

void func_800A6208(u8 *o, s32 b) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;
    s32 xy[2];

    xy[0] = *(s32 *)(*(u8 **)(o + 0x54) + 0x50) >> 8;
    xy[1] = (*(s32 *)(*(u8 **)(o + 0x54) + 0x54) >> 8) - 0x18;
    func_8001F648(&g);
    g.fn7C(0x1002, 2);
    g.fn74(0x140, 0x100);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x1C70001), b, xy[0], xy[1]);
}

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A62B4);

u8 *func_800A6510(s32 link) {
    return func_800143DC(func_800A62B4, 0x58, 0, link);
}

void func_800A6540(u8 *o, s32 id, s32 x) {
    u8 *p = o;
    switch (id) {
    case 0x328:
        *(s32 *)(p + 0x50) = 2;
        break;
    case 0x329:
        *(s32 *)(p + 0x50) = 3;
        break;
    case 0x32A:
        (*(void (**)(u8 *, s32))(p + 0x28))(p, 2);
        break;
    }
    if (id < 0x32A) {
        if (id >= 0x328) {
            *(s32 *)(p + 0x54) = ((s32 (*)(s32, s32, s32))D_8004B7BC[0])(5, x, -1);
        }
    }
}

void func_800A660C(u8 *o, Obj **w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        switch (D_8004B370[0]) {
        case 0:
            w[0] = func_800853F8(1);
            break;
        case 1:
            w[1] = func_800A61A4();
            w[0] = func_800853F8(3);
            break;
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        w[1] = 0;
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A66B0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A660C, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A75D8)();
    return temp_v0;
}

void func_800A670C(void) {
    *D_8004B370 = 1;
}

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A671C);
