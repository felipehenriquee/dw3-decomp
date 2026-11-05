extern s32 D_8004DE10[];
void func_800A32D8(u8 *c, CgPt16 a, CgPt16 n) {
    u8 *sys = (u8 *)D_8004DE10;
    u8 *o;
    u32 *ot;
    PolyF4 *p;
    DrMode *m;

    o = (*(u8 *(**)(s32))(sys + 0x17C))(0x100);
    ot = (*(u32 *(**)(u8 *, s32))(o + 0x138))(o, 0);
    p = (*(PolyF4 *(**)(void))(sys + 0x158))();
    p->r0 = c[0x64];
    p->g0 = c[0x65];
    p->b0 = c[0x66];
    ((u8 *)p)[3] = 5;
    p->code = 0x2A;
    p->x0 = a.x;
    p->x1 = a.x + n.x;
    p->x2 = a.x;
    p->x3 = a.x + n.x;
    p->y0 = a.y;
    p->y1 = a.y;
    p->y2 = a.y + n.y;
    p->y3 = a.y + n.y;
    m = (DrMode *)(p + 1);
    p->tag = (p->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    ((u8 *)m)[3] = 1;
    m->code[0] = ((c[0x5C] & 3) << 5) | 0xE1000205;
    m->tag = (m->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)m & 0xFFFFFF);
    (*(void (**)(void *))(sys + 0x15C))((u8 *)m + 8);
}

