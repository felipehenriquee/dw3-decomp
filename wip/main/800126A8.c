s32 func_800126A8(void) {
    u8 *p = D_80048D34;
    s32 v = (*(s32 (**)(void))(p + 0x2704))();

    if (v == 0x1000) {
        v = *(s32 *)(p + 0x34);
    }
    if (v >= 0x2D7) {
        return -1;
    }
    return v >= 0x270;
}
