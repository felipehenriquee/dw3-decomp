#include "WSTAG261.h"
#include "m2c.h"
#include "WSTAG261_auto.h"
#include "WSTAG261_data.h"

INCLUDE_ASM("asm/ovl/WSTAG261/nonmatchings/WSTAG261", func_800A5DFC);

void func_800A6218(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        switch (arg1) {                             /* irregular */
        case 0x348:
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
            M2C_FIELD(arg0, s16 *, 0x58) = 0;
            return;
        case 0x349:
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
            M2C_FIELD(arg0, s16 *, 0x58) = 1;
            break;
        }
    }
}

extern struct opaque D_80048ABC;
u8 *func_800A628C(s32 link) {
    u8 *o = func_800143DC(func_800A5DFC, 0x6C, 0, link);

    if ((*(s32 (**)(s32, s32))((u8 *)&D_80048ABC + 0x10))(0x1C3D, 1) != 0) {
        *(s16 *)(o + 0x58) = 1;
    } else {
        *(s16 *)(o + 0x58) = 0;
    }
    return o;
}

void func_800A62F4(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        w[0] = func_800A628C(0x33B);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A634C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A62F4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6940)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG261/nonmatchings/WSTAG261", func_800A63A8);
