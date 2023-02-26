#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class SunLightArea : public AreaObj {
public:
	SunLightArea(const char *pName);

	virtual ~SunLightArea();
	virtual const char* getManagerName() const;
};
