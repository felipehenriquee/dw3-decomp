/* carrega uma TIM na VRAM: CLUT (se houver) e pixels; posicoes em D_8005CD20 */
void func_8001FD50(s32 *tim) {
    s16 clut[4];
    s16 pix[4];
    s32 flags;
    u16 *pos;

    tim++;
    flags = *tim++;
    if (flags & 8) {
        switch (flags & 7) {
        case 0:
        case 1:
            clut[0] = *(u16 *)(D_8005CD20 + 0x10);
            clut[1] = *(u16 *)(D_8005CD20 + 0x14);
            clut[2] = *(u16 *)((u8 *)tim + 8);
            clut[3] = *(u16 *)((u8 *)tim + 0xA);
            LoadImage(clut, (u8 *)tim + 0xC);
            break;
        }
        tim = (s32 *)((u8 *)tim + *tim);
    }
    pix[0] = *(u16 *)(D_8005CD20 + 0x8);
    pix[1] = *(u16 *)(D_8005CD20 + 0xC);
    pix[2] = *(u16 *)((u8 *)tim + 8);
    pix[3] = *(u16 *)((u8 *)tim + 0xA);
    LoadImage(pix, (u8 *)tim + 0xC);
    pos = (u16 *)D_8005CD20;
    pos[0] = pix[2];
    pos[1] = pix[3];
}
