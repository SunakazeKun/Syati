#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Gravity/GravityInfo.h"

/* FINISHED */

class PlanetGravityManager : public NameObj {
public:
	PlanetGravityManager(const char *pName);

	virtual ~PlanetGravityManager();
	virtual void init(const JMapInfoIter &rIter);

	bool calcTotalGravityVector(TVec3f *pGravity, GravityInfo *pInfo, const TVec3f &rPosition, u32 gravityType, u32 requester) const;
	void registerGravity(PlanetGravity *pGravity);

	PlanetGravity* mGravities[128]; // _C
	s32 mNumGravities;              // _20C
};
