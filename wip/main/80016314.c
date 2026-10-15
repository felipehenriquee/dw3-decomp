extern s32 D_8004B454 NOT_GP;
void func_80016314(s32 arg0, s32 arg1) {
    u8 *p;

    if (arg1 != 0) {
        ((void (*)(s32, s32))D_8004B454)(arg0, 1);
        return;
    }
    p = &D_80048D34[arg0];
    p[0x3A2]--;
    if ((s8)p[0x3A2] < 0) {
        p[0x3A2] = 0;
    }
}
