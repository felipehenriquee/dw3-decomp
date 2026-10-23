extern u8 D_80048D34[];
extern s16 D_80049372[];
void func_800847C0(u8 *o) {
    s32 i;
    s16 *p;
    s16 *q;
    for (i = 0; i < 0x13B; i++) {
        *(s16 *)(o + i * 2 + 0x88) = 0;
        (o + i)[0x2FE] = D_80048D34[i + 0x3A2];
    }
    p = &D_80049372[*(s32 *)(o + 0x5C) * 51];
    for (i = 0; i < 40; i++) {
        (o + *p++)[0x2FE] -= 1;
    }
    *(s32 *)(o + 0x7C) = 0;
    q = (s16 *)o;
    for (i = 0; i < 0x13B; i++) {
        if (*(s8 *)(o + i + 0x2FE) > 0) {
            q[0x44] = i;
            q++;
            *(s32 *)(o + 0x7C) += 1;
        }
    }
}

====
extern u8 D_80048D34[];
extern s16 D_80049372[];
void func_800847C0(u8 *o) {
    s32 i;
    s16 *p;
    s16 *q;
    for (i = 0; i < 0x13B; i++) {
        *(s16 *)(o + i * 2 + 0x88) = 0;
        (o + i)[0x2FE] = D_80048D34[i + 0x3A2];
    }
    p = &D_80049372[*(s32 *)(o + 0x5C) * 51];
    for (i = 0; i < 40; i++) {
        (o + *p)[0x2FE] -= 1;
        p++;
    }
    *(s32 *)(o + 0x7C) = 0;
    q = (s16 *)o;
    for (i = 0; i < 0x13B; i++) {
        if (*(s8 *)(o + i + 0x2FE) > 0) {
            q[0x44] = i;
            q++;
            *(s32 *)(o + 0x7C) += 1;
        }
    }
}

====
extern u8 D_80048D34[];
extern s16 D_80049372[];
void func_800847C0(u8 *o) {
    s16 *p;
    s32 i;
    s16 *q;
    for (i = 0; i < 0x13B; i++) {
        *(s16 *)(o + i * 2 + 0x88) = 0;
        (o + i)[0x2FE] = D_80048D34[i + 0x3A2];
    }
    p = &D_80049372[*(s32 *)(o + 0x5C) * 51];
    for (i = 0; i < 40; i++) {
        (o + *p++)[0x2FE] -= 1;
    }
    *(s32 *)(o + 0x7C) = 0;
    q = (s16 *)o;
    for (i = 0; i < 0x13B; i++) {
        if (*(s8 *)(o + i + 0x2FE) > 0) {
            q[0x44] = i;
            q++;
            *(s32 *)(o + 0x7C) += 1;
        }
    }
}
