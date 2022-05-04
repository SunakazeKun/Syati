#pragma once

#include "revolution.h"

void JMASinRadian(f32);
void JMASinDegree(f32);
void JMACosRadian(f32);
void JMACosDegree(f32);
void JMAACosRadian(f32);
void JMASqrt(f32);

void JMAEulerToQuat(s16 eulerX, s16 eulerY, s16 eulerZ, Quaternion *dest);
void JMAQuatLerp(const Quaternion *srcA, const Quaternion *srcB, f32 interpolant, Quaternion *dest);

void JMAVECScaleAdd(const Vec *srcForScaling, const Vec *srcAdd, Vec *dest, f32 scale);
void JMAVECLerp(const Vec *srcA, const Vec *srcB, Vec *dest, f32 t);
void JMAMTXApplyScale(const MtxPtr src, MtxPtr dest, f32 scaleX, f32 scaleY, f32 scaleZ);

namespace JMath {
	template<typename T>
	T fastSqrt(T x);

	f32 fastReciprocal(f32 x);

	void gekko_ps_copy12(void *dest, const void *src);
	void gekko_ps_copy16(void *dest, const void *src);
};

namespace JMathInlineVEC {
	void PSVECAdd(const Vec *srcA, const Vec *srcB, Vec *dest);
	void PSVECSubtract(const Vec *srcA, const Vec *srcB, Vec *dest);
};
