extern u8 D_80042B5F[];
s32 func_800A1308(u8 side, s32 k) {
    u8 *e;
    Rec18 *r;
    s32 lim;
    u8 *t;
    if (side == 0 && D_80042B5F[0] != 0) {
        return 0;
    }
    t = D_800A4460;
    e = func_8009EC94(side, 1, *(s32 *)(t + (side >> 4) * 4 + 8));
    r = &D_80042BCA[k];
    if (r->b[0xA] < 2) {
        lim = e[0x35];
    } else {
        lim = r->b[0xB];
    }
    return (((s32 (*)(void))D_8004DC0C)() & 0x7F) < lim;
}
