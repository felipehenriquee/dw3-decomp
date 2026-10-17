#include "STGMCARD.h"
#include "m2c.h"
#include "STGMCARD_auto.h"
#include "STGMCARD_data.h"

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80082CD0);

Obj *func_80082DC8(void) {
    return func_80014504(func_80082CD0, 0x58, 4);
}

void func_80082DF4(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 1);
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    if (arg1 == 0) {
        M2C_FIELD(arg0, s32 *, 0x5C) = 0;
        M2C_FIELD(arg0, s32 *, 0x60) = (s32) (0xFF00 / arg2);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x5C) = 0xFF00;
    M2C_FIELD(arg0, s32 *, 0x60) = (s32) -(0xFF00 / arg2);
}

void func_80082E7C(u8 *obj) {
    u8 *sys = D_8004DE10;
    u8 *o;
    u32 *ot;
    PolyF4 *p;
    DrMode *m;
    s32 c;

    o = (*(u8 *(**)(s32))(sys + 0x17C))(*(s32 *)(obj + 0x50));
    ot = (*(u32 *(**)(u8 *, s32))(o + 0x138))(o, *(s32 *)(obj + 0x54));
    p = (*(PolyF4 *(**)(void))(sys + 0x158))();
    ((u8 *)p)[3] = 5;
    p->code = 0x2A;
    m = (DrMode *)(p + 1);
    c = *(s32 *)(obj + 0x5C) >> 8;
    p->x0 = p->x2 = 0;
    p->y0 = p->y1 = 0;
    p->x1 = p->x3 = 320;
    p->y2 = p->y3 = 256;
    p->r0 = p->g0 = p->b0 = c;
    p->tag = (p->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    ((u8 *)m)[3] = 1;
    m->code[0] = 0xE1000245;
    m->tag = (m->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)m & 0xFFFFFF);
    (*(void (**)(void *))(sys + 0x15C))((u8 *)m + 8);
}

void func_80082FC0(u8 *a) {
    s32 v;

    switch (*(s32 *)(a + 0xC)) {
    case 0:
    default:
        (*(void (**)(void *))(a + 0x38))(a);
        break;
    case 1:
        if (*(s32 *)(a + 0x10) == 0) {
            break;
        }
        v = *(s32 *)(a + 0x5C) + *(s32 *)(a + 0x60);
        *(s32 *)(a + 0x5C) = v;
        if (*(s32 *)(a + 0x58) == 0) {
            if (v > 0xFF00) {
                *(s32 *)(a + 0x5C) = 0xFF00;
                *(s32 *)(a + 0xC) = 2;
            }
        } else if (v < 0) {
            *(s32 *)(a + 0x5C) = 0;
            *(s32 *)(a + 0xC) = 2;
        }
    case 2:
        func_80082E7C(a);
    case 3:
        break;
    }
}

void func_80083074(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80082FC0, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x64) = func_80082DF4;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0;
}

void func_800830B8(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
}

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_800830E0);

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_8008316C);

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_800836C4);

void func_80083B6C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800836C4, 0x90, 0x4C);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x84) = func_800830B8;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x88) = func_800830E0;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x8C) = func_8008316C;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 1;
}

void func_80083BD8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x74) = 0;
    M2C_FIELD(arg0, s32 *, 0x78) = 0;
    M2C_FIELD(arg0, s32 *, 0x68) = 0;
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    M2C_FIELD(arg0, s32 *, 0x94) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x90) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x84) = (s32) M2C_FIELD(arg0, s32 *, 0x58);
    M2C_FIELD(arg0, s32 *, 0x88) = (s32) M2C_FIELD(arg0, s32 *, 0x5C);
}

void func_80083C0C(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    M2C_FIELD(arg0, s32 *, 0x74) = arg2;
    M2C_FIELD(arg0, s32 *, 0x78) = 0;
}

void func_80083C1C(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    M2C_FIELD(arg0, s8 *, 0x6C) = arg1;
    M2C_FIELD(arg0, s8 *, 0x6D) = arg2;
    M2C_FIELD(arg0, s8 *, 0x6E) = arg3;
    M2C_FIELD(arg0, s8 *, 0x6F) = 0;
}

void func_80083C30(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    M2C_FIELD(arg0, s8 *, 0x70) = arg1;
    M2C_FIELD(arg0, s8 *, 0x71) = arg2;
    M2C_FIELD(arg0, s8 *, 0x72) = arg3;
    M2C_FIELD(arg0, s8 *, 0x73) = 0;
}

