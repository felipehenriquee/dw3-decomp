#include "FIELDSTG.h"
#include "m2c.h"
#include "FIELDSTG_auto.h"
#include "FIELDSTG_data.h"

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80083784);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800837EC);

u8 *func_80083CD8(void) {
    return func_800143DC(func_80083784, 80, 0, 813);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80083D08);

void func_80084124(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        switch (arg1) {                             /* irregular */
        case 0x348:
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
            M2C_FIELD(arg0, s16 *, 0x58) = 0;
            return;
        case 0x349:
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
            M2C_FIELD(arg0, s16 *, 0x58) = 1;
            break;
        }
    }
}

/* cria o objeto; 0x58 = flag 0x1C3D ligada */
u8 *func_80084198(s32 link) {
    u8 *o = func_800143DC(func_80083D08, 0x6C, 0, link);

    if ((*(s32 (**)(s32, s32))((u8 *)&D_80048ABC + 0x10))(0x1C3D, 1) != 0) {
        *(s16 *)(o + 0x58) = 1;
    } else {
        *(s16 *)(o + 0x58) = 0;
    }
    return o;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084200);

void func_80084804(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0;
}

void func_80084834(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 1;
}

void func_80084868(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 2;
}

void func_8008489C(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 3;
}

void func_800848D0(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 4;
}

void func_80084904(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 5;
}

void func_80084938(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 6;
}

void func_8008496C(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 7;
}

void func_800849A0(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 8;
}

void func_800849D4(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 9;
}

void func_80084A08(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0xA;
}

void func_80084A3C(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0xB;
}

void func_80084A70(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0xC;
}

void func_80084AA4(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0xD;
}

void func_80084AD8(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0xE;
}

void func_80084B0C(void) {
    M2C_FIELD(func_80014504(func_80084200, 0x68, 0x14), s32 *, 0x50) = 0xF;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084B40);

void *func_80084D30(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80084B40, 0x58, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_80099838)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084D8C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084DD0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084ECC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800853F8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085590);

void func_80085AC4(s32 arg0) {
    M2C_FIELD(func_80014504(func_80085590, 0x6C, 0), s32 *, 0x50) = arg0;
}

/* animacao sem laco: no fim (0xFF) para e retorna 0xFF */
s16 func_80085AFC(s16 *st, s16 *tbl, s32 depth) {
    s16 *e = tbl + st[2] * 2;
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        st[3] -= dt;
    }
    if (st[3] <= 0) {
        st[2]++;
        e += 2;
        st[3] += e[1];
        if (e[0] == 0xFF) {
            return 0xFF;
        }
        func_80085AFC(st, tbl, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085BD4);

void func_80085E0C(s32 arg0, s32 arg1, s16 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085BD4, 0x7C, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg1;
    M2C_FIELD(temp_v0, s16 *, 0x58) = arg2;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085E64);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085ED4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086060);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086284);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800862FC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086770);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800869C8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086C78);

u8 *func_80086C9C(s32 a) {
    u8 *o = func_800143DC(func_800869C8, 0x134, 0x7C, 4);

    *(s32 *)(o + 0x64) = a;
    *(void **)(o + 0x130) = func_80086C78;
    return o;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086CE4);

void func_80086D6C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x50) = ((s32 (*)()) D_8004DF98)();
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086D9C);

s32 func_80086E24(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x6C);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086E30);

void func_800870DC(void *arg0, s32 arg1, void *arg2) {
    M2C_FIELD(arg0, s32 *, 0x228) = arg1;
    M2C_FIELD(arg0, void **, 0x22C) = arg2;
    M2C_FIELD(arg2, M2C_UNK (**)(void *, s32, M2C_UNK), 0x7C)(arg2, M2C_FIELD(arg0, s32 *, 0x68), 0x2800);
    M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x2C)(arg0, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087130);

void func_800872C0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x70) = -1;
}

s32 func_800872CC(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x70);
}

