#pragma once

#include "revolution.h"
#include "Game/MapObj/MapObjActor.h"

class SimpleMapObj : public MapObjActor {
public:
	SimpleMapObj(const char *);

	virtual void init(const JMapInfoIter &);
};