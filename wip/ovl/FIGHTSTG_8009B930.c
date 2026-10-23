void func_8009B930(s32 *m) {
    s32 i, n;
    u8 *d;
    i = 0;
    n = -1;
    for (; i < 99; i++) {
        if (*(s16 *)(D_800A3868 + i * 28) == 0) {
            n = i;
            break;
        }
    }
    if (n != -1) {
        d = D_800A3868;
        *(s16 *)(d + n * 28) = m[0];
        *(s16 *)(d + n * 28 + 2) = m[1];
        for (i = 0; i < 6; i++) {
            *(s32 *)(d + n * 28 + i * 4 + 4) = m[i + 2];
        }
    }
}
====
void func_8009B930(s32 *m) {
    s32 i, n;
    u8 *d;
    i = 0;
    n = -1;
    for (; i < 99; i++) {
        if (*(s16 *)(D_800A3868 + i * 28) == 0) {
            n = i;
            break;
        }
    }
    if (n != -1) {
        d = D_800A3868;
        *(s16 *)(d + n * 28) = m[0];
        *(s16 *)(d + n * 28 + 2) = m[1];
        for (i = 0; i < 6; i++) {
            ((s32 *)(d + n * 28 + 4))[i] = m[i + 2];
        }
    }
}
====
typedef struct { s16 id; s16 v; s32 w[6]; } FtSnd28;
void func_8009B930(s32 *m) {
    s32 i, n;
    FtSnd28 *d;
    i = 0;
    n = -1;
    for (; i < 99; i++) {
        if (((FtSnd28 *)D_800A3868)[i].id == 0) {
            n = i;
            break;
        }
    }
    if (n != -1) {
        d = (FtSnd28 *)D_800A3868;
        d[n].id = m[0];
        d[n].v = m[1];
        for (i = 0; i < 6; i++) {
            d[n].w[i] = m[i + 2];
        }
    }
}
