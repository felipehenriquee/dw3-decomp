typedef struct { u8 pad[0x1B]; u8 f1B; u8 pad1C[4]; } FtE32;
typedef struct { u8 pad0[8]; s32 sel[2]; FtE32 e[2][3]; } FtSel;
extern u8 D_800A43F4[];
extern s32 D_800A4624[];
void func_8009D140(void) {
    u8 *s = D_800A43F4;
    FtSel *t = (FtSel *)D_800A4460;
    s32 k = s[0x20] != 0;
    FtE32 *e = &t->e[k][t->sel[k]];
    s32 r = ((s32 (*)(s32, s32))D_800A4624[0])(s[0x20], *(s32 *)(s + 0x24));
    if (r != 0) {
        if (e->f1B != 0) {
            r <<= 1;
        }
        s[0x3A] = r;
    }
}
