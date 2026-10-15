Unk80044B3C *func_80013A34(void) {
    s32 i;
    Unk80044B3C *p = (Unk80044B3C *)D_80044B3C;

    for (i = 0; i < 64; i++, p++) {
        if (p->id == 0) {
            return p;
        }
    }
    return NULL;
}
