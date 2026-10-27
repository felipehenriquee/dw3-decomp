extern FtE32d D_800A4470[];
s32 func_800A01AC(u8 side, s32 k, s32 crit) {
    u8 *e;
    s32 m;
    s32 v;
    if (side == 0) {
        e = (u8 *)&D_800A4470[k];
    } else {
        e = (u8 *)&D_800A44D0[k];
    }
    if (crit != 0) {
        m = ((s32 (*)(void))D_8004DC0C)() % 9 + 8;
        m = *(s16 *)(e + 6) * m;
    } else {
        m = ((s32 (*)(void))D_8004DC0C)() % 5 + 4;
        m = *(s16 *)(e + 6) * m;
    }
    v = m / 128;
    if (v >= 10000) {
        v = 9999;
    }
    return v;
}

