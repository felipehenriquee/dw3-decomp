#include "main.h"
#include "m2c.h"
#include "main_auto.h"
#include "main_data.h"

void func_80010F4C(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/nonmatchings/main", func_80010FE0);

void func_8001104C(void) {
    s32 i;
    s32 j;
    s32 id;
    u8 *p;
    u8 *sys;

    for (i = 0, sys = D_80048D34; i < 3; i++) {
        id = (*(s32 (**)(s32))(sys + 0x2718))(i);
        if (id >= 0) {
            p = (*(u8 *(**)(s32))(sys + 0x2750))(id);
            *(s16 *)(p + 0x20) = *(s16 *)(p + 0x22);
            *(s16 *)(p + 0x24) = *(s16 *)(p + 0x26);
            for (j = 2; j >= 0; j--) {
                ((s16 *)(p + 0x42))[j] = 0;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_800110E0);

INCLUDE_ASM("asm/nonmatchings/main", func_800119A8);

void func_80011DAC(s32 arg0)
{
    Obj *o = func_80014504(func_800119A8, 0xA0, 0x20);

    o->unk50 = arg0;
    o->unk54 = 1;
}

void func_80011DEC(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, void (**)(void *, s32), 0x28)(arg0, 1);
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    if (arg1 == 0) {
        M2C_FIELD(arg0, s32 *, 0x5C) = 0;
        M2C_FIELD(arg0, s32 *, 0x60) = 0xFF00 / arg2;
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x5C) = 0xFF00;
    M2C_FIELD(arg0, s32 *, 0x60) = -(0xFF00 / arg2);
}

INCLUDE_ASM("asm/nonmatchings/main", func_80011E74);

INCLUDE_ASM("asm/nonmatchings/main", func_80011FB8);

void func_8001206C(s32 arg0) {
    Obj *o = func_80014504(func_80011FB8, 0x68, 0);

    M2C_FIELD(o, void (**)(void *, s32, s32), 0x64) = func_80011DEC;
    o->unk50 = arg0;
    o->unk54 = 0;
}

void func_800120B4(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/nonmatchings/main", func_80012148);

INCLUDE_ASM("asm/nonmatchings/main", func_800121B4);

INCLUDE_ASM("asm/nonmatchings/main", func_800123E0);

s32 func_800126A8(void) {
    u8 *p = D_80048D34;
    s32 v = (*(s32 (**)(void))(p + 0x2704))();

    if (v == 0x1000) {
        v = *(s32 *)(p + 0x34);
    }
    if (v >= 0x2D7) {
        return -1;
    }
    return v >= 0x270;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001270C);

void func_8001345C(s32 arg0, s32 arg1) {
    Obj *o = func_80014504(func_8001270C, 0xA0, 0xAC);

    o->unk50 = arg0;
    o->unk54 = 1;
    M2C_FIELD(o, s32 *, 0x58) = arg1;
}

s32 func_800134AC(s32 id) {
    s32 i;

    for (i = 0; i < 52; i++) {
        if (*(u16 *)&D_8003EF5C[i] == id) {
            return i;
        }
    }
    return -1;
}

Ent *func_800134E8(s32 arg0)
{
    s32 i = func_800134AC(arg0);

    if (i >= 0) {
        return &D_8003EF5C[i];
    }
    return NULL;
}

void func_80013534(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        ((Unk80042B1C *)D_80042B1C)->unk58[i] = 0;
    }
}

Unk80041838 *func_8001355C(s32 arg0) {
    if (arg0 <= 0) {
        return NULL;
    }
    return &D_80041838[arg0];
}

u8 func_80013584(s32 arg0) {
    return D_80042BA8[M2C_FIELD(func_8001355C(arg0), u8 *, 9)];
}

s32 func_800135B8(s32 arg0, s32 arg1) {
    return M2C_FIELD(func_8001355C(arg0), u8 *, 8) == arg1;
}

INCLUDE_ASM("asm/nonmatchings/main", func_800135E8);

s32 func_80013694(void) {
    s32 pos;
    u8 *s;

    CdGetSector(D_8005CD28, 3);
    pos = CdPosToInt(D_8005CD28);
    s = (u8 *)&D_80044B04;
    if (pos == *(s32 *)(s + 0x28)) {
        *(s32 *)(s + 0x28) = pos + 1;
        return 0;
    }
    return -1;
}

/* callback da leitura do CD (registrado por func_80013780) */
void func_800136F4(s32 status) {
    u8 *cd;
    s32 n;

    if (status == 1 && func_80013694() == 0) {
        cd = (u8 *)&D_80044B04;
        CdGetSector(*(s32 *)(cd + 0x24), 0x200);
        *(s32 *)(cd + 0x24) += 0x800;
        n = *(s32 *)(cd + 0x20) - 1;
        *(s32 *)(cd + 0x20) = n;
        if (n != 0) {
            return;
        }
    } else {
        D_80044B24[0] = -1;
    }
    func_8002E27C(0);
    CdControlF(9, 0);
}

void func_80013780(s32 arg0)
{
    s32 *p;

    switch (arg0) {
    case 5:
        if (D_80044B04.state == 4) {
            CdControlF(9, NULL); /* CdlPause */
        } else {
            goto fail;
        }
        break;
    case 2:
        switch (D_80044B04.state) {
        case 1:
            D_8005CCF8[0] = 0xA0;
            CdControlF(0xE, D_8005CCF8); /* CdlSetmode */
            D_80044B04.state++;
            break;
        case 2:
            func_8002E27C(func_800136F4);
            CdControlF(6, NULL); /* CdlReadN */
            D_80044B04.state++;
            break;
        case 3:
            D_80044B04.state = 4;
            break;
        case 4:
            func_8002E25C(0);
            if (D_80044B04.busy != 0) {
                goto fail;
            }
            p = D_80044B04.done;
            D_80044B04.state = 0;
            if (p != NULL) {
                *p = 1;
            }
            break;
        }
        break;
    }
    return;
fail:
    func_800138B8();
}

s32 func_800138A8(void) {
    return D_80044B04.state != 0;
}

void func_800138B8(void) {
    D_80044B04.state = 1;
    M2C_FIELD(&D_80044B04, s32 *, 0x28) = (s32) D_80044B04.pad2[1];
    M2C_FIELD(&D_80044B04, s32 *, 0x24) = (s32) D_80044B04.pad[3];
    D_80044B04.busy = D_80044B04.pad[2];
    func_8002E25C((s32) func_80013780);
    CdControlF(2U, (u8 *) D_80044B04.pad2);
}

INCLUDE_ASM("asm/nonmatchings/main", func_80013914);

Unk80044B3C *func_800139FC(s32 id) {
    s32 i;
    Unk80044B3C *p = (Unk80044B3C *)D_80044B3C;

    for (i = 0; i < 64; i++, p++) {
        if (p->id == id) {
            return p;
        }
    }
    return NULL;
}

Unk80044B3C *func_80013A34(void) {
    s32 i;
    Unk80044B3C *p = (Unk80044B3C *)D_80044B3C;

    for (i = 0; i < 64; i++, p++) {
        if (p->id == 0) {
            return p;
        }
    }
    return NULL;
}

s32 func_80013A6C(s32 arg0) {
    s16 *p = (s16 *)func_800139FC(arg0);

    if (p != NULL) {
        M2C_FIELD(p, s32 *, 8) = (*(s32 (**)(void))&D_8004DF98)();
        if (p[0] == 3) {
            return 0;
        }
    } else {
        func_80013C30(arg0);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/main", func_80013ADC);

void func_80013BE4(void) {
    void *temp_v0;

    temp_v0 = func_80013ADC();
    (*(s32 (**)())&D_8004B5EC)(M2C_FIELD(temp_v0, s32 *, 0xC));
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    M2C_FIELD(temp_v0, s32 *, 0xC) = 0;
    M2C_FIELD(temp_v0, s32 *, 8) = 0;
    M2C_FIELD(temp_v0, s16 *, 2) = 0;
    M2C_FIELD(temp_v0, s16 *, 0) = 0;
}
/* Warning: struct opaque is not defined (only forward-declared) */

INCLUDE_ASM("asm/nonmatchings/main", func_80013C30);

INCLUDE_ASM("asm/nonmatchings/main", func_80013CDC);

void func_80013E20(s32 arg0) {
    func_80013C30(arg0);
    do {
        func_80013CDC();
    } while (func_80013A6C(arg0) != 0);
}

s32 func_80013E5C(s32 id) {
    Unk80044B3C *p = func_800139FC(id);
    CdState *cd;

    if (p != NULL && p->unk0 == 3) {
        p->unk8 = (*(s32 (**)(void))&D_8004DF98)();
        return p->unkC;
    }
    cd = &D_80044B04;
    while ((*(s32 (**)(void))((u8 *)cd + 0x2C))() != 0) {
    }
    func_80013E20(id);
    return func_800139FC(id)->unkC;
}

void func_80013EFC(s32 arg0) {
    s16 *p = (s16 *)func_800139FC(arg0);

    if (p != NULL && p[0] == 3) {
        (*(void (**)(s32))&D_8004B5EC)(M2C_FIELD(p, s32 *, 0xC));
        M2C_FIELD(p, s32 *, 4) = 0;
        M2C_FIELD(p, s32 *, 0xC) = 0;
        M2C_FIELD(p, s32 *, 8) = 0;
        p[1] = 0;
        p[0] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_80013F60);

INCLUDE_ASM("asm/nonmatchings/main", func_80013FF4);

s32 func_800140D8(u32 arg0) {
    s32 idx = arg0 & 0xFFFF;
    s32 *base = (s32 *)func_80013E5C(arg0 >> 16);

    return base[idx] + (s32)base;
}

s32 func_80014110(u16 i, s32 *base) {
    return base[i] + (s32)base;
}

void func_80014128(void) {
    s32 i;
    Unk80044B3C *p = (Unk80044B3C *)D_80044B3C;

    for (i = 0; i < 64; i++, p++) {
        if (p->id == 0) {
            p->unk2 = 0;
        } else {
            p->unk2 = 1;
        }
    }
}

void func_80014170(void) {
    Unk80044B3C *p = (Unk80044B3C *)D_80044B3C;
    s32 t = (*(s32 (**)(void))&D_8004DF98)() - 10;
    s32 i;

    for (i = 0; i < 64; i++, p++) {
        if (p->id != 0 && p->unk2 != 0) {
            p->unk8 = t;
            p->unk2 = 0;
        }
    }
}

s32 func_800141E4(s32 arg0) {
    return (&D_80044F6C)[arg0] != 0;
}

u16 func_80014200(s32 arg0) {
    return D_800474A4[arg0];
}

s32 func_8001421C(s32 arg0) {
    return (&D_80044F6C)[arg0];
}

void func_80014238(s32 arg0, s32 arg1, M2C_UNK arg2) {
    CdIntToPos((&D_80044F6C)[arg0] + arg1, arg2);
}

void func_80014274(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
}

void func_80014288(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
}

void func_80014298(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x14) = arg1;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
}

void func_800142A4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
}

void func_800142AC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + 1);
}

void func_800142C8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + 1);
}

