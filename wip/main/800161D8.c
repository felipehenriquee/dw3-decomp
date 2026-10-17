void func_800161D8(s32 item, s32 add) {
    s8 *p;
    s32 i;
    u8 *q;

    if (add) {
        p = (s8 *)D_80048D34 + item;
        if (++p[0x7C] >= 100) {
            p[0x7C] = 99;
        }
        return;
    }
    p = (s8 *)D_80048D34 + item;
    if (p[0x7C] != 0) {
        if (--p[0x7C] < 0) {
            p[0x7C] = 0;
        }
        return;
    }
    if (p[0x20F] == 0) {
        return;
    }
    for (i = 0; i < 3; i++) {
        if (func_80016124((*(s32 (**)(s32))(D_80048D34 + 0x2718))(i), item)) {
            goto found;
        }
    }
    q = D_80048D34;
    for (i = 0; i < 8; i++, q += 0x3DC) {
        if (*(s32 *)(q + 0x760) >= 3 && func_80016124(i, item)) {
            break;
        }
    }
found:
    {
        u8 *b = D_80048D34 + item;
        b[0x20F]--;
    }
}

