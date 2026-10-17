s32 func_800176AC(s32 who, s16 *out) {
    s32 i = 0;
    s32 n = 0;
    u8 *base = D_80048D34;
    s16 *o = out;
    s32 k;
    s32 off = who * 0x3DC;

    for (; i < 3; i++) {
        s16 id = *(s16 *)((off + i * 2) + base + 0x7B0);
        if (id >= 3) {
            k = func_8001764C(who, id);
            if (k >= 0 && *(s16 *)((off + k * 0x14) + base + 0x7B8) >= 3) {
                *o++ = *(s16 *)((off + k * 0x14) + base + 0x7B8);
                n++;
            }
        }
    }
    for (i = n; i < 3; i++) {
        out[i] = -1;
    }
    return n;
}

