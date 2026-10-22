#include "WSTAG640.h"
#include "m2c.h"
#include "WSTAG640_auto.h"
#include "WSTAG640_data.h"

s16 func_800A5DE0(s16 *st, s16 *tbl, s32 depth) {
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
        if (e[0] == 0xFF) {
            e = tbl;
            st[0] = 0;
            st[1] += e[1];
        }
        func_800A5DE0(st, tbl, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG640/nonmatchings/WSTAG640", func_800A5ED4);

Obj *func_800A6040(void) {
    return func_80014504(func_800A5ED4, 0x5C, 0);
}

void func_800A606C(MapPtOut *out, MapPtList **list, s32 x, s32 y) {
    MapPtList *l;
    MapPt *p;

    for (;;) {
        l = *list;
        if (l == NULL) {
            return;
        }
        if (l->x == x && l->y == y) {
            break;
        }
        list++;
    }
    p = l->pts;
    out->v0 = p->v0;
    out->v3 = p->v3;
    out->v4 = p->v4;
    out->v5 = p->v5;
    out->v1 = p->v1;
    out->v2 = p->v2;
    while (p->next != NULL) {
        p = p->next;
        out++;
        out->v0 = p->v0;
        out->v3 = p->v3;
        out->v4 = p->v4;
        out->v5 = p->v5;
        out->v1 = p->v1;
        out->v2 = p->v2;
    }
}

void func_800A616C(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        w[0] = func_800A6040();
        func_800A606C(D_80099D94[0], D_800A6634, D_80048D34[0x22], D_80048D34[0x23]);
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A61F4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A616C, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6B34)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG640/nonmatchings/WSTAG640", func_800A6250);
