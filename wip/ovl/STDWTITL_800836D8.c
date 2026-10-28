extern s32 D_80089250[];
s32 func_800836D8(DecEnv *dec) {
    s32 cnt = 2000;
    u32 *next;
    s32 t;
    while ((next = func_800835D4(dec)) == 0) {
        if (--cnt == 0) {
            return -1;
        }
    }
    t = D_80089250[0];
    dec->vlcid = dec->vlcid == 0;
    func_8008780C(next, dec->vlcbuf[dec->vlcid], t);
    StFreeRing(next);
    return 0;
}
