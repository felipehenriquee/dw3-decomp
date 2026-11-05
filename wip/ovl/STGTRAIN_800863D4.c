extern s32 D_8004B484[];
extern s32 D_8003EF5C[];
extern u8 **D_8008C454[];
s32 func_800863D4(u8 *o, s32 k) {
    u32 j = k - 8;
    s16 *p;
    u8 *d;
    s32 v;
    s32 m;
    u8 *e;
    if (j >= 7) return 0;
    p = (s16 *)(((u8 *(*)(s32))D_8004B484[0])(*(s32 *)(o + 0x5C)) + (k * 2 + 0x24));
    d = (u8 *)D_8003EF5C + *(s32 *)(o + 0x5C) * 0x58;
    if (*p < 0x64) {
        v = ((d + j)[0x49] - 1) * 3;
    } else if (*p < 0x12C) {
        v = ((d + j)[0x49] - 1) * 3 + 1;
    } else {
        v = ((d + j)[0x49] - 1) * 3 + 2;
    }
    e = (u8 *)D_8008C454[v];
    m = 0;
    if (*(s32 *)(o + 0xD8) != 0) {
        m = 2;
        if (*(s32 *)(o + 0x60) < 0xD) m = 1;
    }
    m += *(s32 *)(*(u8 **)(o + 0x50) + 0x7C) * 3;
    e += m * 8;
    if (*(s32 *)(e + 4) != 0) {
        v = *(s32 *)e + ((s32 (*)(void))D_8004DC0C)() % *(s32 *)(e + 4);
    } else {
        v = *(s32 *)e;
    }
    *p += v;
    if (*p >= 0x3E8) *p = 0x3E7;
    return v;
}
