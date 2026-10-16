/*
 * Declaracoes dos dados do EXE usados pelo codigo C (fora da area $gp).
 * Mantido pelo tools/autodecomp.py: a primeira funcao integrada que usa um
 * simbolo define o tipo dele aqui. Pode ser editado a mao (para trocar por
 * structs de verdade, por exemplo); o autodecomp reescreve com casts o
 * codigo novo que quiser outro tipo.
 * Escalares levam NOT_GP para o gcc nao usar $gp com -G8.
 */
#ifndef MAIN_DATA_H
#define MAIN_DATA_H

/* tipo ainda desconhecido (so o endereco e usado) */
struct opaque;

extern s32 D_800100C4 NOT_GP;
extern s32 D_800100C8 NOT_GP;
extern s32 D_80010234 NOT_GP;
extern u8 D_80042BA8[];
extern s32 D_80044F6C NOT_GP;
extern u16 D_800474A4[];
extern u8 D_80048D34[];
extern u8 D_8004949C[];
extern s32 D_8004B3F8[];
extern s32 D_8004B3FC[];
extern s32 D_8004B400[];
extern s32 D_8004B404[];
extern struct opaque D_8004B5EC;
extern struct opaque D_8004B5F4;
extern struct opaque D_8004B600;
extern s32 D_8004B7BC NOT_GP;
extern u8 D_8004B7D0[];
extern s32 D_8004DC04[];
extern struct opaque D_8004DC0C;
extern s32 D_8004DE00[];
extern s32 D_8004DE18[];
extern s32 D_8004DE20[];
extern s32 D_8004DE28[];
extern s32 D_8004DE30[];
extern u8 D_8004DE48[];
extern u16 D_80055C40[];
extern s32 D_8004DFCC[];
extern s32 D_8004B610[];
extern s32 D_8004DE44[];
extern s32 D_8004B7C8[];
extern u8 D_800519EC[];
extern s32 D_8004DF8C[];
extern s32 D_8004B454[];
extern u8 D_8004DE10[];
extern u8 D_80042B1C[];
extern struct opaque D_80048D88;
extern struct opaque D_8004DF98;
extern u8 D_80044B3C[];
extern s32 D_80055C48[];
extern u8 D_8005CD28[];
extern struct opaque D_80055D28;
extern struct opaque D_80044F4C;
extern struct opaque D_80048744;
extern struct opaque D_8004B5DC;
extern s32 *D_8005CB50[];
extern Unk80041838 D_80041838[];
extern u16 D_8004BC04[];
extern u8 D_8004BBF4[];
extern s32 D_80044B38[];
extern HeapBlock *D_8004B5E0[];
extern Block32 D_800812F8[];
extern Block32 D_80081358[];
extern s32 D_80044B24[];
extern u8 D_80048750[];
extern s32 D_8004B49C[];
extern s32 D_8004DFB8[];
extern s32 D_80042B98[];

#endif /* MAIN_DATA_H */
