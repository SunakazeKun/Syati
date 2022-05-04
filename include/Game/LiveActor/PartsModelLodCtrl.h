#pragma once

#include "revolution.h"
#include "Game/LiveActor/LodCtrl.h"
#include "Game/LiveActor/PartsModel.h"

class PartsModelLodCtrl : public PartsModel {
public:
	PartsModelLodCtrl(LiveActor *pHost, const char *pName, const char *pModelName, MtxPtr pMtx, s32, bool);

	virtual ~PartsModelLodCtrl();
	virtual void init(const JMapInfoIter &rIter);
	virtual void control();
	virtual void calcAndSetBaseMtx();

	void setLodCtrl(LodCtrl *pLodCtrl);
	void initLightCtrl();

	LodCtrl* mLodCtrl; // _A0
};
