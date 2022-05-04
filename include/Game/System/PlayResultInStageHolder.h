#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"

class PlayResultInStageHolder : public NameObj {
public:
	PlayResultInStageHolder();
	~PlayResultInStageHolder();

	void reset();

	void setStageName(const char *);
	const char* getStageName() const;

	void setClearedPowerStarNum(s32);
	s32 getClearedPowerStarNum() const;
	bool addStarPieceNum(s32);
	s32 getClearedStarPieceNum() const;
	void addCoinNum(s32);
	s32 getClearedCoinNum() const;
	bool incPurpleCoinNum();
	s32 getPurpleCoinNum() const;
	void setCollectTicoCoinSaved();

	void setRestartMarioNo(const JMapIdInfo &);
	void clearAfterMiss();
	s32 getPlayerHealth() const;

	void initPlayerHealth();

	char mStageName[48];
	u8 _42;
	u8 _43;
	u8 _44;
	s32 mClearedPowerStarId;       // _48
	s32 mClearedStarPieceNum;      // _4C
	s32 mLastStarPieceOneUpNum;    // _50
	s32 mClearedCoinNum;           // _54
	s32 mLastCoinOneUpNum;         // _58, unused
	s32 mPurpleCoinNum;            // _5C
	u8 mCollectTicoCoin;           // _60
	u8 mSavedTicoCoin;             // _61
	u8 mNotifyTicoCoin;            // _62
	u8 _63;
	s32 _64;
	u8 _68;
	JMapLinkInfo* mRestartMarioNo; // _6C
	s32 _70;
	u8 _74;
	u8 _75;
	u8 _76;
	s32 mPlayerHealth;             // _78
	s32 _7C;
	u8 _80;
	s32 _84;
	u8 _88;
	u8 _8C[12];
	u8 _98[12];
};
