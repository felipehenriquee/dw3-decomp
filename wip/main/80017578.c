/* contadores: a[6] em 0xC (ids 1..6; id 7 = os seis) e b[7] em 0x18 (ids 8..14) */
typedef struct {
    u8 pad0[0xC];
    s16 a[6];
    s16 b[7];
} Unk80017578;

/* soma a um contador, com teto de 999 (13 instrucoes diferentes) */
void func_80017578(Unk80017578 *c, s32 id, s32 v) {
    s32 i;

    if (id == 7) {
        for (i = 0; i < 6; i++) {
            c->a[i] += v;
            if (c->a[i] >= 1000) {
                c->a[i] = 999;
            }
        }
    } else if ((u32)(id - 1) < 6) {
        c->a[id - 1] += v;
        if (c->a[id - 1] >= 1000) {
            c->a[id - 1] = 999;
        }
    } else if ((u32)(id - 8) < 7) {
        c->b[id - 8] += v;
        if (c->b[id - 8] >= 1000) {
            c->b[id - 8] = 999;
        }
    }
}
