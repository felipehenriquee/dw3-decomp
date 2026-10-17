#include "WSTAG785.h"
#include "m2c.h"
#include "WSTAG785_auto.h"
#include "WSTAG785_data.h"

s16 func_800A5DE4(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A5DE4(st, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A5F04);

void func_800A61A4(void) {
    M2C_FIELD(func_80014504(func_800A5F04, 0x6C, 0), s32 *, 0x50) = 1;
}

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A61D8);

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A6208);

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A62B4);

u8 *func_800A6510(s32 link) {
    return func_800143DC(func_800A62B4, 0x58, 0, link);
}

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A6540);

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A660C);

void *func_800A66B0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A660C, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A75D8)();
    return temp_v0;
}

void func_800A670C(void) {
    *D_8004B370 = 1;
}

INCLUDE_ASM("asm/ovl/WSTAG785/nonmatchings/WSTAG785", func_800A671C);
