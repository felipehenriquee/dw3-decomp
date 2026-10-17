#include "WSTAG735.h"
#include "m2c.h"
#include "WSTAG735_auto.h"
#include "WSTAG735_data.h"

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A5DE0);

void *func_800A5EE4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 0x2C);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A736C)();
    return temp_v0;
}

s16 func_800A5F40(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A5F40(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A6060);

s32 func_800A6148(s32 x, s32 y, s32 w, s32 h) {
    s16 r[4];
    u8 *o = (*(u8 *(**)(s32))&D_8004DF8C)(0x1002);

    (*(void (**)(u8 *, s16 *))(o + 0x128))(o, r);
    if (x + w < r[0]) {
        return 0;
    }
    if (r[0] + r[2] < x) {
        return 0;
    }
    if (y + h < r[1]) {
        return 0;
    }
    return r[1] + r[3] >= y;
}

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A620C);

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A649C);

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A64F8);

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A6544);

INCLUDE_ASM("asm/ovl/WSTAG735/nonmatchings/WSTAG735", func_800A6590);
