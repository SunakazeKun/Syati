#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class YoshiLockOnTarget {
public:
	YoshiLockOnTarget(LiveActor *, MtxPtr, const TVec3f &);

	LiveActor* mHost; // _0
	MtxPtr mFollowMtx; // _4
	TVec3f mOffset; // _8
	bool _14;
};

namespace MR {
	YoshiLockOnTarget* createYoshiLockOnTarget(LiveActor *, MtxPtr, const TVec3f &);
	YoshiLockOnTarget* createYoshiLockOnTarget(LiveActor *, const char *, const TVec3f &);
};
