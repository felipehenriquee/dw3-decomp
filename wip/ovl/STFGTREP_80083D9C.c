s32 func_80083D9C(u8 *o) {
    s32 c = 0;
    s32 n, m, i, v, lim;
    u8 *b = *(u8 **)(o + 0x24);
    *(s32 *)(o + 0x140) += 1;
    if (*(s32 *)(o + 0x140) >= 10) {
        *(s32 *)(o + 0x138) = *(s32 *)(o + 0x13C);
        func_80083404(o, b, 1);
        return 0;
    }
    n = *(s32 *)(o + 0x13C);
    for (m = 10; n != 0; m *= 10) {
        n -= n % m;
        c++;
    }
    i = 1;
    for (m = c - 1; m != 0; m--) {
        i = i * 10;
        i++;
    }
    v = *(s32 *)(o + 0x138) + i;
    lim = i * 9;
    *(s32 *)(o + 0x138) = v;
    if (lim < v) {
        *(s32 *)(o + 0x138) = --v - lim;
    }
    func_80083404(o, b, 1);
    return 1;
}
