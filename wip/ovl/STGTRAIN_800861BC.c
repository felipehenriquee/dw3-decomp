extern s32 D_8004DC0C NOT_GP;
typedef struct { s32 base; s32 rnd; } TrDec8;
extern TrDec8 D_8008C304[];
s32 func_800861BC(u8 *o, s32 k) {
    u8 *q = ((u8 *(*)(s32))D_8004B484[0])(*(s32 *)(o + 0x5C));
    u8 *p;
    s32 off = 6;
    TrDec8 *e;
    s32 v;
    if ((u32)(k - 1) >= 5) {
        return 0;
    }
    p = q + (k * 2 + 0x26);
    if (*(s32 *)(o + 0x60) < 13) {
        off = 0;
    }
    off += *(s32 *)(o + 0xD8) * 3 + *(s32 *)(*(u8 **)(o + 0x50) + 0x7C);
    e = &D_8008C304[off];
    if (e->rnd != 0) {
        v = e->base + ((s32 (*)(void))D_8004DC0C)() % e->rnd;
    } else {
        v = e->base;
    }
    *(s16 *)p += v;
    if (*(s16 *)p >= 1000) {
        *(s16 *)p = 999;
    }
    return v;
}

