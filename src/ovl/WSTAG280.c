#include "WSTAG280.h"
#include "m2c.h"
#include "WSTAG280_auto.h"
#include "WSTAG280_data.h"

INCLUDE_ASM("asm/ovl/WSTAG280/nonmatchings/WSTAG280", func_800A5E10);

Obj *func_800A63CC(void) {
    return func_80014504(func_800A5E10, 0x64, 0x14);
}

void func_800A63F8(u8 *o, Obj **w) {
    u8 *f;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        f = (u8 *)&D_80048ABC;
        if ((*(s32 (**)(s32, s32))(f + 0x10))(0x7201, 0) != 0 && (*(s32 (**)(s32, s32))(f + 0x10))(0x8008, 0) != 0 &&
            (*(s32 (**)(s32, s32))(f + 0x10))(0x701A, 0) != 0) {
            w[0] = func_800853F8(0x42);
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A64B8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A63F8, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7934)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG280/nonmatchings/WSTAG280", func_800A6514);

void func_800A6608(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = 1;
    if (arg1 != 0) {
        ((void (*)(s32))D_80055C48[0])(0x40019);
        M2C_FIELD(arg0, s32 *, 4) = 0x1000 / M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 8) = 0;
    } else {
        ((void (*)(s32))D_80055C48[0])(0x4001A);
        M2C_FIELD(arg0, s32 *, 8) = 0x1000;
        M2C_FIELD(arg0, s32 *, 4) = -((0x1000 / M2C_FIELD(arg0, s32 *, 0)) * 2);
    }
}

s32 func_800A669C(Fade *f) {
    if (f->active == 0) {
        return 1;
    }
    f->value += f->speed;
    if (f->speed > 0) {
        if (f->value > 0x1000) {
            f->value = 0x1000;
            f->active = 0;
            return 1;
        }
    } else if (f->value < 0) {
        f->value = 0;
        f->active = 0;
        return 1;
    }
    return 0;
}
