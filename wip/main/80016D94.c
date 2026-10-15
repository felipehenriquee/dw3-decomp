/* struct grande em D_80048D34 (dados do jogador/partida?) */
typedef struct {
    u8 pad0[0x70];
    s32 unk70[3];
} Unk80048D34;

/* elemento de 0x3DC bytes indexado a partir de D_80048D34 */
typedef struct {
    u8 unk0[0x3DC];
} Unk80048D34_3DC;

s32 func_80016D94(u32 arg0) {
    if (arg0 >= 3) {
        return -1;
    }
    return ((Unk80048D34 *)D_80048D34)->unk70[arg0];
}
