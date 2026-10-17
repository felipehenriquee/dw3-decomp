#include "WSTAG840.h"
#include "m2c.h"
#include "WSTAG840_auto.h"
#include "WSTAG840_data.h"

void func_800A5DE4(MapPtOut *out, MapPtList **list, s32 x, s32 y) {
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

INCLUDE_ASM("asm/ovl/WSTAG840/nonmatchings/WSTAG840", func_800A5EE4);

void *func_800A5F50(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5EE4, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7AE8)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG840/nonmatchings/WSTAG840", func_800A5FAC);