void func_80083C44(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    M2C_FIELD(arg0, s32 *, 0x5C) = arg2;
}

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80083C50);

void func_80084058(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80083C50, 0xD8, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xC4) = func_80083BD8;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xC8) = func_80083C0C;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32, s32), 0xCC) = func_80083C1C;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32, s32), 0xD0) = func_80083C30;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xD4) = func_80083C44;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 1;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x60) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0x64) = arg3;
}

void func_8008410C(void *arg0) {
    void **temp_s1;
    void *temp_a0;
    void *temp_a0_2;

    temp_s1 = M2C_FIELD(arg0, void ***, 0x24);
    ((M2C_UNK (*)(s32, M2C_UNK, M2C_UNK, M2C_UNK)) D_80088798)(arg0 + 0x78, -0x55, 0, 0xA);
    temp_a0 = *temp_s1;
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *, M2C_UNK, s32), 0x118)(temp_a0, 1, M2C_FIELD(M2C_FIELD(arg0, void **, 0x50), s32 *, 0x64) + 1);
    temp_a0_2 = *temp_s1;
    M2C_FIELD(temp_a0_2, M2C_UNK (**)(void *, M2C_UNK), 0x144)(temp_a0_2, 0);
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
}

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80084194);

void func_800841FC(void *arg0) {
    ((M2C_UNK (*)(s32, M2C_UNK, M2C_UNK, M2C_UNK)) D_80088798)(arg0 + 0x78, 0, -0x55, 5);
    M2C_FIELD(arg0, s32 *, 0x10) = 4;
}

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80084240);

void func_800842A0(void *arg0) {
    ((M2C_UNK (*)(s32, M2C_UNK, M2C_UNK, M2C_UNK)) D_80088798)(arg0 + 0x5C, 0xDE, 0, 0xA);
    M2C_FIELD(arg0, s32 *, 0x10) = 2;
}

void func_800842E4(void *arg0) {
    ((M2C_UNK (*)(s32, M2C_UNK, M2C_UNK, M2C_UNK)) D_80088798)(arg0 + 0x5C, 0, 0xDE, 5);
    M2C_FIELD(arg0, s32 *, 0x10) = 3;
}

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80084328);

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_800843D8);

void func_800849F0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800843D8, 0xF4, 4);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xDC) = func_80084328;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xE0) = func_8008410C;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xE4) = func_80084194;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xE8) = func_800841FC;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xEC) = func_800842A0;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xF0) = func_800842E4;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80084A80);

void func_80084B20(void *arg0, void *arg1) {
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;

    M2C_FIELD(arg0, s32 *, 0x10) = 0x64;
    M2C_FIELD(arg0, s32 *, 0x2804) = 0;
    M2C_FIELD(arg0, s32 *, 0x68) = (s32) (M2C_FIELD(arg0, s32 *, 0x68) - 1);
    temp_a0 = M2C_FIELD(arg1, void **, 8);
    if (temp_a0 != NULL) {
        M2C_FIELD(temp_a0, M2C_UNK (**)(void *, M2C_UNK), 0x144)(temp_a0, 0);
    }
    temp_a0_2 = M2C_FIELD(arg1, void **, 0xC);
    if (temp_a0_2 != NULL) {
        M2C_FIELD(temp_a0_2, M2C_UNK (**)(void *, M2C_UNK), 0x144)(temp_a0_2, 0);
    }
    temp_a0_3 = M2C_FIELD(arg1, void **, 0x10);
    if (temp_a0_3 != NULL) {
        M2C_FIELD(temp_a0_3, M2C_UNK (**)(void *, M2C_UNK), 0x144)(temp_a0_3, 0);
    }
    temp_a0_4 = M2C_FIELD(arg1, void **, 0x18);
    if (temp_a0_4 != NULL) {
        M2C_FIELD(temp_a0_4, M2C_UNK (**)(void *, M2C_UNK), 0x80)(temp_a0_4, 0);
    }
    temp_a0_5 = M2C_FIELD(arg1, void **, 0x1C);
    if (temp_a0_5 != NULL) {
        M2C_FIELD(temp_a0_5, M2C_UNK (**)(void *), 0xC4)(temp_a0_5);
    }
}

