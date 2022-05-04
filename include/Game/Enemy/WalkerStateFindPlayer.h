#pragma once

#include "revolution.h"
#include "Game/Enemy/WalkerStateParam.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/ActorStateBase.h"

struct WalkerStateFindPlayerParam {
public:
	s32 _0;
	f32 _4;
	f32 _8;
};

class WalkerStateFindPlayer : public ActorStateBaseInterface {
public:
	WalkerStateFindPlayer(LiveActor *pActor, TVec3f *, WalkerStateParam *pWalkerStateParam, WalkerStateFindPlayerParam *pWalkerStateFindPlayerParam);

	virtual ~WalkerStateFindPlayer();
	virtual void appear();

	void exeFind();
	void exeFindJumpStart();
	void exeFindJump();
	void exeFindJumpEnd();
	bool isInSightPlayer() const;
	bool isFindJumpBegin() const;
	bool isLandStart() const;

	LiveActor* mHost; // _C
	TVec3f* _10;
	WalkerStateParam* mParam; // _14
	WalkerStateFindPlayerParam* mFindPlayerParam; // _18
};

namespace NrvWalkerStateFindPlayer {
	NERVE(WalkerStateFindPlayerNrvFind);
	NERVE(WalkerStateFindPlayerNrvFindJumpStart);
	NERVE(WalkerStateFindPlayerNrvFindJump);
	NERVE(WalkerStateFindPlayerNrvFindJumpEnd);
};
