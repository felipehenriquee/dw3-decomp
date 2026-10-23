/* Tipos do jogo compartilhados pelo EXE e pelos overlays (o tools/fn.py
   grava aqui as typedefs novas, para o tools/propagate.py poder usar o
   mesmo C em outros overlays). */
#ifndef TYPES_H
#define TYPES_H

/* de main.h */
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
    s16 unk4;
    s16 end;
    s16 pc;
    u8 unkA;
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

/* texto de um trabalho da janela de mensagem */
typedef struct {
    u8 *buf;
    s16 cap; /* tamanho alocado */
    s16 len;
    s16 pos; /* posicao de leitura */
    s16 unkA;
} MsgWork;

/* janela de mensagem: trabalhos de 12 bytes a partir de 0x5C */
typedef struct {
    u8 pad0[0x5C];
    MsgWork work[6];
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

/* DRAWENV da PsyQ (0x5C bytes) */
typedef struct {
    s16 clip[4];
    s16 ofs[2];
    s16 tw[4];
    u16 tpage;
    u8 dtd, dfe, isbg, r0, g0, b0;
    u32 dr_env[16];
} DrawEnv;

/* POLY_F4 da PsyQ */
typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    s16 x1, y1;
    s16 x2, y2;
    s16 x3, y3;
} PolyF4;

/* DR_MODE da PsyQ */
typedef struct {
    u32 tag;
    u32 code[2];
} DrMode;

/* 32 bytes sem alinhamento (paleta do icone) */
typedef struct {
    u8 b[32];
} Bytes32;

/* save do cartao de memoria em D_80048750: cabecalho "SC" em 0x10 */
typedef struct {
    u8 pad0[0x10];
    u8 magic[2];
    u8 type;
    u8 blocks;
    char title[0x5C];
    Bytes32 clut;
    u8 pad90[0x314 - 0x90];
    s32 nicons;
    s32 icon[3];
} McSave;

/* registro de 20 bytes em D_80048D34 (44 por personagem, a partir de 0x7B8) */
typedef struct {
    s32 w[5];
} Rec14;

typedef struct {
    u8 pad0[0x7B8];
    Rec14 rec;
} Unk80048D34_Rec;

/* de WSTAG635.h */
/* no da lista de pontos do mapa */
typedef struct MapPt {
    s16 v0, v1, v2, v3, v4, v5;
    struct MapPt *next;
} MapPt;

typedef struct {
    s16 x, y;
    MapPt *pts;
} MapPtList;

/* registro de 0x18 bytes preenchido a partir de um MapPt */
typedef struct {
    u8 pad0[0xA];
    s16 v0, v3, v4, v5;
    s16 pad12;
    s16 v1, v2;
} MapPtOut;

/* trecho de interpolacao: duracao, valor final e inicial */
typedef struct {
    s32 len;
    s16 to;
    s16 from;
} Seg;

/* entrada de 18 bytes da tabela em D_80042BCA */
typedef union {
    u8 b[18];
    u16 h[9];
} Rec18;

/* slot de 200 bytes da CARDGAME (a partir de 0x5A2) */
typedef struct {
    s16 v0;
    s16 v1;
    s16 v2;
    u8 pad6[200 - 6];
} CardSlot;

typedef struct {
    u8 pad0[0x422];
    u8 unk422;
    u8 pad423;
    s32 unk424;
    s32 unk428;
    s32 unk42C;
    s32 unk430;
    s32 unk434;
    u8 pad438[0x5A2 - 0x438];
    CardSlot slot[1];
} CardGame;

/* interpolacao em ponto fixo 24.8 */
typedef struct {
    s32 frames;
    s32 unk4;
    s32 cur;
    s32 acc;
    s32 target;
    s32 step;
    s32 active;
} Lerp;

/* par de valores (8 bytes) */
typedef struct {
    s32 x, y;
} Pair32;

/* dois pares passados por valor */
typedef struct {
    Pair32 a, b;
} Pair32x2;

/* trecho de interpolacao de 12 bytes: duracao, valor final e inicial */
typedef struct {
    s32 len;
    s16 to;
    s16 from;
    s32 pad8;
} Seg12;

/* registro de 0x34 bytes copiado como struct */
typedef struct {
    s32 w[13];
} Block34;

/* registro de 0x3C bytes copiado como struct */
typedef struct {
    s32 w[15];
} Block3C;

typedef struct { s16 v[4]; } S16x4;

typedef struct { u8 pad0[0x10]; S16x4 a[3]; u8 pad28[0x44]; S16x4 b[3]; } Elem84;

typedef struct { s16 x, y, z; } S16x3;

typedef struct { s16 x, y; s32 pad; } TitlPt;

typedef struct { u8 pad0[0x18]; TitlPt pt[2]; s32 sel; s16 x, y; s32 pad30; s32 done; } TitlBlink;

/* objeto com um array s16 em 0x50 */
typedef struct { u8 pad[0x50]; s16 a[1]; } CgArr50;

typedef struct { u8 pad0[0xA]; s16 n; u8 padC[0x58]; s16 a[1]; } CgList;

typedef struct { u8 pad[0xC]; u8 id; u8 padD; } CgCard14;

typedef struct { s32 v[8]; } S32x8;

typedef struct { s16 n; s16 k; } S16Pair;

typedef struct {
    s32 a108, b10C;
    u8 pad8[8];
    s32 a118, b11C;
    u8 pad18[0xE];
    s16 h12E;
    s32 w130;
    s32 w134;
    u8 pad30[0x12];
    u8 b14A;
    u8 pad43[4];
    u8 b14F;
    u8 pad48[4];
} CgE4C;

typedef struct { u8 pad[0x108]; CgE4C e[1]; } CgObjE;

typedef struct { s32 a; s32 b; Pair32 c; } FtE16;

typedef struct { s16 id; s16 idx; s16 pad[2]; } FtMap8;

/* bloco de 0x72 bytes da CARDGAME (a partir de 0x72C) */
typedef struct { u8 b0; u8 pad[0x71]; } CgE72;

typedef struct { u8 pad[0x72C]; CgE72 e[1]; } CgObj72C;

/* entrada de 14 bytes dentro do bloco de 0x72 (a partir de +8) */
typedef struct { s16 x, y; u8 pad[10]; } CgSub14;

typedef struct { u8 n; u8 pad1[7]; CgSub14 s[7]; u8 pad[0x72 - 8 - 98]; } CgE72b;

typedef struct { u8 pad[0x72C]; CgE72b e[1]; } CgObj72Cb;

typedef struct { s16 x, y; u8 pad[200 - 4]; } CgSlot59C;

typedef struct { u8 pad[0x59C]; CgSlot59C s[1]; } CgObj59C;

typedef struct { s16 x, y; } W212Pt;

typedef struct { s16 id; u8 idx; u8 kind; } FtCard4;

typedef struct { s32 id; s32 isB; s32 idx; s32 kind; u8 *p10; u8 *p14; } FtCardCur;

typedef struct { u8 pad[0x5A2]; CardSlot s[1]; } CgObjSlot;

typedef struct { u8 pad[0xC]; u8 *s[1]; } FdTbl;

typedef struct { s32 pad; s32 *e[8]; } FdSet4;

typedef struct { s16 x, y; } CgPt16;

typedef struct { u8 pad[0x58]; s32 v[4]; } FtArr58;

typedef struct { u8 pad[0x64]; s16 a[1]; } ItArr64;

#endif /* TYPES_H */
