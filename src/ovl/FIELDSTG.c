#include "FIELDSTG.h"
#include "m2c.h"
#include "FIELDSTG_auto.h"
#include "FIELDSTG_data.h"

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80083784);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800837EC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80083CD8);

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

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084198);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084200);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084804);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084834);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084868);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008489C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800848D0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084904);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084938);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008496C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800849A0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800849D4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084A08);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084A3C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084A70);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084AA4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084AD8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084B0C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084B40);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084D30);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084D8C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084DD0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80084ECC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800853F8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085590);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085AC4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085AFC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085BD4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085E0C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085E64);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80085ED4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086060);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086284);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800862FC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086770);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800869C8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086C78);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80086C9C);

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

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087580);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800875AC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087704);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087854);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087974);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087D68);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087DB0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087E7C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80087F84);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088144);

void func_80088190(s32 arg0) {
    func_80088144(0, 0, arg0);
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

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088A4C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088A84);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088B84);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088CA0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088D38);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80088EEC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089038);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089490);

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

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089BA4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089BDC);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089F24);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80089F7C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008A5E4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008A9B0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008AA10);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008B6A4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008B6D4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008B770);

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

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C8B4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C910);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008C98C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008CCC8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008CE40);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008CF1C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008CFD4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D068);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D244);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D27C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D744);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D788);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008D998);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008DC58);

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

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008EFF4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F004);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F064);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F0A4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F0F0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F128);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F1D4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F280);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F304);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F3E4);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F44C);

void func_8008F4B4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xA0) = arg1;
    M2C_FIELD(arg0, s32 *, 0xCC) = 0;
    M2C_FIELD(arg0, s32 *, 0xD0) = 0;
    M2C_FIELD(arg0, s32 *, 0xE8) = 0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F4C8);

s32 func_8008F520(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xE8);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F52C);

void func_8008F9B8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x60) = arg1;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008F9C0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8008FD60);

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

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800915A0);

void func_80091600(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x400, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8009162C);

void func_8009168C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x401, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800916B8);

void func_80091718(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x402, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80091744);

void func_800917A4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x403, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800917D0);

void func_80091830(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x404, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8009185C);

void func_800918BC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x405, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800918E8);

void func_80091948(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x406, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80091974);

void func_800919D4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x407, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80091A00);

void func_80091A60(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x408, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80091A8C);

void func_80091AEC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x409, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80091B18);

void func_80091B78(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40A, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80091BA4);

void func_80091C04(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40B, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80091C30);

void func_80091C90(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40C, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80091CBC);

void func_80091D1C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40D, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80091D48);

void func_80091DA8(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40E, 1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80091DD4);

void func_80091E34(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) D_80048AC8)(0x40F, 1);
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

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092070);

s32 func_800920DC(s32 arg0) {
    return (&D_80099E00)[arg0];
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800920F8);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092110);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800921E4);

void func_80092214(void) {
    ((M2C_UNK (*)(s32 *, M2C_UNK)) D_8004B600)(&D_8009B3C4, 8);
}

void func_80092244(s32 arg0) {
    ((M2C_UNK (*)(M2C_UNK, s32, M2C_UNK)) D_8004B7BC)(5, arg0, -1);
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092274);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092304);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092350);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8009239C);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092408);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_8009243C);

s32 func_80092484(s32 arg0) {
    s32 var_v1;
    void *temp_v0;

    temp_v0 = func_8009243C();
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

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_800928E4);

void func_80092908(s32 arg0) {
    D_8004B414 = arg0;
}

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092914);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092A90);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092CA0);

INCLUDE_ASM("asm/ovl/FIELDSTG/nonmatchings/FIELDSTG", func_80092DA0);
