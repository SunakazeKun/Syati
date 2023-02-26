#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class SpinGuidanceArea : public AreaObj {
public:
	SpinGuidanceArea(const char *pName);

	virtual ~SpinGuidanceArea();
	virtual void init(const JMapInfoIter &rIter);
};
