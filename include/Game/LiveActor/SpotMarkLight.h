#pragma once

#include "revolution.h"
#include "Game/LiveActor/PartsModel.h"

class SpotMarkLight : public PartsModel {
public:
	SpotMarkLight(LiveActor *pHost, f32 hScale, f32 vScale, MtxPtr pMtx);

	virtual ~SpotMarkLight();
	virtual void control();
	virtual void calcAndSetBaseMtx();

	bool mIsDisappeared; // _9F
};
