extern struct opaque D_80048D88;

/* contexto do interpretador: base do script e posicao atual */
typedef struct {
    u8 *base;
    s32 unk4;
    s16 pc;
} ScriptCtx;

s32 func_8001ABA4(s32 arg0, ScriptCtx *ctx) {
    if (ctx->base[ctx->pc + 2] < 6) {
        func_800196E4(arg0, &D_80048D88, -1, ctx->base[ctx->pc + 2]);
        ctx->base[ctx->pc + 2] = 6;
    }
    return 0x8003;
}
