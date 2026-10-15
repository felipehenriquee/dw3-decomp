typedef struct {
    u8 pad0[0x7B8];
    s16 unk7B8;
} Unk80048D34_7B8;

s32 func_8001764C(s32 arg0, s32 arg1) {
    s32 i;
    s16 v;

    for (i = 0; i < 44; i++) {
        v = ((Unk80048D34_7B8 *)(D_80048D34 + arg0 * 0x3DC + i * 0x14))->unk7B8;
        if (v >= 3 && v == arg1) {
            return i;
        }
    }
    return -1;
}
