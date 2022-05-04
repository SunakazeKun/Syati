#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class MarioNullBck : public LiveActor {
public:
	MarioNullBck(const char *);

	virtual ~MarioNullBck();
	virtual void init(const JMapInfoIter &);
	virtual void appear();

	bool getFramePos(f32, TVec3f *, TVec3f *);
	void getLastPos(TVec3f *);

	u16 _90;
};
