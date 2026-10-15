s32 func_800189B8(s32 arg0) {
    s32 ret;

    if (*(s32 *)D_8004B7D0 & 0x800000) {
        if (*(s16 *)(D_8004B7D0 + 0x3D6) == arg0) {
            ret = 1;
        } else {
            ret = -1;
        }
    } else {
        ret = 0;
    }
    return ret;
}
