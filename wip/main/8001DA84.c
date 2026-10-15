s32 func_8001DA84(s32 arg0) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (((Unk8004DE10 *)D_8004DE10)->used[i] != 0 &&
            ((Unk8004DE10 *)D_8004DE10)->id[i] == arg0) {
            return ((Unk8004DE10 *)D_8004DE10)->used[i];
        }
    }
    return 0;
}
