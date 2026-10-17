extern s32 D_8005CCAC[];
extern s32 D_800519D4[];
extern s32 D_800519E0[];
void func_80020A10(void) {
    s32 i;
    u8 *t;

    SsSetTableSize(D_800519EC, 6, 16);
    SsSetTickMode(D_8005CCAC[0] ? 0x1000 : 0x1032);
    SsStart2();
    SsSetMVol(0x7F, 0x7F);
    SsSetSerialAttr(0, 0, 1);
    SsSetSerialVol(0, 0x7F, 0x7F);
    SsUtSetReverbType(3);
    SsUtSetReverbDepth(0, 0);
    SsUtReverbOn();
    for (i = 0; i < 3; i++) {
        t = D_800519EC + i * 0x18;
        *(s16 *)(t + 0x4204) = -1;
        *(s16 *)(t + 0x4206) = 0;
        *(s32 *)(t + 0x4210) = D_800519D4[i];
        *(s32 *)(t + 0x4214) = D_800519E0[i];
    }
    *(s16 *)(D_800519EC + 0x4256) = 0;
    *(s16 *)(D_800519EC + 0x4254) = 0;
    *(s32 *)(D_800519EC + 0x4250) = 0;
    func_8002044C(0, 1);
    while (func_8002043C()) {
        (*(void (**)(void))((u8 *)D_80044B38 + 0x410))();
        func_800205F0();
    }
}
