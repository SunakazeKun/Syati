#pragma once

#include "revolution.h"
#include "Game/Util/TriggerChecker.h"

class GameSystemDimmingWatcher {
public:
	GameSystemDimmingWatcher();

	void update();

	TriggerChecker* mTriggerChecker; // _0
	bool _4;
	bool _5;
};
