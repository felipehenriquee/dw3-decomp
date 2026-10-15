/*
 * Macros usadas pelo codigo gerado pelo m2c em modo --valid-syntax.
 * Codigo que ja foi limpo nao deve precisar deste arquivo.
 */
#ifndef M2C_H
#define M2C_H

#include "common.h"

typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;

/* campo de struct ainda sem tipo: *(type_ptr)((s8 *)expr + offset) */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))

#endif /* M2C_H */
