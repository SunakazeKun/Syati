#ifndef __REVOLUTION_TYPES_H
#define __REVOLUTION_TYPES_H

// Primary data types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef float f32;
typedef double f64;

// Volatile data types
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;
typedef volatile f32 vf32;
typedef volatile f64 vf64;

// Null-pointer alias
#define NULL 0

// 32-bit floating point 3D vector
typedef struct {
	f32 x, y, z;
} Vec;

// Signed 16-bit integer 3D vector
typedef struct {
	s16 x, y, z;
} S16Vec;

// Quaternion & pointer
typedef struct {
	f32 x, y, z, w;
} Quaternion;

// 3x4 matrix & pointer
typedef f32 Mtx[3][4];
typedef f32 (*MtxPtr)[4];

// 4x3 reordered matrix & pointer
typedef f32 ROMtx[4][3];
typedef f32 (*ROMtxPtr)[3];

// 3x3 matrix & pointer
typedef f32 Mtx33[3][3];
typedef f32(*Mtx33Ptr)[3];

// 4x4 matrix & pointer
typedef f32 Mtx44[4][4];
typedef f32 (*Mtx44Ptr)[4];

#endif // __REVOLUTION_TYPES_H
