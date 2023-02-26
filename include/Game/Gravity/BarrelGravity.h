#pragma once

#include "revolution.h"
#include "Game/Gravity/PlanetGravity.h"

/* FINISHED */

class BarrelGravity : public PlanetGravity {
public:
	BarrelGravity();

	virtual void updateMtx(const TMtx34f &rMtx);
	virtual bool calcOwnGravityVector(TVec3f *pDest, f32 *pScalar, const TVec3f &rPosition) const;

	void setLocalPosition(const TVec3f &rLocalPos);
	void setUpDirection(const TVec3f &rUpDir);
	void setRadius(f32 val);
	void setUnusedArg0(f32 val);
	void setInwardsThreshold(f32 val);

	TVec3f mLocalPos;      // _28
	TVec3f mGlobalPos;     // _34
	TVec3f mLocalUpDir;    // _40
	TVec3f mGlobalUpDir;   // _4C
	f32 mLocalRadius;      // _58
	f32 mGlobalRadius;     // _5C
	f32 mUnusedArg0;       // _60
	f32 mInwardsThreshold; // _64
};
