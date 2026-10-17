#include "WSTAG460.h"
#include "m2c.h"
#include "WSTAG460_auto.h"
#include "WSTAG460_data.h"

INCLUDE_ASM("asm/ovl/WSTAG460/nonmatchings/WSTAG460", func_800A5DE0);

void func_800A5F90(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x34C)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG460/nonmatchings/WSTAG460", func_800A5FC8);

s16 func_800A5FF8(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A5FF8(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG460/nonmatchings/WSTAG460", func_800A6118);

void func_800A630C(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s16 *, 0x52) = 0x14;
    }
}

INCLUDE_ASM("asm/ovl/WSTAG460/nonmatchings/WSTAG460", func_800A6328);

void func_800A6358(void) {
    func_80014504(func_800A6118, 0x5C, 0);
}

s16 func_800A6384(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A6384(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG460/nonmatchings/WSTAG460", func_800A64A4);

void func_800A676C(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s16 *, 0x52) = 0x96;
    }
}

INCLUDE_ASM("asm/ovl/WSTAG460/nonmatchings/WSTAG460", func_800A6788);

void func_800A67B8(void) {
    func_80014504(func_800A64A4, 0x64, 0);
}

s16 func_800A67E4(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A67E4(st, tbl, once, depth + 1);
    }
    return e[0];
}

s32 func_800A6904(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/WSTAG460/nonmatchings/WSTAG460", func_800A6940);

INCLUDE_ASM("asm/ovl/WSTAG460/nonmatchings/WSTAG460", func_800A6AB0);

INCLUDE_ASM("asm/ovl/WSTAG460/nonmatchings/WSTAG460", func_800A6C2C);

void func_800A6F08(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x50) = 2;
        M2C_FIELD(arg0, s32 *, 0x58) = 0x3C;
    }
}

INCLUDE_ASM("asm/ovl/WSTAG460/nonmatchings/WSTAG460", func_800A6F24);

void func_800A6F54(s8 arg0, s8 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6C2C, 0x80, 0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg2;
    M2C_FIELD(temp_v0, s8 *, 0x53) = arg1;
    M2C_FIELD(temp_v0, s8 *, 0x52) = arg0;
}

INCLUDE_ASM("asm/ovl/WSTAG460/nonmatchings/WSTAG460", func_800A6FAC);

void *func_800A701C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6FAC, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A76D8)();
    return temp_v0;
}

void func_800A7078(void) {
    *D_8004B370 = 0xF;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x8010, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG460/nonmatchings/WSTAG460", func_800A70B0);
