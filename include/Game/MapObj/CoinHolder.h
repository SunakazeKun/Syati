#pragma once

#include "Game/LiveActor/LiveActorGroup.h"

class Coin;

class CoinHostInfo {
public:
	CoinHostInfo();

	const NameObj *mHost; // _0
	s32 mDeclaredCount;	  // _4
	s32 mAppearedCount;	  // _8
	s32 mCollectedCount;  // _C
};

class CoinHolder : public LiveActorGroup {
public:
	CoinHolder(const char *pName);
	
	virtual ~CoinHolder();
	virtual void init(const JMapInfoIter &rIter);

	bool appearCoin(const NameObj *pHost, const TVec3f &, const TVec3f &, s32, s32, s32, f32);
	bool hopCoin(const NameObj *pHost, const TVec3f &, const TVec3f &);
	bool appearCoinPop(const NameObj *pHost, const TVec3f &, s32);
	bool appearCoinPopToDirection(const NameObj *pHost, const TVec3f &, const TVec3f &, s32);
	bool appearCoinAgainstGravity(const NameObj *pHost, const TVec3f &, s32);
	bool appearCoinToVelocity(const NameObj *pHost, const TVec3f &, const TVec3f &, s32);
	bool appearCoinCircle(const NameObj *pHost, const TVec3f &, s32);
	void declare(const NameObj *pHost, s32 count);
	s32 getDeclareRemnantCoinCount(const NameObj *pHost) const;
	s32 getUncollectedCoinCount(const NameObj *pHost) const;
	CoinHostInfo* findHostInfo(const NameObj *pHost) const;

	CoinHostInfo* mHostInfos; // _20
	s32 mDeclaredCount;       // _24
};

namespace MR {
	void createCoinHolder();
	CoinHolder* getCoinHolder();
	void addToCoinHolder(const NameObj *pHost, Coin *pCoin);
};
