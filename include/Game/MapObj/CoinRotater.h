#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"

class CoinRotater : public NameObj {
public:
	CoinRotater(const char *pName);

	virtual ~CoinRotater();
	virtual void movement();

	f32 mRotateY;               // _14
	f32 mHiSpeedRotateY;        // _18
	f32 mInWaterRotateY;        // _1C
	TMtx34f mMtxRotateY;        // _20
	TMtx34f mMtxHiSpeedRotateY; // _50
	TMtx34f mMtxInWaterRotateY; // _80
};

namespace MR {
	CoinRotater* createCoinRotater();
	TMtx34f* getCoinRotateYMatrix();
	TMtx34f* getCoinHiSpeedRotateYMatrix();
	TMtx34f* getCoinInWaterRotateYMatrix();
};
