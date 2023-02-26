#pragma once

#include "revolution.h"
#include "Game/Gravity/PlanetGravity.h"

/* FINISHED */

class DiskTorusGravity : public PlanetGravity {
public:
	DiskTorusGravity();

	virtual void updateMtx(const TMtx34f &rMtx);
	virtual bool calcOwnGravityVector(TVec3f *pDest, f32 *pScalar, const TVec3f &rPosition) const;

	void setPosition(const TVec3f &rPosition);
	void setDirection(const TVec3f &rDirection);
	void setRadius(f32 val);
	void setDiskRadius(f32 val);
	void setEdgeType(s32 val);
	void setBothSide(bool val);

	TVec3f mLocalPos;     // _28
	TVec3f mGlobalPos;    // _34
	TVec3f mLocalDir;     // _40
	TVec3f mGlobalDir;    // _4C
	f32 mLocalRadius;     // _58
	f32 mGlobalRadius;    // _5C
	f32 mDiskRadius;      // _60
	s32 mEdgeType;        // _64
	bool mEnableBothSide; // _68
};
