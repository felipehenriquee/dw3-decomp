void func_80096CF0(s32 a, s32 b, s32 c, s16 *st) {
    if (st[4] == 0) {
        return;
    }
    switch (st[4]) {
    case 1:
    default:
        st[1] = 0x1000 - (st[2] << 12) / st[3];
        st[2] -= ((s32 (*)(void))D_8004DF9C)();
        if (st[2] <= 0) {
            st[4] = 2;
        }
        break;
    case 2:
        st[1] = 0x1000;
        break;
    case 3:
        st[2] -= ((s32 (*)(void))D_8004DF9C)();
        if (st[2] <= 0) {
            st[4] = 0;
        }
        st[1] = (st[2] << 12) / st[3];
        break;
    }
    func_80096C20(a, b, c, st);
}

