#pragma once

#include "revolution.h"
#include "JSystem.h"

namespace MR {
	void makeMtxRotate(MtxPtr, s16, s16, s16);
	void makeMtxRotate(MtxPtr, f32, f32, f32);
	void makeMtxRotate(MtxPtr, const TVec3f &);
	void makeMtxRotateY(MtxPtr, f32);
	void makeMtxTR(MtxPtr, f32, f32, f32, f32, f32, f32);
	void makeMtxTR(MtxPtr, const TVec3f &, const TVec3f &);
	void makeMtxTransRotateY(MtxPtr, f32, f32, f32, f32);
	void rotateMtxLocalX(MtxPtr, f32);
	void rotateMtxLocalY(MtxPtr, f32);
	void rotateMtxLocalZ(MtxPtr, f32);
	void rotateMtxLocalXDegree(MtxPtr, f32);
	void rotateMtxLocalYDegree(MtxPtr, f32);
	void rotateMtxLocalZDegree(MtxPtr, f32);
	void preScaleMtx(MtxPtr, f32);
	void preScaleMtx(MtxPtr, const TVec3f &);
	void preScaleMtx(MtxPtr, f32, f32, f32);
	void scaleMtxToLocalMtx(MtxPtr, MtxPtr, MtxPtr, const TVec3f &);
	void scaleMtxToLocalMtx(MtxPtr, MtxPtr, const TVec3f &);
	void scaleMtxToDir(TMtx34f *, const TVec3f &, const TVec3f &);
	void makeMtxTRS(MtxPtr, f32, f32, f32, f32, f32, f32, f32, f32, f32);
	void makeMtxTRS(MtxPtr, const TVec3f &, const TVec3f &, const TVec3f &);
	void setMtxAxisXYZ(MtxPtr, const TVec3f &, const TVec3f &, const TVec3f &);
	void flattenMtx(MtxPtr, MtxPtr, const TVec3f &);
	void flattenMtx(MtxPtr, const TVec3f &);
	void blendMtxRotate(MtxPtr, MtxPtr, f32, MtxPtr);
	void blendMtxRotateSlerp(MtxPtr, MtxPtr, f32, MtxPtr);
	void blendMtx(MtxPtr, MtxPtr, f32, MtxPtr);
	void makeMtxWithoutScale(TMtx34f *, const TMtx34f &);
	void makeSRTFromMtxPtr(TVec3f *pTranslate, TVec3f *pEuler, TVec3f *pScale, MtxPtr pMtx, bool);
	void makeRTFromMtxPtr(TVec3f *pTranslate, TVec3f *pEuler, MtxPtr pMtx, bool);
	void makeMtxSideUp(TMtx34f *, const TVec3f &, const TVec3f &);
	void makeMtxSideUpPos(TMtx34f *, const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxSideFront(TMtx34f *, const TVec3f &, const TVec3f &);
	void makeMtxUpSide(TMtx34f *, const TVec3f &, const TVec3f &);
	void makeMtxUpSidePos(TMtx34f *, const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxUpFront(TMtx34f *, const TVec3f &, const TVec3f &);
	void makeMtxUpFrontPos(TMtx34f *, const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxFrontSidePos(TMtx34f *, const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxFrontUp(TMtx34f *, const TVec3f &, const TVec3f &);
	void makeMtxFrontUpPos(TMtx34f *, const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxUpNoSupport(TMtx34f *, const TVec3f &);
	void makeMtxUpNoSupportPos(TMtx34f *, const TVec3f &, const TVec3f &);
	void makeMtxFrontNoSupport(TMtx34f *, const TVec3f &);
	void makeMtxFrontNoSupportPos(TMtx34f *, const TVec3f &, const TVec3f &);
	void orthogonalize(TMtx34f *);
	void turnMtxToXDirRate(TMtx34f *, const TVec3f &, f32);
	void turnMtxToXDirDegree(TMtx34f *, const TVec3f &, f32);
	void turnMtxToYDirRate(TMtx34f *, const TVec3f &, f32);
	void turnMtxToYDirDegree(TMtx34f *, const TVec3f &, f32);
	void turnMtxToLocalDirDegree(TMtx34f *, const TVec3f &, const TVec3f &, f32);
	void makeMtxMoment(TMtx34f *, const TVec3f &);

	void setMtxTrans(MtxPtr, const TVec3f &);
	void setMtxTrans(MtxPtr, f32, f32, f32);
	void addTransMtx(MtxPtr, const TVec3f &);
	void addTransMtxLocal(MtxPtr, const TVec3f &);
	void addTransMtxLocalX(MtxPtr, f32);
	void addTransMtxLocalY(MtxPtr, f32);
	void addTransMtxLocalZ(MtxPtr, f32);
	void extractMtxXDir(MtxPtr, TVec3f *);
	void extractMtxYDir(MtxPtr, TVec3f *);
	void extractMtxZDir(MtxPtr, TVec3f *);
	void extractMtxXYZDir(MtxPtr, TVec3f *, TVec3f *, TVec3f *);
	void extractMtxTrans(MtxPtr, TVec3f *);

	bool isSameMtx(MtxPtr, MtxPtr);
	bool isSameMtxRot(MtxPtr, MtxPtr);
	bool isRotAxisY(MtxPtr, MtxPtr);
	void calcMtxRotAxis(TVec3f *, MtxPtr, MtxPtr);
	MtxPtr tmpMtxTrans(const TVec3f &);
	MtxPtr tmpMtxScale(f32, f32, f32);
	MtxPtr tmpMtxRotXRad(f32);
	MtxPtr tmpMtxRotYRad(f32);
	MtxPtr tmpMtxRotZRad(f32);
	MtxPtr tmpMtxRotXDeg(f32);
	MtxPtr tmpMtxRotYDeg(f32);
	MtxPtr tmpMtxRotZDeg(f32);
	void orderRotateMtx(s16, const TVec3f &, MtxPtr);
};
