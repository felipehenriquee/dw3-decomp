void func_80013CDC(void) {
    s32 *flag = D_80044B38;
    Unk80044B3C *e;
    CdState *cd;
    s32 i, busy, started;
    u8 *sys;

    if (flag[0] == 0) {
        return;
    }
    cd = &D_80044B04;
    if ((*(s32 (**)(void))((u8 *)cd + 0x2C))() == 1) {
        return;
    }
    e = (Unk80044B3C *)(flag + 1);
    started = 0;
    busy = 0;
    sys = D_8004DE10;
    for (i = 0; i < 64; i++, e++) {
        if (e->id == 0) {
            continue;
        }
        if (e->unk0 == 2) {
            e->unk0 = 3;
            busy = 1;
        } else if (e->unk0 == 1) {
            busy = 1;
            if (started) {
                continue;
            }
            (*(void (**)(s32, s32, s32, s32, s32))((u8 *)cd + 0x30))(e->id, 0, 0, e->unkC, 0);
            e->unk0 = 2;
            started = busy;
        } else {
            continue;
        }
        e->unk8 = (*(s32 (**)(void))(sys + 0x188))();
    }
    if (!busy) {
        flag[0] = 0;
    }
}
