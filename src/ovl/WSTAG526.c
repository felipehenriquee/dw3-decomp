#include "WSTAG526.h"
#include "m2c.h"
#include "WSTAG526_auto.h"
#include "WSTAG526_data.h"

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A5DE0);

void func_800A5FF0(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x34B)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6028);

s16 func_800A6058(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A6058(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6178);

void func_800A6364(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s16 *, 0x52) = 0x96;
    }
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6380);

void func_800A63B0(void) {
    func_80014504(func_800A6178, 0x5C, 0);
}

s16 func_800A63DC(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A63DC(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A64FC);

void func_800A67A4(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s16 *, 0x52) = 0x5A;
    }
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A67C0);

void func_800A67F0(void) {
    func_80014504(func_800A64FC, 0x64, 0);
}

s16 func_800A681C(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A681C(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A693C);

void func_800A6AF4(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s16 *, 0x52) = 0x28;
    }
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6B10);

void func_800A6B40(void) {
    func_80014504(func_800A693C, 0x5C, 0);
}

s16 func_800A6B6C(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A6B6C(st, tbl, once, depth + 1);
    }
    return e[0];
}

s32 func_800A6C8C(void *arg0, s32 arg1) {
    s32 var_a1;
    s32 var_a2;

    var_a2 = M2C_FIELD(arg0, s16 *, 0x6C) - M2C_FIELD(arg0, s32 *, 0x5C);
    var_a1 = M2C_FIELD(arg0, s16 *, 0x6E) - M2C_FIELD(arg0, s32 *, 0x60);
    if (var_a2 < 0) {
        var_a2 = -var_a2;
    }
    if (var_a1 < 0) {
        var_a1 = -var_a1;
    }
    return arg1 < (var_a2 + var_a1);
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6CC8);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6E38);

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A6FB4);

void func_800A734C(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s32 *, 0x58) = 0x3C;
    }
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A7368);

void func_800A7398(s8 arg0, s8 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6FB4, 0x88, 0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg2;
    M2C_FIELD(temp_v0, s8 *, 0x53) = arg1;
    M2C_FIELD(temp_v0, s8 *, 0x52) = arg0;
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A73F0);

void *func_800A7460(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A73F0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7F94)();
    return temp_v0;
}

void func_800A74BC(void) {
    *D_8004B370 = 0x1E;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x8011, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG526/nonmatchings/WSTAG526", func_800A74F4);
