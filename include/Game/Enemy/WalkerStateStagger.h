#pragma once

#include "Game/Enemy/WalkerStateParam.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/ActorStateBase.h"

struct WalkerStateStaggerParam
{
public:
	f32 _0;
	f32 _4;
	f32 _8;
	s32 _C;
	s32 _10;
	s32 _14;
	s32 _18;
	s32 _1C;
	f32 _20;
	f32 _24;
	f32 _28;
	f32 _2C;
};

class WalkerStateStagger : public ActorStateBaseInterface
{
public:
	WalkerStateStagger(LiveActor *pActor, TVec3f *, WalkerStateParam *pWalkerStateParam, WalkerStateStaggerParam *pWalkerStateStaggerParam);

	virtual ~WalkerStateStagger();
	virtual void appear();
	virtual void kill();

	void setPunchDirection(HitSensor *, HitSensor *);
	void exeStagger();
	void exeStaggerEnd();
	void reboundWall();
	bool isEnableKick() const;
	bool isUpsideDown() const;
	bool isStaggerStart() const;
	bool isSwooning(s32) const;
	bool isSpinning(s32, s32);
	bool isRecoverStart() const;

	LiveActor* mHost; // _C
	WalkerStateParam* mParam; // _10
	WalkerStateStaggerParam* mStaggerParam; // _14
	TVec3f _18;
	TVec3f* _24;
	bool isStaggerEnd; // _28
};

namespace NrvWalkerStateStagger
{
	NERVE(WalkerStateStaggerNrvStagger);
	NERVE(WalkerStateStaggerNrvStaggerEnd);
};
