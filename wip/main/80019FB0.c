void func_80019FB0(u8 *w) {
    s32 extra = 0;
    s32 depth;
    s32 go;
    s32 pos;
    s32 *tbl;
    u8 *p;

    if (*(s32 *)(w + 0xC) != 1) {
        return;
    }
    pos = *(s16 *)(w + 0xA6);
    depth = extra;
    go = 1;
    tbl = D_8004DE00;
    do {
        switch ((s32)((u32)((*(s32 (**)(u8 *, s32, s32))(tbl + 3))(*(u8 **)(w + 0x5C) + pos, w[0x66],
                                                           *(s32 *)(w + 0x50)) << 16) >> 24)) {
        default:
            if (*(s16 *)(w + 0x66) != 0) {
                pos += 2;
            } else {
                pos += 1;
            }
            break;
        case 1:
            pos += 2;
            break;
        case 2:
            p = *(u8 **)(w + 0x5C) + pos;
            switch (p[1]) {
            case 2:
                if (p[2] < 5) {
                    go = 0;
                }
                pos += ((s32 *)tbl[1])[2];
                break;
            case 1:
                if (++depth < w[0xBF]) {
                    pos += ((s32 *)tbl[1])[1];
                } else {
                    go = 0;
                }
                break;
            case 3:
                go = 0;
                break;
            case 5:
                if (p[2] < 6) {
                    extra += *(s16 *)(w + p[2] * 12 + 0x62);
                    pos += ((s32 *)tbl[1])[5];
                } else {
                    go = 0;
                }
                break;
            default:
                pos += ((s32 *)tbl[1])[p[1]];
                break;
            }
            break;
        case 4:
            go = 0;
            break;
        }
    } while (go);
    *(s16 *)(w + 0xA4) = pos + extra;
}
