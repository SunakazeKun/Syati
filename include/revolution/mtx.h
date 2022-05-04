#ifndef __REVOLUTION_MTX_H
#define __REVOLUTION_MTX_H

#include "revolution/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
* General matrix
*/
void PSMTXIdentity(Mtx matrix);
void PSMTXCopy(const Mtx src, Mtx dest);
void PSMTXConcat(const Mtx srcA, const Mtx srcB, Mtx dest);
u32 PSMTXInverse(const Mtx src, Mtx dest);
u32 PSMTXInvXpose(const Mtx src, Mtx dest);

/*
* Matrix-vector
*/
void PSMTXMultVec(const Mtx matrix, const Vec *src, Vec *dest);
void PSMTXMultVecSR(const Mtx matrix, const Vec *src, Vec *dest);
void PSMTXMultVecArraySR(const Mtx matrix, const Vec *src, Vec *dest, u32 count);

/*
* Model matrix
*/
void PSMTXQuat(Mtx dest, const Quaternion *quat);

void PSMTXTrans(Mtx matrix, f32 x, f32 y, f32 z);
void PSMTXTransApply(const Mtx src, Mtx dest, f32 x, f32 y, f32 z);
void PSMTXScale(Mtx matrix, f32 x, f32 y, f32 z);
void PSMTXScaleApply(const Mtx src, Mtx dest, f32 x, f32 y, f32 z);

void PSMTXRotRad(Mtx matrix, char axis, f32 rad);
void PSMTXRotTrig(Mtx matrix, char axis, f32 sinA, f32 cosA);
void PSMTXRotAxisRad(Mtx matrix, const Vec* axis, f32 rad);

/*
* View matrix
*/
void C_MTXLookAt(Mtx dest, const Vec *cameraPos, const Vec *cameraUp, const Vec *target);

/*
* Projection matrix
*/
void C_MTXPerspective(Mtx44 dest, f32 fovy, f32 aspect, f32 near, f32 far);
void C_MTXOrtho(Mtx44 dest, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far);

/*
* Texture projection matrix
*/
void C_MTXLightPerspective(Mtx dest, f32 fovy, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT);
void C_MTXLightOrtho(Mtx dest, f32 top, f32 bottom, f32 left, f32 right, f32 scaleS, f32 scaleT, f32 transS, f32 transT);

/*
* Vector section
*/
f32 C_VECMag(const Vec *vec);

void PSVECAdd(const Vec *srcA, const Vec *srcB, Vec *dest);
void PSVECSubtract(const Vec *srcA, const Vec *srcB, Vec *dest);
void PSVECScale(const Vec *src, Vec *dest, f32 scale);
void PSVECNormalize(const Vec *srcA, Vec *dest);
f32 PSVECMag(const Vec *vec);
f32 PSVECDotProduct(const Vec *srcA, const Vec *srcB);
void PSVECCrossProduct(const Vec *srcA, const Vec *srcB, Vec *dest);
f32 PSVECDistance(const Vec *srcA, const Vec *srcB);

/*
* Quaternion section
*/
void C_QUATMtx(Quaternion *dest, const Mtx matrix);
void C_QUATSlerp(const Quaternion *srcA, const Quaternion *srcB, Quaternion *dest, f32 val);

void PSQUATMultiply(const Quaternion *srcA, const Quaternion *srcB, Quaternion *dest);
f32 PSQUATDotProduct(const Quaternion *srcA, const Quaternion *srcB);

/*
* 4x4 general matrix section
*/
void PSMTX44Identity(Mtx44 matrix);
void PSMTX44Copy(const Mtx44 src, Mtx44 dest);

#ifdef __cplusplus
}
#endif

#endif // __REVOLUTION_MTX_H
