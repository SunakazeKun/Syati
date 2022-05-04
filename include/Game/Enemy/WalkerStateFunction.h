#pragma once

#include "revolution.h"
#include "Game/Enemy/WalkerStateParam.h"
#include "Game/LiveActor/LiveActor.h"

class WalkerStateFunction {
public:
	static bool isInSightPlayer(const LiveActor *pActor, const TVec3f &, const WalkerStateParam *pParam);
	static void calcPassiveMovement(LiveActor *pActor, const WalkerStateParam *pParam);
};
