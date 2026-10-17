#ifndef MAIN_H
#define MAIN_H

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

/* elemento da tabela em D_8004B7D0 (0x1C0 bytes) */
typedef struct {
    u8 pad0[0x48];
    u16 unk48;
    u16 unk4A;
    u16 unk4C;
    u16 unk4E;
    u8 pad50[0x1C0 - 0x50];
} Unk8004B7D0;

extern Obj *func_80014504(void (*fn)(), s32, s32);
extern void func_800119A8();
extern s32 func_800134AC(s32);
extern void func_800136F4();
extern void func_800138B8(void);
extern void func_8002E25C(s32);
extern void func_8002E27C(void (*)());
extern s32 CdControlF(u8 com, u8 *param);

extern Ent D_8003EF5C[];
extern CdState D_80044B04;
extern u8 D_8005CCF8[4];
extern s32 D_8005CD08;

/* contexto de desenho: duas OTs (buffer duplo) */
typedef struct {
    u8 pad0[0x5C];
    s32 ot[2];
    s32 otLen;
    s32 unk68;
} Unk8001DDA0;

/* D_800519EC + 0x4204: tabela de 0x18 bytes por entrada */
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4[10];
} Unk800519EC_4204;

typedef struct {
    u8 pad0[0x4204];
    Unk800519EC_4204 unk4204[1];
} Unk800519EC;

/* struct grande em D_80048D34 (dados do jogador/partida?) */
typedef struct {
    u8 pad0[0x70];
    s32 unk70[3];
} Unk80048D34;

/* elemento de 0x3DC bytes indexado a partir de D_80048D34 */
typedef struct {
    u8 unk0[0x3DC];
} Unk80048D34_3DC;

/* no de 0x14 bytes da lista em func_8001E324 */
typedef struct Unk8001E324 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    struct Unk8001E324 *next;
} Unk8001E324;

/* tabela em D_8004DE10: 30 slots (em uso + id) */
typedef struct {
    u8 pad0[0x60];
    s32 used[30];
    s32 id[30];
} Unk8004DE10;

typedef struct {
    u8 pad0[0x58];
    s16 unk58[8];
} Unk80042B1C;

/* contexto do interpretador: base do script e posicao atual */
typedef struct {
    u8 *base;
    s32 unk4;
    s16 pc;
} ScriptCtx;

/* tabela em D_80044B3C: 64 entradas de 0x10 bytes */
typedef struct {
    s16 unk0;
    s16 unk2;
    s32 id;
    s32 unk8;
    s32 unkC;
} Unk80044B3C;

/* 4 bytes sem alinhamento (o gcc copia com lwl/lwr) */
typedef struct {
    u8 b[4];
} Bytes4;

typedef struct {
    u8 pad0[0x7B8];
    s16 unk7B8;
} Unk80048D34_7B8;

typedef struct {
    u8 unk0[0xC];
} Unk80041838;

/* bloco do heap (lista encadeada; tag 1 = fim) */
typedef struct HeapBlock {
    struct HeapBlock *unk0;
    struct HeapBlock *next;
    s32 tag;
} HeapBlock;

/* bloco de 32 bytes copiado como struct (tamanho de um MATRIX da PsyQ) */
typedef struct {
    s32 w[8];
} Block32;

/* janela de mensagem: trabalhos de 12 bytes a partir de 0x5C */
typedef struct {
    u8 pad0[0x5C];
    struct {
        u8 unk0[0xA];
        s16 unkA;
    } work[6];
} MsgWin;

typedef struct {
    u8 pad0[0x63E];
    u16 unk63E;
} Unk80048D34_63E;

/* personagem em D_8004949C (0x3DC bytes); atributos s16 a partir de 0x1C */
typedef struct {
    u8 pad0[0x1C];
    s16 stat[19];
    u8 pad42[0x3DC - 0x42];
} Unk8004949C;

/* fade: valor de 0 a 0x1000 andando 'speed' por quadro */
typedef struct {
    s32 unk0;
    s32 speed;
    s32 value;
    s32 active;
} Fade;

/* banco de som carregado (D_80055BEC, entradas de 0x18 bytes) */
typedef struct {
    s32 id;
    s16 vab;
    s16 nseq;
    s16 seq[8];
} SndBank;

/* pedido de carga do banco de som (D_80055BEC + 0x50) */
typedef struct {
    s32 *data;
    s16 state;
    s16 slot;
} SndReq;

#endif /* MAIN_H */