s32 func_800872D8(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x58);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800872E4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800873D8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800874D0);

Obj *func_80087580(void) {
    return func_80014504(func_800874D0, 0x50, 0xC);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800875AC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087704);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087854);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087974);

u8 *func_80087D68(s32 a) {
    u8 *o = func_800143DC(func_80087974, 0x1C0, 8, 9);

    *(s32 *)(o + 4) = a;
    D_80099DD4[0] = 1;
    return o;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087DB0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087E7C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087F84);

u8 *func_80088144(s32 arg0, s32 arg1, s32 arg2) {
    u8 *o = func_800143DC(func_80087F84, 108, 0, arg2);

    *(s32 *)(o + 0x4) = arg0;
    *(s32 *)(o + 0x8) = arg1;
    return o;
}

s32 func_80088190(s32 arg0) {
    return func_80088144(0, 0, arg0);
}

void func_800881B8(void *arg0, s32 arg1, M2C_UNK arg2) {
    if (arg0 != NULL) {
        switch (arg1) {                             /* irregular */
        case 0x325:
            M2C_FIELD(arg0, s32 *, 8) = 0;
            break;
        case 0x327:
            M2C_FIELD(arg0, s32 *, 8) = 1;
            break;
        case 0x326:
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
            break;
        }
        if ((arg1 == 0x325) || (arg1 == 0x327)) {
            M2C_FIELD(arg0, s32 *, 0x50) = ((s32 (*)(M2C_UNK, M2C_UNK, M2C_UNK)) D_8004B7BC)(5, arg2, -1);
        }
    }
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088288);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008836C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800885D4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088888);

void func_80088A4C(s32 arg0) {
    M2C_FIELD(func_80014504(func_80088888, 0x68, 8), s32 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088A84);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088B84);

void *func_80088CA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80088B84, 0x64, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg3;
    M2C_FIELD(temp_v0, s32 *, 0x60) = ((s32 (*)(s32)) *D_80044F5C)(*D_80099DC8);
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088D38);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088EEC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089038);

void func_80089490(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80089038, 0x58, 4);
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800894D8);

void func_80089548(s32 arg0) {
    D_8009B8FC = arg0;
    D_8009B8F8 = D_80099D90;
    func_800894D8();
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008957C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089610);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089700);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089B28);

void func_80089BA4(s32 arg0) {
    M2C_FIELD(func_80014504(func_80089B28, 0x54, 0), s32 *, 8) = arg0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089BDC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089F24);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089F7C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008A5E4);

s32 func_8008A9B0(void) {
    u8 *d = D_80048D34;

    if ((*(s32 (**)(void))(d + 0x2704))() == 0x22D) {
        return 1;
    }
    return (*(s32 (**)(void))(d + 0x2704))() == 0x2DE;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008AA10);

u8 *func_8008B6A4(void) {
    return func_800143DC(func_8008AA10, 128, 124, 7);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008B6D4);

s32 func_8008B770(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_8008B6D4(arg0, arg1, arg2, arg3, /* extra? */ arg4, /* extra? */ 0);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008B798);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008BF38);

void func_8008BFA4(s32 arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(((void *(*)(M2C_UNK, M2C_UNK, M2C_UNK)) D_8004B7BC)(7, -1, -1), void **, 0x24);
    M2C_FIELD(temp_s0, s32 *, 0xC) = func_800853F8((s16) D_800978D8[arg0]);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C000);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C078);

s32 func_8008C0F0(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = rsin(arg0 >> 2) * arg1;
    if (var_v0 < 0) {
        var_v0 += 0xFFF;
    }
    return var_v0 >> 0xC;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C130);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C610);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C6B8);

Obj *func_8008C8B4(Pair32x2 v) {
    Obj *o = func_80014504(func_8008C6B8, 0x6C, 0);

    *(Pair32 *)((u8 *)o + 0x5C) = v.a;
    *(Pair32 *)((u8 *)o + 0x64) = v.b;
    return o;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C910);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C98C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008CCC8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008CE40);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008CF1C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008CFD4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D068);

