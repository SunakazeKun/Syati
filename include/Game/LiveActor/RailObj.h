#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class RailObj : public LiveActor {
	RailObj(const char *pName);

	virtual ~RailObj();
	virtual void init(const JMapInfoIter &rIter);

	s32 mObjArg0; // _90
	s32 mObjArg1; // _94
	s32 mObjArg2; // _98
	s32 mObjArg3; // _9C
	s32 mObjArg4; // _A0
	s32 mObjArg5; // _A4
	s32 mObjArg6; // _A8
	s32 mObjArg7; // _AC
};
