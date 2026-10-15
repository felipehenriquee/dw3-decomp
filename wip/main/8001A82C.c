s32 func_8001A82C(void *arg0, ScriptCtx *ctx) {
    if (ctx->base[ctx->pc + 2] < 5) {
        M2C_FIELD(arg0, s32 *, 0xC) = 2;
        M2C_FIELD(arg0, s32 *, 0x10) = 1;
        if ((u8)(ctx->base[ctx->pc + 2] - 1) >= 4) {
            M2C_FIELD(arg0, s32 *, 0x14) = 0;
        } else {
            M2C_FIELD(arg0, s32 *, 0x14) = ctx->base[ctx->pc + 2];
        }
        M2C_FIELD(arg0, s32 *, 0x18) = ctx->pc + 2;
        return 0;
    }
    return 0x8003;
}
