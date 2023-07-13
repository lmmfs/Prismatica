#pragma once

// Unsigned int types
typedef unsigned char u8; 
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Floating point types
typedef float f32;
typedef double f64;

// Bolean types
typedef int b32;
typedef char b8;

// Propely define static assertions
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _static_assert
#else
#define STATIC_ASSERT static_assert
#endif


#define TRUE 1
#define FALSE 0
