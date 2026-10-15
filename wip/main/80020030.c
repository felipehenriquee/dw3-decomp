s32 func_80020030(s32 arg0) {
    s32 i;
    u8 *p;

    for (i = 0, p = D_800519EC; i < 3; i++, p += 0x18) {
        if (*(s32 *)(p + 0x4200) == arg0) {
            return i;
        }
    }
    return -1;
}
