#include "WSTAG680.h"
#include "m2c.h"
#include "WSTAG680_auto.h"
#include "WSTAG680_data.h"

s16 func_800A5EDC(u8 *o, AnimEnt4 *tbl, s32 depth) {
    AnimEnt4 *e = tbl + *(s16 *)(o + 0xC);
    s32 k;
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        *(s16 *)(o + 0xE) -= dt;
    }
    if (*(s16 *)(o + 0xE) <= 0) {
        *(s16 *)(o + 0xC) += 1;
        e++;
        *(s16 *)(o + 0xE) += e->dur;
        if (e->id == 0xFF) {
            *(s32 *)(o + 0x4) = e->next;
            e = tbl;
            *(s16 *)(o + 0xC) = 0;
            *(s16 *)(o + 0xE) += e->dur;
        }
        func_800A5EDC(o, tbl, depth + 1);
    }
    return e->id;
}

INCLUDE_ASM("asm/ovl/WSTAG680/nonmatchings/WSTAG680", func_800A5FD8);

INCLUDE_ASM("asm/ovl/WSTAG680/nonmatchings/WSTAG680", func_800A627C);

u8 *func_800A63AC(s32 arg0) {
    return func_800143DC(func_800A5FD8, 332, 0, arg0);
}

void func_800A63DC(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (D_8004B370[0] == 15) {
            w[0] = func_800853F8(412);
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A6454(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A63DC, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6998)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG680/nonmatchings/WSTAG680", func_800A64B0);
