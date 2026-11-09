extern struct opaque D_80048ABC;
extern u8 D_80048D34[];
extern s32 D_80048ACC[];
extern Ent0C D_800A8504[];
void func_800A6BBC(u8 *o, s32 *w) {
    s32 i;

    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        w[0] = (s32)func_800A6084();
        for (i = 0; i < 2; i++) {
            if (D_800A8504[i].off == 0) {
                w[i + 3] = (s32)func_800A7894(D_800A8504[i].p, D_800A8504[i].q, D_800A8504[i].a);
            }
        }
        {
        u8 *d = D_80048D34;
        if (*(s32 *)(d + 0x263C) == 0x17) {
            u8 *f = (u8 *)&D_80048ABC;
            if ((*(s32 (**)(s32, s32))(f + 0x10))(0x404E, 0)) { w[5] = func_800853F8(0x2A8); goto end; }
            if (*(s32 *)(d + 0x263C) == 0x17) {
                if ((*(s32 (**)(s32, s32))(f + 0x10))(0x404E, 1) && (*(s32 (**)(s32, s32))(f + 0x10))(0x404F, 0)) {
                    w[5] = func_800853F8(0x2A9);
                    w[1] = (s32)func_800A65D4(0x33F);
                    w[2] = (s32)func_800A6B58(0x340);
                    goto end;
                }
                if (D_8004B370[0] == 0x17 && ((s32 (*)(s32, s32))D_80048ACC[0])(0x404F, 1)) { w[5] = func_800853F8(0x2AA); goto end; }
            }
        }
        }
        if (D_8004B370[0] == 0x26) {
            w[5] = func_800853F8(0x3C1);
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
/* 7 dif (s0/s1 de v e f). O permuter zerou com
   if (D_800A8504 || f) { bloco 0x2A9 } else { mesmo bloco }
   em volta do bloco 0x2A9: falta achar a forma real. */