void func_8008D244(s32 arg0) {
    M2C_FIELD(func_80014504(func_8008D068, 0x64, 0), s32 *, 4) = arg0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D27C);

Obj *func_8008D744(Pair32 p) {
    Obj *o = func_80014504(func_8008D27C, 0x68, 0);

    *(Pair32 *)((u8 *)o + 0x50) = p;
    return o;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D788);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D998);

u8 *func_8008DC58(void) {
    u8 *o = func_800143DC(func_8008D998, 144, 0, 16);

    *(s16 *)(o + 0x64) = -1;
    return o;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008DC90);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008DD40);

void func_8008DDC8(s32 arg0) {
    void *temp_v0;

    temp_v0 = ((void *(*)(M2C_UNK, M2C_UNK, M2C_UNK)) D_8004B7BC)(0x10, -1, -1);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x5C) = arg0;
    }
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008DE0C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008DFEC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008E13C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008E210);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008E2CC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008E45C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008E8AC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008EA44);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008EAE8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008ED2C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008EEF0);

void func_8008EFD0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s32 *, 0xEC) = 1;
    M2C_FIELD(arg0, s32 *, 0xF0) = arg1;
    M2C_FIELD(arg0, s32 *, 0xF4) = arg2;
    M2C_FIELD(arg0, s32 *, 0xF8) = arg3;
}

s32 func_8008EFE8(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xEC);
}

void func_8008EFF4(void *arg0) {
    M2C_FIELD(arg0, s32 (**)(s32), 0x108) = func_8008EEF0;
}

void func_8008F004(void *arg0) {
    u32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u32 *, 8);
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, s32 (**)(s32), 0x108) = func_8008E8AC;
        M2C_FIELD(arg0, s32 *, 0xBC) = 0;
        return;
    case 1:
        M2C_FIELD(arg0, s32 (**)(s32), 0x108) = NULL;
        return;
    case 2:
    case 4:
    case 8:
        M2C_FIELD(arg0, s32 (**)(s32), 0x108) = func_8008EAE8;
        /* fallthrough */
    default:
        return;
    }
}

void func_8008F064(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x108) = 0;
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 5);
    M2C_FIELD(arg0, s32 *, 0x60) = arg1;
}

void func_8008F0A4(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x10) != 0x4F) {
        M2C_FIELD(arg0, s32 *, 0x108) = 0;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 0x4F);
        M2C_FIELD(arg0, s32 *, 0x60) = arg1;
    }
}

void func_8008F0F0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x10) == 0x4F) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 0x50);
    }
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F128);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F1D4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F280);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F304);

void func_8008F3E4(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x108) = 0;
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    *D_80099DD8 = 1;
    func_8008C078(arg2, (s32) (arg0 + 0x58), arg1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F44C);

void func_8008F4B4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xA0) = arg1;
    M2C_FIELD(arg0, s32 *, 0xCC) = 0;
    M2C_FIELD(arg0, s32 *, 0xD0) = 0;
    M2C_FIELD(arg0, s32 *, 0xE8) = 0;
}

void func_8008F4C8(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0xEC) = 0;
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 0);
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
    func_8008F4B4(arg0, arg1);
}

s32 func_8008F520(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xE8);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F52C);

void func_8008F9B8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x60) = arg1;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F9C0);

void func_8008FD60(void *arg0) {
    M2C_FIELD(arg0, s32 (**)(s32), 0x108) = func_8008E8AC;
    M2C_FIELD(arg0, s32 *, 0x90) = 0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008FD74);

void func_8008FE68(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 8) == 0) {
        if (!(M2C_FIELD(arg0, s32 *, 0x18) & 0xF)) {
            ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x800458BD);
        }
        M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) + 1);
    }
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008FED0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80090E70);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80090EF0);

