#include "WSTAG620.h"
#include "m2c.h"
#include "WSTAG620_auto.h"
#include "WSTAG620_data.h"

s16 func_800A5DE0(u8 *o, s16 *tbl, s32 once, s32 depth) {
    s16 *e = tbl + *(s16 *)(o + 0x8) * 2;
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        *(s16 *)(o + 0xA) -= dt;
    }
    if (*(s16 *)(o + 0xA) <= 0) {
        *(s16 *)(o + 0x8) += 1;
        e += 2;
        *(s16 *)(o + 0xA) += e[1];
        if (once != 0) {
            if (e[0] == 0xFF) {
                return 0xFF;
            }
        } else if (e[0] == 0xFF) {
            e = tbl;
            *(s16 *)(o + 0x8) = 0;
            *(s16 *)(o + 0xA) += e[1];
        }
        func_800A5DE0(o, tbl, once, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG620/nonmatchings/WSTAG620", func_800A5F00);

u8 *func_800A6198(s32 arg0) {
    return func_800143DC(func_800A5F00, 128, 0, arg0);
}

INCLUDE_ASM("asm/ovl/WSTAG620/nonmatchings/WSTAG620", func_800A61C8);

void *func_800A6314(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A61C8, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7F38)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A6370(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x403B, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

void func_800A63BC(void) {
    *D_8004B370 = 0x14;
}

extern struct opaque D_80048ABC;
void func_800A63CC(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x1C1C, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x403A, 1);
}

void func_800A6418(void) {
    *D_8004B370 = 0x15;
}

INCLUDE_ASM("asm/ovl/WSTAG620/nonmatchings/WSTAG620", func_800A6428);
