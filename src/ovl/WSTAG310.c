#include "WSTAG310.h"
#include "m2c.h"
#include "WSTAG310_auto.h"
#include "WSTAG310_data.h"

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

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A5F34);

Obj *func_800A6084(void) {
    return func_80014504(func_800A5F34, 0x60, 0);
}

/* animacao com o estado em st[2], st[3] (ver func_800A6DD8) */
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

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A61D0);

void func_800A6598(u8 *o, s32 id) {
    if (o != NULL && id == 0x359) {
        *(s16 *)(o + 0x58) = 0;
        *(s16 *)(o + 0x5A) = D_800A8392[0];
        *(s16 *)(o + 0x60) = 0;
        *(s16 *)(o + 0x62) = D_800A83C6[0];
        *(s32 *)(o + 0x50) = 3;
    }
}

u8 *func_800A65D4(s32 arg0) {
    u8 *o = func_800143DC(func_800A61D0, 132, 0, arg0);

    *(s32 *)(o + 0x50) = 2;
    return o;
}

Obj *func_800A660C(void) {
    return func_80014504(func_800A61D0, 0x84, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6638);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6758);

void func_800A6B1C(u8 *o, s32 id) {
    if (o != NULL && id == 0x359) {
        *(s16 *)(o + 0x5C) = 0;
        *(s16 *)(o + 0x5E) = D_800A849E[0];
        *(s16 *)(o + 0x68) = 0;
        *(s16 *)(o + 0x6A) = D_800A84D2[0];
        *(s32 *)(o + 0x50) = 3;
    }
}

u8 *func_800A6B58(s32 arg0) {
    u8 *o = func_800143DC(func_800A6758, 156, 0, arg0);

    *(s32 *)(o + 0x50) = 2;
    return o;
}

Obj *func_800A6B90(void) {
    return func_80014504(func_800A6758, 0x9C, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6BBC);

void *func_800A6D7C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6BBC, 0x54, 0x18);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A8CE4)();
    return temp_v0;
}

/* como a animacao em laco, mas com once != 0 para no fim (retorna 0xFF) */
s16 func_800A6DD8(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A6DD8(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6EF8);

/* o retangulo (x, y, w, h) toca o retangulo do objeto 0x1002? */
s32 func_800A6FE8(s32 x, s32 y, s32 w, s32 h) {
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

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A70AC);

u8 *func_800A72CC(s32 link) {
    u8 *o = func_800143DC(func_800A70AC, 0x6C, 0, link);

    *(s32 *)(o + 0x54) = 0x26C;
    *(s32 *)(o + 0x58) = 0xFC;
    ((void (*)(s32))D_80055C48[0])(0x4001D);
    *(s32 *)(o + 0x50) = 0x14;
    return o;
}

s16 func_800A7338(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A7338(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A7458);

s32 func_800A7540(s32 x, s32 y, s32 w, s32 h) {
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

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A7604);

void func_800A7894(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A7604, 0x6C, 0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg2;
}

extern struct opaque D_80048ABC;
void func_800A78EC(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0xC13, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7401, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x404E, 1);
}

extern struct opaque D_80048ABC;
void func_800A794C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x404F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

void func_800A7998(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4050, 1);
}

void func_800A79C4(void) {
    *D_8004B370 = 0x27;
}

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A79D4);
