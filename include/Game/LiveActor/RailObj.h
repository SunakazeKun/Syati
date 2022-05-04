#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class RailObj : public LiveActor {
	RailObj(const char *pName);

	virtual ~RailObj();
	virtual void init(const JMapInfoIter &rIter);

	s32 mObj_arg0; // _90
	s32 mObj_arg1; // _94
	s32 mObj_arg2; // _98
	s32 mObj_arg3; // _9C
	s32 mObj_arg4; // _A0
	s32 mObj_arg5; // _A4
	s32 mObj_arg6; // _A8
	s32 mObj_arg7; // _AC
};
