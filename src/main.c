#include "common.h"

/* objeto alocado por func_80014504 */
typedef struct {
    s32 pad[0x50 / 4];
    s32 unk50;
    s32 unk54;
} Obj;

typedef struct {
    u8 unk[0x58];
} Ent;

/* estado da leitura de CD controlada por func_80013780 */
typedef struct {
    s32 state;
    s32 pad[4];
    s32 *done;
    s32 pad2[2];
    s32 busy;
} CdState;

extern Obj *func_80014504(void (*fn)(), s32, s32);
extern void func_800119A8();
extern s32 func_800134AC(void);
extern void func_800136F4();
extern void func_800138B8(void);
extern void func_8002E25C(s32);
extern void func_8002E27C(void (*)());
extern s32 CdControlF(u8 com, u8 *param);

extern Ent D_8003EF5C[];
extern CdState D_80044B04;
extern u8 D_8005CCF8[4];
extern s32 D_8005CD08;

INCLUDE_ASM("asm/nonmatchings/main", func_80010F4C);

INCLUDE_ASM("asm/nonmatchings/main", func_80010FE0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001104C);

INCLUDE_ASM("asm/nonmatchings/main", func_800110E0);

INCLUDE_ASM("asm/nonmatchings/main", func_800119A8);

void func_80011DAC(s32 arg0)
{
    Obj *o = func_80014504(func_800119A8, 0xA0, 0x20);

    o->unk50 = arg0;
    o->unk54 = 1;
}

INCLUDE_ASM("asm/nonmatchings/main", func_80011DEC);

INCLUDE_ASM("asm/nonmatchings/main", func_80011E74);

INCLUDE_ASM("asm/nonmatchings/main", func_80011FB8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001206C);

INCLUDE_ASM("asm/nonmatchings/main", func_800120B4);

INCLUDE_ASM("asm/nonmatchings/main", func_80012148);

INCLUDE_ASM("asm/nonmatchings/main", func_800121B4);

INCLUDE_ASM("asm/nonmatchings/main", func_800123E0);

INCLUDE_ASM("asm/nonmatchings/main", func_800126A8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001270C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001345C);

INCLUDE_ASM("asm/nonmatchings/main", func_800134AC);

