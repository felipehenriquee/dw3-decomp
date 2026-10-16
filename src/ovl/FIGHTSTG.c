#include "FIGHTSTG.h"
#include "m2c.h"
#include "FIGHTSTG_auto.h"
#include "FIGHTSTG_data.h"

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800832D0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800835F4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80083854);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800839C0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80083A54);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80083C30);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80083E0C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80084464);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800844F8);

s32 func_80084554(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x7C);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80084560);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80084790);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800847C4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800847F4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80084A54);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80084BC0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80084E0C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80085000);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80085110);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80085958);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80085F3C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80085FD4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008606C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008610C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800861F4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80086304);

void func_800868C0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x50);
    if (temp_v0 != arg1) {
        M2C_FIELD(arg0, s32 *, 0x54) = temp_v0;
        M2C_FIELD(arg0, s32 *, 0x50) = arg1;
        M2C_FIELD(arg0, s32 *, 0xB0) = arg2;
        M2C_FIELD(arg0, s32 *, 0xAC) = arg3;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

s32 func_80086904(void) {
    return (((s32 (*)()) D_8004DC0C)() % 27) + 1;
}

s16 func_8008695C(s32 arg0) {
    return M2C_FIELD(((arg0 * 0x58) + ((s32 (*)(M2C_UNK)) D_80044F4C)(0x1CB)), s16 *, 6);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800869A8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80086A00);

void *func_80087000(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80086A00, 0x68, 0xC);
    M2C_FIELD(temp_v0, s32 *, 4) = arg0;
    if (arg1 != 0) {
        M2C_FIELD(temp_v0, s32 *, 8) = 0x10;
    } else {
        M2C_FIELD(temp_v0, s32 *, 8) = 0;
    }
    M2C_FIELD(temp_v0, s32 *, 0x64) = arg2;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087070);

void func_80087160(void) {
    func_80014504(func_80087070, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008718C);

void func_80087B84(void) {
    func_80014504(func_8008718C, 0x6C, 0);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087BB0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087BF8);

s32 func_80087C3C(void *arg0) {
    s32 var_v1;
    void *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
loop_1:
    if (M2C_FIELD(var_a0, s32 *, 0x50) != 0) {
        var_v1 += 1;
        var_a0 += 0x4C;
        if (var_v1 >= 4) {
            return -1;
        }
        goto loop_1;
    }
    return var_v1;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087C70);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087D00);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087E28);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087E7C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087EE4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80087F38);

void func_80088024(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_80087E28();
    if (temp_v0 != 0) {
        M2C_FIELD(temp_v0, s32 *, 0x18) = arg2;
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80088054);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800880F0);

void func_8008834C(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800880F0, 0x70, 8);
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg1;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80088394);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80088564);

void func_80088C00(void) {
    func_80014504(func_80088564, 0x80, 8);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80088C2C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80089148);

void func_80089214(void) {
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008921C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800893DC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008966C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008970C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800897F8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80089844);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80089978);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80089A24);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80089BE4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80089CD8);

void func_8008A7F4(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80089CD8, 0x74, 0x18);
    M2C_FIELD(temp_v0, s32 *, 4) = arg0;
    M2C_FIELD(temp_v0, s32 *, 8) = arg1;
}

void func_8008A83C(void *arg0, s32 arg1, s32 arg2) {
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

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008A8C4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008AA08);

void func_8008AAAC(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008AA08, 0x68, 0);
    M2C_FIELD(temp_v0, void (**)(void *, s32, s32), 0x64) = func_8008A83C;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1006;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008AAF0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008AE9C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008AF10);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B06C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B0B8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B118);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B160);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B200);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B508);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B630);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B66C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B674);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B67C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B684);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B68C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B694);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B69C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008B7F4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008BC80);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008BEA8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C004);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C220);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C2CC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C454);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C514);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C590);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C910);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008C93C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008CB44);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008CB70);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008D37C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008D3B4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008DAC0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008EE4C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008EE84);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008F57C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008F5D4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8008F714);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80090C44);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80090C8C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80090E58);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80090E84);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800914EC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80091534);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80091B54);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80091B8C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80091C1C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80091CF4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80091DAC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80091DF4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80092244);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800922B4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800923B4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009257C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80092618);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80092684);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80092D50);

void func_80092D80(s32 arg0) {
    void *temp_v0;

    temp_v0 = ((void *(*)(M2C_UNK, M2C_UNK, M2C_UNK)) D_8004B7BC)(0xE, -1, -1);
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0xC) == 1)) {
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s32), 0x2C)(temp_v0, arg0);
    }
}

s32 func_80092DE4(void) {
    return M2C_FIELD(((void *(*)(M2C_UNK, M2C_UNK, M2C_UNK)) D_8004B7BC)(0xE, -1, -1), s32 *, 0x10) != 0;
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80092E18);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80092F7C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093088);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800930C0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093108);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009328C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093364);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800934F0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093A74);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093CC8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093CF4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093E44);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093F9C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80093FEC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094064);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009426C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094298);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094478);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009482C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094878);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009492C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094A00);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094AD0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094C18);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094D50);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80094F08);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800953E4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009543C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009563C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800957B4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800959B0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80095E00);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80095E40);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80096048);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80096314);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800967A0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80096E88);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80096EC8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80096FE4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800970C0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800972C8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80097498);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80097984);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800979E4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80097AB0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80097BD8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80097CFC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800980E4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098884);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800988FC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098924);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098A84);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098C9C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098D14);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098DE0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098E9C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098F08);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098F74);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80098FE0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80099048);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800990A0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800990E8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80099140);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_80099588);

