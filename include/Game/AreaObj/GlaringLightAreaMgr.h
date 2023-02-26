#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class GlaringLightAreaMgr : public AreaObjMgr {
public:
	GlaringLightAreaMgr(s32 size, const char *pName);

	virtual ~GlaringLightAreaMgr();
};
