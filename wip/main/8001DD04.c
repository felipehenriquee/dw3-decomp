void func_8001DD04(s32 arg0, s32 arg1, s32 arg2) {
    s32 i = func_8001DAD0(arg0);
    s32 j = func_8001DAD0(arg1);
    s32 n;
    s32 used;
    s32 id;

    if (i != -1 && j != -1) {
        n = j + arg2;
        used = ((Unk8004DE10 *)D_8004DE10)->used[i];
        id = ((Unk8004DE10 *)D_8004DE10)->id[i];
        if (n <= 0) {
            n = 0;
        }
        func_8001DB34(i);
        func_8001DB84(n, used, id);
    }
}
