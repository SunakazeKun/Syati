#pragma once

#include "revolution.h"
#include "Game/LiveActor/PartsModel.h"

class MarioParts : public PartsModel {
public:
	MarioParts(LiveActor *, const char *, const char *, bool, MtxPtr, MtxPtr);
	MarioParts(LiveActor *, const char *, const char *, MtxPtr);

	virtual ~MarioParts();
	virtual void init(const JMapInfoIter &);

	const char* mEffectGroupName; // _A0
};
