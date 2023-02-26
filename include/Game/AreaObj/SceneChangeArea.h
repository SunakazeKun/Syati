#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class SceneChangeArea : public AreaObj {
public:
	SceneChangeArea(const char *pName);

	virtual ~SceneChangeArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
};
