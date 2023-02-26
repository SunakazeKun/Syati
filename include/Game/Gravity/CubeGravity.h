#pragma once

#include "revolution.h"
#include "Game/Gravity/PlanetGravity.h"

/* FINISHED */

class CubeGravity : public PlanetGravity {
	CubeGravity();

	virtual void updateMtx(const TMtx34f &rMtx);
	virtual bool calcOwnGravityVector(TVec3f *pDest, f32 *pScalar, const TVec3f &rPosition) const;

	void setCube(const TMtx34f &);
	void calcGravityArea(const TVec3f &rPosition) const;
	void calcFaceGravity(const TVec3f &rPosition, s32, TVec3f *pDest, f32 *pScalar) const;
	void calcEdgeGravity(const TVec3f &rPosition, s32, TVec3f *pDest, f32 *pScalar) const;
	void calcCornerGravity(const TVec3f &rPosition, s32, TVec3f *pDest, f32 *pScalar) const;

	TMtx34f mLocalMtx;  // _28
	TMtx34f mGlobalMtx; // _58
	f32 mExtentX;       // _88
	f32 mExtentY;       // _8C
	f32 mExtentZ;       // _90
	u8 mActiveFaces;    // _94
};
