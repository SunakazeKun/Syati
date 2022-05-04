#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

class SoundEmitterCube : public AreaObj {
public:
	SoundEmitterCube(const char *pName);

	virtual ~SoundEmitterCube();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();

	u32* mSound; // _48
	TVec3f mSoundPos; // _4C
};
