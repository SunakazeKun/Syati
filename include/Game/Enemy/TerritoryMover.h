#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class TerritoryMover {
public:
	TerritoryMover(f32);

	void decideNextTargetPos(const LiveActor *pActor);
	bool isReachedTarget(const LiveActor *pActor, f32);
	void setCenter(const TVec3f &rCenter);

	f32 _0;
	TVec3f mCenter; // _4
	TVec3f _10;
};