void func_800142E0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + 1);
}

void func_800142F4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) + 1);
}

INCLUDE_ASM("asm/nonmatchings/main", func_80014308);

INCLUDE_ASM("asm/nonmatchings/main", func_800143DC);

Obj *func_80014504(void (*fn)(), s32 size, s32 prio) {
    return (Obj *)func_800143DC(fn, size, prio, 0);
}

INCLUDE_ASM("asm/nonmatchings/main", func_80014524);

INCLUDE_RODATA("asm/nonmatchings/main", D_800100C4);

INCLUDE_RODATA("asm/nonmatchings/main", D_800100C8);

INCLUDE_ASM("asm/nonmatchings/main", func_800148C0);

INCLUDE_ASM("asm/nonmatchings/main", func_80014908);

INCLUDE_ASM("asm/nonmatchings/main", func_8001491C);

INCLUDE_ASM("asm/nonmatchings/main", func_80014930);

/* consulta assincrona do cartao de memoria, com contador de tentativas */
s32 func_80014AA8(void) {
    s32 cmd;
    u32 result;
    s32 r;
    u8 *mc;

    r = MemCardSync(1, &cmd, &result);
    if (r != 1) {
        return r;
    }
    mc = D_80048750;
    *(s32 *)(mc + 0x90) = cmd;
    *(s32 *)(mc + 0x94) = result;
    if (result < 2 || result == 3) {
        *(s32 *)(mc + 0x98) = 0;
    } else {
        if (++*(s32 *)(mc + 0x98) < *(s32 *)(mc + 0x9C)) {
            *(s32 *)(mc + 0xA0) = r;
            return 0;
        }
        *(s32 *)(mc + 0x98) = 0;
        *(s32 *)(mc + 0xA0) = 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/main", func_80014B44);

INCLUDE_ASM("asm/nonmatchings/main", func_80014C24);

INCLUDE_RODATA("asm/nonmatchings/main", jtbl_80010114);

INCLUDE_ASM("asm/nonmatchings/main", func_80014D04);

INCLUDE_ASM("asm/nonmatchings/main", func_80014FC4);

INCLUDE_ASM("asm/nonmatchings/main", func_80015288);

s32 func_80015480(s32 arg0) {
    s32 r = func_80015288(arg0, 0);

    if (r == 1) {
        return 1;
    }
    return r;
}

s32 func_800154B8(s32 arg0) {
    s32 r = func_80015288(arg0, 1);

    if (r == 1) {
        return 1;
    }
    return r;
}

s32 func_800154F0(s32 arg0) {
    s32 r = func_80015288(arg0, 2);

    if (r == 1) {
        return 1;
    }
    return r;
}

s32 func_80015528(void) {
    return 2;
}

/* confere o checksum XOR de n bytes */
s32 func_80015530(u8 *p, s32 n, u8 expected) {
    u8 sum = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        sum ^= *p++;
    }
    return sum == expected;
}

/* checksum XOR de n bytes */
u8 func_80015564(u8 *p, s32 n) {
    u8 sum = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        sum ^= *p++;
    }
    return sum;
}

s32 func_80015590(u8 *bits, s32 n, s32 flag)
{
    s32 idx = n >> 3;
    s32 mask = 1 << (n & 7);

    if (flag != 0) {
        return (bits[idx] & mask) != 0;
    }
    return (bits[idx] & mask) == 0;
}

void func_800155D4(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_a3;
    u8 *temp_v0;
    u8 *temp_v1;

    temp_a3 = arg1 >> 3;
    temp_a0 = 1 << (arg1 & 7);
    if (arg2 != 0) {
        temp_v1 = arg0 + temp_a3;
        *temp_v1 |= temp_a0;
        return;
    }
    temp_v0 = arg0 + temp_a3;
    *temp_v0 &= ~temp_a0;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001561C);

INCLUDE_ASM("asm/nonmatchings/main", func_80015754);

INCLUDE_ASM("asm/nonmatchings/main", func_80015AAC);

INCLUDE_ASM("asm/nonmatchings/main", func_80015B9C);

INCLUDE_ASM("asm/nonmatchings/main", func_80015BD8);

s32 func_80015D4C(void) {
    void *temp_v0;

    temp_v0 = (*(s32 (**)())&D_8004B7BC)(0x16, -1, -1);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x2C)(temp_v0, 3);
    return 1;
}
/* Warning: struct opaque is not defined (only forward-declared) */

INCLUDE_ASM("asm/nonmatchings/main", func_80015D90);

INCLUDE_ASM("asm/nonmatchings/main", func_80015EC8);

INCLUDE_ASM("asm/nonmatchings/main", func_80015F04);

INCLUDE_ASM("asm/nonmatchings/main", func_80015F70);

INCLUDE_ASM("asm/nonmatchings/main", func_80015FBC);

INCLUDE_ASM("asm/nonmatchings/main", func_800160A8);

INCLUDE_ASM("asm/nonmatchings/main", func_80016124);

INCLUDE_ASM("asm/nonmatchings/main", func_800161D8);

void func_80016314(s32 arg0, s32 arg1) {
    u8 *p;

    if (arg1 != 0) {
        ((void (*)(s32, s32))D_8004B454[0])(arg0, 1);
        return;
    }
    p = &D_80048D34[arg0];
    p[0x3A2]--;
    if ((s8)p[0x3A2] < 0) {
        p[0x3A2] = 0;
    }
}

