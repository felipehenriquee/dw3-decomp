#include "WSTAG924.h"
#include "m2c.h"
#include "WSTAG924_auto.h"
#include "WSTAG924_data.h"

void func_800A5E44(void *arg0) {
    switch (M2C_FIELD(arg0, s32 *, 0xC)) {
    case 0:
    default:
        M2C_FIELD(arg0, void (**)(void *), 0x38)(arg0);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5E8C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5E44, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A79EC)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG924/nonmatchings/WSTAG924", func_800A5EE8);

void func_800A5FFC(void *arg0, s32 arg1) {
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

s32 func_800A6090(Fade *f) {
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

INCLUDE_ASM("asm/ovl/WSTAG924/nonmatchings/WSTAG924", func_800A60FC);

void func_800A6A68(void) {
    func_80014504(func_800A60FC, 0x84, 0x28);
}

INCLUDE_ASM("asm/ovl/WSTAG924/nonmatchings/WSTAG924", func_800A6A94);

void func_800A7400(void) {
    func_80014504(func_800A6A94, 0x84, 0x28);
}
