#pragma once

#include "revolution.h"
#include "Game/Screen/LayoutActor.h"

class MarioMeter;
class RedCoinCounter;

class CounterLayoutController : public LayoutActor {
public:
	CounterLayoutController();
	virtual void init(const JMapInfoIter& rIter);
	virtual void appear();
	virtual void kill();
	void forceAppear();
	void setHPMeter(MarioMeter*);
	void requestedTicoEat(bool);
	bool isInvalidSystemStateShowCounter();
	bool isWaitToDisappearCounter(const LayoutActor* pLayout);
	virtual void control();
	void showAllLayout();
	void hideAllLayout();
	bool isHiddenOrWaitAllLayout() const;
	bool isPlayerMoving();
	void appearAllCounterWithoutStar();
	void killAllCoounter();
	void tryEndTicoEatStarPiece();
	void exePlayerMoving();
	void exePlayerNotMoving();

	LayoutActor* _2C;
	LayoutActor* _30;
	LayoutActor* mCoinCounter;
	LayoutActor* mStarPieceCounter;
	LayoutActor* mPlayerLeft;
	LayoutActor* mStarCounter;
	LayoutActor* mMarioMeter;
	LayoutActor* mCometMedalCounter;
};
