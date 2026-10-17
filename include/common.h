#ifndef COMMON_H
#define COMMON_H

#include "include_asm.h"

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

/* dado fora da area pequena: o gcc nao usa $gp para ele mesmo se for
 * pequeno (com -G8 o gcc usaria $gp para qualquer extern de ate 8 bytes) */
#define NOT_GP __attribute__((section(".data")))

#ifndef NULL
#define NULL 0
#endif

#include "types.h"

#endif /* COMMON_H */
