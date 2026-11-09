extern s32 D_8004DF6C[];
void func_8009946C(u8 *o) {
    u8 *sys;
    u8 *x;
    u32 *ot;
    PolyF4 *p;
    s32 v, k;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (*(s32 *)(o + 0x78) != 0 && *(s32 *)(o + 0x68) != 0) {
            v = (*(s32 *)(o + 0x80) - *(s32 *)(o + 0x7C)) << 8;
            *(s32 *)(o + 0x64) = v / *(s32 *)(o + 0x70) * *(s32 *)(o + 0x6C);
            *(s32 *)(o + 0x88) = v / *(s32 *)(o + 0x70);
            (*(void (**)(u8 *))(o + 0x38))(o);
        }
        break;
    case 1:
        sys = D_8004DE10;
        x = (*(u8 *(**)(s32))(sys + 0x17C))(*(s32 *)(o + 0x50));
        ot = (*(u32 *(**)(u8 *, s32))(x + 0x138))(x, *(s32 *)(o + 0x54));
        p = (*(PolyF4 *(**)(void))(sys + 0x158))();
        if (*(s32 *)(o + 0x74) < *(s32 *)(o + 0x70) - 1) {
            v = *(s32 *)(o + 0x7C) + ((*(s32 *)(o + 0x74) * *(s32 *)(o + 0x88)) >> 8);
            *(s32 *)(o + 0x5C) = v;
            k = *(s32 *)(o + 0x80) - (*(s32 *)(o + 0x64) >> 8);
            if (k < v) {
                *(s32 *)(o + 0x5C) = k;
            }
        } else {
            *(s32 *)(o + 0x5C) = *(s32 *)(o + 0x80) - (*(s32 *)(o + 0x64) >> 8);
        }
        ((u8 *)p)[3] = 5;
        p->code = 0x28;
        p->b0 = 0xFF;
        p->g0 = 0xFF;
        p->r0 = 0xFF;
        p->x0 = p->x2 = *(s16 *)(o + 0x58);
        p->x1 = p->x3 = *(s16 *)(o + 0x58) + *(s16 *)(o + 0x60);
        p->y0 = p->y1 = *(s32 *)(o + 0x5C);
        p->y2 = p->y3 = *(s32 *)(o + 0x5C) + (*(s32 *)(o + 0x64) >> 8);
        p->tag = (p->tag & 0xFF000000) | (*ot & 0xFFFFFF);
        *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
        ((void (*)(void *))D_8004DF6C[0])((u8 *)p + 0x18);
        break;
    case 2:
    case 3:
        break;
    }
}