void func_8009A254(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 4;
    M2C_FIELD(arg0, s32 *, 0x98) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = ((s32 (*)()) D_8004DF98)();
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009A298);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009A2DC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009A3B4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009A514);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009A6BC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009A734);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009A898);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009AB74);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009ABD8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009ADD4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009AF4C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B0C8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B13C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B460);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B4EC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B650);

void func_8009B6E4(void *arg0) {
    s32 temp_v1;
    s32 temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0xC);
    if (temp_v1 >= 0) {
        if (temp_v1 >= 2) {
            if (temp_v1 >= 4) {
                goto block_3;
            }
        } else {
            goto block_4;
        }
    } else {
block_3:
block_4:
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x58) - D_800A4464;
        M2C_FIELD(arg0, s32 *, 0x58) = temp_v1_2;
        if (temp_v1_2 <= 0) {
            ((M2C_UNK (*)(s32, s16)) D_80055C50)(M2C_FIELD(arg0, s32 *, 0x50), M2C_FIELD(arg0, s16 *, 0x54));
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 3);
        }
    }
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B774);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B864);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B8D0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B930);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009B9D0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009BA4C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009BBA8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009BC14);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009BC54);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009BC94);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009BD44);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009BDA4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C330);

void func_8009C4BC(s32 arg0) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 2;
    M2C_FIELD(&D_800A4780, s32 *, 4) = arg0;
    M2C_FIELD(&D_800A4780, s32 *, 8) = -1;
    func_8009B930(&D_800A4780);
}

void func_8009C4F8(s32 arg0) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 3;
    M2C_FIELD(&D_800A4780, s32 *, 4) = arg0;
    M2C_FIELD(&D_800A4780, s32 *, 8) = -1;
    func_8009B930(&D_800A4780);
}

void func_8009C534(u8 arg0) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 1;
    M2C_FIELD(&D_800A4780, s32 *, 4) = 1;
    M2C_FIELD(&D_800A4780, s32 *, 8) = -1;
    *D_800A435C = arg0;
    func_8009B9D0(&D_800A4780);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C578);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C5E8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C6A4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C740);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C7D4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C8B0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009C9C0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009CB10);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009CC20);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009CD1C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009CE84);

void func_8009CED0(void) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 0x12;
    M2C_FIELD(&D_800A4780, s32 *, 4) = 0;
    func_8009B930(&D_800A4780);
}

void func_8009CF00(s32 arg0) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 0x13;
    M2C_FIELD(&D_800A4780, s32 *, 4) = func_8009BDA4(0, arg0 + 3);
    M2C_FIELD(&D_800A4780, s32 *, 8) = 0;
    M2C_FIELD(&D_800A4780, s32 *, 0xC) = (s32) D_800A4468;
    func_8009B930(&D_800A4780);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009CF54);

void func_8009CFB0(void) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 0x15;
    M2C_FIELD(&D_800A4780, s32 *, 4) = 1;
    M2C_FIELD(&D_800A4780, s32 *, 8) = 0;
    M2C_FIELD(&D_800A4780, s32 *, 0xC) = (s32) D_800A4468;
    func_8009B9D0(&D_800A4780);
}

void func_8009CFF4(void) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 0x16;
    M2C_FIELD(&D_800A4780, s32 *, 4) = 1;
    M2C_FIELD(&D_800A4780, s32 *, 8) = 0;
    M2C_FIELD(&D_800A4780, s32 *, 0xC) = (s32) D_800A4468;
    func_8009B9D0(&D_800A4780);
}

void func_8009D038(void) {
    M2C_FIELD(&D_800A4780, s32 *, 0) = 0x17;
    M2C_FIELD(&D_800A4780, s32 *, 4) = 1;
    func_8009B9D0(&D_800A4780);
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D06C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D0EC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D140);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D1DC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D2C4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D3AC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D470);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D4B8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D61C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D72C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D768);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D7A4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D858);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009D944);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DA0C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DAAC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DB94);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DC8C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DD64);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DDD8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DEBC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009DF78);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E0CC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E428);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E510);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E53C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E77C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E950);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E970);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009E994);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009EADC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009EB94);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009EBE0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009EC94);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009F644);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009F6DC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009F97C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009FAB4);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009FE1C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_8009FF40);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0108);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A01AC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A02AC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0514);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A06AC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A08C8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0A18);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0B98);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0D00);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0E68);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A0FAC);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1114);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1308);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A13C0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1458);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1508);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1558);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A15A8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1608);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A17C8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1910);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A19D8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1AA8);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1C18);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1D3C);

void func_800A1E84(void) {
}

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1E8C);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1F74);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A1FE0);

INCLUDE_ASM("asm/ovl/FIGHTSTG/nonmatchings/FIGHTSTG", func_800A246C);
