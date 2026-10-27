extern FtSkill58 D_8003EF5C[];
extern u8 D_80042B84[];
void func_800A69F0(void) {
    u8 *t = D_800A4460;
    u8 *f = D_80042B84;
    u8 *d;
    s32 h;
    u8 *e;
    s16 buf[4];
    s32 i;
    (f + *(s32 *)(t + 8) * 4)[6] = 1;
    d = (u8 *)D_80048D34;
    h = (*(s32 (**)(s32))(d + 0x2718))(*(s32 *)(t + 8));
    e = *(s32 *)(t + 8) * 32 + (t + 0x10);
    if (D_8003EF5C[h].id == *(s16 *)e) {
        return;
    }
    if ((*(s32 (**)(s32, s16 *))(d + 0x2738))(h, buf) <= 0) {
        return;
    }
    for (i = 0; i < 3; i++) {
        if (buf[i] == *(s16 *)e) {
            (f + (i + *(s32 *)(t + 8) * 4))[7] = 1;
            return;
        }
    }
}
