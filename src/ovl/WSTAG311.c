#include "WSTAG311.h"
#include "m2c.h"
#include "WSTAG311_auto.h"
#include "WSTAG311_data.h"

s16 func_800A5E40(s16 *st, s16 *tbl, s32 depth) {
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
        func_800A5E40(st, tbl, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A5F34);

Obj *func_800A6084(void) {
    return func_80014504(func_800A5F34, 0x60, 0);
}

s16 func_800A60B0(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A60B0(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A61D0);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6594);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6604);

Obj *func_800A6634(void) {
    return func_80014504(func_800A61D0, 0x84, 0);
}

s16 func_800A6660(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A6660(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6780);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6B44);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6BB4);

Obj *func_800A6BE4(void) {
    return func_80014504(func_800A6780, 0x84, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6C10);

void *func_800A6DD0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6C10, 0x54, 0x1C);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A8B18)();
    return temp_v0;
}

s16 func_800A6E2C(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A6E2C(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6F4C);

s32 func_800A7034(s32 x, s32 y, s32 w, s32 h) {
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

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A70F8);

/* cria o objeto de func_800A70F8 com posicao (x, y) e parametro p */
u8 *func_800A7388(s32 x, s32 y, s32 p) {
    u8 *o = func_800143DC(func_800A70F8, 0x6C, 0, 0x17);

    *(s32 *)(o + 0x54) = x;
    *(s32 *)(o + 0x58) = y;
    *(s32 *)(o + 0x50) = p;
    return o;
}

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A73E4);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A7460);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A74C0);

void func_800A750C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x405F, 1);
}

void func_800A7538(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4060, 1);
}

void func_800A7564(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x406C, 1);
}

void func_800A7590(void) {
    *D_8004B370 = 0x28;
}

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A75A0);
