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

#endif /* MAIN_H */
