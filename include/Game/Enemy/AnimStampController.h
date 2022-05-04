#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/System/NerveExecutor.h"

class AnimStampController : public NerveExecutor {
public:
	AnimStampController();

	virtual ~AnimStampController();

	void init(s32, f32, f32, f32, f32, f32, f32);
	void startAnim(const TVec3f &);
	void exeAnim();
	bool isAnimEnd();

	TVec3f _8;
	Mtx _14;
	s32 _44;
	f32 _48;
	f32 _4C;
	f32 _50;
	f32 _54;
	f32 _58;
	f32 _5C;
};

namespace NrvAnimStampController {
	NERVE(HostNrvAnim);
	NERVE(HostNrvAnimEnd);
};
