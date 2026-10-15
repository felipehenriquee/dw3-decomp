s32 func_80017898(s32 arg0, u16 *out) {
    s32 i;
    s32 n = 0;
    u16 *p = out;
    s16 v;

    for (i = 0; i < 44; i++) {
        v = ((Unk80048D34_7B8 *)(D_80048D34 + arg0 * 0x3DC + i * 0x14))->unk7B8;
        if (v >= 3) {
            *p++ = v;
            n++;
        }
    }
    for (i = n; i < 44; i++) {
        out[i] = 0;
    }
    return n;
}
