#pragma once

#include "revolution.h"
#include "JSystem.h"

void PSVECKillElement(const Vec *, const Vec *, const Vec *);

namespace MR {
	void initAcosTable();
	f32 acosEx(f32);
	f32 getRandom();
	f32 getRandom(f32, f32);
	s32 getRandom(s32, s32);
	f32 getRandomDegree();
	bool isHalfProbability();
	f32 getSignHalfProbability();
	void getRandomVector(TVec3f *, f32);
	void addRandomVector(TVec3f *, const TVec3f &, f32);
	void turnRandomVector(TVec3f *, const TVec3f &, f32);
	f32 getInterpolateValue(f32, f32, f32);
	f32 getLinerValue(f32, f32, f32, f32);
	f32 getLinerValueFromMinMax(f32, f32, f32, f32, f32);

	f32 getEaseInValue(f32, f32, f32, f32);
	f32 getEaseOutValue(f32, f32, f32, f32);
	f32 getEaseInOutValue(f32, f32, f32, f32);

	f32 getScaleWithReactionValueZeroToOne(f32, f32, f32);
	f32 getConvergeVibrationValue(f32, f32, f32, f32, f32);
	f32 getReduceVibrationValue(f32, f32, f32, f32, f32);
	void makeAxisFrontUp(TVec3f *, TVec3f *, const TVec3f &, const TVec3f &);
	void makeAxisFrontSide(TVec3f *, TVec3f *, const TVec3f &, const TVec3f &);
	void makeAxisUpFront(TVec3f *, TVec3f *, const TVec3f &, const TVec3f &);
	void makeAxisUpSide(TVec3f *, TVec3f *, const TVec3f &, const TVec3f &);
	void makeAxisVerticalZX(TVec3f *, const TVec3f &);

	bool makeAxisCrossPlane(TVec3f *, TVec3f *, const TVec3f &);
	bool makeAxisAndCosignVecToVec(TVec3f *, f32 *, const TVec3f &, const TVec3f &);
	f32 calcPerpendicFootToLine(TVec3f *, const TVec3f &, const TVec3f &, const TVec3f &);
	f32 calcPerpendicFootToLineInside(TVec3f *, const TVec3f &, const TVec3f &, const TVec3f &);
	bool checkHitSegmentSphere(const TVec3f &, const TVec3f &, const TVec3f &, f32, TVec3f *);
	bool checkHitSemilinePlane(TVec3f *, const TVec3f &, const TVec3f &, const TVec3f &, const TVec3f &);
	bool calcReboundVelocity(TVec3f *, const TVec3f &, f32);
	bool calcReboundVelocity(TVec3f *, const TVec3f &, f32, f32);
	void calcParabolicFunctionParam(f32 *, f32 *, f32, f32);
	void makeQuatRotateRadian(TQuat4f *, const TVec3f &);
	void makeQuatRotateDegree(TQuat4f *, const TVec3f &);
	void makeQuatFromVec(TQuat4f *, const TVec3f &, const TVec3f &);
	void makeQuatSideUp(TQuat4f *, const TVec3f &, const TVec3f &);
	void makeQuatUpFront(TQuat4f *, const TVec3f &, const TVec3f &);
	void makeQuatFrontUp(TQuat4f *, const TVec3f &, const TVec3f &);
	void makeQuatUpNoSupport(TQuat4f *, const TVec3f &);
	void blendQuatUpFront(TQuat4f *, const TVec3f &, const TVec3f &, f32, f32);
	void blendQuatFrontUp(TQuat4f *, const TVec3f &, const TVec3f &, f32, f32);
	void rotateQuatMoment(TQuat4f *, const TVec3f &);
	void rotateQuatRollBall(TQuat4f *, const TVec3f &, const TVec3f &, f32);

	// return type correct?
	void turnQuat(TQuat4f *, const TQuat4f &, const TVec3f &, const TVec3f &, f32);
	void turnQuatXDirRad(TQuat4f *, const TQuat4f &, const TVec3f &, f32);
	void turnQuatYDirRad(TQuat4f *, const TQuat4f &, const TVec3f &, f32);
	void turnQuatZDirRad(TQuat4f *, const TQuat4f &, const TVec3f &, f32);
	void turnQuatXDirRate(TQuat4f *, const TQuat4f &, const TVec3f &, f32);
	void turnQuatYDirRate(TQuat4f *, const TQuat4f &, const TVec3f &, f32);
	void turnQuatZDirRate(TQuat4f *, const TQuat4f &, const TVec3f &, f32);
	f32 sign(f32);
	void f32ToFixed16(TVec3s *, const TVec3f &, u8);
	void fixed16Tof32(TVec3f *, const TVec3s &, u8);

	void clampVecAngleDeg(TVec3f *, const TVec3f &, f32);
	void clampLength(TVec3f *, const TVec3f &, f32);
	f32 convergeRadian(f32, f32, f32);
	bool isInRange(f32, f32, f32);

	void rotateVecDegree(TVec3f *, const TVec3f &, f32);
	void rotateVecDegree(TVec3f *, const TVec3f &, const TVec3f &, f32);
	void rotateVecRadian(TVec3f *, const TVec3f &, f32);
	void rotateVecRadian(TVec3f *, const TVec3f &, const TVec3f &, f32);

