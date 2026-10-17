#include "WSTAG925.h"
#include "m2c.h"
#include "WSTAG925_auto.h"
#include "WSTAG925_data.h"

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A5DE0);

void *func_800A5E64(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A65B8)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A5EC0);

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A5F0C);

s16 func_800A6000(s16 *st, s16 *tbl, s32 depth) {
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
        func_800A6000(st, tbl, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A60D8);

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A6110);

INCLUDE_ASM("asm/ovl/WSTAG925/nonmatchings/WSTAG925", func_800A639C);