void func_80084BF8(void *arg0, void *arg1) {
    void *temp_a0;
    void *temp_a0_2;

    temp_a0 = M2C_FIELD(arg1, void **, 8);
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *, M2C_UNK), 0x144)(temp_a0, 0);
    temp_a0_2 = M2C_FIELD(arg1, void **, 0x1C);
    M2C_FIELD(temp_a0_2, M2C_UNK (**)(void *), 0xC4)(temp_a0_2);
    M2C_FIELD(arg0, s32 *, 0x10) = 0x5A;
    M2C_FIELD(arg0, s32 *, 0x14) = 0x64;
    M2C_FIELD(M2C_FIELD(arg1, void **, 0x20), s32 *, 0x10) = 0;
}

void func_80084C70(void *arg0) {
    void *temp_a0;

    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), void **, 0x24);
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *), 0x8C)(temp_a0);
}

void func_80084CA8(void *arg0) {
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_a0_6;
    void *temp_a0_7;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x24);
    temp_a0 = M2C_FIELD(temp_s0, void **, 4);
    if (temp_a0 != NULL) {
        M2C_FIELD(temp_a0, M2C_UNK (**)(void *, M2C_UNK), 0x144)(temp_a0, 0);
    }
    temp_a0_2 = M2C_FIELD(temp_s0, void **, 0x14);
    if (temp_a0_2 != NULL) {
        M2C_FIELD(temp_a0_2, M2C_UNK (**)(void *, M2C_UNK), 0x144)(temp_a0_2, 0);
    }
    temp_a0_3 = M2C_FIELD(temp_s0, void **, 8);
    if (temp_a0_3 != NULL) {
        M2C_FIELD(temp_a0_3, M2C_UNK (**)(void *, M2C_UNK), 0x144)(temp_a0_3, 0);
    }
    temp_a0_4 = M2C_FIELD(temp_s0, void **, 0xC);
    if (temp_a0_4 != NULL) {
        M2C_FIELD(temp_a0_4, M2C_UNK (**)(void *, M2C_UNK), 0x144)(temp_a0_4, 0);
    }
    temp_a0_5 = M2C_FIELD(temp_s0, void **, 0x10);
    if (temp_a0_5 != NULL) {
        M2C_FIELD(temp_a0_5, M2C_UNK (**)(void *, M2C_UNK), 0x144)(temp_a0_5, 0);
    }
    temp_a0_6 = M2C_FIELD(temp_s0, void **, 0x18);
    if (temp_a0_6 != NULL) {
        M2C_FIELD(temp_a0_6, M2C_UNK (**)(void *, M2C_UNK), 0x80)(temp_a0_6, 0);
    }
    temp_a0_7 = M2C_FIELD(temp_s0, void **, 0x1C);
    if (temp_a0_7 != NULL) {
        M2C_FIELD(temp_a0_7, M2C_UNK (**)(void *), 0xC4)(temp_a0_7);
    }
    M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
}

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80084DCC);

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80087368);

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80087534);

void func_80087798(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80087534, 0x285C, 0x28);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x2854) = func_80084C70;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x2858) = func_80084CA8;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
}

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_800877F0);

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80087B08);

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80087C18);

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80087DF0);

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_80087E78);

void func_80087EDC(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = 1;
    if (arg1 != 0) {
        ((void (*)(s32))D_80055C48[0])(0x40019);
        M2C_FIELD(arg0, s32 *, 4) = 0x1000 / M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 8) = 0;
    } else {
        ((void (*)(s32))D_80055C48[0])(0x4001A);
        M2C_FIELD(arg0, s32 *, 8) = 0x1000;
        M2C_FIELD(arg0, s32 *, 4) = -((0x1000 / M2C_FIELD(arg0, s32 *, 0)) * 2);
    }
}

s32 func_80087F70(Fade *f) {
    if (f->active == 0) {
        return 1;
    }
    f->value += f->speed;
    if (f->speed > 0) {
        if (f->value > 0x1000) {
            f->value = 0x1000;
            f->active = 0;
            return 1;
        }
    } else if (f->value < 0) {
        f->value = 0;
        f->active = 0;
        return 1;
    }
    return 0;
}

void func_80087FDC(Lerp *l, s32 from, s32 to, s32 n) {
  if (from != to)
  {
    l->frames = n;
    l->acc = from << 8;
    l->step = ((to - from) << 8) / l->frames;
    l->cur = from;
    l->target = to;
    l->active = 1;
  }
}

INCLUDE_ASM("asm/ovl/STGMCARD/nonmatchings/STGMCARD", func_8008801C);