Ent *func_800134E8(void)
{
    s32 i = func_800134AC();

    if (i >= 0) {
        return &D_8003EF5C[i];
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/main", func_80013534);

INCLUDE_ASM("asm/nonmatchings/main", func_8001355C);

INCLUDE_ASM("asm/nonmatchings/main", func_80013584);

INCLUDE_ASM("asm/nonmatchings/main", func_800135B8);

INCLUDE_ASM("asm/nonmatchings/main", func_800135E8);

INCLUDE_ASM("asm/nonmatchings/main", func_80013694);

INCLUDE_ASM("asm/nonmatchings/main", func_800136F4);

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

INCLUDE_ASM("asm/nonmatchings/main", func_800138A8);

INCLUDE_ASM("asm/nonmatchings/main", func_800138B8);

INCLUDE_ASM("asm/nonmatchings/main", func_80013914);

INCLUDE_ASM("asm/nonmatchings/main", func_800139FC);

INCLUDE_ASM("asm/nonmatchings/main", func_80013A34);

INCLUDE_ASM("asm/nonmatchings/main", func_80013A6C);

INCLUDE_ASM("asm/nonmatchings/main", func_80013ADC);

INCLUDE_ASM("asm/nonmatchings/main", func_80013BE4);

INCLUDE_ASM("asm/nonmatchings/main", func_80013C30);

INCLUDE_ASM("asm/nonmatchings/main", func_80013CDC);

INCLUDE_ASM("asm/nonmatchings/main", func_80013E20);

INCLUDE_ASM("asm/nonmatchings/main", func_80013E5C);

INCLUDE_ASM("asm/nonmatchings/main", func_80013EFC);

INCLUDE_ASM("asm/nonmatchings/main", func_80013F60);

INCLUDE_ASM("asm/nonmatchings/main", func_80013FF4);

INCLUDE_ASM("asm/nonmatchings/main", func_800140D8);

INCLUDE_ASM("asm/nonmatchings/main", func_80014110);

INCLUDE_ASM("asm/nonmatchings/main", func_80014128);

INCLUDE_ASM("asm/nonmatchings/main", func_80014170);

INCLUDE_ASM("asm/nonmatchings/main", func_800141E4);

INCLUDE_ASM("asm/nonmatchings/main", func_80014200);

INCLUDE_ASM("asm/nonmatchings/main", func_8001421C);

INCLUDE_ASM("asm/nonmatchings/main", func_80014238);

INCLUDE_ASM("asm/nonmatchings/main", func_80014274);

INCLUDE_ASM("asm/nonmatchings/main", func_80014288);

INCLUDE_ASM("asm/nonmatchings/main", func_80014298);

INCLUDE_ASM("asm/nonmatchings/main", func_800142A4);

INCLUDE_ASM("asm/nonmatchings/main", func_800142AC);

INCLUDE_ASM("asm/nonmatchings/main", func_800142C8);

INCLUDE_ASM("asm/nonmatchings/main", func_800142E0);

INCLUDE_ASM("asm/nonmatchings/main", func_800142F4);

INCLUDE_ASM("asm/nonmatchings/main", func_80014308);

INCLUDE_ASM("asm/nonmatchings/main", func_800143DC);

INCLUDE_ASM("asm/nonmatchings/main", func_80014504);

INCLUDE_ASM("asm/nonmatchings/main", func_80014524);

INCLUDE_ASM("asm/nonmatchings/main", func_800148C0);

INCLUDE_ASM("asm/nonmatchings/main", func_80014908);

INCLUDE_ASM("asm/nonmatchings/main", func_8001491C);

INCLUDE_ASM("asm/nonmatchings/main", func_80014930);

INCLUDE_ASM("asm/nonmatchings/main", func_80014AA8);

INCLUDE_ASM("asm/nonmatchings/main", func_80014B44);

INCLUDE_ASM("asm/nonmatchings/main", func_80014C24);

INCLUDE_ASM("asm/nonmatchings/main", func_80014D04);

INCLUDE_ASM("asm/nonmatchings/main", func_80014FC4);

INCLUDE_ASM("asm/nonmatchings/main", func_80015288);

INCLUDE_ASM("asm/nonmatchings/main", func_80015480);

INCLUDE_ASM("asm/nonmatchings/main", func_800154B8);

INCLUDE_ASM("asm/nonmatchings/main", func_800154F0);

INCLUDE_ASM("asm/nonmatchings/main", func_80015528);

INCLUDE_ASM("asm/nonmatchings/main", func_80015530);

INCLUDE_ASM("asm/nonmatchings/main", func_80015564);

s32 func_80015590(u8 *bits, s32 n, s32 flag)
{
    s32 idx = n >> 3;
    s32 mask = 1 << (n & 7);

    if (flag != 0) {
        return (bits[idx] & mask) != 0;
    }
    return (bits[idx] & mask) == 0;
}

INCLUDE_ASM("asm/nonmatchings/main", func_800155D4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001561C);

INCLUDE_ASM("asm/nonmatchings/main", func_80015754);

INCLUDE_ASM("asm/nonmatchings/main", func_80015AAC);

INCLUDE_ASM("asm/nonmatchings/main", func_80015B9C);

INCLUDE_ASM("asm/nonmatchings/main", func_80015BD8);

INCLUDE_ASM("asm/nonmatchings/main", func_80015D4C);

INCLUDE_ASM("asm/nonmatchings/main", func_80015D90);

INCLUDE_ASM("asm/nonmatchings/main", func_80015EC8);

INCLUDE_ASM("asm/nonmatchings/main", func_80015F04);

INCLUDE_ASM("asm/nonmatchings/main", func_80015F70);

INCLUDE_ASM("asm/nonmatchings/main", func_80015FBC);

INCLUDE_ASM("asm/nonmatchings/main", func_800160A8);

INCLUDE_ASM("asm/nonmatchings/main", func_80016124);

INCLUDE_ASM("asm/nonmatchings/main", func_800161D8);

INCLUDE_ASM("asm/nonmatchings/main", func_80016314);

INCLUDE_ASM("asm/nonmatchings/main", func_80016378);

INCLUDE_ASM("asm/nonmatchings/main", func_800163B0);

INCLUDE_ASM("asm/nonmatchings/main", func_800165AC);

INCLUDE_ASM("asm/nonmatchings/main", func_80016924);

INCLUDE_ASM("asm/nonmatchings/main", func_80016988);

INCLUDE_ASM("asm/nonmatchings/main", func_800169E0);

INCLUDE_ASM("asm/nonmatchings/main", func_80016A94);

INCLUDE_ASM("asm/nonmatchings/main", func_80016B28);

INCLUDE_ASM("asm/nonmatchings/main", func_80016B58);

INCLUDE_ASM("asm/nonmatchings/main", func_80016B68);

INCLUDE_ASM("asm/nonmatchings/main", func_80016B78);

INCLUDE_ASM("asm/nonmatchings/main", func_80016B88);

INCLUDE_ASM("asm/nonmatchings/main", func_80016B9C);

INCLUDE_ASM("asm/nonmatchings/main", func_80016BAC);

INCLUDE_ASM("asm/nonmatchings/main", func_80016D94);

INCLUDE_ASM("asm/nonmatchings/main", func_80016DC0);

INCLUDE_ASM("asm/nonmatchings/main", func_80016E2C);

INCLUDE_ASM("asm/nonmatchings/main", func_80016E6C);

INCLUDE_ASM("asm/nonmatchings/main", func_80016F0C);

INCLUDE_ASM("asm/nonmatchings/main", func_80016F2C);

INCLUDE_ASM("asm/nonmatchings/main", func_80016FD8);

INCLUDE_ASM("asm/nonmatchings/main", func_80017028);

INCLUDE_ASM("asm/nonmatchings/main", func_800170C8);

INCLUDE_ASM("asm/nonmatchings/main", func_80017174);

INCLUDE_ASM("asm/nonmatchings/main", func_80017578);

INCLUDE_ASM("asm/nonmatchings/main", func_8001764C);

INCLUDE_ASM("asm/nonmatchings/main", func_800176AC);

INCLUDE_ASM("asm/nonmatchings/main", func_800177D0);

INCLUDE_ASM("asm/nonmatchings/main", func_80017898);

INCLUDE_ASM("asm/nonmatchings/main", func_80017924);

INCLUDE_ASM("asm/nonmatchings/main", func_80017A1C);

INCLUDE_ASM("asm/nonmatchings/main", func_80017AB4);

INCLUDE_ASM("asm/nonmatchings/main", func_80017B4C);

INCLUDE_ASM("asm/nonmatchings/main", func_80017B70);

void func_80017BDC(void) {
}

INCLUDE_ASM("asm/nonmatchings/main", func_80017BE4);

INCLUDE_ASM("asm/nonmatchings/main", func_80017C5C);

INCLUDE_ASM("asm/nonmatchings/main", func_80017CB0);

INCLUDE_ASM("asm/nonmatchings/main", func_80017D08);

INCLUDE_ASM("asm/nonmatchings/main", func_80017D2C);

INCLUDE_ASM("asm/nonmatchings/main", func_80017DDC);

INCLUDE_ASM("asm/nonmatchings/main", func_80017E84);

INCLUDE_ASM("asm/nonmatchings/main", func_80017EEC);

INCLUDE_ASM("asm/nonmatchings/main", func_80017F54);

INCLUDE_ASM("asm/nonmatchings/main", func_80017F94);

INCLUDE_ASM("asm/nonmatchings/main", func_80017FB4);

INCLUDE_ASM("asm/nonmatchings/main", func_80017FDC);

INCLUDE_ASM("asm/nonmatchings/main", func_80018014);

INCLUDE_ASM("asm/nonmatchings/main", func_8001804C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001810C);

INCLUDE_ASM("asm/nonmatchings/main", func_80018140);

INCLUDE_ASM("asm/nonmatchings/main", func_80018230);

INCLUDE_ASM("asm/nonmatchings/main", func_8001829C);

INCLUDE_ASM("asm/nonmatchings/main", func_800182C8);

INCLUDE_ASM("asm/nonmatchings/main", func_80018310);

INCLUDE_ASM("asm/nonmatchings/main", func_8001843C);

INCLUDE_ASM("asm/nonmatchings/main", func_80018460);

INCLUDE_ASM("asm/nonmatchings/main", func_800184D0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001851C);

INCLUDE_ASM("asm/nonmatchings/main", func_800186E0);

INCLUDE_ASM("asm/nonmatchings/main", func_80018854);

INCLUDE_ASM("asm/nonmatchings/main", func_80018878);

INCLUDE_ASM("asm/nonmatchings/main", func_8001889C);

INCLUDE_ASM("asm/nonmatchings/main", func_800188C0);

INCLUDE_ASM("asm/nonmatchings/main", func_80018928);

INCLUDE_ASM("asm/nonmatchings/main", func_80018980);

INCLUDE_ASM("asm/nonmatchings/main", func_800189A8);

void func_800189B0(void) {
}

INCLUDE_ASM("asm/nonmatchings/main", func_800189B8);

INCLUDE_ASM("asm/nonmatchings/main", func_800189F0);

INCLUDE_ASM("asm/nonmatchings/main", func_80018A64);

INCLUDE_ASM("asm/nonmatchings/main", func_80018AA0);

INCLUDE_ASM("asm/nonmatchings/main", func_80018AD8);

INCLUDE_ASM("asm/nonmatchings/main", func_80018BCC);

INCLUDE_ASM("asm/nonmatchings/main", func_80018F44);

INCLUDE_ASM("asm/nonmatchings/main", func_8001902C);

INCLUDE_ASM("asm/nonmatchings/main", func_80019148);

INCLUDE_ASM("asm/nonmatchings/main", func_80019224);

INCLUDE_ASM("asm/nonmatchings/main", func_8001932C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001933C);

INCLUDE_ASM("asm/nonmatchings/main", func_80019370);

INCLUDE_ASM("asm/nonmatchings/main", func_800194C4);

INCLUDE_ASM("asm/nonmatchings/main", func_800194E8);

INCLUDE_ASM("asm/nonmatchings/main", func_80019508);

INCLUDE_ASM("asm/nonmatchings/main", func_800195B0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001968C);

INCLUDE_ASM("asm/nonmatchings/main", func_800196E4);

INCLUDE_ASM("asm/nonmatchings/main", func_800197A4);

INCLUDE_ASM("asm/nonmatchings/main", func_80019FB0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A180);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A1B8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A1E8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A1F4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A1FC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A204);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A23C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A25C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A2AC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A418);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A420);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A43C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A448);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A450);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A458);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A460);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A46C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A478);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A48C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A6E8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A73C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A82C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001A8B4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001AA08);

