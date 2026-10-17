#include "WSTAG750.h"
#include "m2c.h"
#include "WSTAG750_auto.h"
#include "WSTAG750_data.h"

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

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A5EB8);

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A5EF0);

void func_800A6170(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x335)) {
        M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(D_800A7258, s16 *, 0);
        M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(D_800A7258, s16 *, 2);
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A61C0);

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A61F0);

void *func_800A6424(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A61F0, 0x54, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7850)();
    return temp_v0;
}

s16 func_800A6480(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A6480(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A65A0);

s32 func_800A6688(s32 x, s32 y, s32 w, s32 h) {
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

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A674C);

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A69DC);

void func_800A6A38(void) {
    *D_8004B370 = 0x20;
}

void func_800A6A48(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4048, 1);
}

void func_800A6A74(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4047, 1);
}

void func_800A6AA0(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4062, 1);
}

void func_800A6ACC(void) {
    *D_8004B370 = 0x21;
}

void func_800A6ADC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x7C0A, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG750/nonmatchings/WSTAG750", func_800A6B08);
