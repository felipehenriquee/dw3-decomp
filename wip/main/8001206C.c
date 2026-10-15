void func_8001206C(s32 arg0) {
    Obj *o = func_80014504(func_80011FB8, 0x68, 0);

    M2C_FIELD(o, void (**)(void *, s32, s32), 0x64) = func_80011DEC;
    o->unk50 = arg0;
    o->unk54 = 0;
}
