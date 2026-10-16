extern u16 *D_80042BC8[];
s32 func_800135E8(s32 arg0, u16 *out) {
    s32 idx = arg0 & 0x7FFFFFFF;
    s32 all = arg0 < 0;
    u16 *list;
    s32 n;
    u16 id;
    s8 *e;

    if (idx >= 5) {
        return 0;
    }
    list = D_80042BC8[idx];
    n = 0;
    if (*list != 0) {
        do {
            id = *list;
            e = (s8 *)D_80048D34 + id;
            if (e[0x7C] != 0 || (all && e[0x20F] != 0)) {
                *out++ = id;
                n++;
            }
            list++;
        } while (*list != 0);
    }
    return n;
}
