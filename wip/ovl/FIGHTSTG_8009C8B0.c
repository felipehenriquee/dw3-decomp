void func_8009C8B0(u8 a, s32 unused, s8 c) {
    s32 k = a != 0;
    u8 *q = D_800A4460;
    u8 *t = q + k * 4;
    s32 i = func_8009BC94(10, a, *(s32 *)(t + 8));
    s32 v;
    s32 *m;
    u8 *e;
    s32 idx;
    s32 j;
    D_800A3868[0xAF5] = c;
    v = func_8009BDA4(a, 9);
    if (i >= 0) {
        e = D_800A3868;
        *(s16 *)(e + i * 28 + 2) = v;
    } else {
        m = &D_800A4780;
        m[0] = 10;
        m[1] = v;
        m[2] = a;
        m[3] = *(s32 *)(t + 8);
        func_8009B930(m);
    }
    j = k * 3;
    e = D_800A4460;
    idx = *(s32 *)(e + k * 4 + 8);
    e += 0x10;
    e = (j << 5) + ((idx << 5) + e);
    e[0x1D] = c;
    e[0x1C] |= 2;
}

