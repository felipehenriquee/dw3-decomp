#include "STGTRAIN.h"
#include "m2c.h"
#include "STGTRAIN_auto.h"
#include "STGTRAIN_data.h"

void func_80083058(void *arg0, void *arg1, s32 arg2) {
    M2C_FIELD(arg0, void **, 0x80) = arg1;
    M2C_FIELD(arg0, s32 *, 0x88) = arg2;
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) M2C_FIELD(arg1, u16 *, 2);
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) M2C_FIELD(arg1, u16 *, 4);
}

/* inicia a sequencia p (o primeiro s16 depois do cabecalho e a duracao) */
void func_80083078(u8 *o, s16 *p) {
    if (p != NULL) {
        *(s16 **)(o + 0x8C) = p;
        *(s32 *)(o + 0x90) = 0;
        *(s32 *)(o + 0x98) = 0;
        *(s32 *)(o + 0x94) = p[1];
        *(s32 *)(o + 0x78) = 0;
    }
}

void func_800830A0(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    M2C_FIELD(arg0, s32 *, 0x5C) = arg2;
}

void func_800830AC(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x60) = arg1;
    M2C_FIELD(arg0, s32 *, 0x64) = arg2;
}

void func_800830B8(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x68) = arg1;
    M2C_FIELD(arg0, s32 *, 0x6C) = arg2;
}

void func_800830C4(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x70) = arg1;
    M2C_FIELD(arg0, s32 *, 0x74) = arg2;
}

void func_800830D0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s32 *, 0xA8) = arg1;
    M2C_FIELD(arg0, s32 *, 0xAC) = arg2;
    M2C_FIELD(arg0, s32 *, 0xB0) = arg3;
    M2C_FIELD(arg0, s32 *, 0x9C) = 1;
}

void func_800830E8(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0xA0) = arg1;
    M2C_FIELD(arg0, s32 *, 0xA4) = arg2;
}

void func_800830F4(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s16 *, 0xB8) = arg1;
    M2C_FIELD(arg0, s16 *, 0xBA) = arg2;
    M2C_FIELD(arg0, s16 *, 0xBC) = arg3;
    M2C_FIELD(arg0, s32 *, 0x9C) = 1;
}

s32 func_8008310C(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x78) & 0x7FFFFFFF;
}

void func_80083120(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x78) = (s32) (M2C_FIELD(arg0, s32 *, 0x78) | 0x80000000);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x78) = (s32) (M2C_FIELD(arg0, s32 *, 0x78) & 0x7FFFFFFF);
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80083150);

Obj *func_80083880(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80083150, 0x10C, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xE0) = func_80083058;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xE4) = func_80083078;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xE8) = func_800830AC;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xEC) = func_800830B8;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xF0) = func_800830A0;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xF4) = func_800830C4;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32, s32), 0xF8) = func_800830D0;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xFC) = func_800830E8;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32, s32), 0x100) = func_800830F4;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x104) = func_8008310C;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x108) = func_80083120;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80083930);

Obj *func_80083AC0(void) {
    return func_80014504(func_80083930, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80083AEC);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80083D10);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80084064);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80084270);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80084370);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80084838);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008517C);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80085BB0);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80085DD8);

void func_80085EF4(void *arg0, s32 arg1, s32 arg2) {
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

void func_80085F7C(u8 *obj) {
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

void func_800860C0(u8 *a) {
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
        func_80085F7C(a);
    case 3:
        break;
    }
}

Obj *func_80086174(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800860C0, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x64) = func_80085EF4;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 6;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_800861BC);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_800862D0);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_800863D4);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_800865A0);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_800866CC);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80086ABC);

