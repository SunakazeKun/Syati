#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class MirrorActor : public LiveActor {
public:
	MirrorActor(LiveActor *pHost, const char *pName, const char *pModelName);

	virtual ~MirrorActor();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual void calcAnim();
	virtual void CalcViewAndEntry();
	
	bool isHostInTheOtherSideOfMirror() const;
	TVec3f getHostCenterPos() const;

	LiveActor* mHost; // _90
	TVec3f mCenter;   // _94
	f32 _A0;
	bool mIsActive;   // _A4
};
