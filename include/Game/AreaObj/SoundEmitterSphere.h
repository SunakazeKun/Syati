#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

class SoundEmitterSphere : public AreaObj {
public:
	SoundEmitterSphere(const char *pName);

	virtual ~SoundEmitterSphere();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();

	u32* mSound; // _48
	TVec3f mSoundPos; // _4C
};
