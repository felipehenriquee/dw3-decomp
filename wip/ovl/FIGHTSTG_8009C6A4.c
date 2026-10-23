void func_8009C6A4(u8 a, s32 b, s32 c) {
    s32 i = func_8009BC94(6, a, b);
    s32 *m;
    if (i >= 0) {
        *(s32 *)(D_800A3868 + i * 28 + 0xC) = 0xBD;
    } else {
        m = &D_800A4780;
        m[0] = 6;
        m[1] = 1000;
        m[2] = a;
        m[3] = b;
        m[4] = c;
        func_8009B930(m);
    }
}
