#include "WSTAG730.h"
#include "m2c.h"
#include "WSTAG730_auto.h"
#include "WSTAG730_data.h"

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

INCLUDE_ASM("asm/ovl/WSTAG730/nonmatchings/WSTAG730", func_800A5ED4);

Obj *func_800A5F94(void) {
    return func_80014504(func_800A5ED4, 0x54, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG730/nonmatchings/WSTAG730", func_800A5FC0);

void *func_800A6024(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5FC0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6978)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG730/nonmatchings/WSTAG730", func_800A6080);
