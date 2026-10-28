s32 func_800870E0(s32 *p) {
    s32 v, d, e;
    if (p[6] == 0) {
        return 1;
    }
    d = p[5];
    v = p[3] + d;
    p[3] = v;
    v >>= 8;
    p[2] = v;
    if (d > 0) {
        e = p[4];
        v = e < v;
    } else {
        e = p[4];
        v = v < e;
    }
    if (v != 0) {
        p[2] = e;
        p[6] = 0;
        return 1;
    }
    return 0;
}
