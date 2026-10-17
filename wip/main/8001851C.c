void func_8001851C(void) {
    u8 *pd = D_8004B7D0;
    u8 *rec = *(u8 **)(pd + 0x3D8) + *(s16 *)(pd + 0x3DC) * 34;
    s32 r;
    u8 *base;
    u8 *s;
    s32 p, i;
    s32 roff;
    s32 port;

    r = PadChkVsync();
    if (r != 1) {
        return;
    }
    if (++*(s16 *)(pd + 0x3DC) >= 0x707 && func_800189B8(*(s16 *)(pd + 0x3D6)) == r) {
        func_800189B0();
        return;
    }
    base = D_8004B7D0;
    for (p = 0; p < 2; p++) {
        port = p * 16;
        if (base[p * 0x22 + 5] == 0x80) {
            i = 0;
            s = base + 6 + p * 0x22;
            roff = 2;
            for (; i < 4; i++) {
                if (*(s32 *)D_8004B7D0 & 0x400000) {
                    func_80018BCC(port & 0xFF, s, rec + roff);
                } else {
                    func_80018F44((port + i) & 0xFF, s);
                }
                s += 8;
                roff += 8;
            }
        } else if (*(s32 *)D_8004B7D0 & 0x400000) {
            func_80018BCC(port & 0xFF, p * 0x22 + (base + 4), rec);
        } else {
            func_80018F44(port & 0xFF, p * 0x22 + (base + 4));
        }
    }
}
