#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

class SoundPlayArea : public AreaObj {
public:
	SoundPlayArea(const char *pName);

	virtual ~SoundPlayArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();

	void setupSoundPos();

	TVec3f mSoundPos; // _48
	bool _54;
	bool _55;
	u32* mSound; // _58
};
