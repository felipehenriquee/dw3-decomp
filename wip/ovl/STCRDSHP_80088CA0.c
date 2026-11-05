typedef struct { s32 k; s32 v; } ShKV;
extern ShKV D_8008CB28[];
extern s32 D_8004B448[];
Obj *func_80088CA0(void) {
    u8 *o = (u8 *)func_80014504(func_80088B50, 0x3CC, 0x2C);
    ShKV *p;
    u8 *t;
    u8 *d;
    s32 k;
    *(void (**)(u8 *))(o + 0x3C8) = func_80088AFC;
    *(s32 *)(o + 0x50) = 0x1000;
    *(s32 *)(o + 0x54) = 7;
    d = (u8 *)D_80048D34;
    *(s32 *)(o + 0x60) = (*(s32 (**)(void))(d + 0x2708))();
    k = *(s32 *)(d + 0x34);
    for (p = D_8008CB28; p->k != 0; p++) {
        if (p->k == k) {
            *(s32 *)(o + 0x64) = p->v;
        }
    }
    if (*(s32 *)(o + 0x64) == 0) {
        *(s32 *)(o + 0x64) = 0x1F;
    }
    if (((s32 (*)(s32))D_8004B448[0])(k) == 0x400) {
        *(s32 *)(o + 0x6C) = 2;
    }
    t = (u8 *)D_80044B38;
    (*(void (**)(s32))(t + 0x40C))(0x7F6);
    (*(void (**)(s32))(t + 0x40C))(0x7F7);
    (*(void (**)(s32))(t + 0x40C))(0x7F8);
    (*(void (**)(s32))(t + 0x40C))(0x7F9);
    (*(void (**)(s32))(t + 0x40C))(0x7FA);
    (*(void (**)(s32))(t + 0x40C))(D_8005CCA8[0] + 0x16);
    (*(void (**)(s32))(t + 0x40C))(D_8005CCA8[0] + 0x1D);
    return (Obj *)o;
}
