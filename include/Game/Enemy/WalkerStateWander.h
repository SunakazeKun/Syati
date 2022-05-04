#pragma once

#include "Game/Enemy/TerritoryMover.h"
#include "Game/Enemy/WalkerStateParam.h"
#include "Game/LiveActor/ActorStateBase.h"

struct WalkerStateWanderParam
{
public:
	s32 _0;
	s32 _4;
	f32 _8;
	f32 _C;
	f32 _10;
};

class WalkerStateWander : public ActorStateBaseInterface
{
public:
	WalkerStateWander(LiveActor *pActor, TVec3f *, WalkerStateParam *pWalkerStateParam, WalkerStateWanderParam *pWalkerStateWanderParam);

	virtual ~WalkerStateWander();
	virtual void appear();

	void setWanderCenter(const TVec3f &rCenter);
	void exeWait();
	void exeWalk();

	LiveActor* mHost; // _C
	TVec3f* _10;
	TerritoryMover* mTerritoryMover; // _14
	WalkerStateParam* mParam; // _18
	WalkerStateWanderParam* mWanderParam; // _1C
};

namespace NrvWalkerStateWander
{
	NERVE(WalkerStateStaggerNrvWait);
	NERVE(WalkerStateStaggerNrvWalk);
};
