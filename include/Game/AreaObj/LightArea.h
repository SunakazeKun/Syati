#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"
#include "Game/Map/LightZoneDataHolder.h"

class LightArea : public AreaObj {
public:
	LightArea(const char *pName);

	virtual ~LightArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual const char* getManagerName();

	bool _48;
};

class LightAreaHolder : public AreaObjMgr {
public:
	LightAreaHolder(s32 size, const char *pName);

	virtual ~LightAreaHolder();
	virtual void initAfterPlacement();

	void tryFindLightID(const TVec3f &, ZoneLightID *) const;
};
