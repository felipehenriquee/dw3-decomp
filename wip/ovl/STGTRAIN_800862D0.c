extern s32 D_8004DC04[];
typedef struct { s32 base; s32 rnd; } TrDec8;
extern TrDec8 D_8008C364[];
s32 func_800862D0(u8 *o, s32 arg) {
    s32 k = arg;
    u8 *p = ((u8 *(*)(s32))D_8004B484[0])(*(s32 *)(o + 0x5C));
    TrDec8 *e;
    s32 v;
    if ((u32)(k - 1) >= 5 || (((s32 (*)(void))D_8004DC04[2])() & 1)) {
        return 0;
    }
    p += k * 2 + 0x26;
    e = &D_8008C364[*(s32 *)(*(u8 **)(o + 0x50) + 0x7C)];
    if (e->rnd != 0) {
        v = e->base + ((s32 (*)(void))D_8004DC04[2])() % e->rnd;
    } else {
        v = e->base;
    }
    *(s16 *)p -= v;
    if (*(s16 *)p < 0) {
        *(s16 *)p = 0;
    }
    return v;
}
