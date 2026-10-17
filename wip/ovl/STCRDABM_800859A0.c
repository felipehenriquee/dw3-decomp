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

void func_800859A0(Lerp *l, s32 from, s32 to, s32 n) {
    if (from != to) {
        l->frames = n;
        l->step = ((to - from) << 8) / l->frames;
        l->acc = from << 8;
        l->cur = from;
        l->target = to;
        l->active = 1;
    }
}
