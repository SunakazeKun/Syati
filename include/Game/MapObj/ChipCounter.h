#pragma once

#include "revolution.h"
#include "Game/Screen/LayoutActor.h"

class ChipCounter : public LayoutActor {
public:
	ChipCounter(const char *, s32);

	virtual ~ChipCounter();
	virtual void init(const JMapInfoIter &);
	virtual void control();

	void setCount(s32);
	void requestShow(s32, s32);
	void requestComplete(s32);
	void requestHide(s32);
	void requestActive();
	void requestDeactive();
	bool tryEndFrameIn();
	bool tryEndFrameOut();
	bool tryEndComplete();
	void exeComplete();
	void exeCompleteOut();

	u32* mCollectCounter; // 2C
	s32 _30;
	s32 mType; // _34
	s32 _38;
	f32 _3C;
};
