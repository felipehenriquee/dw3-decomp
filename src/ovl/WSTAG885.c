#include "WSTAG885.h"
#include "m2c.h"
#include "WSTAG885_auto.h"
#include "WSTAG885_data.h"

void func_800A5DE0(MapPtOut *out, MapPtList **list, s32 x, s32 y) {
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

void func_800A5EE0(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        func_800A5DE0(D_80099D94[0], D_800A6A88, D_80048D34[0x22], D_80048D34[0x23]);
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5F54(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5EE0, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800AA2B0)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG885/nonmatchings/WSTAG885", func_800A5FB0);
