s32 func_800A3E9C(u8 *o, s32 j) {
    s8 *p;
    s32 i;
    s32 r = 0;
    u8 n;
    if (j == 1) {
        p = o + 0x44C;
    } else {
        p = o + 0x446;
    }
    n = o[j * 0x72 + 0x72C];
    for (i = 0; i < n; i++) {
        if (p[i] != 0) {
            r = 1;
            o[*(s8 *)(o + 0x575) * 8 + 0x586] = o[(j * 57 + i * 7) * 2 + 0x73A];
            break;
        }
    }
    return r;
}
====
s32 func_800A3E9C(u8 *o, s32 j) {
    s8 *p;
    s32 i;
    s32 r = 0;
    u8 n;
    if (j == 1) {
        p = o + 0x44C;
    } else {
        p = o + 0x446;
    }
    n = o[j * 0x72 + 0x72C];
    for (i = 0; i < n; i++) {
        if (p[i] != 0) {
            r = 1;
            o[*(s8 *)(o + 0x575) * 8 + 0x586] = o[(j * 57 + i * 7) * 2 + 0x73A];
            return r;
        }
    }
    return r;
}
