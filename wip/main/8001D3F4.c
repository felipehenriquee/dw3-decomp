extern s32 D_8005CCAC[];

/* callback de VSync (registrado por func_8001D4E0) */
void func_8001D3F4(void) {
    u8 *t;
    u8 *g;
    u8 *p;
    u8 *env;
    s32 a;
    s32 b;
    s32 sel;

    /* contadores de tempo em 8.8: 0x100 ou 0x133 (= 0x100 * 6/5) por quadro */
    if (D_8005CCAC[0] != 0) {
        p = D_8004DE10;
        g = D_80048D34;
        *(s32 *)(p + 0x14) += 0x100;
        a = *(s32 *)(p + 0x1C) + 0x100;
        b = *(s32 *)(g + 0x48) + 0x100;
    } else {
        p = D_8004DE10;
        g = D_80048D34;
        *(s32 *)(p + 0x14) += 0x133;
        a = *(s32 *)(p + 0x1C) + 0x133;
        b = *(s32 *)(g + 0x48) + 0x133;
    }
    *(s32 *)(p + 0x1C) = a;
    *(s32 *)(g + 0x48) = b;
    t = D_8004DE10;
    if (*(s32 *)t != 0) {
        (*(void (**)(s32))t)(*(s32 *)(t + 4));
    }
    env = t + 0x38;
    if (D_8005CD00 != 0) {
        sel = *(s32 *)(t + 0x30) == 0;
        *(s32 *)(t + 0x30) = sel;
        PutDispEnv(env + sel * 20);
    }
    SsSeqCalledTbyT();
    D_8005CD00 = 0;
}
