#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class SpinSwitchArea : public AreaObj {
public:
	SpinSwitchArea(const char *pName);

	virtual ~SpinSwitchArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
};
