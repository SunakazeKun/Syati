#pragma once

#include "revolution.h"

/* FINISHED */

class ValueControl {
public:
	ValueControl(int maxFrame);

	void setDirToOneResetFrame();
	void setDirToZero();
	void setDirToZeroResetFrame();
	void setMaxFrame(int maxFrame);
	void update();
	void setZero();
	void setOne();
	f32 getValue() const;
	void resetFrame();

	s32 mFrame;     // _0
	s32 mMaxFrame;  // _4
	s32 mDirection; // _8
};
