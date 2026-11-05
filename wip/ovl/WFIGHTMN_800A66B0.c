typedef struct { s16 h0, p2, p4, h6, h8, hA, hC, pE; s32 p10, p14; s16 h18; s16 p1A; s32 p1C; } WfE20;
extern s32 D_800A37FC[];
void func_800A66B0(s32 first) {
    s32 i;
    s32 k;
    u8 *p;
    u8 *d = D_80048D34;
    WfE20 *e;
    WfE20 *tb;
    u8 *q;
    tb = (WfE20 *)D_800A4470;
    e = tb;
    for (i = 0; i < 3; i++) {
        k = (*(s32 (**)(s32))(d + 0x2718))(i);
        if (k >= 0) {
            p = (*(u8 *(**)(s32))(d + 0x2750))(k);
            if (i == 0) {
                tb->h0 = first;
            } else {
                e->h0 = *(s16 *)(D_8003EF5C + k * 0x58);
            }
            e->h8 = *(s16 *)(p + 0x20);
            e->h6 = *(s16 *)(p + 0x22);
            e->hC = *(s16 *)(p + 0x24);
            e->hA = *(s16 *)(p + 0x26);
        }
        e++;
    }
    e = (WfE20 *)D_800A44D0;
    q = D_80042B1C;
    for (i = 0; i < 3; i++) {
        e->h0 = *(u16 *)(q + 0x18);
        if (*(u16 *)(q + 0x18) != 0) {
            e->h6 = e->h8 = *(s16 *)(q + 0x1E);
            e->hA = e->hC = *(s16 *)(q + 0x20);
            p = ((u8 *(*)(s32))D_800A37FC[0])(e->h0);
            if (*(s16 *)(p + 2) != 0) {
                e->h18 = *(s16 *)(p + 2);
            }
        }
        e++;
        q += 12;
    }
}
