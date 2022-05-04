#pragma once

#include "revolution.h"
#include "Game/AreaObj/SoundEmitterCube.h"

class SoundEmitterCubeWorldMapSync : public SoundEmitterCube {
public:
	SoundEmitterCubeWorldMapSync(const char *pName);

	virtual ~SoundEmitterCubeWorldMapSync();
	virtual void init(const JMapInfoIter &rIter);
};
