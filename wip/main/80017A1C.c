/* registro de 20 bytes em D_80048D34 (44 por personagem, a partir de 0x7B8) */
typedef struct {
    s32 w[5];
} Rec14;

typedef struct {
    u8 pad0[0x7B8];
    Rec14 rec;
} Unk80048D34_Rec;
s32 func_80017A1C(s32 arg0, s32 arg1, Rec14 *out) {
    s32 i = func_8001764C(arg0, arg1);

    if (i != -1) {
        *out = ((Unk80048D34_Rec *)(D_80048D34 + (arg0 * 247 + i * 5) * 4))->rec;
    }
    return i;
}
