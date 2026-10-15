/* contexto do interpretador: base do script e posicao atual */
typedef struct {
    u8 *base;
    s32 unk4;
    s16 pc;
} ScriptCtx;
s32 func_8001A6E8(void *arg0, ScriptCtx *ctx) {
    u8 v = ctx->base[ctx->pc + 1];

    if (v == 0 || v != 7) {
        func_80019FB0(arg0, ctx, v);
    } else {
        M2C_FIELD(arg0, s16 *, 0xA6) = ctx->pc + 2;
    }
    return 0;
}
