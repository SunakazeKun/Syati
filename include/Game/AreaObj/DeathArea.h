#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class DeathArea : public AreaObj {
public:
	DeathArea(const char *pName);

	virtual ~DeathArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual bool isInVolume(const TVec3f &mTranslation) const;
	virtual const char* getManagerName() const;

	s32 getDeathType() const;
};
