#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class MapObjConnector {
public:
	MapObjConnector(LiveActor *);

	bool attachToUnder();
	bool attachToBack();
	bool attach(const TVec3f &);
	
	void connect();
	void connect(LiveActor *);

	LiveActor* mActor; // _0
	u32* _4; // appears to be a pointer
	TMtx34f mMtx; // _8
};
