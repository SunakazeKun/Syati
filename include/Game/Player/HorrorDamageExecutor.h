#pragma once

#include "Game/System/NerveExecutor.h"

class MarioDamage;

class HorrorDamageExecutor : public NerveExecutor {
public:
	HorrorDamageExecutor(MarioDamage *);

	virtual ~HorrorDamageExecutor();

	void startBreak();
	bool isBreakEnd() const;
	void exeBoneBreakStart();
	void exeBoneBreakWait();
	void exeBoneBreakEnd();

	MarioDamage* mDamageState; // _8
	s32 mBreakTime; // _C
	bool mIsBreakEnd; // _10
};