void func_80016378(s32 arg0, s32 arg1) {
    func_8008B770(0x700, (arg0 * 2) + arg1 + 1, 0, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/main", func_800163B0);

INCLUDE_ASM("asm/nonmatchings/main", func_800165AC);

/* lista de pares u16 terminada em 0xFFFF; para no primeiro que falhar */
s32 func_80016924(u16 *p) {
    u16 a = *p;

    while (a != 0xFFFF) {
        p++;
        if (func_800163B0(a, *p++) == 0) {
            return 0;
        }
        a = *p;
    }
    return 1;
}

/* lista de pares u16 terminada em 0xFFFF */
void func_80016988(u16 *p) {
    u16 a = *p;

    while (a != 0xFFFF) {
        p++;
        func_800165AC(a, *p++);
        a = *p;
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_800169E0);

void func_80016A94(void) {
    (*(s32 (**)())&D_8004B600)(D_80048D34, 0x26C4);
    M2C_FIELD(D_80048D34, s32 *, 0x26C4) = 0x1600;
    M2C_FIELD(D_80048D34, s32 *, 0x26C8) = 0x1600;
    M2C_FIELD(D_80048D34, s8 *, 4) = 1;
    M2C_FIELD(D_80048D34, s8 *, 0x26D4) = 1;
    M2C_FIELD(D_80048D34, s8 *, 0x26D5) = 8;
    M2C_FIELD(D_80048D34, s8 *, 0x26D7) = 0x3C;
    M2C_FIELD(D_80048D34, s32 *, 0x26D0) = 0;
    M2C_FIELD(D_80048D34, s8 *, 0x26D6) = 0;
    M2C_FIELD(D_80048D34, s32 *, 0xC) = -1;
    func_80016BAC();
    M2C_FIELD(D_80048D34, s32 *, 0x30) = (s32) (((*(s32 (**)())&D_8004DC0C)() & 0x1FF) + 0x200);
}
/* Warning: struct opaque is not defined (only forward-declared) */

void func_80016B28(void) {
    u8 *p = D_80048D34;
    s32 v = *(s32 *)(p + 0x26C8);
    s32 old;

    if (v != 0) {
        old = *(s32 *)(p + 0x26C4);
        *(s32 *)(p + 0x26C4) = v;
        *(s32 *)(p + 0x26C8) = 0;
        *(s32 *)(p + 0x26CC) = old;
    }
}

s32 func_80016B58(void) {
    return D_8004B400[0];
}

s32 func_80016B68(void) {
    return D_8004B3F8[0];
}

s32 func_80016B78(void) {
    return D_8004B404[0];
}

void func_80016B88(s32 arg0, s32 arg1) {
    u8 *p = D_80048D34;

    *(s32 *)(p + 0x26C8) = arg0;
    *(s32 *)(p + 0x26D0) = arg1;
}

s32 func_80016B9C(void) {
    return D_8004B3FC[0] != 0;
}

INCLUDE_ASM("asm/nonmatchings/main", func_80016BAC);

s32 func_80016D94(u32 arg0) {
    if (arg0 >= 3) {
        return -1;
    }
    return ((Unk80048D34 *)D_80048D34)->unk70[arg0];
}

INCLUDE_ASM("asm/nonmatchings/main", func_80016DC0);

void func_80016E2C(s32 arg0, s32 arg1) {
    u8 *temp_a0;
    u8 temp_v0;

    temp_a0 = &D_80048D34[arg0];
    M2C_FIELD(temp_a0, s8 *, 0x4DF) = 1;
    temp_v0 = M2C_FIELD(temp_a0, u8 *, 0x3A2) + arg1;
    M2C_FIELD(temp_a0, u8 *, 0x3A2) = temp_v0;
    if ((s8) temp_v0 >= 0xA) {
        M2C_FIELD(temp_a0, u8 *, 0x3A2) = 9U;
    }
}

void func_80016E6C(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 40; i++) {
        func_80016E2C(D_8004B49C[i], 1);
    }
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 40; i++) {
            ((Unk80048D34_63E *)(D_80048D34 + j * 0x66 + i * 2))->unk63E = D_8004B49C[i];
        }
    }
}

void func_80016F0C(void) {
    u8 *p = D_80048D34;

    *(s16 *)(p + 0x52) = 0;
    *(s16 *)(p + 0x50) = 0;
    *(s16 *)(p + 0x4E) = 0;
    *(s16 *)(p + 0x4C) = 0;
    *(s32 *)(p + 0x48) = 0;
}

/* relogio do tempo de jogo (quadros em 0x48, s/m/h em 0x50/0x4E/0x4C) */
void func_80016F2C(void) {
    u8 *p = D_80048D34;
    s32 frames = *(s32 *)(p + 0x48);

    if ((frames >> 8) >= 60) {
        *(s32 *)(p + 0x48) = frames & 0xFF;
        if (++*(s16 *)(p + 0x50) >= 60) {
            *(s16 *)(p + 0x50) = 0;
            if (++*(s16 *)(p + 0x4E) >= 60) {
                *(s16 *)(p + 0x4E) = 0;
                if (++*(s16 *)(p + 0x4C) >= 1000) {
                    *(s16 *)(p + 0x4C) = 999;
                    *(s16 *)(p + 0x4E) = 59;
                    *(s16 *)(p + 0x50) = 59;
                    *(s16 *)(p + 0x52) = 1;
                }
            }
        }
    }
}

s32 func_80016FD8(u32 arg0) {
    Unk80048D34_3DC *p;
    s32 idx;

    if (arg0 >= 3) {
        return -1;
    }
    idx = ((Unk80048D34 *)D_80048D34)->unk70[arg0];
    p = &((Unk80048D34_3DC *)D_80048D34)[idx];
    return *(s32 *)(p->unk0 + 0x760) - 3;
}

