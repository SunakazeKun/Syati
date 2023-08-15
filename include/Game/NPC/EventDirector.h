#pragma once

#include "revolution.h"
#include "JSystem.h"

class EventFunction {
public:
	static bool isStartCometEvent(const char *);
};

namespace MR {
	void appearEventPowerStar(const char*, s32, const TVec3f *, bool, bool, bool);
};
