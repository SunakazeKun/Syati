#pragma once

#include "revolution.h"
#include "Game/Gravity/PlanetGravity.h"

class SegmentGravity : public PlanetGravity {
public:
	SegmentGravity();

	virtual void updateMtx(const TMtx34f &rMtx);
	virtual bool calcOwnGravityVector(TVec3f *pDest, f32 *pScalar, const TVec3f &rPosition) const;

	void setGravityPoint(u32 index, const TVec3f &rGravityPoint);
	void setSideVector(const TVec3f &rSideVec);
	void setValidSideDegree(f32 val);
	void setEdgeValid(u32 index, bool val);
	void updateLocalParam();

	TVec3f mLocalGravityPoints[2];   // _28
	TVec3f mGlobalGravityPoints[2];  // _40
	TVec3f mLocalSideVec;            // _58
	TVec3f mOrthonormalLocalSideVec; // _64
	TVec3f mGlobalSideVec;           // _70
	TVec3f mSegmentDir;              // _7C
	f32 mSegmentLength;              // _88
	f32 mValidSideDegree;            // _8C
	f32 mValidSideCos;               // _90
	f32 _94[2];
	bool mValidEdges[2];             // _9C
};
