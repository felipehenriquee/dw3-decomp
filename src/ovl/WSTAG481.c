#include "WSTAG481.h"
#include "m2c.h"
#include "WSTAG481_auto.h"
#include "WSTAG481_data.h"

void func_800A5DF8(u8 *o, u8 (**tbl)[4], AnimSt *st, s32 depth) {
    s32 dt;
    if (depth == 0) {
        dt = (*(s32 (**)(void))&D_8004DF9C)();
        if (dt >= 5) {
            dt = 4;
        }
        st->t -= dt;
    }
    if (st->t <= 0) {
        if (tbl[st->seq][st->frame][3] != 0) {
            st->seq++;
            st->frame = 0;
            if (tbl[st->seq] == NULL) {
                st->seq = 0;
            }
        } else {
            st->frame++;
        }
        st->t += tbl[st->seq][st->frame][1];
        func_800A5DF8(o, tbl, st, depth + 1);
    }
    if (depth == 0) {
        o[4] = tbl[st->seq][st->frame][0];
        o[9] = tbl[st->seq][st->frame][2];
    }
}

extern u8 (**D_800A6564[])[4];
void func_800A5F84(u8 *o) {
    Rec18 *q;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *(s16 *)(o + 0x50) = 0;
        *(s16 *)(o + 0x52) = 0;
        *(s32 *)(o + 0x54) = (*D_800A6564[0])[0][1];
        *(s16 *)(o + 0x58) = 0;
        *(s16 *)(o + 0x5A) = 0;
        *(s32 *)(o + 0x5C) = (*D_800A6564[1])[0][1];
        *(s16 *)(o + 0x60) = 0;
        *(s16 *)(o + 0x62) = 0;
        *(s32 *)(o + 0x64) = (*D_800A6564[2])[0][1];
        *(s16 *)(o + 0x68) = 0;
        *(s16 *)(o + 0x6A) = 0;
        *(s32 *)(o + 0x6C) = (*D_800A6564[3])[0][1];
        *(s16 *)(o + 0x70) = 0;
        *(s16 *)(o + 0x72) = 0;
        *(s32 *)(o + 0x74) = (*D_800A6564[3])[0][1];
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        for (q = D_80099D90; q->b[2] != 0; q++) {
            switch (q->b[1]) {
            case 1:
                func_800A5DF8((u8 *)q, D_800A6564[0], (AnimSt *)(o + 0x50), 0);
                break;
            case 2:
                func_800A5DF8((u8 *)q, D_800A6564[1], (AnimSt *)(o + 0x58), 0);
                break;
            case 3:
                func_800A5DF8((u8 *)q, D_800A6564[2], (AnimSt *)(o + 0x60), 0);
                break;
            case 4:
                func_800A5DF8((u8 *)q, D_800A6564[3], (AnimSt *)(o + 0x68), 0);
                break;
            case 5:
                func_800A5DF8((u8 *)q, D_800A6564[4], (AnimSt *)(o + 0x70), 0);
                break;
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}

Obj *func_800A6164(void) {
    return func_80014504(func_800A5F84, 0x78, 0);
}

void func_800A6190(u8 *o, Obj **out) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *out = func_800A6164();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A61F4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6190, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6FB0)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG481/nonmatchings/WSTAG481", func_800A6250);