void func_80017028(s32 who, u32 stat, s16 v) {
    Unk8004949C *c = &((Unk8004949C *)D_8004949C)[who];
    s16 *p = c->stat;

    if (stat < 19) {
        p += stat;
        *p = v;
        if (v < 0) {
            *p = 0;
            return;
        }
        if (stat < 2) {
            if (v >= 100) {
                *p = 99;
                return;
            }
        } else if (stat - 2 < 4) {
            if (v >= 10000) {
                *p = 9999;
                return;
            }
        } else if (v >= 1000) {
            *p = 999;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_800170C8);

INCLUDE_ASM("asm/nonmatchings/main", func_80017174);

INCLUDE_ASM("asm/nonmatchings/main", func_80017578);

s32 func_8001764C(s32 arg0, s32 arg1) {
    s32 i;
    s16 v;

    for (i = 0; i < 44; i++) {
        v = ((Unk80048D34_7B8 *)(D_80048D34 + arg0 * 0x3DC + i * 0x14))->unk7B8;
        if (v >= 3 && v == arg1) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/main", func_800176AC);

INCLUDE_ASM("asm/nonmatchings/main", func_800177D0);

INCLUDE_ASM("asm/nonmatchings/main", func_80017898);

INCLUDE_ASM("asm/nonmatchings/main", func_80017924);

INCLUDE_ASM("asm/nonmatchings/main", func_80017A1C);

INCLUDE_ASM("asm/nonmatchings/main", func_80017AB4);

void *func_80017B4C(s32 arg0) {
    return (arg0 * 0x3DC) + D_8004949C;
}

void func_80017B70(void *arg0) {
    void **temp_v1;
    void *temp_a0;
    void *temp_a1;

    temp_a1 = arg0 - 0xC;
    if (arg0 != NULL) {
        temp_a0 = M2C_FIELD(arg0, void **, -0xC);
        temp_v1 = M2C_FIELD(temp_a1, void ***, 4);
        M2C_FIELD(temp_a1, s32 *, 8) = 0;
        if (M2C_FIELD(temp_v1, s32 *, 8) == 0) {
            M2C_FIELD(temp_a1, void ***, 4) = (void **) M2C_FIELD(temp_v1, void ***, 4);
            *M2C_FIELD(temp_v1, void ***, 4) = temp_a1;
        }
        if (M2C_FIELD(temp_a0, s32 *, 8) == 0) {
            M2C_FIELD(temp_a0, void ***, 4) = (void **) M2C_FIELD(temp_a1, void ***, 4);
            M2C_FIELD(M2C_FIELD(temp_a1, void ***, 4), void **, 0) = temp_a0;
        }
    }
}

void func_80017BDC(void) {
}

void func_80017BE4(s32 tag) {
    HeapBlock *b = D_8004B5E0[0];

    while (b->tag != 1) {
        if (b->tag == tag) {
            func_80017B70(b + 1);
        }
        b = b->next;
    }
}

/* inicializa o heap: de D_8005CB50[0] ate 0x801FF000 (abaixo da pilha) */
void func_80017C5C(void) {
    s32 *info = (s32 *)&D_8004B5DC;
    s32 *start;
    s32 *end;

    info[2] = 0x801FF000;
    end = (s32 *)0x801FEFF4;
    start = D_8005CB50[0];
    info[1] = (s32)start;
    info[0] = 0x801FF000 - (s32)start;
    start[0] = (s32)start;
    start[1] = (s32)end;
    start[2] = 0;
    end[0] = (s32)start;
    end[2] = 1;
    end[1] = info[2];
}

void func_80017CB0(u8 *p, s32 n) {
    s32 i;

    if (n & 3) {
        for (i = 0; i < n; i++) {
            *p++ = 0;
        }
    } else {
        n >>= 2;
        for (i = 0; i < n; i++) {
            *(s32 *)p = 0;
            p += 4;
        }
    }
}

void func_80017D08(s8 *arg0, s8 arg1, s32 arg2) {
    s32 var_v1;
    s8 *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    if (arg2 > 0) {
        do {
            *var_a0 = arg1;
            var_v1 += 1;
            var_a0 += 1;
        } while (var_v1 < arg2);
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_80017D2C);

INCLUDE_ASM("asm/nonmatchings/main", func_80017DDC);

s32 func_80017E84(s32 size, s32 arg1) {
    u8 *sys = (u8 *)D_80044B38;
    s32 p;

    while ((p = func_80017D2C(size, arg1)) == 0) {
        (*(void (**)(void))(sys + 0x408))();
    }
    return p;
}

s32 func_80017EEC(s32 size, s32 arg1) {
    u8 *sys = (u8 *)D_80044B38;
    s32 p;

    while ((p = func_80017DDC(size, arg1)) == 0) {
        (*(void (**)(void))(sys + 0x408))();
    }
    return p;
}

/* aloca e zera */
s32 func_80017F54(s32 size, s32 arg1) {
    s32 p;

    p = func_80017E84(size, arg1);
    func_80017CB0(p, size);
    return p;
}

void func_80017F94(s32 arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = arg0 - 0xC;
    if (arg1 != 0) {
        M2C_FIELD(temp_a0, s32 *, 8) = 4;
        return;
    }
    M2C_FIELD(temp_a0, s32 *, 8) = 2;
}

void func_80017FB4(void) {
    s32 i;

    for (i = 99; i >= 0; i--) {
        D_8004B610[i] = 0;
    }
}

void func_80017FDC(s32 arg0) {
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_8004B610[i] == 0) {
            D_8004B610[i] = arg0;
            return;
        }
    }
}

void func_80018014(s32 arg0) {
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_8004B610[i] == arg0) {
            D_8004B610[i] = 0;
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001804C);

void func_8001810C(s32 arg0, s32 arg1, s32 arg2) {
    s32 *p = D_8004B610;

    p[100] = arg0;
    p[101] = arg1;
    p[102] = arg2;
    p[103] = 0;
    func_8001804C();
}

INCLUDE_ASM("asm/nonmatchings/main", func_80018140);

void func_80018230(void *arg0) {
    s32 n = M2C_FIELD(arg0, s32 *, 0x20);
    s32 *items = M2C_FIELD(arg0, s32 **, 0x24);
    s32 i;

    for (i = 0; i < n; i++) {
        if (items[i] != 0) {
            items[i] = func_80018140(items[i]);
        }
    }
}

s32 func_8001829C(s32 arg0) {
    if (arg0 != 0) {
        return func_80018140(arg0);
    }
    return 0;
}

void func_800182C8(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, void (**)(void *, s32), 0x28)(arg0, 3);
        ((void (*)(void *))D_8004B7C8[0])(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_80018310);

void func_8001843C(void) {
    func_800184D0();
    *((s32 *)&D_8004B7D0) = 0;
}

void func_80018460(void) {
    if (!(*((s32 *)&D_8004B7D0) & 0x40000000)) {
        func_80018310(0, 0x10);
    }
    if (!(*((s32 *)&D_8004B7D0) & 0x20000000)) {
        PadStartCom();
        *((s32 *)&D_8004B7D0) |= 0x20000000;
    }
}

void func_800184D0(void) {
    if (*((s32 *)&D_8004B7D0) & 0x20000000) {
        PadStopCom();
    }
    *((s32 *)&D_8004B7D0) &= 0xDFFFFFFF;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001851C);

INCLUDE_ASM("asm/nonmatchings/main", func_800186E0);

u16 func_80018854(s32 arg0) {
    return ((Unk8004B7D0 *)D_8004B7D0)[arg0].unk48;
}

u16 func_80018878(s32 arg0) {
    return ((Unk8004B7D0 *)D_8004B7D0)[arg0].unk4E;
}

u16 func_8001889C(s32 arg0) {
    return ((Unk8004B7D0 *)D_8004B7D0)[arg0].unk4A;
}

void func_800188C0(s32 arg0) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_8004B7D0[i + (arg0 & 3) * 0x70 + ((u32)(arg0 & 0xFF) >> 4) * 0x1C0 + 0xA4] = D_8004BBF4[i];
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_80018928);

u8 func_80018980(s32 arg0, s32 arg1) {
    return D_8004B7D0[arg1 + arg0 * 0x1C0 + 0xA4];
}

s32 func_800189A8(void) {
    return 0;
}

void func_800189B0(void) {
}

s32 func_800189B8(s32 arg0) {
    if (*(s32 *)D_8004B7D0 & 0x800000) {
        if (*(s16 *)(D_8004B7D0 + 0x3D6) == arg0) {
            return 1;
        }
        return -1;
    }
    return 0;
}

s32 func_800189F0(s16 arg0, s32 arg1) {
    if (!(M2C_FIELD(D_8004B7D0, s32 *, 0) & 0xC00000)) {
        M2C_FIELD(D_8004B7D0, s32 *, 0) = (s32) (M2C_FIELD(D_8004B7D0, s32 *, 0) | 0x400000);
        if (M2C_FIELD(D_8004B7D0, s32 *, 0x3D8) == 0) {
            M2C_FIELD(D_8004B7D0, s16 *, 0x3D6) = arg0;
            M2C_FIELD(D_8004B7D0, s32 *, 0x3D8) = arg1;
            M2C_FIELD(D_8004B7D0, s16 *, 0x3DC) = 0;
            func_800186E0((arg0 * 0x10) & 0xF0, 0, 0, 0);
            return 1;
        }
    }
    return 0;
}

void func_80018A64(void) {
    if (M2C_FIELD(D_8004B7D0, s32 *, 0) & 0x400000) {
        M2C_FIELD(D_8004B7D0, s32 *, 0) = (s32) (M2C_FIELD(D_8004B7D0, s32 *, 0) & 0xFFBFFFFF);
        M2C_FIELD(D_8004B7D0, s32 *, 0x3D8) = 0;
        M2C_FIELD(D_8004B7D0, s16 *, 0x3D6) = 0;
        M2C_FIELD(D_8004B7D0, s16 *, 0x3DC) = 0;
    }
}

s32 func_80018AA0(s32 arg0) {
    if (*(s32 *)D_8004B7D0 & 0x400000) {
        if (*(s16 *)(D_8004B7D0 + 0x3D6) == arg0) {
            return 1;
        }
        return -1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/main", func_80018AD8);

INCLUDE_ASM("asm/nonmatchings/main", func_80018BCC);

INCLUDE_ASM("asm/nonmatchings/main", func_80018F44);

INCLUDE_ASM("asm/nonmatchings/main", func_8001902C);

INCLUDE_ASM("asm/nonmatchings/main", func_80019148);

INCLUDE_ASM("asm/nonmatchings/main", func_80019224);

void func_8001932C(s32 arg0) {
    *D_8004DC04 = arg0 & 0xFFF;
}

u16 func_8001933C(void) {
    s32 temp_v1;

    temp_v1 = (*D_8004DC04 + 1) & 0xFFF;
    *D_8004DC04 = temp_v1;
    return D_8004BC04[temp_v1];
}

INCLUDE_ASM("asm/nonmatchings/main", func_80019370);

void func_800194C4(s32 arg0, s32 arg1) {
    func_80019370(arg0, arg0 + 0x5C, arg1);
}

void func_800194E8(s32 arg0, s32 arg1, s32 arg2) {
    func_800196E4(arg0, arg1, arg2, 0);
}

INCLUDE_ASM("asm/nonmatchings/main", func_80019508);

INCLUDE_ASM("asm/nonmatchings/main", func_800195B0);

void func_8001968C(MsgWin *arg0, s32 arg1, s32 arg2) {
    if ((u32)(arg2 - 1) >= 5) {
        /* "ＥｘｔＭｅｓｓ：メッセージのワークばんごうがみたいおう" */
        func_800194C4(arg0, "\x82\x64\x82\x98\x82\x94\x82\x6C\x82\x85\x82\x93\x82\x93\x81\x46\x83\x81\x83\x62\x83\x5A\x81\x5B\x83\x57\x82\xCC\x83\x8F\x81\x5B\x83\x4E\x82\xCE\x82\xF1\x82\xB2\x82\xA4\x82\xAA\x82\xDD\x82\xBD\x82\xA2\x82\xA8\x82\xA4");
        return;
    }
    func_80019370(arg0, &arg0->work[arg2], arg1);
}

INCLUDE_ASM("asm/nonmatchings/main", func_800196E4);

INCLUDE_RODATA("asm/nonmatchings/main", D_80010234);

INCLUDE_ASM("asm/nonmatchings/main", func_800197A4);

INCLUDE_ASM("asm/nonmatchings/main", func_80019FB0);

void func_8001A180(void *arg0, s32 arg1) {
    s32 var_a1;
    u8 *temp_v1;

    var_a1 = arg1;
    if ((u32) (var_a1 - 1) >= 3U) {
        var_a1 = 1;
    }
    temp_v1 = *D_8004DE00 + (var_a1 * 0x18);
    M2C_FIELD(arg0, u8 **, 0x50) = temp_v1;
    M2C_FIELD(arg0, u8 *, 0xBE) = (u8) *temp_v1;
}

void func_8001A1B8(void *arg0, s32 arg1) {
    if (arg1 <= 0) {
        M2C_FIELD(arg0, s16 *, 0xA8) = 0;
        M2C_FIELD(arg0, s16 *, 0xAA) = 0;
        M2C_FIELD(arg0, u16 *, 0xA4) = M2C_FIELD(arg0, u16 *, 0x62);
        return;
    }
    M2C_FIELD(arg0, u16 *, 0xA4) = 0;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    M2C_FIELD(arg0, s16 *, 0xAA) = arg1;
    M2C_FIELD(arg0, s16 *, 0xA6) = 0;
}

void func_8001A1E8(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0xB0) = arg1;
    M2C_FIELD(arg0, s16 *, 0xB2) = arg2;
}

void func_8001A1F4(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0xC0) = arg1;
}

void func_8001A1FC(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0xBE) = arg1;
}

void func_8001A204(void *arg0, s16 arg1, s16 arg2) {
    if (((arg1 << 0x10) != 0) || ((arg2 << 0x10) != 0)) {
        M2C_FIELD(arg0, s8 *, 0xC2) = 1;
        M2C_FIELD(arg0, s16 *, 0xB4) = arg1;
        M2C_FIELD(arg0, s16 *, 0xB6) = arg2;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0xC2) = 0;
    M2C_FIELD(arg0, s16 *, 0xB4) = 0;
    M2C_FIELD(arg0, s16 *, 0xB6) = 0;
}

void func_8001A23C(void *arg0, s8 arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x62) == 0) {
        M2C_FIELD(arg0, s8 *, 0xC1) = 0;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0xC1) = arg1;
}

