#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class LavaHomeVolcanoFlow : public LiveActor {
public:
	LavaHomeVolcanoFlow(const char *pName);

	virtual ~LavaHomeVolcanoFlow();
	virtual void init(const JMapInfoIter &rIter);
	virtual void startClipped();
	virtual void endClipped();

	void exeWait();
	void exeMove();
};

namespace NrvLavaHomeVolcanoFlow {
	NERVE(HostTypeWait);
	NERVE(HostTypeMove);
	NERVE(HostTypeDone);
};
