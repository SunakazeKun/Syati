#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class MessageArea : public AreaObj {
public:
	MessageArea(const char *pName);

	virtual ~MessageArea();
	virtual void init(const JMapInfoIter &rIter);

	s32 mZoneId;
};