void func_8001A25C(void *arg0, u8 arg1) {
    struct {
        s32 unk0;
        s16 (*fn)(void *, s32, s32);
        s32 unk8;
        s32 unkC;
    } sp10;

    if (arg1 != 0) {
        func_8001FCC0(&sp10);
        M2C_FIELD(arg0, s16 *, 0xBC) = sp10.fn((u8 *)arg0 + 0x5C, M2C_FIELD(arg0, s32 *, 0x50), M2C_FIELD(arg0, s16 *, 0xB4));
    } else {
        M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001A2AC);

void func_8001A418(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC8) = arg1;
}

void func_8001A420(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0xD8) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0xD0) = arg1;
    M2C_FIELD(arg0, s32 *, 0xD4) = arg2;
    M2C_FIELD(arg0, s32 *, 0xCC) = 1;
}

void func_8001A43C(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0xE0) = arg1;
    M2C_FIELD(arg0, s32 *, 0xE4) = arg2;
}

void func_8001A448(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
}

void func_8001A450(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0xBF) = arg1;
}

void func_8001A458(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0xC4) = arg1;
}

u8 func_8001A460(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0xC3);
}

u8 func_8001A46C(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0xC1);
}

s32 func_8001A478(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x10) == 1;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001A48C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A6E8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A73C);

s32 func_8001A82C(void *arg0, ScriptCtx *ctx) {
    if (ctx->base[ctx->pc + 2] < 5) {
        M2C_FIELD(arg0, s32 *, 0xC) = 2;
        M2C_FIELD(arg0, s32 *, 0x10) = 1;
        if ((u8)(ctx->base[ctx->pc + 2] - 1) >= 4) {
            M2C_FIELD(arg0, s32 *, 0x14) = 0;
        } else {
            M2C_FIELD(arg0, s32 *, 0x14) = ctx->base[ctx->pc + 2];
        }
        M2C_FIELD(arg0, s32 *, 0x18) = ctx->pc + 2;
        return 0;
    }
    return 0x8003;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001A8B4);

s32 func_8001AA08(void) {
    return 0x8003;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001AA10);

s32 func_8001AB30(void *arg0, ScriptCtx *ctx) {
    if (ctx->base[ctx->pc + 2] < 0xFF) {
        M2C_FIELD(arg0, s32 *, 0xC) = 2;
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
        M2C_FIELD(arg0, s32 *, 0x14) = ctx->base[ctx->pc + 2];
        ctx->base[ctx->pc + 2] = 0xFF;
        M2C_FIELD(arg0, s16 *, 0xA8) = 0;
        return 0x8000;
    }
    return 0x8003;
}

s32 func_8001ABA4(s32 arg0, ScriptCtx *ctx) {
    if (ctx->base[ctx->pc + 2] < 6) {
        func_800196E4(arg0, &D_80048D88, -1, ctx->base[ctx->pc + 2]);
        ctx->base[ctx->pc + 2] = 6;
    }
    return 0x8003;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001AC14);

INCLUDE_ASM("asm/nonmatchings/main", func_8001AE38);

void func_8001B04C(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x64) = arg1;
    if (arg1 == 0) {
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
        M2C_FIELD(arg0, s32 *, 0x70) = 0;
    }
    M2C_FIELD(arg0, s32 *, 0x68) = 1;
}

void func_8001B068(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    M2C_FIELD(arg0, s32 *, 0x5C) = arg2;
    M2C_FIELD(arg0, s32 *, 0x68) = 1;
}

void func_8001B07C(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x60) = arg1;
    M2C_FIELD(arg0, s32 *, 0x68) = 1;
}

void func_8001B08C(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x74) = arg1;
}

void func_8001B094(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x78) = arg1;
}

void func_8001B09C(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x7C) = arg1;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001B0A4);

void func_8001B364(s16 arg0, s32 arg1, s16 arg2, s16 arg3) {
    Obj *o = func_80014504(func_8001B0A4, 0x98, 4);

    o->unk50 = arg0;
    o->unk54 = arg1;
    M2C_FIELD(o, s32 *, 0x58) = arg2;
    M2C_FIELD(o, s32 *, 0x5C) = arg3;
    M2C_FIELD(o, s32 *, 0x64) = 1;
    M2C_FIELD(o, s32 *, 0x74) = 0x20;
    M2C_FIELD(o, s32 *, 0x78) = 6;
    M2C_FIELD(o, void **, 0x80) = func_8001B04C;
    M2C_FIELD(o, void **, 0x84) = func_8001B068;
    M2C_FIELD(o, void **, 0x8C) = func_8001B08C;
    M2C_FIELD(o, void **, 0x90) = func_8001B094;
    M2C_FIELD(o, void **, 0x88) = func_8001B07C;
    M2C_FIELD(o, void **, 0x94) = func_8001B09C;
}

void func_8001B444(void *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x64);
    if (temp_a0 != 0) {
        (*(s32 (**)())&D_8004B5EC)(temp_a0);
    }
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
}
/* Warning: struct opaque is not defined (only forward-declared) */

void func_8001B48C(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 **, 0x50) = arg1;
    if (arg1[0] == 0x4E454C52) {
        M2C_FIELD(arg0, s32 *, 0x58) = 1;
        M2C_FIELD(arg0, s32 *, 0x5C) = arg1[1];
    } else {
        M2C_FIELD(arg0, s32 *, 0x58) = 0;
        M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    }
    arg1 += 2;
    M2C_FIELD(arg0, s32 **, 0x54) = arg1;
    M2C_FIELD(arg0, s32 **, 0x68) = arg1;
}

void func_8001B4CC(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x5C) > M2C_FIELD(arg0, s32 *, 0x60)) {
        if (M2C_FIELD(arg0, s32 *, 0x64) != 0) {
            (*(void (**)(s32))&D_8004B5EC)(M2C_FIELD(arg0, s32 *, 0x64));
        }
        M2C_FIELD(arg0, s32 *, 0x64) = (*(s32 (**)(s32, s32))&D_8004B5F4)(M2C_FIELD(arg0, s32 *, 0x5C), 2);
        M2C_FIELD(arg0, s32 *, 0x60) = M2C_FIELD(arg0, s32 *, 0x5C);
    }
    M2C_FIELD(arg0, s32 *, 0x6C) = M2C_FIELD(arg0, s32 *, 0x64);
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001B554);

s32 func_8001B63C(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x70) = 0x10000000;
    func_8001B48C(arg0, arg1);
    if (M2C_FIELD(arg0, s32 *, 0x58) != 0) {
        func_8001B4CC(arg0);
        func_8001B554(arg0);
        return M2C_FIELD(arg0, s32 *, 0x64);
    }
    return arg1;
}

void func_8001B698(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x70) = arg2;
    func_8001B48C(arg0, arg1);
    if (M2C_FIELD(arg0, s32 *, 0x58) != 0) {
        func_8001B4CC(arg0);
        M2C_FIELD(arg0, void (**)(void *, s32), 0x2C)(arg0, 1);
    }
}

