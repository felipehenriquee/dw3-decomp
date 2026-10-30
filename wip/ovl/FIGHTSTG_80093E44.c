extern Block32 D_800A34CC[];
extern s32 D_8004BBC4[];
extern s32 D_80055C48[];
void func_80093E44(u8 *o, Obj **w) {
    u8 b;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *w = func_8009B0C8(D_800A34CC);
        (*w)->unk50 = *(s32 *)(o + 0x50);
        func_80093CF4(o);
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        if (((s32 (*)(s32))D_8004BBC4[0])(0) & 0x2000) {
            ((void (*)(s32))D_80055C48[0])(0x4001C);
            { u8 *tb = D_800A4460; b = (tb + *(s32 *)(tb + 8) * 32)[0x2C]; }
            if ((b & 8) && (*w)->unk50 < 3) break;
            if ((b & 0x20) && (*w)->unk50 == 2) break;
            **(s32 **)(o + 0x54) = (*w)->unk50;
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
            (*w)->unk54 = 1;
        }
        break;
    case 2:
    case 3:
        break;
    }
}
