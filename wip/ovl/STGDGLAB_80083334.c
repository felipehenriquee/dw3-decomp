extern s32 D_8008FD68[];
s32 func_80083334(u8 *arg0, s32 arg1, u32 k, s32 m) {
    u8 *o = arg0;
    s32 slot = arg1;
    s32 i, j;
    s32 *out;
    s16 *p;
    s32 *cnt;
    s32 t;
    if (k >= 5) return 0;
    i = 0;
    cnt = (s32 *)(o + slot * 4);
    t = *(s32 *)(o + 0xBC);
    out = (s32 *)(o + slot * 0x50 + 0xD0 + m * 0x14);
    cnt[0x88] = 0;
    p = ((s16 (*)[6])(&D_8008FD68[t])[2])[slot * 4 + k] + 1;
    do {
        *out = 0;
        if (*p > 0) {
            s16 v = *p;
            for (j = 0; j < *(s32 *)(o + 0xB8); j++) {
                if (((s16 *)(o + 0x60))[j] == v) {
                    *out = ((s16 *)(o + 0x60))[j];
                    cnt[0x88] += 1;
                    break;
                }
            }
        }
        out++; i++; p++;
    } while (i < 5);
    if (*(s32 *)(o + slot * 4 + 0x220) < ((s16 (*)[6])(&D_8008FD68[t])[2])[slot * 4 + k][0])
        *(s32 *)(o + slot * 4 + 0x210) = 0;
    return 5;
}