s32 func_8001B6EC(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x58) != 0) {
        return M2C_FIELD(arg0, s32 *, 0x64);
    }
    return M2C_FIELD(arg0, s32 *, 0x50);
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001B724);

void func_8001B7B8(void) {
    Obj *temp_v0;

    temp_v0 = func_80014504((void (*)()) func_8001B724, 0x84, 0);
    M2C_FIELD(temp_v0, s32 (**)(void *, s32), 0x74) = func_8001B63C;
    M2C_FIELD(temp_v0, void (**)(void *), 0x80) = func_8001B444;
    M2C_FIELD(temp_v0, void (**)(void *, s32, s32), 0x7C) = func_8001B698;
    M2C_FIELD(temp_v0, s32 (**)(void *), 0x78) = func_8001B6EC;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001B814);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B930);

INCLUDE_ASM("asm/nonmatchings/main", func_8001BA2C);

Obj *func_8001BB88(s32 arg0) {
    Obj *temp_v0;

    temp_v0 = func_80014504((void (*)()) func_8001BA2C, 0x6C, 0);
    temp_v0->unk50 = arg0;
    ((M2C_UNK (*)(M2C_UNK)) *D_80055C48)(0x40019);
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001BBE8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001BE00);

INCLUDE_ASM("asm/nonmatchings/main", func_8001BEEC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001C050);

INCLUDE_ASM("asm/nonmatchings/main", func_8001C448);

void func_8001C4B4(s32 arg0) {
    func_80014504(func_8001C448, 0x60, 0)->unk50 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001C4EC);

void func_8001C7D8(u8 *arg0) {
    switch (*(s32 *)(arg0 + 0xC)) {
    case 0:
    default:
        *(s32 *)(arg0 + 0x68) = 0;
        if (*(s32 *)(arg0 + 0xB8) == 0) {
            *(s32 *)(arg0 + 0x60) = 0;
        } else {
            *(s32 *)(arg0 + 0x60) = 0x1000;
        }
        *(s32 *)(arg0 + 0x90) = 0;
        *(s32 *)(arg0 + 0x88) = *(s16 *)(arg0 + 0x54);
        *(s32 *)(arg0 + 0x8C) = *(s16 *)(arg0 + 0x56);
        (*(void (**)(void *))(arg0 + 0x38))(arg0);
        break;
    case 1:
        func_8001C4EC(arg0);
        break;
    case 2:
    case 3:
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001C85C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001C948);

INCLUDE_ASM("asm/nonmatchings/main", func_8001CAB0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001CE44);

void func_8001D1E4(void) {
    struct {
        u8 pad0[0x24];
        void (*fn24)(s32, s32);
        s32 unk28;
        void (*fn2C)(s32);
        s32 unk30;
        s32 unk34;
    } obj;
    u8 *sys;

    func_8001FFA8(&obj);
    obj.fn24(0x140, 0);
    sys = (u8 *)D_80044B38;
    obj.fn2C((*(s32 (**)(s32))(sys + 0x424))(0x2870000));
    (*(void (**)(s32))(sys + 0x418))(0x287);
    (*(void (**)(s32))(sys + 0x40C))(0x286);
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001D264);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D3F4);

void func_8001D4E0(void) {
    VSyncCallback(func_8001D3F4);
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001D504);

s32 func_8001D6E4(void) {
    return D_8004DE18[0];
}

s32 func_8001D6F4(void) {
    return D_8004DE20[0];
}

s32 func_8001D704(void) {
    return D_8004DE28[0];
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001D714);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D7C4);

s32 func_8001D844(void) {
    return D_8004DE30[0];
}

void func_8001D854(s32 arg0) {
    *D_8004DE30 = arg0;
}

void func_8001D860(void) {
    u8 *p = D_8004DE10;

    if (*(s32 *)(p + 0x24) != 0) {
        (*(void (**)(s32))&D_8004B5EC)(*(s32 *)(p + 0x24));
    }
    if (*(s32 *)(p + 0x28) != 0) {
        (*(void (**)(s32))&D_8004B5EC)(*(s32 *)(p + 0x28));
    }
    *(s32 *)(p + 0x24) = 0;
    *(s32 *)(p + 0x28) = 0;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001D8CC);

void func_8001DA00(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    SetDefDispEnv(D_8004DE48, arg0, arg1, arg2, arg3);
    SetDefDispEnv(D_8004DE48 + 0x14, arg0, arg1, arg2, arg3);
}

s32 func_8001DA84(s32 arg0) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (((Unk8004DE10 *)D_8004DE10)->used[i] != 0 &&
            ((Unk8004DE10 *)D_8004DE10)->id[i] == arg0) {
            return ((Unk8004DE10 *)D_8004DE10)->used[i];
        }
    }
    return 0;
}

s32 func_8001DAD0(s32 arg0) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (arg0 != 0) {
            if (((Unk8004DE10 *)D_8004DE10)->used[i] != 0 &&
                ((Unk8004DE10 *)D_8004DE10)->id[i] == arg0) {
                return i;
            }
        } else if (((Unk8004DE10 *)D_8004DE10)->used[i] == 0) {
            return i;
        }
    }
    return -1;
}

void func_8001DB34(s32 i) {
    for (; i < 29; i++) {
        ((Unk8004DE10 *)D_8004DE10)->used[i] = ((Unk8004DE10 *)D_8004DE10)->used[i + 1];
        ((Unk8004DE10 *)D_8004DE10)->id[i] = ((Unk8004DE10 *)D_8004DE10)->id[i + 1];
    }
}

void func_8001DB84(s32 slot, s32 used, s32 id) {
    s32 i;

    for (i = 29; i != slot; i--) {
        ((Unk8004DE10 *)D_8004DE10)->used[i] = ((Unk8004DE10 *)D_8004DE10)->used[i - 1];
        ((Unk8004DE10 *)D_8004DE10)->id[i] = ((Unk8004DE10 *)D_8004DE10)->id[i - 1];
    }
    ((Unk8004DE10 *)D_8004DE10)->used[slot] = used;
    ((Unk8004DE10 *)D_8004DE10)->id[slot] = id;
}

s32 func_8001DBE0(s16 *rect, s32 arg1, s32 id) {
    s32 env[0x5C / 4];
    s32 i = func_8001DAD0(0);

    if (i != -1) {
        SetDefDrawEnv(env, rect[0], rect[1], rect[2], rect[3]);
        ((Unk8004DE10 *)D_8004DE10)->id[i] = id;
        return ((Unk8004DE10 *)D_8004DE10)->used[i] = func_8001E5BC(env, arg1);
    }
    return 0;
}

s32 func_8001DC7C(s32 id) {
    s32 i = func_8001DAD0(id);
    s32 *obj;

    if (i != -1) {
        obj = (s32 *)((Unk8004DE10 *)D_8004DE10)->used[i];
        (*(void (**)(void *))((u8 *)obj + 0x168))(obj);
        (*(void (**)(s32))&D_8004B5EC)(((Unk8004DE10 *)D_8004DE10)->used[i]);
        func_8001DB34(i);
        return 1;
    }
    return 0;
}

void func_8001DD04(s32 arg0, s32 arg1, s32 arg2) {
    s32 i = func_8001DAD0(arg0);
    s32 j = func_8001DAD0(arg1);
    s32 n;
    s32 used;
    s32 id;

    if (i != -1 && j != -1) {
        n = j + arg2;
        used = ((Unk8004DE10 *)D_8004DE10)->used[i];
        id = ((Unk8004DE10 *)D_8004DE10)->id[i];
        if (n <= 0) {
            n = 0;
        }
        func_8001DB34(i);
        func_8001DB84(n, used, id);
    }
}

void func_8001DDA0(Unk8001DDA0 *arg0) {
    ClearOTagR(arg0->ot[D_8004DE44[0]], arg0->otLen);
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001DDDC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DE68);

u32 *func_8001DFA8(Unk8001DDA0 *arg0, s32 arg1) {
    return (u32 *)arg0->ot[D_8004DE44[0]] + arg1;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001DFCC);

s32 func_8001DFFC(Unk8001DDA0 *arg0) {
    return arg0->ot[D_8004DE44[0]];
}

s32 func_8001E01C(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x68);
}

void func_8001E028(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    M2C_FIELD(arg0, s8 *, 0x19) = arg1;
    M2C_FIELD(arg0, s8 *, 0x1B) = arg3;
    M2C_FIELD(arg0, s8 *, 0x1A) = arg2;
    if ((arg3 | (arg1 | arg2)) & 0xFF) {
        M2C_FIELD(arg0, s8 *, 0x18) = 1;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x18) = 0;
}

