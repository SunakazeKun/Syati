#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class MirrorReflectionModel : public LiveActor {
public:
	MirrorReflectionModel(const LiveActor *pHost, const char *pName, const char *pModelName, MtxPtr pMtx);

	virtual ~MirrorReflectionModel();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual void calcAnim();
	virtual void calcViewAndEntry();
	virtual void calcAndSetBaseMtx();

	const LiveActor* mHost; // _90
	MtxPtr mMtx;            // _94
	bool mIsActive;         // _98
};
