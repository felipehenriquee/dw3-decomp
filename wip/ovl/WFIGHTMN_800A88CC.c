extern u8 D_800A4470[];
void func_800A88CC(u8 *o, u8 **w) {
    u8 *b = (u8 *)D_800A3868;
    u8 *q;
    s32 j, i;
    u8 *e = (s8)b[0xAF1] * 28 + b;
    switch (*(s32 *)(o + 0x14)) {
    case 0:
    default:
        w[7] = (u8 *)func_8009A298();
        *(s32 *)(o + 0x50) = *(s32 *)(e + 0xC) + 0x5B;
        *(s32 *)(o + 0x54) = *(s32 *)(e + 4);
        *(s32 *)(o + 0x58) = *(s32 *)(e + 8);
        (*(void (**)(u8 *, s32, u8 *))(w[7] + 0xAC))(w[7], 7, o + 0x50);
        *(s32 *)(o + 0x14) += 1;
        break;
    case 1:
        if (w[7] == NULL) {
            j = *(s32 *)(e + 4) >> 4;
            i = *(s32 *)(e + 8);
            q = (u8 *)(j * 3 * 32) + (s32)(i * 32 + D_800A4470);
            *(s16 *)(q + *(s32 *)(e + 0xC) * 2 + 0x10) = 0;
            (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0);
        }
        break;
    }
}

