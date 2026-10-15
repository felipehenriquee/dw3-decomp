/*
 * Funcoes usadas para identificar o compilador (ver CLAUDE.md).
 * Todas batem byte a byte com GCC 2.8.1 + maspsx e -G4/-G8:
 *
 *   tools/cc.sh tools/compiler_probe.c build/probe.o 8
 *   python3 -I tools/cc_cmp.py build/probe.o disc/SLES_049.36 \
 *       func_80011DAC func_80015590 func_800134E8 func_8001E7E0 func_80013780
 */
typedef struct { int pad[0x50 / 4]; int a; int b; } Obj;
extern Obj *func_80014504(void (*fn)(), int, int);
extern void func_800119A8();

void func_80011DAC(int arg0)
{
    Obj *o = func_80014504(func_800119A8, 0xA0, 0x20);
    o->a = arg0;
    o->b = 1;
}

typedef struct { char d[0x58]; } Ent;
extern int func_800134AC(void);
extern Ent D_8003EF5C[];

int func_80015590(unsigned char *bits, int n, int flag)
{
    int idx = n >> 3;
    int mask = 1 << (n & 7);

    if (flag != 0) {
        return (bits[idx] & mask) != 0;
    }
    return (bits[idx] & mask) == 0;
}

Ent *func_800134E8(void)
{
    int i = func_800134AC();

    if (i >= 0) {
        return &D_8003EF5C[i];
    }
    return 0;
}

typedef struct {
    int state;
    int pad[4];
    int *done;
    int pad2[2];
    int busy;
} CdState;
extern CdState D_80044B04;
extern unsigned char D_8005CCF8[4];
extern int D_8005CD08;
extern int CdControlF(unsigned char com, unsigned char *param);
extern void func_8002E27C(void (*)());
extern void func_8002E25C(int);
extern void func_800136F4();
extern void func_800138B8(void);

void func_8001E7E0(int a) { D_8005CD08 = a; }

void func_80013780(int arg0)
{
    int *p;

    switch (arg0) {
    case 5:
        if (D_80044B04.state == 4) {
            CdControlF(9, 0);
        } else {
            goto fail;
        }
        break;
    case 2:
        switch (D_80044B04.state) {
        case 1:
            D_8005CCF8[0] = 0xA0;
            CdControlF(0xE, D_8005CCF8);
            D_80044B04.state++;
            break;
        case 2:
            func_8002E27C(func_800136F4);
            CdControlF(6, 0);
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
            if (p != 0) {
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
