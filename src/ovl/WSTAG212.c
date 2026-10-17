#include "WSTAG212.h"
#include "m2c.h"
#include "WSTAG212_auto.h"
#include "WSTAG212_data.h"

s16 func_800A5DE4(s16 *st, s16 *tbl, s32 depth) {
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
        func_800A5DE4(st, tbl, depth + 1);
    }
    return e[0];
}

/* zera os 3 contadores e copia o segundo valor de cada tabela */
void func_800A5EBC(u8 *o) {
    s32 i;

    for (i = 0; i < 3; i++) {
        *(s16 *)(o + i * 8 + 0x5C) = 0;
        *(s16 *)(o + i * 8 + 0x5E) = D_800A816C[i][1];
    }
}

INCLUDE_ASM("asm/ovl/WSTAG212/nonmatchings/WSTAG212", func_800A5EF4);

INCLUDE_ASM("asm/ovl/WSTAG212/nonmatchings/WSTAG212", func_800A6148);

u8 *func_800A61FC(s32 link) {
    return func_800143DC(func_800A5EF4, 0x70, 0, link);
}

INCLUDE_ASM("asm/ovl/WSTAG212/nonmatchings/WSTAG212", func_800A622C);

void *func_800A63DC(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A622C, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A8E94)();
    return temp_v0;
}

void func_800A6438(void) {
    *D_8004B370 = 3;
}

INCLUDE_ASM("asm/ovl/WSTAG212/nonmatchings/WSTAG212", func_800A6448);

void func_800A6494(void) {
    *D_8004B370 = 0xC;
}

void func_800A64A4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4005, 0);
    *D_8004B370 = 0xE;
}

INCLUDE_ASM("asm/ovl/WSTAG212/nonmatchings/WSTAG212", func_800A64D8);
