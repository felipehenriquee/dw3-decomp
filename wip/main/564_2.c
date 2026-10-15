u8 func_80015564(u8 *p, s32 n) {
    u8 sum = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        sum ^= *p++;
    }
    return sum;
}
