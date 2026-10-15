void func_8001DB84(s32 slot, s32 used, s32 id) {
    s32 i;

    for (i = 29; i != slot; i--) {
        ((Unk8004DE10 *)D_8004DE10)->used[i] = ((Unk8004DE10 *)D_8004DE10)->used[i - 1];
        ((Unk8004DE10 *)D_8004DE10)->id[i] = ((Unk8004DE10 *)D_8004DE10)->id[i - 1];
    }
    ((Unk8004DE10 *)D_8004DE10)->used[slot] = used;
    ((Unk8004DE10 *)D_8004DE10)->id[slot] = id;
}
