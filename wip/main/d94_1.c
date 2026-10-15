typedef struct {
    u8 pad0[0x70];
    s32 unk70[3];
} Unk80048D34;

s32 func_80016D94(u32 arg0) {
    if (arg0 < 3) {
        return ((Unk80048D34 *)D_80048D34)->unk70[arg0];
    }
    return -1;
}
