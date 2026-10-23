extern s32 D_800A446C NOT_GP;
extern s16 D_800A4588;
s32 func_800A0108(u8 side, s32 k) {
    u16 x;
    s32 v;
    if (side == 0) {
        func_8009EC94(0, 1, D_800A4468);
    } else {
        func_8009EC94(0x10, 1, D_800A446C);
    }
    x = D_80042BCA[k].h[1];
    v = x * 64 + D_800A4588 * x / 8;
    if (v >= 10000) {
        v = 9999;
    }
    return v;
}