INCLUDE_ASM("asm/nonmatchings/main", func_8001AA10);

INCLUDE_ASM("asm/nonmatchings/main", func_8001AB30);

INCLUDE_ASM("asm/nonmatchings/main", func_8001ABA4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001AC14);

INCLUDE_ASM("asm/nonmatchings/main", func_8001AE38);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B04C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B068);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B07C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B08C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B094);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B09C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B0A4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B364);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B444);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B48C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B4CC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B554);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B63C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B698);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B6EC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B724);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B7B8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B814);

INCLUDE_ASM("asm/nonmatchings/main", func_8001B930);

INCLUDE_ASM("asm/nonmatchings/main", func_8001BA2C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001BB88);

INCLUDE_ASM("asm/nonmatchings/main", func_8001BBE8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001BE00);

INCLUDE_ASM("asm/nonmatchings/main", func_8001BEEC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001C050);

INCLUDE_ASM("asm/nonmatchings/main", func_8001C448);

INCLUDE_ASM("asm/nonmatchings/main", func_8001C4B4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001C4EC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001C7D8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001C85C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001C948);

INCLUDE_ASM("asm/nonmatchings/main", func_8001CAB0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001CE44);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D1E4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D264);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D3F4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D4E0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D504);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D6E4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D6F4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D704);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D714);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D7C4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D844);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D854);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D860);

