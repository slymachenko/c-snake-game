#ifndef C_SNAKE_GAME_BASE_DEFS_H
#define C_SNAKE_GAME_BASE_DEFS_H

#include <stdint.h>

// fixed-width typedefs
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef i8 b8;
typedef i32 b32;

typedef float f32;
typedef double f64;

_Static_assert(sizeof(f32) == 4, "f32 must be 32-bit IEEE-754 float");
_Static_assert(sizeof(f64) == 8, "f64 must be 64-bit IEEE-754 double");

// byte-size macros
#define KiB(n) ((u64)(n) << 10)
#define MiB(n) ((u64)(n) << 20)
#define GiB(n) ((u64)(n) << 30)

#endif // C_SNAKE_GAME_BASE_DEFS_H
