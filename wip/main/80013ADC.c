Unk80044B3C *func_80013ADC(void) {
    Unk80044B3C *best = NULL;
    s32 size = 0;
    s32 i = 0;
    s32 t = (*(s32 (**)(void))&D_8004DF98)();
    Unk80044B3C *tbl = (Unk80044B3C *)D_80044B3C;
    u8 *cd = (u8 *)&D_80048740;

    for (; i < 64; i++) {
        Unk80044B3C *e = &tbl[i];
        if (e->id != 0 && tbl[i].unk0 == 3 && t >= e->unk8) {
            if (t == e->unk8 && (*(s32 (**)(s32))(cd + 4))(e->id) < size) {
                continue;
            }
            best = e;
            size = (*(s32 (**)(s32))(cd + 4))(e->id);
            t = e->unk8;
        }
    }
    return best;
}