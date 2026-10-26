#include "STAGSLCT.h"
#include "m2c.h"
#include "STAGSLCT_auto.h"
#include "STAGSLCT_data.h"

/* estado 0: cria o objeto e guarda em *out */
void func_800849CC(u8 *o, Obj **out) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *out = func_80085EA4();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

Obj *func_80084A30(void) {
    return func_80014504(func_800849CC, 0x50, 4);
}

void func_80084A5C(u8 *o, s32 d) {
    s32 stop = 0;
    s32 oy = *(s32 *)(o + 0x54);
    s32 ox = *(s32 *)(o + 0x50);
    s32 v;
    do {
        *(s32 *)(o + 0x50) += d;
        if (*(s32 *)(o + 0x50) < 0) {
            *(s32 *)(o + 0x50) = 0;
            *(s32 *)(o + 0x54) -= 1;
            if (*(s32 *)(o + 0x54) < 0) {
                *(s32 *)(o + 0x54) = 0;
                stop = 1;
            }
        }
        v = *(s32 *)(o + 0x58) - 1;
        if (v < *(s32 *)(o + 0x50)) {
            *(s32 *)(o + 0x50) = v;
            *(s32 *)(o + 0x54) += 1;
            if (*(s32 *)(o + 0x5C) - *(s32 *)(o + 0x58) < *(s32 *)(o + 0x54)) {
                *(s32 *)(o + 0x54) = *(s32 *)(o + 0x5C) - *(s32 *)(o + 0x58);
                stop = 1;
            }
        }
        if (D_80085EEC[*(s32 *)(o + 0x54) + *(s32 *)(o + 0x50)].c != 0) {
            return;
        }
    } while (stop == 0);
    *(s32 *)(o + 0x54) = oy;
    *(s32 *)(o + 0x50) = ox;
}

void func_80084B2C(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_v1;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0x54) + arg1;
    M2C_FIELD(arg0, s32 *, 0x54) = temp_a1;
    if (temp_a1 < 0) {
        M2C_FIELD(arg0, s32 *, 0x54) = 0;
        return;
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x5C) - M2C_FIELD(arg0, s32 *, 0x58);
    if (temp_v1 < temp_a1) {
        M2C_FIELD(arg0, s32 *, 0x54) = temp_v1;
    }
}

INCLUDE_ASM("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", func_80084B70);

INCLUDE_ASM("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", func_80084C94);

INCLUDE_RODATA("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", D_80082CB0);

INCLUDE_RODATA("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", D_800849A4);

INCLUDE_ASM("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", func_80084D9C);

Obj *func_80085EA4(void) {
    return func_80014504(func_80084D9C, 0, 0);
}
