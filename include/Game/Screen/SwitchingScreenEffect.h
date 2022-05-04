#pragma once

#include "revolution.h"

class SwitchingScreenEffect;

namespace MR {
	SwitchingScreenEffect* createSwitchingScreenEffect();
	void onSwitchingScreenEffect();
	void offSwitchingScreenEffect();
};
