#pragma once

#include "revolution.h"
#include "Game/Gravity/PlanetGravity.h"

/* FINISHED */

class PointGravity : public PlanetGravity {
public:
	PointGravity();

	virtual void updateMtx(const TMtx34f &rMtx);
	virtual bool calcOwnGravityVector(TVec3f *pDest, f32 *pScalar, const TVec3f &rPosition) const;

	TVec3f mLocalPos;  // _28
	TVec3f mGlobalPos; // _34
};