void func_80090F70(void *arg0, void *arg1) {
    void *temp_a2;

    temp_a2 = (M2C_FIELD(arg0, s32 *, 0x60) * 8) + D_80097CCC;
    M2C_FIELD(arg1, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0x58) + M2C_FIELD(temp_a2, s32 *, 0));
    M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 0x5C) + M2C_FIELD(temp_a2, s32 *, 4));
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80090FB0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8009116C);

extern struct opaque D_80048ABC;
void func_800915A0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x707E, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B19, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x400, 1);
}

s32 func_80091600(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x400, 1);
}

extern struct opaque D_80048ABC;
void func_8009162C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x707E, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B1F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x401, 1);
}

s32 func_8009168C(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x401, 1);
}

extern struct opaque D_80048ABC;
void func_800916B8(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x707F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B1A, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x402, 1);
}

s32 func_80091718(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x402, 1);
}

extern struct opaque D_80048ABC;
void func_80091744(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x707F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B20, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x403, 1);
}

s32 func_800917A4(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x403, 1);
}

extern struct opaque D_80048ABC;
void func_800917D0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7080, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8489, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x404, 1);
}

s32 func_80091830(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x404, 1);
}

extern struct opaque D_80048ABC;
void func_8009185C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7080, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8495, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x405, 1);
}

s32 func_800918BC(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x405, 1);
}

extern struct opaque D_80048ABC;
void func_800918E8(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7081, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x847C, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x406, 1);
}

s32 func_80091948(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x406, 1);
}

extern struct opaque D_80048ABC;
void func_80091974(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7081, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8462, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x407, 1);
}

s32 func_800919D4(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x407, 1);
}

extern struct opaque D_80048ABC;
void func_80091A00(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7082, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8ADE, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x408, 1);
}

s32 func_80091A60(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x408, 1);
}

extern struct opaque D_80048ABC;
void func_80091A8C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7082, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8AE8, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x409, 1);
}

s32 func_80091AEC(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x409, 1);
}

extern struct opaque D_80048ABC;
void func_80091B18(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7083, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8AF4, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40A, 1);
}

s32 func_80091B78(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40A, 1);
}

extern struct opaque D_80048ABC;
void func_80091BA4(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7083, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8AF3, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40B, 1);
}

s32 func_80091C04(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40B, 1);
}

extern struct opaque D_80048ABC;
void func_80091C30(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7084, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B01, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40C, 1);
}

s32 func_80091C90(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40C, 1);
}

extern struct opaque D_80048ABC;
void func_80091CBC(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7085, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B0D, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40D, 1);
}

s32 func_80091D1C(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40D, 1);
}

extern struct opaque D_80048ABC;
void func_80091D48(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7086, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B02, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40E, 1);
}

s32 func_80091DA8(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40E, 1);
}

extern struct opaque D_80048ABC;
void func_80091DD4(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x7087, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B0F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40F, 1);
}

s32 func_80091E34(void) {
    return ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40F, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80091E60);

void func_80091FDC(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = 1;
    if (arg1 != 0) {
        ((void (*)(s32))((s32 *)&D_80055C48)[0])(0x40019);
        M2C_FIELD(arg0, s32 *, 4) = 0x1000 / M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 8) = 0;
    } else {
        ((void (*)(s32))((s32 *)&D_80055C48)[0])(0x4001A);
        M2C_FIELD(arg0, s32 *, 8) = 0x1000;
        M2C_FIELD(arg0, s32 *, 4) = -((0x1000 / M2C_FIELD(arg0, s32 *, 0)) * 2);
    }
}

/* passo de um fade: soma p[1] em p[2] ate 0x1000 (subindo) ou 0 (descendo);
   retorna 1 quando termina */
s32 func_80092070(s32 *p) {
    s32 v;

    if (p[3] == 0) {
        return 1;
    }
    p[2] = v = p[2] + p[1];
    if (p[1] > 0) {
        if (v > 0x1000) {
            p[2] = 0x1000;
            p[3] = 0;
            return 1;
        }
    } else if (v < 0) {
        p[2] = 0;
        p[3] = 0;
        return 1;
    }
    return 0;
}

