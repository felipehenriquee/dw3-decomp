extern s32 D_800A4654[];
void func_800A7FE4(u8 *o, u8 **w) {
    u8 *b;
    u8 *e;
    switch (*(s32 *)(o + 0x18)) {
    case 0:
    default:
        b = D_800A3868;
        e = (s8)b[0xAF1] * 28 + b;
        if (((s32 (*)(s32))D_800A4654[0])(e[4]) != 0) {
            *(s32 *)(o + 0x18) = 1;
            *(s16 *)e = 0;
            w[7] = (u8 *)func_8009A298();
            if (*(s32 *)(e + 4) == 0) {
                *(s32 *)(o + 0x50) = 0x43;
            } else {
                *(s32 *)(o + 0x50) = 0x5F;
            }
            *(s32 *)(o + 0x54) = *(s32 *)(e + 4);
            (*(void (**)(u8 *, s32, u8 *))(w[7] + 0xAC))(w[7], 2, o + 0x50);
        } else {
            *(s16 *)(e + 2) = (*(s32 (**)(s32, s32))(b + 0xB14))(e[4], 1);
            (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0);
        }
        break;
    case 1:
        if (w[7] == NULL) {
            func_8009C534(0);
            (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0);
        }
        break;
    }
}
