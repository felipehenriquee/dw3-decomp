void func_800A3D90(u8 *o, s32 j) {
    s8 *p;
    s32 best = 0xFFF;
    s32 bi = 0;
    s32 i, v;
    u8 *e;
    if (j == 1) {
        p = o + 0x44C;
    } else {
        p = o + 0x446;
    }

    for (i = 0; i < (o + j * 0x72)[0x72C]; i++) {
        if (p[i] != 0) {
            v = func_800A3934(o, j, 1 << i);
            if (v <= best) {
                best = v;
                p[bi] = 0;
                bi = i;
                p[i] = 1;
            } else {
                p[i] = 0;
            }
        }
    }
}
