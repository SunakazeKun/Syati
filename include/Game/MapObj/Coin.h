#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/NameObj/NameObj.h"
#include "Game/MapObj/MapObjConnector.h"

//class CoinHostInfo;
class AirBubble;
class FlashingCtrl;

class CoinHostInfo {
public:
	CoinHostInfo();
	s32 _0;
	s32 _4;
	s32 _8;
	s32 _C;
};

class Coin : public LiveActor {
public:
	Coin(const char*);

	virtual void init(const JMapInfoIter&);
	virtual void initAfterPlacement();
	virtual void makeActorAppeared();
	virtual void makeActorDead();
	virtual void calcAndSetBaseMtx();
	virtual bool receiveOtherMsg(u32, HitSensor*, HitSensor*);
	void initShadow(const JMapInfoIter&);
	void setShadowAndPoseModeFromJMapIter(const JMapInfoIter&);
	void exeNonActive();
	void exeFix();
	void exeFixTimer();
	void exeMove();
	void exeControled();
	void exeSpinDrained();
	void exeHop();
	void appear();
	void appearFixInit();
	void appearFix();
	void appearFixTimer(s32, s32);
	void appearMove(const TVec3f&, const TVec3f&, s32, s32);
	void appearHop(const TVec3f&, const TVec3f&);
	void requestSpinDrain();
	void requestShow();
	void requestHide();
	void noticeGetCoin();
	void setLife(s32);
	void setHostInfo(CoinHostInfo*);
	void setCalcShadowMode();
	void setCannotTime(s32);
	void calcRebouond();
	void attenuateVelocity();
	bool isNeedBubble();

    CoinHostInfo* mCoinHostInfo;
    FlashingCtrl* mFlashingCtrl;
    AirBubble* mAirBubble;
    MapObjConnector* mConnector;
	TVec3f mShadowVec;
    TVec3f mClippingDistance;
    TVec3f mSpin;
    s32 mLifeTime;
    s32 mCannotTime;
    s32 arg6;
    bool mIsInWater;
    bool mIsPoseMode;
    bool _D2;
    bool _D3;
    bool mIsPurple;
    bool mIsBubble;
};

namespace NrvCoin {
	NERVE(CoinNrvNonActive);
	NERVE(CoinNrvFix);
	NERVE(CoinNrvFixHide);
	NERVE(CoinNrvFixTimer);
	NERVE(CoinNrvControled);
	NERVE(CoinNrvSpinDrained);
	NERVE(CoinNrvMove);
	NERVE(CoinNrvHop);
};

namespace MR
{
	LiveActor* createCoin(const NameObj *, const char *);
	LiveActor* createPurpleCoin(const NameObj *, const char *);
};
