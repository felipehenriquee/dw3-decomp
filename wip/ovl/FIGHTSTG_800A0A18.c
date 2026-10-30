extern u8 D_80042B5A[];
u8 func_800A0A18(u8 side, s32 id) {
    u8 *a;
    u8 *b;
    Rec18 *r;
    s32 lv, k, v;
    u8 m;
    if (side == 0) {
        s32 *tb;
        if (D_80042B5A[0] != 0) return 0;
        tb = (s32 *)D_800A4460;
        func_8009EC94(0, 1, tb[2]);
        func_8009EC94(0x10, 0, tb[3]);
    } else {
        s32 *tb = (s32 *)D_800A4460;
        func_8009EC94(0, 0, tb[2]);
        func_8009EC94(0x10, 1, tb[3]);
    }
    a = D_800A4580;
    r = &D_80042BCA[id];
    b = a + 0x40;
    if (r->b[0xA] < 2) {
        m = a[0x2E];
        v = a[0x2D] + *(s16 *)(a + 8) / 8;
    } else {
        m = r->b[0xC];
        v = r->b[0xB] + *(s16 *)(a + 8) / 8;
    }
    k = v - (*(s16 *)(b + 0x1A) + *(s16 *)(b + 0xE) + *(s16 *)(b + 8) / 2) / 8;
    if (k <= 0) k = 1;
    if (k >= 0x80) k = 0x7F;
    if ((((s32 (*)(void))D_8004DC0C)() & 0x7F) >= k) m = 0;
    return m;
}

