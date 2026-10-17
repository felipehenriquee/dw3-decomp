#include "WSTAG406.h"
#include "m2c.h"
#include "WSTAG406_auto.h"
#include "WSTAG406_data.h"

s16 func_800A5DE0(s16 *st, s16 *tbl, s32 depth) {
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
        func_800A5DE0(st, tbl, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG406/nonmatchings/WSTAG406", func_800A5ED4);

Obj *func_800A5FA8(void) {
    return func_80014504(func_800A5ED4, 0x54, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG406/nonmatchings/WSTAG406", func_800A5FD4);

void *func_800A6084(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5FD4, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6A9C)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A60E0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x407A, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A612C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x407B, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8AF5, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG406/nonmatchings/WSTAG406", func_800A6178);