void func_80086B24(void *arg0, void *arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x74, 0xC0);
    M2C_FIELD(arg1, s32 *, 0) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, M2C_UNK), 0x160)(temp_v0, 2);
    M2C_FIELD(arg1, s32 *, 4) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x74, 0xCE);
    M2C_FIELD(arg1, s32 *, 8) = func_8001AE38(0x1002, 1, 0xA2, 0x75);
    M2C_FIELD(arg1, s32 *, 0xC) = func_8001AE38(0x1002, 1, 0xA2, 0x91);
    M2C_FIELD(arg1, s32 *, 0x10) = func_8001AE38(0x1002, 1, 0xA2, 0xA1);
    temp_v0_2 = func_8001B364(0x1002, M2C_FIELD(arg0, s32 *, 0x58) - 1, 0x94, 0x91);
    M2C_FIELD(arg1, s32 *, 0x14) = temp_v0_2;
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s32, M2C_UNK), 0x80)(temp_v0_2, 0);
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80086C0C);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008706C);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80087F28);

void *func_80088070(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80087F28, 0x134, 0x1C);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x60) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0xA0) = ((s32 (*)()) D_8004B43C)();
    return temp_v0;
}

void func_80088100(void) {
}

void func_80088108(void) {
}

/* prepara um contexto de desenho e o descarta (sobra de codigo) */
void func_80088110(void) {
    u8 g[0xA0];

    func_8001F648(g);
}

void func_80088130(void) {
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80088138);

void func_800881CC(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80088138, 0x6C, 0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

void func_80088214(void *arg0, void *arg1) {
    s32 temp_v0;

    M2C_FIELD(arg1, s32 *, 0) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0xA2, 0x49);
    M2C_FIELD(arg1, s32 *, 4) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0xBC, 0x14);
    M2C_FIELD(arg1, s32 *, 8) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0xC0, 0x29);
    M2C_FIELD(arg1, s32 *, 0xC) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x98, 0x66);
    M2C_FIELD(arg1, s32 *, 0x10) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0xC0, 0x66);
    M2C_FIELD(arg1, s32 *, 0x14) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0xE6, 0x66);
    M2C_FIELD(arg1, s32 *, 0x18) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x94, 0x87);
    M2C_FIELD(arg1, s32 *, 0x1C) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0xA2, 0x64);
    M2C_FIELD(arg1, s32 *, 0x20) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0xA2, 0x74);
    temp_v0 = func_8001B364((s32) M2C_FIELD(arg0, s16 *, 0x54), M2C_FIELD(arg0, s32 *, 0x58) - 1, 0, 0);
    M2C_FIELD(arg1, s32 *, 0x24) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, M2C_UNK), 0x80)(temp_v0, 0);
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80088348);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_800888BC);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_80089698);

void func_80089758(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0x1E;
}

void func_80089764(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80089698, 0xFC, 0x28);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xF8) = func_80089758;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_800897B8);

void func_8008A0F4(void *arg0) {
    void *temp_a0;
    void *temp_a0_2;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x24);
    temp_a0 = M2C_FIELD(temp_s0, void **, 0);
    if (temp_a0 != NULL) {
        M2C_FIELD(temp_a0, M2C_UNK (**)(void *, M2C_UNK), 0x108)(temp_a0, 1);
    }
    temp_a0_2 = M2C_FIELD(temp_s0, void **, 4);
    if (temp_a0_2 != NULL) {
        M2C_FIELD(temp_a0_2, M2C_UNK (**)(void *, M2C_UNK), 0x108)(temp_a0_2, 1);
    }
}

void func_8008A158(void *arg0) {
    void *temp_a0;
    void *temp_a0_2;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x24);
    temp_a0 = M2C_FIELD(temp_s0, void **, 0);
    if (temp_a0 != NULL) {
        M2C_FIELD(temp_a0, M2C_UNK (**)(void *, M2C_UNK), 0x108)(temp_a0, 0);
    }
    temp_a0_2 = M2C_FIELD(temp_s0, void **, 4);
    if (temp_a0_2 != NULL) {
        M2C_FIELD(temp_a0_2, M2C_UNK (**)(void *, M2C_UNK), 0x108)(temp_a0_2, 0);
    }
    M2C_FIELD(arg0, s32 *, 0x50) = 4;
}

