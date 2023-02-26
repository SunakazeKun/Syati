#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class CumulativeTimerSwitchArea : public AreaObj {
public:
	CumulativeTimerSwitchArea(const char *pName);

	virtual ~CumulativeTimerSwitchArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();

	s32 mTimer; // _48
};
