#pragma once

#include "revolution.h"

class TimeStopScreenEffect;

namespace MR {
	TimeStopScreenEffect* createTimeStopScreenEffect();
	void onTimeStopScreenEffect();
	void offTimeStopScreenEffect();
};