	void calcLocalVec(TVec3f *, MtxPtr);
	void normalize(TVec2f *);
	void normalize(TVec3f *);
	void normalize(TVec2f *, const TVec2f &);
	void normalize(TVec3f *, const TVec3f &);
	void normalizeOrZero(TVec2f *);
	void normalizeOrZero(TVec3f *);
	void normalizeOrZero(const TVec3f &, TVec3f *);
	void normalize(f32, f32, f32);
	void normalizeAbs(f32, f32, f32);
	void normalizeAngleAbs(f32);
	void separateScalarAndDirection(f32 *, TVec2f *, const TVec2f &);
	void separateScalarAndDirection(f32 *, TVec3f *, const TVec3f &);
	bool turnVecToVecCos(TVec3f *, const TVec3f &, const TVec3f &, f32, const TVec3f &, f32);
	bool turnVecToVecCosOnPlane(TVec3f *, const TVec3f &, const TVec3f &, const TVec3f &, f32);
	bool turnVecToVecCosOnPlane(TVec3f *, const TVec3f &, const TVec3f &, f32);
	f32 turnVecToVecRadian(TVec3f *, const TVec3f &, const TVec3f &, f32, const TVec3f &);
	f32 turnVecToVecDegree(TVec3f *, const TVec3f &, const TVec3f &, f32, const TVec3f &);
	void calcMomentRollBall(TVec3f *, const TVec3f &, const TVec3f &, f32);
	bool calcReflectionVector(TVec3f *, const TVec3f &, f32, f32);
	bool isSameDirection(const TVec3f &, const TVec3f &, f32);
	bool isOppositeDirection(const TVec3f &, const TVec3f &, f32);
	bool isNearZero(f32, f32);
	bool isNearZero(const TVec3f &, f32);
	bool isNearZero(const TVec2f &, f32);
	f32 diffAngleAbs(f32, f32);
	bool isAngleBetween(f32, f32, f32);
	bool blendAngle(f32, f32, f32);
	f32 lerp(u8, u8, f32);
	f32 lerp(f32, f32, f32);
	f32 lerp(GXColor, GXColor, f32);
	void sortSmall(long, f32 *, long *);
	void sortSmall(long, u32 *, long *);
	void PSvecBlend(const TVec3f *, const TVec3f *, f32, f32);
	void vecBlend(TVec3f *, const TVec3f &, const TVec3f &, f32);
	void vecBlendNormal(TVec3f *, const TVec3f &, const TVec3f &, f32);
	void vecBlendSphere(TVec3f *, const TVec3f &, const TVec3f &, f32);
	void blendColor(GXColor *, GXColor const &, GXColor const &, f32);
	void turnVecToPlane(TVec3f *, const TVec3f &, const TVec3f &);
	void getRotatedAxisY(TVec3f *, const TVec3f &);
	void getRotatedAxisZ(TVec3f *, const TVec3f &);
	f32 getMaxElement(const TVec3f &);
	f32 getMaxAbsElement(const TVec3f &);
	u32 getMaxElementIndex(const TVec3f &);
	u32 getMaxAbsElementIndex(const TVec3f &);
	f32 diffAngleAbsFast(const TVec3f &, const TVec3f &);
	f32 diffAngleAbs(const TVec3f &, const TVec3f &);
	f32 diffAngleAbs(const TVec2f &, const TVec2f &);
	f32 diffAngleSigned(const TVec3f &, const TVec3f &, const TVec3f &);
	f32 diffAngleAbsHorizontal(const TVec3f &, const TVec3f &, const TVec3f &);
	f32 diffAngleSignedHorizontal(const TVec3f &, const TVec3f &, const TVec3f &);
	bool isNearAngleRadian(const TVec3f &, const TVec3f &, f32);
	bool isNearAngleDegree(const TVec3f &, const TVec3f &, f32);
	bool isNearAngleRadianHV(const TVec3f &, const TVec3f &, const TVec3f &, f32, f32);
	bool isNearAngleDegreeHV(const TVec3f &, const TVec3f &, const TVec3f &, f32, f32);
	void createBoundingBox(const TVec3f *, u32, TVec3f *, TVec3f *);
	bool isNormalize(const TVec3f &, f32);
	void setNan(TVec3f &);
	bool isNan(const TVec3f &);
	f32 calcRotateY(f32, f32);

	void vecKillElement(const TVec3f &, const TVec3f &, TVec3f *);
	void vecRotAxis(const TVec3f &, const TVec3f &, const TVec3f &, const TVec3f *, f32);
	void rotAxisVecRad(const TVec3f &, const TVec3f &, const TVec3f *, f32);
	void getFootPoint(const TVec3f &, const TVec3f &, const TVec3f &, const TVec3f *);
	f32 sin(f32);
	f32 sinDegree(f32);
	f32 cos(f32);
	f32 cosDegree(f32);
	f32 min(f32, f32);
	f32 max(f32, f32);
	f32 repeat(f32, f32, f32);
	f32 mod(f32, f32);

	s32 clamp(s32 val, s32 min, s32 max);
	f32 clamp(f32 val, f32 min, f32 max);
};
