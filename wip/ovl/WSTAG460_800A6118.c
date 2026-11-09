extern Rec18 *D_80099D90;
extern s16 D_800A726C[];
extern s16 D_800A72AC[];
void func_800A6118(u8 *o) {
    Rec18 *q;
    Rec18 *r;
    s32 v;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *(s16 *)(o + 0x58) = 0;
        *(s16 *)(o + 0x5A) = D_800A726C[1];
        *(s16 *)(o + 0x58) = 0;
        *(s16 *)(o + 0x5A) = D_800A726C[1];
        *(s16 *)(o + 0x50) = 1;
        for (q = D_80099D90; q->b[2] != 0; q++) {
            if (q->b[1] == 0xA) {
                *(Rec18 **)(o + 0x54) = q;
            }
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        r = *(Rec18 **)(o + 0x54);
        if (*(s16 *)(o + 0x50) != 0) {
            r->b[0] = 1;
            r->b[4] = 0x3C;
            r->b[9] = func_800A5FF8((s16 *)(o + 0x54), D_800A726C, 0, 0);
        } else {
            r->b[0] = 0;
        }
        if (*(s16 *)(o + 0x50) == 2) {
            *(s16 *)(o + 0x52) -= 1;
            if (*(s16 *)(o + 0x52) <= 0) {
                (*(s32 (**)(u8 *, s32))(o + 0x28))(o, 2);
            }
        }
        break;
    case 2:
        if (*(s32 *)(o + 0x10) == 0) {
            *(s16 *)(o + 0x58) = 0;
            *(s16 *)(o + 0x5A) = D_800A72AC[1];
            (*(void (**)(u8 *, s32))(o + 0x2C))(o, 1);
        }
        r = *(Rec18 **)(o + 0x54);
        v = ((s32 (*)(s16 *, s16 *, s32, s32))func_800A5FF8)((s16 *)(o + 0x54), D_800A72AC, 1, 0);
        if (v != 0xFF) {
            if (v == 0x12C) {
                r->b[0] = 0;
            } else {
                r->b[0] = 1;
                r->b[4] = 0x3D;
                r->b[9] = v;
            }
        } else {
            r->b[0] = 0;
            *(s16 *)(o + 0x50) = 0;
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 1);
        }
        break;
    case 3:
        break;
    }
}

