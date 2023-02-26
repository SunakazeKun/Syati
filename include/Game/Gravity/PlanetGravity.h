#pragma once

#include "revolution.h"
#include "JSystem.h"

/* FINISHED */

// Gravity vector calculation flags
#define GRAVITY_TYPE_NORMAL 1
#define GRAVITY_TYPE_SHADOW 2
#define GRAVITY_TYPE_MAGNET 4
#define GRAVITY_TYPE_MARIO_LAUNCHER 8

// Gravity power types
#define GRAVITY_POWER_LIGHT 0
#define GRAVITY_POWER_NORMAL 1
#define GRAVITY_POWER_HEAVY 2

class PlanetGravity {
public:
	PlanetGravity();

	virtual void updateMtx(const TMtx34f &rMtx);
	virtual bool calcOwnGravityVector(TVec3f *pDest, f32 *pScalar, const TVec3f &rPosition) const;

	void calcGravity(TVec3f *pDest, const TVec3f &rPosition) const;
	void calcGravityFromMassPosition(TVec3f *pDirection, f32 *pScalar, const TVec3f &rPosition, const TVec3f &rMassPosition) const;

	bool isInRangeSquare(f32 radius) const;
	bool isInRangeDistance(f32 radius) const;

	void setPriority(s32 priority);
	void updateIdentityMtx();

	f32 mRange;          // _4
	f32 mDistant;        // _8
	s32 mPriority;       // _C
	s32 mGravityId;      // _10
	const void* mHost;   // _14
	u32 mGravityType;    // _18
	u32 mGravityPower;   // _1C
	bool mActivated;     // _20
	bool mIsInverse;     // _21
	bool mIsZero;        // _22
	bool mValidFollower; // _23
	bool mIsRegistered;  // _24
	bool mAppeared;      // _25
};
