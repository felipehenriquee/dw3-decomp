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
