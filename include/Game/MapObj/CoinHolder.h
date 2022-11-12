#pragma once

#include "syati.h"
#include "revolution.h"
#include "Game/MapObj/Coin.h"

class NameObj;
class CoinHolder : public NameObj {

public:
	CoinHolder(const char*);
	virtual void init(const JMapInfoIter&);
	void appearCoin(const NameObj*, const TVec3f&, const TVec3f&, s32, s32, s32, f32);
	void hopCoin(const NameObj*, TVec3f&, TVec3f&);
	void appearCoinPop(const NameObj*, const TVec3f&, s32);
	void appearCoinPopToDirection(const NameObj*, TVec3f&, TVec3f&, s32);
	void appearCoinToVelocity(const NameObj*, TVec3f&, TVec3f&, s32);
	void appearCoinCircle(const NameObj*, TVec3f&, s32);
	void declare(const NameObj*, s32);
	void getDeclareRemnantCoinCount(const NameObj*) const;
	void findHostInfo(const NameObj*) const;

	s32 _14;
    s32 _18;
    f32 _1C;
	f32 _20;
	s32 _24;
	Coin* mCoin;
};

namespace MR {
	CoinHolder* getCoinHolder();
    CoinHolder* createCoinHolder();
	void addToCoinHolder(const NameObj*, Coin*);
};