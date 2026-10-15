void func_80016B28(void) {
    u8 *p = D_80048D34;
    s32 v = *(s32 *)(p + 0x26C8);
    s32 old;

    if (v != 0) {
        old = *(s32 *)(p + 0x26C4);
        *(s32 *)(p + 0x26C4) = v;
        *(s32 *)(p + 0x26C8) = 0;
        *(s32 *)(p + 0x26CC) = old;
    }
}
