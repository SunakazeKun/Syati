#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActorGroup.h"

class AllLiveActorGroup : public LiveActorGroup {
public:
	AllLiveActorGroup();

	virtual ~AllLiveActorGroup();
	
	void initActorSystemInfo(const JMapInfoIter &rIter);

	s32 _20;
};

namespace MR {
	AllLiveActorGroup* getAllLiveActorGroup();
	void startInitLiveActorSystemInfo();
	void initLiveActorSystemInfo(const JMapInfoIter &rIter);
	void endInitLiveActorSystemInfo();
};
