extern u8 D_8004DCF4[];
void func_8001C948(u8 *o, s32 x, s32 y) {
    s32 i;
    u8 **w;
    u8 **p;
    u8 *c;
    s32 k;
    s16 *t;
    s32 xx, yy;

    w = *(u8 ***)(o + 0x24);
    *(s16 *)(o + 0x60) = x;
    *(s16 *)(o + 0x62) = y;
    for (i = 0, p = w; i < 3; i++, p++) {
        c = *p;
        if (c != NULL && *(s32 *)(c + 0xC) == 1) {
            *(s16 *)(c + 0x50) = *(s16 *)(c + 0x6C) + x;
            *(s16 *)(c + 0x52) = *(s16 *)(c + 0x6E) + y;
        }
    }
    c = w[3];
    k = *(s32 *)(o + 0x58);
    if (c != NULL) {
        t = (s16 *)(D_8004DCF4 + k * 32);
        xx = *(s16 *)(o + 0x60) + t[10];
        yy = *(s16 *)(o + 0x62) + t[11];
        if ((u32)k < 2) {
            xx -= *(s16 *)(o + 0x64);
        }
        (*(void (**)(u8 *, s16, s16))(c + 0x134))(c, xx, yy);
    }
    c = w[4];
    if (c != NULL) {
        t = (s16 *)(D_8004DCF4 + k * 32);
        xx = *(s16 *)(o + 0x60) + t[12];
        yy = *(s16 *)(o + 0x62) + t[13];
        if ((u32)k < 2) {
            xx -= *(s16 *)(o + 0x64);
        }
        (*(void (**)(u8 *, s16, s16))(c + 0x134))(c, xx, yy);
    }
}
