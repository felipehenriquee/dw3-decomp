extern struct opaque D_80048ABC;
extern u8 D_80048D34[];
extern Ent0C D_800A71AC[];
void func_800A6008(u8 *o, s32 *w) {
    s32 i;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        for (i = 0; i < 4; i++) {
            if (D_800A71AC[i].off == 0) {
                w[i + 1] = (s32)func_800A6718(D_800A71AC[i].p, D_800A71AC[i].q, D_800A71AC[i].a);
            } else if (D_800A71AC[i].off == 2) {
                w[i + 1] = (s32)func_800A6774(0x34D);
            }
        }
        {
            u8 *d = D_80048D34;
            if (*(s32 *)(d + 0x263C) == 0x29) {
                u8 *f = (u8 *)&D_80048ABC;
                if ((*(s32 (**)(s32, s32))(f + 0x10))(0x4074, 0)) { w[0] = func_800853F8(0x424); goto end; }
                if (*(s32 *)(d + 0x263C) == 0x29 && (*(s32 (**)(s32, s32))(f + 0x10))(0x4074, 1) && (*(s32 (**)(s32, s32))(f + 0x10))(0x4075, 0)) {
                    w[0] = func_800853F8(0x42E);
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
