#pragma once

#include "revolution.h"
#include "Game/System/AllData/GalaxyStatusAccessor.h"
#include "Game/System/BinaryDataChunkHolder.h"

class BinaryDataContentHeaderSerializer;
class BinaryDataContentAccessor;

class GameDataSomeScenarioAccessor {
public:
	GameDataSomeScenarioAccessor();

	void resetAllData();

	s8 mMissNum; // _0
	s32 mBestTime; // _4
	u8 mFlag; // _8
};

#define SOME_GALAXY_STORAGE_FLAG_TICO_COIN 1
#define SOME_GALAXY_STORAGE_FLAG_COMET 2

class GameDataSomeGalaxyStorage {
public:
	GameDataSomeGalaxyStorage(const GalaxyStatusAccessor &rGalaxyStatusAccessor);

	GameDataSomeScenarioAccessor* getScenarioAccessor(s32 scenario) const;
	void resetAllData();
	s32 getPowerStarNumOwned() const;
	void serialize(const BinaryDataContentAccessor &rAccessor, u8 *pDest) const;
	void deserialize(const BinaryDataContentAccessor &rAccessor, const u8 *pSrc);

	const char* mGalaxyName; // _0
	u8 mScenarioNum; // _4
	u8 mGalaxyState; // _5
	u8 mFlag; // _6
	GameDataSomeScenarioAccessor* mScenarioAccessors; // _8
};

// This one extends BinaryDataChunkBase but also something else?
class GameDataAllGalaxyStorage {
public:
	GameDataAllGalaxyStorage();

	GameDataSomeGalaxyStorage* makeAccessor(const char *pStageName) const;
	s32 calcCurrentPowerStarNum() const;
	s32 calcNormalPowerStarNum() const;
	s32 getPowerStarNumOwned(const char *pStageName) const;
	s32 calcTicoCoinNum() const;
	//u32 makeHeaderHashCode() const;
	//u32 getSignature() const;
	//void serialize(u8 *, u32) const;
	//void deserialize(const u8 *, u32);
	//void initializeData();
	void initHeaderSerializer();
	s32 findIndex(const char *pStageName) const;
	s32 findIndex(u16 hash) const;

	u8 _0[8]; // vtables
	GameDataSomeGalaxyStorage** mGalaxyStorages; // _8
	s32 mGalaxyStorageCapacity; // _C
	s32 mNumGalaxies; // _10
	BinaryDataContentHeaderSerializer* mGalaxySerializer; // _14
	BinaryDataContentHeaderSerializer* mScenarioSerializer; // _18
};
