extern s32 D_8004DF8C NOT_GP;
void func_8001E938(s32 arg0, s32 arg1) {
    void *obj;

    obj = ((void *(*)(s32))D_8004DF8C)(arg0);
    M2C_FIELD(D_8005CD08, void **, 0x24) = obj;
    M2C_FIELD(D_8005CD08, s32 *, 0x28) = M2C_FIELD(obj, s32 (**)(void *, s32), 0x138)(obj, arg1);
}
