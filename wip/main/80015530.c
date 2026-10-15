/* confere o checksum XOR de n bytes */
s32 func_80015530(u8 *p, s32 n, u8 expected) {
    u8 sum = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        sum ^= *p++;
    }
    return sum == expected;
}
