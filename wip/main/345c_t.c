s32 func_8001270C();
void func_8001345C(s32 arg0, s32 arg1) {
    Obj *o = func_80014504(func_8001270C, 0xA0, 0xAC);

    o->unk50 = arg0;
    o->unk54 = 1;
    M2C_FIELD(o, s32 *, 0x58) = arg1;
}
