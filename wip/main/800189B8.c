s32 func_800189B8(s32 arg0) {
    if (*(s32 *)D_8004B7D0 & 0x800000) {
        if (*(s16 *)(D_8004B7D0 + 0x3D6) == arg0) {
            return 1;
        }
        return -1;
    }
    return 0;
}
