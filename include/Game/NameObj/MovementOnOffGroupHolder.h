#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"

/* FINISHED */

class MovementOnOffGroupHolder : public NameObj {
public:
	MovementOnOffGroupHolder(const char *pName);

	virtual ~MovementOnOffGroupHolder();

	NameObj* mObjs[32]; // _14
	s32 mNumObjs;       // _94
};
