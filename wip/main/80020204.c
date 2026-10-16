extern u8 D_80055BEC[];
extern s32 D_80055C34[];

/* para todas as sequencias dos 3 canais */
void func_80020204(void) {
    s32 i;
    s32 j;
    s32 k;
    u8 *e = D_80055BEC;

    for (i = 0; i < 3; i++, e += 0x18) {
        if (*(s16 *)(e + 4) != -1) {
            for (j = 0; j < *(s16 *)(e + 6); j++) {
                for (k = 0; k < 16; k++) {
                    SsSepStop(((s16 *)(e + 8))[j], (s16)k);
                }
            }
        }
    }
    SsUtAllKeyOff(0);
    D_80055C34[0] = 0;
}
