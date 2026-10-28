extern u8 D_80042B5D[];
s32 func_800A0E68(u8 side, s32 k) {
    u8 *t;
    u8 *s;
    u8 *p;
    Rec18 *r;
    s32 lim;
    if (side == 0) {
        if (D_80042B5D[0] != 0) {
            return 0;
        }
        t = D_800A4460;
        func_8009EC94(0, 1, *(s32 *)(t + 8));
        func_8009EC94(0x10, 0, *(s32 *)(t + 0xC));
    } else {
        t = D_800A4460;
        func_8009EC94(0, 0, *(s32 *)(t + 8));
        func_8009EC94(0x10, 1, *(s32 *)(t + 0xC));
    }
    s = D_800A4580;
    p = s + 0x40;
    r = &D_80042BCA[k];
    lim = r->b[0xB] + *(s16 *)(s + 8) / 8 - (*(s16 *)(p + 0x20) + *(s16 *)(p + 0x10) + *(s16 *)(p + 8) / 2) / 8;
    if (lim <= 0) {
        lim = 1;
    }
    if (lim >= 0x80) {
        lim = 0x7F;
    }
    return (((s32 (*)(void))D_8004DC0C)() & 0x7F) < lim;
}
