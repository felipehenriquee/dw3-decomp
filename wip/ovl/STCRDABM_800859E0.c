s32 func_800859E0(Lerp *l) {
    s32 v, t, done;

    if (l->active == 0) {
        return 1;
    }
    l->acc += l->step;
    l->cur = v = l->acc >> 8;
    if (l->step > 0) {
        t = l->target;
        done = t < v;
    } else {
        t = l->target;
        done = v < t;
    }
    if (done) {
        l->cur = t;
        l->active = 0;
        return 1;
    }
    return 0;
}
