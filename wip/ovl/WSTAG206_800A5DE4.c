extern struct opaque D_80048ABC;
extern u8 D_80048D34[];
void func_800A5DE4(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        {
        u8 *d = D_80048D34;
        if (*(s32 *)(d + 0x263C) == 0x24) {
            u8 *f = (u8 *)&D_80048ABC;
            if ((*(s32 (**)(s32, s32))(f + 0x10))(0x40CA, 0)) { w[0] = func_800853F8(0x399); goto end; }
            if (*(s32 *)(d + 0x263C) == 0x24 && (*(s32 (**)(s32, s32))(f + 0x10))(0x40CA, 1)) {
                w[0] = func_800853F8(0x39A);
            }
        }
        }
    end:
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}