void func_8001E058(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x6C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x6E) = arg2;
}

void func_8001E064(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0x70) >> 8);
    M2C_FIELD(arg1, s32 *, 4) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0x74) >> 8);
}

void func_8001E088(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x70) = arg1;
    M2C_FIELD(arg0, s32 *, 0x74) = arg2;
}

void func_8001E094(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) + arg1);
    M2C_FIELD(arg0, s32 *, 0x74) = (s32) (M2C_FIELD(arg0, s32 *, 0x74) + arg2);
}

void func_8001E0B0(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0) = arg1;
    M2C_FIELD(arg0, s16 *, 2) = arg2;
}

void func_8001E0BC(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 4) = arg1;
    M2C_FIELD(arg0, s16 *, 6) = arg2;
}

void func_8001E0C8(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = (s16) ((M2C_FIELD(arg0, u16 *, 0) - M2C_FIELD(arg0, u16 *, 0x6C)) + ((s32) M2C_FIELD(arg0, s32 *, 0x70) >> 8));
    M2C_FIELD(arg1, s16 *, 2) = (s16) ((M2C_FIELD(arg0, u16 *, 2) - M2C_FIELD(arg0, u16 *, 0x6E)) + ((s32) M2C_FIELD(arg0, s32 *, 0x74) >> 8));
    M2C_FIELD(arg1, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 4);
    M2C_FIELD(arg1, u16 *, 6) = (u16) M2C_FIELD(arg0, u16 *, 6);
}

void func_8001E118(u8 *arg0) {
    u8 *heap;

    DrawSync(0);
    heap = (u8 *)&D_8004B5DC;
    (*(void (**)(s32))(heap + 0x10))(*(s32 *)(arg0 + 0x5C));
    (*(void (**)(s32))(heap + 0x10))(*(s32 *)(arg0 + 0x60));
    if (*(s32 *)(arg0 + 0x78) != 0) {
        (*(void (**)(s32))(heap + 0x10))(*(s32 *)(arg0 + 0x80));
    }
}

void func_8001E19C(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x80), s32 *, 0) = 0x7FFFFFFF;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x80), s32 *, 4) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x80), s32 *, 8) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x80), s32 *, 0xC) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x80), s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x7C) = 1;
}

void func_8001E1E8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x80) = (*(s32 (**)())&D_8004B5F4)(arg1 * 0x14, 2);
    M2C_FIELD(arg0, s32 *, 0x78) = arg1;
    func_8001E19C(arg0);
}
/* Warning: struct opaque is not defined (only forward-declared) */

INCLUDE_ASM("asm/nonmatchings/main", func_8001E240);

void func_8001E324(void *arg0, s32 arg1, s32 arg2) {
    Unk8001E324 *n;

    if (M2C_FIELD(arg0, s32 *, 0x7C) < M2C_FIELD(arg0, s32 *, 0x78)) {
        n = &M2C_FIELD(arg0, Unk8001E324 **, 0x80)[M2C_FIELD(arg0, s32 *, 0x7C)];
        n->unk8 = arg1;
        n->unkC = arg2;
        n->unk0 = 0;
        n->unk4 = 0;
        n->next = NULL;
        if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
            n[-1].next = n;
        }
        M2C_FIELD(arg0, s32 *, 0x7C)++;
    }
}

void func_8001E38C(void *arg0) {
    M2C_UNK (*temp_v0)(s32, void *, s32);
    void *var_s0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        var_s0 = M2C_FIELD(arg0, void **, 0x80);
        do {
            temp_v0 = M2C_FIELD(var_s0, M2C_UNK (**)(s32, void *, s32), 8);
            if (temp_v0 != NULL) {
                temp_v0(M2C_FIELD(var_s0, s32 *, 0xC), arg0, M2C_FIELD(var_s0, s32 *, 4));
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0x10);
        } while (var_s0 != NULL);
        func_8001E19C(arg0);
    }
}

void func_8001E404(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0x84) = arg1;
    if (arg1 != 0) {
        *(s32 *)(arg0 + 0x88) = arg2;
        *(Block32 *)(arg0 + (D_8004DE44[0] << 5) + 0x8C) = D_80081358[0];
    }
}

void func_8001E470(u8 *arg0) {
    func_8002998C(*(s32 *)(arg0 + 0x88));
    D_80081358[0] = *(Block32 *)(arg0 + (D_8004DE44[0] << 5) + 0x8C);
}

void func_8001E4F4(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0xCC) = arg1;
    if (arg1 != 0) {
        *(Block32 *)(arg0 + (D_8004DE44[0] << 5) + 0xD0) = D_800812F8[0];
    }
}

void func_8001E55C(u8 *arg0) {
    D_800812F8[0] = *(Block32 *)(arg0 + (D_8004DE44[0] << 5) + 0xD0);
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001E5BC);

void func_8001E7E0(s32 arg0)
{
    D_8005CD08 = arg0;
}

/* blocos de 0x62C bytes em bancos de 64 */
void func_8001E7EC(s32 n) {
    s32 idx;
    s32 bank;

    if (n > 0) {
        idx = n - 1;
        bank = (*(s32 (**)(s32))&D_80044F4C)(*(D_8004DFB8 + (idx >> 6)));
        idx &= 0x3F;
        *(s32 *)D_8005CD08 = bank + idx * 0x62C;
    } else {
        *(s32 *)D_8005CD08 = (*(s32 (**)(s32))&D_80044F4C)(D_8004DFB8[0]);
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001E890);

void func_8001E938(s32 arg0, s32 arg1) {
    void *obj;

    obj = ((void *(*)(s32))D_8004DF8C[0])(arg0);
    M2C_FIELD(D_8005CD08, void **, 0x24) = obj;
    M2C_FIELD(D_8005CD08, s32 *, 0x28) = M2C_FIELD(obj, s32 (**)(void *, s32), 0x138)(obj, arg1);
}

void func_8001E98C(s32 arg0, s32 arg1) {
    M2C_FIELD(D_8005CD08, s32 *, 4) = arg0;
    M2C_FIELD(D_8005CD08, s32 *, 8) = arg1;
}

void func_8001E9A0(s32 arg0, s32 arg1) {
    M2C_FIELD(D_8005CD08, s32 *, 0xC) = arg0;
    M2C_FIELD(D_8005CD08, s32 *, 0x10) = arg1;
}

void func_8001E9B4(s32 arg0, s32 arg1) {
    M2C_FIELD(D_8005CD08, s32 *, 0x14) = arg0;
    M2C_FIELD(D_8005CD08, s32 *, 0x18) = arg1;
}

void func_8001E9C8(s32 arg0) {
    M2C_FIELD(D_8005CD08, s32 *, 0x1C) = arg0;
}

void func_8001E9D4(s32 arg0) {
    M2C_FIELD(D_8005CD08, s32 *, 0x20) = arg0;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001E9E0);

s32 func_8001EBCC(void) {
    return D_8004DFCC[(*(u8 **)D_8005CD08)[3]];
}

void func_8001EBF8(void *arg0) {
    (*(s32 (**)())&D_8004B600)(arg0, 0x54);
    M2C_FIELD(arg0, s32 (**)(s32), 0x2C) = func_8001E7EC;
    M2C_FIELD(arg0, s32 (**)(), 0x30) = func_8001E890;
    M2C_FIELD(arg0, void (**)(s32, s32), 0x38) = func_8001E938;
    M2C_FIELD(arg0, void (**)(s32, s32), 0x3C) = func_8001E98C;
    M2C_FIELD(arg0, void (**)(s32, s32), 0x40) = func_8001E9A0;
    M2C_FIELD(arg0, void (**)(s32, s32), 0x44) = func_8001E9B4;
    M2C_FIELD(arg0, void (**)(s32), 0x48) = func_8001E9C8;
    M2C_FIELD(arg0, void (**)(s32), 0x4C) = func_8001E9D4;
    M2C_FIELD(arg0, s32 (**)(s32), 0x34) = func_8001E9E0;
    M2C_FIELD(arg0, s32 (**)(), 0x50) = func_8001EBCC;
    func_8001E7E0((s32) arg0);
    M2C_FIELD(arg0, s32 *, 0x1C) = 8;
}
/* Warning: struct opaque is not defined (only forward-declared) */

void func_8001ECB0(s32 arg0) {
    D_8005CD10 = arg0;
}

void func_8001ECBC(s32 arg0, s32 arg1) {
    M2C_FIELD(D_8005CD10, s32 *, 8) = arg0;
    M2C_FIELD(D_8005CD10, s32 *, 0xC) = arg1;
    M2C_FIELD(D_8005CD10, s32 *, 0x10) = arg0;
    M2C_FIELD(D_8005CD10, s32 *, 0x14) = arg1;
}

void func_8001ECD8(s32 arg0, s32 arg1) {
    M2C_FIELD(D_8005CD10, s32 *, 0x18) = arg0;
    M2C_FIELD(D_8005CD10, s32 *, 0x1C) = (s32) (arg1 - 0x100);
}

void func_8001ECEC(s32 arg0) {
    M2C_FIELD(D_8005CD10, s32 *, 0x20) = arg0;
}

void func_8001ECF8(void *arg0, s32 arg1) {
    M2C_FIELD(D_8005CD10, void **, 0) = arg0;
    M2C_FIELD(D_8005CD10, s32 *, 4) = M2C_FIELD(arg0, s32 (**)(void *, s32), 0x138)(arg0, arg1);
}

void func_8001ED34(s32 arg0, s32 arg1) {
    func_8001ECF8((void *)((s32 (*)(s32))D_8004DF8C[0])(arg0), arg1);
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001ED6C);

void func_8001F5D0(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(D_8005CD10, s32 *, 0x38) = arg0;
    M2C_FIELD(D_8005CD10, s32 *, 0x3C) = arg1;
    M2C_FIELD(D_8005CD10, s32 *, 0x40) = arg2;
    M2C_FIELD(D_8005CD10, s32 *, 0x2C) = 1;
}

void func_8001F5EC(s16 arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(D_8005CD10, s16 *, 0x48) = arg0;
    M2C_FIELD(D_8005CD10, s16 *, 0x4A) = arg1;
    M2C_FIELD(D_8005CD10, s16 *, 0x4C) = arg2;
    M2C_FIELD(D_8005CD10, s32 *, 0x2C) = 1;
}

void func_8001F608(s32 arg0, s32 arg1) {
    M2C_FIELD(D_8005CD10, s32 *, 0x30) = arg0;
    M2C_FIELD(D_8005CD10, s32 *, 0x34) = arg1;
}

void func_8001F61C(s32 arg0) {
    M2C_FIELD(D_8005CD10, s32 *, 0x24) = arg0;
}

void func_8001F628(Bytes4 *arg0) {
    *(Bytes4 *)((u8 *)D_8005CD10 + 0x28) = *arg0;
}

void func_8001F648(void *arg0) {
    (*(s32 (**)())&D_8004B600)(arg0, 0xA0);
    M2C_FIELD(arg0, s32 *, 0x38) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x40) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x24) = 1;
    M2C_FIELD(arg0, u8 *, 0x2A) = 0x80;
    M2C_FIELD(arg0, u8 *, 0x29) = 0x80;
    M2C_FIELD(arg0, u8 *, 0x28) = 0x80;
    M2C_FIELD(arg0, void (**)(s32, s32), 0x74) = func_8001ECBC;
    M2C_FIELD(arg0, s32 (**)(s32, s32, s32, s32), 0x84) = func_8001ED6C;
    M2C_FIELD(arg0, void (**)(s32, s32), 0x78) = func_8001ECD8;
    M2C_FIELD(arg0, void (**)(s32, s32), 0x7C) = func_8001ED34;
    M2C_FIELD(arg0, void (**)(void *, s32), 0x80) = func_8001ECF8;
    M2C_FIELD(arg0, void (**)(s32), 0x70) = func_8001ECB0;
    M2C_FIELD(arg0, void (**)(s32), 0x88) = func_8001ECEC;
    M2C_FIELD(arg0, void (**)(s32, s32, s32), 0x8C) = func_8001F5D0;
    M2C_FIELD(arg0, void (**)(s16, s16, s16), 0x90) = func_8001F5EC;
    M2C_FIELD(arg0, void (**)(s32, s32), 0x94) = func_8001F608;
    M2C_FIELD(arg0, void (**)(s32), 0x98) = func_8001F61C;
    M2C_FIELD(arg0, void (**)(Bytes4 *), 0x9C) = func_8001F628;
    func_8001ECB0((s32) arg0);
}
/* Warning: struct opaque is not defined (only forward-declared) */

