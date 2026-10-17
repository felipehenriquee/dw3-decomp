/* processa os comandos do texto do trabalho 0 ate o fim (codigo 4 para) */
void func_8001A2AC(MsgWin *w) {
    MsgWork *e = &w->work[0];
    s32 i;
    s32 *tbl;
    u8 *p;
    u8 n;
    u8 op;

    if (e->buf == NULL) {
        return;
    }
    for (i = 0; i < w->work[0].len;) {
        tbl = D_8004DE00;
        switch ((u32)((*(s32 (**)(u8 *, s32, s32))(tbl + 3))(e->buf + i, *(u8 *)&e->unkA,
                                                            *(s32 *)((u8 *)w + 0x50)) << 16) >> 24) {
        case 0:
        case 3:
        default:
            if (e->unkA != 0) {
                i += 2;
            } else {
                i += 1;
            }
            break;
        case 1:
            i += 2;
            break;
        case 2:
            op = e->buf[i + 1];
            p = e->buf + i;
            if (op == 4) {
                break;
            }
            if (op == 8) {
                n = p[2];
                func_8001968C(w, (s32)&D_80048D88, n);
                w->work[n].unkA = 0;
                i += ((s32 *)tbl[1])[8];
            } else {
                i += ((s32 *)tbl[1])[op];
            }
            break;
        case 4:
            return;
        }
    }
}
