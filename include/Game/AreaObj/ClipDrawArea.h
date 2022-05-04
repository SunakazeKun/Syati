#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

class ClipDrawArea : public AreaObj {
public:
	ClipDrawArea(const char *pName);

	virtual ~ClipDrawArea();
	virtual void init(const JMapInfoIter &rIter);
};
