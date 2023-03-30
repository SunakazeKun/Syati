#pragma once

#include "revolution.h"
#include "Game/System/AllData/GameDataHolder.h"

class ConfigDataHolder;

class UserFile {
public:
	UserFile();

	bool isCreated() const;
	s32 getPowerStarNum() const;
	s32 calcNormalPowerStarNum() const;
	s32 getPlayerMissNum() const;
	bool getMiiId(void *) const;
	bool getIconId(u32 *) const;
	void isView120StarsEnding() const;
	void isComplete() const;
	void getLastModified() const;
	void hasGrandStar(int) const;
	void getCumulativePlayTime() const;
	void setCreated();
	void setMiiOrIconId(const void *, const u32 *);
	void updateLastModified();
	void setUserName(const wchar_t *);
	void getGameDataName() const;
	void makeGameDataBinary(u8 *, u32) const;
	void loadFromGameDataBinary(const char *, const u8 *, u32);
	void getConfigDataName() const;
	void makeConfigDataBinary(u8 *, u32) const;
	void loadFromConfigDataBinary(const char *, const u8 *, u32);
	void resetAllData();

	GameDataHolder* mGameDataHolder; // _0
	ConfigDataHolder* mConfigDataHolder; // _4
	bool mGameDataLoaded; // _8
	bool mConfigDataLoaded; // _9
	wchar_t* mUserName; // _C
};
