#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class SpinHitController {
public:
	SpinHitController(const LiveActor *pActor);
	SpinHitController(const LiveActor *pActor, s32, s32, f32, f32, f32);

	void setParameter(const LiveActor *pActor, s32, s32, f32, f32, f32);
	void start(LiveActor *, const TVec3f &, const TVec3f &);
	void startWithoutStopScene(LiveActor *pActor, const TVec3f &, const TVec3f &);
	void execute(LiveActor *);

	s32 _0;
	s32 _4;
	f32 _8;
	f32 _C;
	f32 _10;
	bool mStopScene; // _14
};