void func_8008A1D0(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x80) = arg1;
    M2C_FIELD(arg0, s32 *, 0x84) = arg2;
    M2C_FIELD(arg0, s32 *, 0x94) = 1;
}

void func_8008A1E4(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x88) = arg1;
    M2C_FIELD(arg0, s32 *, 0x8C) = arg2;
    M2C_FIELD(arg0, s32 *, 0x98) = 1;
}

void func_8008A1F8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x9C) = arg1;
}

void func_8008A200(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x68) = 0x199;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, s32 *, 0x50) = 2;
}

void func_8008A218(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x64) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x68) = -0x333;
    M2C_FIELD(arg0, s32 *, 0x50) = 2;
}

void func_8008A234(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x70) = 1;
    M2C_FIELD(arg0, s32 *, 0x64) = arg1;
}

/* valor em 0x60 se o bit 0 de 0x50 esta ligado, senao -1 */
s32 func_8008A244(u8 *o) {
    if (*(s32 *)(o + 0x50) & 1) {
        return *(s32 *)(o + 0x60);
    }
    return -1;
}

void func_8008A264(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x50) = 8;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
}

void func_8008A274(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800897B8, 0xD4, 0xC);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xA4) = func_8008A1D0;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xA8) = func_8008A1E4;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xAC) = func_8008A1F8;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xB0) = func_8008A200;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xB4) = func_8008A218;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xB8) = func_8008A158;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xBC) = func_8008A0F4;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xC0) = func_8008A234;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xC4) = func_8008A244;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x74) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0x78) = arg3;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xC8) = func_8008A264;
}

void func_8008A354(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0xAE, 0x49);
    M2C_FIELD(arg1, s32 *, 4) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0xA3, 0xA0);
    M2C_FIELD(arg1, s32 *, 8) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x74, 0xC0);
    M2C_FIELD(arg1, s32 *, 0xC) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x74, 0xCE);
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008A3E0);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008A524);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008AAD4);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008B520);

void func_8008B7F0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xC) = 1;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
}

void func_8008B800(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xC) = 1;
    M2C_FIELD(arg0, s32 *, 0x10) = 0x32;
}

s32 func_8008B814(void *arg0) {
    return func_8008A3E0((s32) arg0, M2C_FIELD(arg0, s32 *, 0x24), 1);
}

void func_8008B838(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008B520, 0x114, 0x10);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x108) = func_8008B7F0;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x10C) = func_8008B800;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x110) = func_8008B814;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008B8A4);

void func_8008B8FC(void *arg0, s32 arg1) {
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

s32 func_8008B990(Fade *f) {
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

void func_8008B9FC(Lerp *l, s32 from, s32 to, s32 n) {
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

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008BA3C);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008BAA8);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008BB38);

void func_8008BBD0(void) {
    if (D_8008CFD4[0] != -1) {
        (*(void (**)(s32))&D_80044F50)(D_8008CE3C[D_8008CFD4[0] * 4]);
    }
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008BC1C);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008BC94);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008BD08);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008BD90);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008BE54);

s32 func_8008C064(s32 i) {
    return D_8008CE3C[i * 4];
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008C080);

s32 func_8008C0A4(s32 i) {
    s32 *t = D_8008CE3C;

    return (t + i * 4)[3];
}

s32 func_8008C0C0(s32 i) {
    return D_8008CFCC[i * 20 + 4];
}

s32 func_8008C0E4(s32 i) {
    return D_8008CFCC[i * 20 + 5];
}

s32 func_8008C108(s32 i) {
    return D_8008CFCC[i * 20 + 6];
}

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008C12C);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008C158);

INCLUDE_ASM("asm/ovl/STGTRAIN/nonmatchings/STGTRAIN", func_8008C1C8);
