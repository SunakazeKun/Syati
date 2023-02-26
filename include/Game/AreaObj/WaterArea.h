#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class WaterArea : public AreaObj {
public:
	WaterArea(const char *pName);

	virtual ~WaterArea();
	virtual void init(const JMapInfoIter &rIter);
};

class WaterAreaMgr : public AreaObjMgr {
public:
	WaterAreaMgr(s32 size, const char *pName);

	virtual ~WaterAreaMgr();
};
