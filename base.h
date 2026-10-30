/*
 * base.h
 * Common definitions and utilities.
 *
 * Copyright (c) 2026 Alex Cross
 */

#ifndef ACD_BASE_H
#define ACD_BASE_H

#include <bits/time.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

/* Primative Types */
typedef char                s8;
typedef short               s16;
typedef int                 s32;
typedef long int            s64;

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long int   u64;

typedef char                b8;
typedef int                 b32;

typedef float               f32;
typedef double              f64;

static_assert(sizeof(s8) == 1, "s8 is required to be 1 byte");
static_assert(sizeof(s16) == 2, "s16 is required to be 2 bytes");
static_assert(sizeof(s32) == 4, "s32 is required to be 4 bytes");
static_assert(sizeof(s64) == 8, "s64 is required to be 8 bytes");

static_assert(sizeof(u8) == 1, "s8 is required to be 1 byte");
static_assert(sizeof(u16) == 2, "s16 is required to be 2 bytes");
static_assert(sizeof(u32) == 4, "s32 is required to be 4 bytes");
static_assert(sizeof(u64) == 8, "s64 is required to be 8 bytes");

static_assert(sizeof(b8) == 1, "b8 is required to be 1 bytes");
static_assert(sizeof(b32) == 4, "b32 is required to be 4 bytes");

static_assert(sizeof(f32) == 4, "f32 is required to be 4 bytes");
static_assert(sizeof(f64) == 8, "f64 is required to be 8 bytes");

/* Utility Macros */
#define UNUSED(x) ((void)x)
#define ARRAY_LEN(a) (sizeof(a) / sizeof((a)[0]))

/*
 * This macros have niche use cases
 * The compiler optimizations will do most of this automatically and
 * it is hard to predict if something is going to be more likely over
 * the lifetime of a program.
 * Some use cases are after rigorous benchmarking
 */
#define LIKELY(x)   __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

/* Global Defines */
#define CACHELINE 64

#define U32_MAX     4294967295
#define S32_MAX     2147483647
#define S32_MIN     -2147483648

#define U64_MAX     18446744073709551615
#define S64_MAX     9223372036854775807
#define S64_MIN     -9223372036854775808

#endif
