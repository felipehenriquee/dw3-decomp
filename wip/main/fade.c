/* fade: valor de 0 a 0x1000 andando 'speed' por quadro */
typedef struct {
    s32 unk0;
    s32 speed;
    s32 value;
    s32 active;
} Fade;

s32 func_80010FE0(Fade *f) {
    s32 speed;

    if (f->active == 0) {
        return 1;
    }
    speed = f->speed;
    f->value += speed;
    if (speed > 0) {
        if (f->value > 0x1000) {
            f->value = 0x1000;
            f->active = 0;
            return 1;
        }
    } else if (f->value < 0) {
        f->value = 0;
        f->active = 0;
        return 1;
    }
    return 0;
}
