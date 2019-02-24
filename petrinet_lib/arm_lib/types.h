#pragma once
#include "stdint.h"
//#include "common.h"
//typedef uint8_t byte;

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef void (*voidfunc )( );

typedef uint16_t WORD;
typedef uint8_t BYTE;
typedef uint8_t u8;
typedef uint32_t u32;
typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;
typedef unsigned long ulong;
typedef unsigned long long u64;
typedef signed long long s64;
typedef signed short i16;
typedef unsigned short u16;

#define NULL_FUNCTION (function *)NULL
