#pragma once

#include "Game/NameObj/NameObj.h"

class CoinRotater : public NameObj
{
public:
	CoinRotater(const char *);

	virtual ~CoinRotater();
	virtual void movement();

	f32 mRotateY; // _14
	f32 mHiSpeedRotateY; // _18
	f32 mInWaterRotateY; // _1C
	Mtx mMtxRotateY; // _20
	Mtx mMtxHiSpeedRotateY; // _50
	Mtx mMtxInWaterRotateY; // _80
};

namespace MR
{
	CoinRotater* createCoinRotater();
	TMtx34f* getCoinRotateYMatrix();
	TMtx34f* getCoinHiSpeedRotateYMatrix();
	TMtx34f* getCoinInWaterRotateYMatrix();
};