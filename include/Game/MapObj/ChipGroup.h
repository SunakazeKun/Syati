#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Map/StageSwitch.h"
#include "Game/MapObj/ChipBase.h"

struct ChipStruct {
	ChipBase* mChip; // 0
	bool mIsCollected; // 4
};

class ChipGroup : public NameObj {
public:
	ChipGroup(const char *, s32);

	virtual ~ChipGroup();
	virtual void init(const JMapInfoIter &);
	virtual void movement();

	void updateUIRange();
	void registerChip(ChipBase *);
	void noticeGet(ChipBase *);
	void noticeEndCompleteDemo();
	void receiveAppearRequest();
	s32 getGotCount();
	bool isComplete();

	ChipStruct mChips[5]; // 14
	StageSwitchCtrl* mStageSwitchCtrl; // 3C
	TVec3f mTranslate; // 40
	s32 mCollectedChips; // 4C
	s32 mNumChips; // 50
	s32 mArg0; // 54
	s32 mType; // 58
	s32 mArg1; // 5C
	s32 _60;
	f32 _64;
	f32 mArg2; // 68
	bool _6C;
	s32 _70;
	bool mUseSwAppear; // 74
	bool mAppeared; // 75
};

class YellowChipGroup : public ChipGroup {
public:
	YellowChipGroup(const char *);

	virtual ~YellowChipGroup();
};
