/* descompressao RLE incremental: para quando passar de 0x70 bytes */
void func_8001B554(u8 *o) {
    s32 total = 0;
    u8 *src = *(u8 **)(o + 0x68);
    u8 c = *src;
    u8 *dst = *(u8 **)(o + 0x6C);
    s32 stop = 0;
    s32 n;
    s32 i;

    while (c != 0) {
        if (c & 0x80) {
            /* repeticao: n copias do proximo byte */
            n = c & 0x7F;
            src++;
            for (i = 0; i < n; i++) {
                *dst++ = *src;
            }
            src++;
        } else {
            /* literal: n bytes */
            n = *src++;
            for (i = 0; i < n; i++) {
                *dst++ = *src++;
            }
        }
        total += n;
        if (total >= *(s32 *)(o + 0x70)) {
            stop = 1;
            *(u8 **)(o + 0x68) = src;
            *(u8 **)(o + 0x6C) = dst;
            break;
        }
        c = *src;
    }
    if (stop == 0) {
        (*(void (**)(void *, s32))(o + 0x2C))(o, 0);
    }
}
