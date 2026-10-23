typedef struct { u8 b[0x20]; } FtE32c;
typedef struct { u8 pad0[8]; s32 sel; s32 sel2; FtE32c e[6]; } FtSelC;
extern u8 D_800A43F4[];
void func_8009DA0C(void) {
    FtSelC *t = (FtSelC *)D_800A4460;
    u8 *s = D_800A43F4;
    u8 *e = (u8 *)&t->e[t->sel];
    Rec18 *r = &D_80042BCA[*(s32 *)(s + 0x24)];
    if (*(s16 *)(e + 0xC) != 0) {
        *(s32 *)(s + 0x2C) = *(s16 *)(e + 0xA) * r->b[0xC] / 128;
        if (*(s16 *)(e + 0xC) < *(s32 *)(s + 0x2C)) {
            *(s32 *)(s + 0x2C) = *(s16 *)(e + 0xC);
        }
        s[r->b[0xA] + 0x38] = s[0x2C];
    }
}

====
typedef struct { u8 b[0x20]; } FtE32c;
typedef struct { u8 pad0[8]; s32 sel; s32 sel2; FtE32c e[6]; } FtSelC;
extern u8 D_800A43F4[];
void func_8009DA0C(void) {
    FtSelC *t = (FtSelC *)D_800A4460;
    u8 *s = D_800A43F4;
    u8 *e = t->e[t->sel].b;
    Rec18 *r = &D_80042BCA[*(s32 *)(s + 0x24)];
    if (*(s16 *)(e + 0xC) != 0) {
        *(s32 *)(s + 0x2C) = *(s16 *)(e + 0xA) * r->b[0xC] / 128;
        if (*(s16 *)(e + 0xC) < *(s32 *)(s + 0x2C)) {
            *(s32 *)(s + 0x2C) = *(s16 *)(e + 0xC);
        }
        s[r->b[0xA] + 0x38] = s[0x2C];
    }
}

====
typedef struct { u8 b[0x20]; } FtE32c;
typedef struct { u8 pad0[8]; s32 sel; s32 sel2; FtE32c e[6]; } FtSelC;
extern u8 D_800A43F4[];
void func_8009DA0C(void) {
    FtSelC *t = (FtSelC *)D_800A4460;
    u8 *s = D_800A43F4;
    u8 *e = (u8 *)(t->e + t->sel);
    Rec18 *r = &D_80042BCA[*(s32 *)(s + 0x24)];
    if (*(s16 *)(e + 0xC) != 0) {
        *(s32 *)(s + 0x2C) = *(s16 *)(e + 0xA) * r->b[0xC] / 128;
        if (*(s16 *)(e + 0xC) < *(s32 *)(s + 0x2C)) {
            *(s32 *)(s + 0x2C) = *(s16 *)(e + 0xC);
        }
        s[r->b[0xA] + 0x38] = s[0x2C];
    }
}
