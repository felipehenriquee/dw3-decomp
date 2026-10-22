
s32 func_800A1F74(s32 mode, s32 a, s32 r) {
    s32 x;

    switch (mode) {
    case 0:
    default:
        x = a >> 2;
        break;
    case 1:
        x = a >> 2;
        x += 0x400;
        break;
    case 2:
        x = a >> 1;
        break;
    }
    x = rsin(x);
    return x * r / 4096;
}
