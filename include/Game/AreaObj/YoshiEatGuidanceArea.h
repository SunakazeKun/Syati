#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

class YoshiEatGuidanceArea : public AreaObj {
public:
	YoshiEatGuidanceArea(const char *pName);

	virtual ~YoshiEatGuidanceArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
};