INCLUDE_ASM("asm/nonmatchings/main", func_8001D8CC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DA00);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DA84);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DAD0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DB34);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DB84);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DBE0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DC7C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DD04);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DDA0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DDDC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DE68);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DFA8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DFCC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001DFFC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E01C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E028);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E058);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E064);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E088);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E094);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E0B0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E0BC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E0C8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E118);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E19C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E1E8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E240);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E324);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E38C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E404);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E470);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E4F4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E55C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E5BC);

void func_8001E7E0(s32 arg0)
{
    D_8005CD08 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/main", func_8001E7EC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E890);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E938);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E98C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E9A0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E9B4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E9C8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E9D4);

INCLUDE_ASM("asm/nonmatchings/main", func_8001E9E0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001EBCC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001EBF8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001ECB0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001ECBC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001ECD8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001ECEC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001ECF8);

INCLUDE_ASM("asm/nonmatchings/main", func_8001ED34);

INCLUDE_ASM("asm/nonmatchings/main", func_8001ED6C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001F5D0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001F5EC);

INCLUDE_ASM("asm/nonmatchings/main", func_8001F608);

INCLUDE_ASM("asm/nonmatchings/main", func_8001F61C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001F628);

INCLUDE_ASM("asm/nonmatchings/main", func_8001F648);

INCLUDE_ASM("asm/nonmatchings/main", func_8001F738);

INCLUDE_ASM("asm/nonmatchings/main", func_8001F744);

INCLUDE_ASM("asm/nonmatchings/main", func_8001F770);

INCLUDE_ASM("asm/nonmatchings/main", func_8001FA20);

INCLUDE_ASM("asm/nonmatchings/main", func_8001FCC0);

INCLUDE_ASM("asm/nonmatchings/main", func_8001FD1C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001FD28);

INCLUDE_ASM("asm/nonmatchings/main", func_8001FD3C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001FD50);

INCLUDE_ASM("asm/nonmatchings/main", func_8001FE38);

INCLUDE_ASM("asm/nonmatchings/main", func_8001FF9C);

INCLUDE_ASM("asm/nonmatchings/main", func_8001FFA8);

INCLUDE_ASM("asm/nonmatchings/main", func_80020030);

INCLUDE_ASM("asm/nonmatchings/main", func_8002006C);

INCLUDE_ASM("asm/nonmatchings/main", func_80020204);

INCLUDE_ASM("asm/nonmatchings/main", func_800202D4);

INCLUDE_ASM("asm/nonmatchings/main", func_8002037C);

INCLUDE_ASM("asm/nonmatchings/main", func_8002043C);

INCLUDE_ASM("asm/nonmatchings/main", func_8002044C);

INCLUDE_ASM("asm/nonmatchings/main", func_80020574);

INCLUDE_ASM("asm/nonmatchings/main", func_800205F0);

INCLUDE_ASM("asm/nonmatchings/main", func_8002090C);

INCLUDE_ASM("asm/nonmatchings/main", func_8002096C);

INCLUDE_ASM("asm/nonmatchings/main", func_80020A10);

INCLUDE_ASM("asm/nonmatchings/main", func_80020B58);

INCLUDE_ASM("asm/nonmatchings/main", func_80020C38);

INCLUDE_ASM("asm/nonmatchings/main", func_80020C64);

INCLUDE_ASM("asm/nonmatchings/main", func_80020D10);
