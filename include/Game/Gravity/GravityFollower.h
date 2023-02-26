#pragma once

#include "revolution.h"
#include "Game/Gravity/GlobalGravityObj.h"
#include "Game/Util/BaseMatrixFollowTargetHolder.h"

/* FINISHED */

class GravityFollower : public BaseMatrixFollower {
public:
	GravityFollower(GlobalGravityObj *pGravityObj, const JMapInfoIter &rIter);

	virtual void setGravityFollowHost(const NameObj *pHost);
	virtual void update();

	PlanetGravity* mGravity; // _14
};

namespace MR {
	bool addBaseMatrixFollowerGravity(GlobalGravityObj *pGravityObj, const JMapInfoIter &rIter);
};
