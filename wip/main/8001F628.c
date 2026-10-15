/* 4 bytes sem alinhamento (o gcc copia com lwl/lwr) */
typedef struct {
    u8 b[4];
} Bytes4;

void func_8001F628(Bytes4 *arg0) {
    *(Bytes4 *)((u8 *)D_8005CD10 + 0x28) = *arg0;
}