void func_8001F738(s32 arg0) {
    D_8005CD18 = arg0;
}

/* tabela de offsets relativos: [0] = quantidade, [1..] = offsets */
s32 func_8001F744(s32 *tbl, s32 i) {
    s32 n = tbl[0];

    if (i < 0 || n < i) {
        return 0;
    }
    return (s32)tbl + tbl[i + 1];
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001F770);

INCLUDE_ASM("asm/nonmatchings/main", func_8001FA20);

void func_8001FCC0(void **arg0) {
    (*(void (**)(void *, s32))&D_8004B600)(arg0, 12);
    arg0[0] = func_8001F744;
    arg0[1] = func_8001F770;
    arg0[2] = func_8001FA20;
    func_8001F738(arg0);
}

void func_8001FD1C(s32 arg0) {
    D_8005CD20 = arg0;
}

void func_8001FD28(s32 arg0, s32 arg1) {
    M2C_FIELD(D_8005CD20, s32 *, 8) = arg0;
    M2C_FIELD(D_8005CD20, s32 *, 0xC) = arg1;
}

void func_8001FD3C(s32 arg0, s32 arg1) {
    M2C_FIELD(D_8005CD20, s32 *, 0x10) = arg0;
    M2C_FIELD(D_8005CD20, s32 *, 0x14) = arg1;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001FD50);

INCLUDE_ASM("asm/nonmatchings/main", func_8001FE38);

void func_8001FF9C(s32 arg0) {
    M2C_FIELD(D_8005CD20, s32 *, 0x18) = arg0;
}

void func_8001FFA8(void *arg0) {
    (*(s32 (**)())&D_8004B600)(arg0, 0x34);
    M2C_FIELD(arg0, s32 (**)(s32), 0x20) = func_8001FD50;
    M2C_FIELD(arg0, void (**)(s32, s32), 0x28) = func_8001FD3C;
    M2C_FIELD(arg0, void (**)(s32, s32), 0x24) = func_8001FD28;
    M2C_FIELD(arg0, void (**)(s32), 0x1C) = func_8001FD1C;
    M2C_FIELD(arg0, s32 (**)(s32), 0x2C) = func_8001FE38;
    M2C_FIELD(arg0, void (**)(s32), 0x30) = func_8001FF9C;
    func_8001FD1C((s32) arg0);
    M2C_FIELD(arg0, s32 *, 0x18) = 0xA800;
}
/* Warning: struct opaque is not defined (only forward-declared) */

s32 func_80020030(s32 arg0) {
    s32 i;
    u8 *p;

    for (i = 0, p = D_800519EC; i < 3; i++, p += 0x18) {
        if (*(s32 *)(p + 0x4200) == arg0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8002006C);

INCLUDE_ASM("asm/nonmatchings/main", func_80020204);

INCLUDE_ASM("asm/nonmatchings/main", func_800202D4);

INCLUDE_ASM("asm/nonmatchings/main", func_8002037C);

s32 func_8002043C(void) {
    return (s16) *D_80055C40 != 0;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8002044C);

void func_80020574(s32 id) {
    u8 *p = D_800519EC;

    if (*(s32 *)(p + 0x4218) != id && *(s32 *)(p + 0x4230) != id) {
        if (*(s32 *)(p + 0x424C) == 1) {
            func_8002044C(2, id);
            *(s32 *)(p + 0x424C) = 2;
        } else {
            func_8002044C(1, id);
            *(s32 *)(p + 0x424C) = 1;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_800205F0);

s16 func_8002090C(s32 arg0, s16 arg1, s16 arg2) {
    return SsUtKeyOn(((Unk800519EC *)D_800519EC)->unk4204[arg0].unk0, arg1, 0, arg2, 0, 0x7F, 0x7F);
}

/* som: id empacotado -> SsUtKeyOff */
void func_8002096C(s32 id, s16 voice) {
    s32 ch;
    s32 prog = (id >> 11) & 0x7F;
    s32 tone = (id >> 7) & 0xF;
    s32 note = id & 0x7F;

    ch = func_80020030((id >> 18) & 0x7F);

    if (voice != -1 && ch != -1) {
        SsUtKeyOff(voice, ((Unk800519EC *)D_800519EC)->unk4204[ch].unk0, prog, tone, note);
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_80020A10);

INCLUDE_ASM("asm/nonmatchings/main", func_80020B58);

void func_80020C38(void) {
    func_80014504(func_80020B58, 0x50, 4);
}

INCLUDE_ASM("asm/nonmatchings/main", func_80020C64);

void func_80020D10(s32 arg0) {
    s32 *s = (s32 *)&D_80055D28;
    void *src;

    if (s[1] != arg0) {
        s[1] = arg0;
        src = (*(void *(**)(s32))&D_80044F4C)(arg0);
        memcpy(D_800100C8, src, (*(s32 (**)(s32))&D_80048744)(arg0) << 11);
    }
}

INCLUDE_RODATA("asm/nonmatchings/main", jtbl_800102B8);
