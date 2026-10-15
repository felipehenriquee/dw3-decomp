void func_8001DB34(s32 i) {
    for (; i < 29; i++) {
        ((Unk8004DE10 *)D_8004DE10)->used[i] = ((Unk8004DE10 *)D_8004DE10)->used[i + 1];
        ((Unk8004DE10 *)D_8004DE10)->id[i] = ((Unk8004DE10 *)D_8004DE10)->id[i + 1];
    }
}
