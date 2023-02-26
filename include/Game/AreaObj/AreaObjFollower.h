#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"
#include "Game/Util/BaseMatrixFollowTargetHolder.h"

/* FINISHED */

class AreaObjFollower : public BaseMatrixFollower {
public:
	AreaObjFollower(AreaObj *pArea, const JMapInfoIter &rIter);

	virtual void update();

	TMtx34f mFollowMtx;     // _14
	AreaObj* mFollowerArea; // _44
};

namespace MR {
	bool addBaseMatrixFollowerAreaObj(AreaObj *pArea, const JMapInfoIter &rIter);
};
