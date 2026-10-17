/* estado dos controles em D_8004B7D0 */
typedef struct {
    u8 pad0[0x6C];
    s16 motor[2]; /* tempo restante de cada motor de vibracao */
} PadSlot;

typedef struct {
    s32 flags;
    u8 pad4[0x44];
    PadSlot port[2][4];
    u8 act[2][6]; /* buffer do PadSetAct de cada porta */
} PadState;

s32 func_800186E0(s32 port, s32 motor, s32 time, u8 power) {
    s32 p = port;
    PadState *ps = (PadState *)D_8004B7D0;
    u32 n;
    PadSlot *s;
    s32 mode;

    if (!(ps->flags & 0x8000000) || func_80018AD8(p & 0xFF) == 0) {
        return 0;
    }
    mode = PadInfoMode(p & 0xFF, 2, 0);
    n = (p & 0xFF) >> 4;
    s = &ps->port[n][port & 3];
    if (mode == 4 || mode == 7) {
        ps->act[n][motor & 1] = power;
    } else {
        ps->act[n][0] = 0x40;
        ps->act[n][1] = 1;
    }
    if (s->motor[motor] <= 0) {
        s->motor[motor] = time;
    } else if ((s16)time == 0) {
        s->motor[motor] = 0;
    }
    PadSetAct(p & 0xFF, ((PadState *)D_8004B7D0)->act[n], 2);
    return 1;
}
