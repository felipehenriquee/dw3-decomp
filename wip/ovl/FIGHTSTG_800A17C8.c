s32 func_800A17C8(u8 side, s32 x) {
    u8 *t;
    u8 *b;
    u8 *s;
    s32 k;
    s32 j;
    s32 lim;
    if (side == 0) {
        func_8009EC94(0, 0, D_800A4468);
    } else {
        func_8009EC94(0x10, 0, D_800A446C);
    }
    k = side != 0;
    t = D_800A4460;
    s = D_800A45C0;
    b = D_800A3868;
    j = (*(s32 (**)(s32, s32, s32))(b + 0xB0C))(12, side, *(s32 *)(t + k * 4 + 8));
    lim = (x << 7) / *(s16 *)(s + 4) + (0x40 - *(u8 *)(t + (k * 3 + *(s32 *)(t + k * 4 + 8)) * 32 + 0x2E) / 2) - (s16)(*(s16 *)(b + j * 28 + 2) / 100);
    return (((s32 (*)(void))D_8004DC0C)() & 0x7F) < lim;
}

