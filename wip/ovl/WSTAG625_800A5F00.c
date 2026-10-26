extern Rec18 *D_80099D90;
typedef struct { s16 *tbl; s16 once; s16 next; } AnimSel8;
typedef struct { s16 mode; s16 flag; Rec18 *r; s16 st0; s16 st1; } AnimCh12;
extern AnimSel8 D_800A67D4[4][4];
void func_800A5F00(u8 *o) {
    Rec18 *q;
    AnimCh12 *c;
    Rec18 *r;
    s32 i;
    s32 v;
    u8 *p;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        p = o;
        for (q = D_80099D90; q->b[2] != 0; q++) {
            if ((u8)(q->b[1] - 1) < 4) {
                *(Rec18 **)(p + 0x54) = q;
                p += 12;
            }
        }
        *(s16 *)(o + 0x74) = *(s16 *)(o + 0x68) = *(s16 *)(o + 0x76) = 1;
        *(s16 *)(o + 0x6A) = *(s16 *)(o + 0x5E) = *(s16 *)(o + 0x52) = 0;
        *(s16 *)(o + 0x5C) = *(s16 *)(o + 0x50) = 2;
        *(s16 *)(o + 0x58) = 0;
        *(s16 *)(o + 0x5A) = D_800A67D4[0][2].tbl[1];
        *(s16 *)(o + 0x64) = 0;
        *(s16 *)(o + 0x66) = D_800A67D4[1][2].tbl[1];
        *(s16 *)(o + 0x70) = 0;
        *(s16 *)(o + 0x72) = D_800A67D4[2][1].tbl[1];
        *(s16 *)(o + 0x7C) = 0;
        *(s16 *)(o + 0x7E) = D_800A67D4[3][1].tbl[1];
        break;
    case 1:
        for (i = 0; i < 4; i++) {
            p = o + i * 12;
            r = *(Rec18 **)(p + 0x54);
            if (*(s16 *)(p + 0x50) != 0) {
                v = ((s32 (*)(u8 *, s16 *, s32, s32))func_800A5DE0)(o + 0x50 + i * 12, D_800A67D4[i][*(s16 *)(p + 0x50)].tbl, D_800A67D4[i][*(s16 *)(p + 0x50)].once, 0);
                if (v == 0xFF) {
                    if (D_800A67D4[i][*(s16 *)(p + 0x50)].next == 0) {
                        *(s16 *)(p + 0x50) = 0;
                        goto off;
                    }
                    *(s16 *)(p + 0x50) = D_800A67D4[i][*(s16 *)(p + 0x50)].next;
                    *(s16 *)(p + 0x58) = 0;
                    *(s16 *)(p + 0x5A) = D_800A67D4[i][*(s16 *)(p + 0x50)].tbl[1];
                } else if (v == 0x12C) {
                    goto off;
                } else {
                    r->b[0] = 1;
                    if (*(s16 *)(p + 0x52) == 0) {
                        r->b[9] = v;
                    } else {
                        r->b[4] = v;
                    }
                }
            } else {
            off:
                r->b[0] = 0;
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}
