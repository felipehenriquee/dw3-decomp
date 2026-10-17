#include "WSTAG545.h"
#include "m2c.h"
#include "WSTAG545_auto.h"
#include "WSTAG545_data.h"

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A5E18);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A5F20);

void func_800A6054(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5F20, 0x64, 0);
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg2;
}

s16 func_800A60AC(s16 *st, s16 *tbl, s32 depth) {
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
        func_800A60AC(st, tbl, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A6184);

void func_800A6304(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x35A)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

u8 *func_800A633C(s32 link) {
    return func_800143DC(func_800A6184, 0x58, 0, link);
}

s16 func_800A636C(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        if (once) {
            if (e[0] == 0xFF) {
                return 0xFF;
            }
        } else if (e[0] == 0xFF) {
            e = tbl;
            st[2] = 0;
            st[3] += e[1];
        }
        func_800A636C(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A648C);

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A6780);

u8 *func_800A6894(s32 arg0) {
    return func_800143DC(func_800A648C, 96, 20, arg0);
}

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A68C4);

void *func_800A6984(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A68C4, 0x54, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7370)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A69E0);

void func_800A6A2C(void) {
    *D_8004B370 = 0x1B;
}

INCLUDE_ASM("asm/ovl/WSTAG545/nonmatchings/WSTAG545", func_800A6A3C);
