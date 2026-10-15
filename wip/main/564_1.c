u8 func_80015564(u8 *p, s32 n) {
    s32 i;
    s32 sum;

    for (sum = 0, i = 0; i < n; i++) {
        sum ^= *p++;
    }
    return sum;
}
