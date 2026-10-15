/* struct grande em D_80048D34 (dados do jogador/partida?) */
typedef struct {
    u8 pad0[0x70];
    s32 unk70[3];
} Unk80048D34;

/* elemento de 0x3DC bytes indexado a partir de D_80048D34 */
typedef struct {
    u8 unk0[0x3DC];
} Unk80048D34_3DC;

typedef struct {
    u8 pad0[0x7B8];
    s16 unk7B8;
} Unk80048D34_7B8;
s32 func_80017898(s32 arg0, u16 *out) {
    s32 i;
    s32 n = 0;
    u16 *p = out;
    s16 v;

    for (i = 0; i < 44; i++) {
        v = ((Unk80048D34_7B8 *)(D_80048D34 + arg0 * 0x3DC + i * 0x14))->unk7B8;
        if (v >= 3) {
            *p++ = v;
            n++;
        }
    }
    for (i = n; i < 44; i++) {
        out[i] = 0;
    }
    return n;
}