s32 func_800920DC(s32 arg0) {
    return (&D_80099E00)[arg0];
}

u8 func_800920F8(s32 arg0) {
    return D_8009A458[arg0];
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092110);

/* procura entre as 30 entradas (0x1C bytes) a de id */
u8 *func_800921E4(u8 *e, s32 id) {
    s32 i;

    for (i = 0; i < 30; i++, e += 0x1C) {
        if (*(s32 *)(e + 4) == id) {
            return e;
        }
    }
    return NULL;
}

s32 func_80092214(void) {
    return ((M2C_UNK (*)(s32 *, M2C_UNK)) D_8004B600)(&D_8009B3C4, 8);
}

/* procura o objeto de tipo 5 com id */
u8 *func_80092244(s32 id) {
    return ((u8 *(*)(s32, s32, s32))D_8004B7BC)(5, id, -1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092274);

void func_80092304(s32 id, s32 *count) {
    u8 *o = func_80092244(id);

    if ((*(s32 (**)(u8 *))(o + 0x138))(o) != 0) {
        (*count)++;
    }
}

void func_80092350(s32 id, s32 *count) {
    u8 *o = func_80092244(id);

    if ((*(s32 (**)(u8 *))(o + 0x140))(o) == 0) {
        (*count)++;
    }
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8009239C);

/* limpa 0x10C do objeto 1 (ou do 2, se o 1 nao existe) */
void func_80092408(void) {
    u8 *o = func_80092244(1);

    if (o == NULL) {
        o = func_80092244(2);
    }
    *(s32 *)(o + 0x10C) = 0;
}

/* procura id na tabela de 12 bytes (0 termina) */
s32 *func_8009243C(s32 id) {
    s32 *e = D_8009B3E8;

    while (e[0] != 0) {
        if (e[0] == id) {
            return e;
        }
        e += 3;
    }
    return NULL;
}

s32 func_80092484(s32 arg0) {
    s32 var_v1;
    void *temp_v0;

    temp_v0 = func_8009243C(arg0);
    var_v1 = 0;
    if (temp_v0 != NULL) {
        var_v1 = M2C_FIELD(temp_v0, s32 (**)(s32), 4)(arg0);
    }
    return var_v1;
}

void func_800924C8(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK (*temp_v0_2)(s32, M2C_UNK, M2C_UNK);
    void *temp_v0;

    temp_v0 = func_8009243C(arg1);
    if (temp_v0 != NULL) {
        temp_v0_2 = M2C_FIELD(temp_v0, M2C_UNK (**)(s32, M2C_UNK, M2C_UNK), 8);
        if (temp_v0_2 != NULL) {
            temp_v0_2(arg0, arg2, arg3);
        }
    }
}

void func_8009252C(void) {
    s32 temp_a0;

    temp_a0 = ((s32 (*)()) D_8004DC0C)() % 2304;
    if (temp_a0 < 0x100) {
        D_80048D64 = temp_a0;
        return;
    }
    D_80048D64 = (s32) (temp_a0 + 0x100) / 2;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800925A8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092664);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800927A0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800927FC);

void func_800928CC(s32 arg0, s32 arg1) {
    (&D_8009B6C4)[arg0] = arg1;
}

void func_800928E4(s32 v) {
    u8 *d = D_80048D34;

    if (*(s32 *)(d + 0x26D8) != 0) {
        *(s32 *)(d + 0x26E0) = v;
    }
}

void func_80092908(s32 arg0) {
    D_8004B414 = arg0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092914);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092A90);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092CA0);

/* out = tabela[k] * s / 4096 (dois valores) */
void func_80092DA0(s32 unused, s32 s, s32 k, s32 *out) {
    s32 *t = D_8009B724;
    s32 *e = t + k * 2;

    out[0] = e[0] * s / 4096;
    out[1] = e[1] * s / 4096;
}
