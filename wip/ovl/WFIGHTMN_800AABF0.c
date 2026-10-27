s32 func_800AABF0(u8 side, s32 dmg, s32 n) {
    s32 k = side == 0;
    u8 *t = D_800A4460;
    u8 *e = k * 3 * 32 + (*(s32 *)(t + k * 4 + 8) * 32 + (t + 0x10));
    s16 lim;
    s32 hp;
    switch (*(s16 *)(t + 0xD6)) {
    case 1:
    case 2:
        if (side != 0) {
            return dmg;
        }
        lim = *(s16 *)(e + 6) / 11;
        if (n != 0) {
            hp = *(s16 *)(e + 8);
            if (hp <= lim) {
                return 0;
            }
            if (hp - dmg * n < lim) {
                dmg = (hp - lim) / n;
                return dmg;
            }
        } else {
            hp = *(s16 *)(e + 8);
            if (hp <= lim) {
                return 0;
            }
            if (hp - dmg < lim) {
                dmg = hp - lim;
            }
        }
        break;
    case 3:
        if (side == 0) {
            dmg = 0;
        }
        break;
    }
    return dmg;
}
