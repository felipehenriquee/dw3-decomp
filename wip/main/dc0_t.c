/* struct grande em D_80048D34 (dados do jogador/partida?) */
typedef struct {
    u8 pad0[0x70];
    s32 unk70[3];
} Unk80048D34;

/* elemento de 0x3DC bytes indexado a partir de D_80048D34 */
typedef struct {
    u8 unk0[0x3DC];
} Unk80048D34_3DC;

extern u8 D_8004B490[];
extern s32 D_8004B374[];
void func_80016DC0(s32 arg0) {
    s32 i;
    s32 v;

    for (i = 0; i < 3; i++) {
        v = D_8004B490[arg0 * 3 + i];
        ((Unk80048D34 *)D_80048D34)->unk70[i] = v;
        *(s32 *)((u8 *)&((Unk80048D34_3DC *)D_80048D34)[v] + 0x760) = v + 3;
    }
    D_8004B374[0] = arg0;
}
