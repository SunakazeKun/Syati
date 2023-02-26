#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class ShadowColorArea : public AreaObj {
public:
	ShadowColorArea(const char *pName);

	virtual ~ShadowColorArea();
	virtual void init(const JMapInfoIter &rIter);
};
