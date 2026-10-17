#include "WSTAG555.h"
#include "m2c.h"
#include "WSTAG555_auto.h"
#include "WSTAG555_data.h"

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

INCLUDE_ASM("asm/ovl/WSTAG555/nonmatchings/WSTAG555", func_800A5ED4);

Obj *func_800A6040(void) {
    return func_80014504(func_800A5ED4, 0x5C, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG555/nonmatchings/WSTAG555", func_800A606C);

void *func_800A60D0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A606C, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A69C0)();
    return temp_v0;
}

void func_800A612C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x400C, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG555/nonmatchings/WSTAG555", func_800A6158);
