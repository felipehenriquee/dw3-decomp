#include "WSTAG226.h"
#include "m2c.h"
#include "WSTAG226_auto.h"
#include "WSTAG226_data.h"

s16 func_800A5DE0(s16 *st, s16 *tbl, s32 depth) {
    s16 *e = tbl + st[2] * 2;
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        st[3] -= dt;
    }
    if (st[3] <= 0) {
        st[2]++;
        e += 2;
        st[3] += e[1];
        if (e[0] == 0xFF) {
            return 0xFF;
        }
        func_800A5DE0(st, tbl, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A5EB8);

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A5EF0);

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A6164);

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A61CC);

Obj *func_800A61FC(void) {
    return func_80014504(func_800A5EF0, 0x70, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A6228);

void *func_800A62C8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6228, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6D88)();
    return temp_v0;
}

void func_800A6324(void) {
    *D_8004B370 = 0x26;
}

INCLUDE_ASM("asm/ovl/WSTAG226/nonmatchings/WSTAG226", func_800A6334);
