/* estado dos controles em D_8004B7D0 */
typedef struct {
    u8 pad0[0x6C];
    s16 motor[2]; /* tempo restante de cada motor de vibracao */
} PadSlot;

typedef struct {
    u8 pad0[0x48];
    PadSlot port[2][4];
    u8 act[2][6]; /* buffer do PadSetAct de cada porta */
} PadState;

#define PADS ((PadState *)D_8004B7D0)

/* conta o tempo dos dois motores de vibracao do controle e desliga os que
   chegaram a zero */
void func_80019224(u32 port) {
    s32 i = 0;
    u8 *sys = D_8004DE10;
    PadSlot *s = &PADS->port[(u8)port >> 4][port & 3];

    for (; i < 2; i++) {
        if (s->motor[i] != 0) {
            s->motor[i] -= (*(s32 (**)(void))(sys + 0x18C))();
            if (s->motor[i] <= 0) {
                s->motor[i] = 0;
                PADS->act[(u8)port >> 4][i] = 0;
            }
            PadSetAct((u8)port, PADS->act[(u8)port >> 4], 2);
        }
    }
}
