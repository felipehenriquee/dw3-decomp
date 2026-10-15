u8 func_80015564(u8 *p, s32 n) {
    s32 i;
    u8 sum = 0;

    for (i = 0; i < n; i++) {
        sum ^= p[i];
    }
    return sum;
}
