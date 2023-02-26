#pragma once

#include "revolution.h"
#include "Game/Gravity/PlanetGravity.h"
#include "Game/Util/Array.h"

/* FINISHED */

class WireGravity : public PlanetGravity {
public:
	WireGravity();

	virtual bool calcOwnGravityVector(TVec3f *pDest, f32 *pScalar, const TVec3f &rPosition) const;

	void setPointListSize(u32 listSize);
	void addPoint(const TVec3f &rPoint);

	MR::AssignableArray<TVec3f> mPoints; // _28
	s32 mCount;                          // _30
};
