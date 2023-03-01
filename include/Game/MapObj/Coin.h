#pragma once

#include "revolution.h"
#include "Game/LiveActor/FlashingCtrl.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/PartsModel.h"
#include "Game/MapObj/MapObjConnector.h"
#include "Game/NameObj/NameObj.h"

/* FINISHED */

class CoinHostInfo;

class Coin : public LiveActor {
public:
	Coin(const char *pName);

	virtual ~Coin();
	virtual void init(const JMapInfoIter &rIter);
	virtual void initAfterPlacement();
	virtual void appear();
	virtual void makeActorAppeared();
	virtual void makeActorDead();
	virtual void calcAndSetBaseMtx();
	virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

	void initShadow(const JMapInfoIter &rIter);
	void setShadowAndPoseModeFromJMapIter(const JMapInfoIter &rIter);
	void setShadowCylinder();

	void exeNonActive();
	void exeFix();
	void exeFixTimer();
	void exeMove();
	void exeControled();
	void exeSpinDrained();
	void exeHop();
	void exeSupportTicoThrow();

	void appearFixInit();
	void appearFix();
	void appearFixTimer(s32 lifeTime, s32 cannotTime);
	void appearMove(const TVec3f &rPosition, const TVec3f &rVelocity, s32 lifeTime, s32 cannotTime);
	void appearHop(const TVec3f &rPosition, const TVec3f &rHopDir);

	bool requestGetCoin();
	bool requestStartControl();
	bool requestEndControl();
	bool requestMove();
	bool requestThrow();
	void requestShow();
	void requestHide();
	void noticeGetCoin();

	void setLife(s32 lifeTime);
	void setHostInfo(CoinHostInfo *pInfo);
	void setCalcShadowMode();
	void setCannotTime(s32 cannotTime);

	void calcRebouond();
	f32 attenuateVelocity();
	bool isNeedBubble(const JMapInfoIter &rIter);
	bool canStartMove() const;

	CoinHostInfo* mCoinHostInfo;    // _90
	FlashingCtrl* mFlashingCtrl;    // _94
	PartsModel* mAirBubble;         // _98
	MapObjConnector* mConnector;    // _9C
	TVec3f mShadowDropPos;          // _A0
	TVec3f _AC;                     // unused
	TVec3f _B8;                     // unused
	s32 mLifeTime;                  // _C4
	s32 mCannotTime;                // _C8
	s32 mShadowType;                // _CC
	bool mInWater;                  // _D0
	bool mShadowCalcOn;             // _D1
	bool mIgnoreGravity;            // _D2
	bool mCalcShadowPrivateGravity; // _D3
	bool mIsPurple;                 // _D4
	bool mIsInBubble;               // _D5
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
	NERVE(CoinNrvSupportTicoThrow);
	NERVE(CoinNrvGot);
};

namespace MR {
	Coin* createDirectSetCoin(const char *pName);
	Coin* createCoin(const NameObj *pHost, const char *pName);
	Coin* createDirectSetPurpleCoin(const char *pName);
	Coin* createPurpleCoin(const NameObj *pHost, const char *pName);
};
