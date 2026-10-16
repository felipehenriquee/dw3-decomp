void func_80013F60(void) {
    s32 i;
    Unk80044B3C *p;
    u8 *heap = (u8 *)&D_8004B5DC;

    for (i = 0; i < 64; i++) {
        p = &((Unk80044B3C *)D_80044B3C)[i];
        if (p->id != 0) {
            (*(void (**)(s32))(heap + 0x10))(p->unkC);
            p->id = 0;
            p->unkC = 0;
            p->unk8 = 0;
            p->unk2 = 0;
            p->unk0 = 0;
        }
    }
}
