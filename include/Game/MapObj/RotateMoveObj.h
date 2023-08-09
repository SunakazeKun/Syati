#pragma once

#include "Game/MapObj/MapObjActor.h"

class RotateMoveObj : public MapObjActor {
public:
	inline RotateMoveObj(const char *pName) : MapObjActor(pName) {}

	virtual ~RotateMoveObj();
	virtual void init(const JMapInfoIter &rIter);
	virtual void initCaseUseSwitchB(const MapObjActorInitInfo &rInfo);
	virtual void initCaseNoUseSwitchB(const MapObjActorInitInfo &rInfo);

	void setStateMove();
	void exeMove();
	void exeStop();
};

namespace NrvRotateMoveObj {
	NERVE(HostTypeWaitForPlayerOn);
	NERVE(HostTypeWait);
	NERVE(HostTypeMove);
	NERVE(HostTypeStop);
};
