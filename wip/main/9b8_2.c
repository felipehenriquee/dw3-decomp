s32 func_800189B8(s32 arg0) {
    u8 *p = D_8004B7D0;
    s32 ret = 0;

    if (*(s32 *)p & 0x800000) {
        ret = 1;
        if (*(s16 *)(p + 0x3D6) != arg0) {
            ret = -1;
        }
    }
    return ret;
}
