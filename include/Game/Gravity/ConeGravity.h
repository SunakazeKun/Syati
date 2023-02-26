#pragma once

#include "revolution.h"
#include "Game/Gravity/PlanetGravity.h"

/* FINISHED */

class ConeGravity : public PlanetGravity {
	ConeGravity();

	virtual void updateMtx(const TMtx34f &rMtx);
	virtual bool calcOwnGravityVector(TVec3f *pDest, f32 *pScalar, const TVec3f &rPosition) const;

	void setLocalMatrix(const TMtx34f &rMtx);
	void setEnableBottom(bool val);
	void setTopCutRate(f32 val);

	TMtx34f mLocalMtx;  // _28
	TMtx34f mGlobalMtx; // _58
	f32 _88;            // unused
	f32 _8C;            // unused
	f32 mRadius;        // _90
	bool mEnableBottom; // _94
	f32 mTopCutRate;    // _98
};
