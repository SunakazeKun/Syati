#pragma once

#include "revolution.h"

class SaveDataHandleSequence;
class GameEventValueChecker;
class GameDataPlayerStatus;
class GameDataSomeGalaxyStorage;
class GameDataTicoFatStorage;
class GameDataWorldMapStorage;

class GameDataFunction {
public:
	static SaveDataHandleSequence* getSaveDataHandleSequence();
	static GameEventValueChecker* getCurrentGameEventValueChecker();
	static GameDataPlayerStatus* getCurrentGameDataPlayerStatus();
	static GameDataSomeGalaxyStorage* makeSomeGalaxyStorage(const char *pStageName);
	static GameDataTicoFatStorage* getCurrentGameDataTicoFatStorage();
	static GameDataWorldMapStorage* getCurrentGameDataWorldMapStorage();
	static void setPowerStar(const char *pStageName, s32 scenario);
	static bool hasPowerStar(const char *pStageName, s32 scenario);
	static bool hasGrandStar(int);
	static void setBronzeStar(const char *pStageName, s32 scenario);
	static bool hasBronzeStar(const char *pStageName, s32 scenario);
	static s32 calcCurrentPowerStarNum();
	static s32 calcCurrentGrandStarNum();
	static s32 getNormalPowerStarNumOwned(const char *pStageName);
	static s32 getPowerStarNumOwned(const char *pStageName);

	static s32 getPowerStarNumMax();

	static bool isOnGalaxyScenarioFlagGhostLuigi(const char *pStageName, s32 scenario);
	static void onGalaxyScenarioFlagGhostLuigi(const char *pStageName, s32 scenario);
	static bool isOnGalaxyScenarioFlagAlreadyVisited(const char *pStageName, s32 scenario);
	static void onGalaxyScenarioFlagAlreadyVisited(const char *pStageName, s32 scenario);

	static bool isGalaxyStateClosed(const char *pStageName);
	static bool isGalaxyStateNew(const char *pStageName);
	static bool isGalaxyStateOpened(const char *pStageName);
	static void setGalaxyStateNew(const char *pStageName);
	static void setGalaxyStateOpened(const char *pStageName);
	static void onGalaxyFlagTicoCoin(const char *pStageName);
	static bool isOnGalaxyFlagTicoCoin(const char *pStageName);
	static s32 calcTicoCoinNum();
	static void onGalaxyFlagComet(const char *pStageName);
	static void offGalaxyFlagComet(const char *pStageName);
	static bool isOnGalaxyFlagComet(const char *pStageName);
	static void tryOnDimensionBigCastleGalaxyComet();
	static void onGameEventFlag(const char *pStageName);
	static void offGameEventFlag(const char *pStageName);
	static bool isOnGameEventFlag(const char *pStageName);
	static bool isOnGameEventFlagEnding120Stars();
	static bool isOnGameEventFlagFinalGalaxyAppearance();
	static bool isOnGameEventFlagStarPieceCounterStop();
	static bool isOnGameEventFlagCoinCounterStop();
	static bool isOnGameEventFlagCometExplain();
	static void onGameEventFlagOpenScenario(const char *pStageName, s32 scenario);
	static bool isOnGameEventFlagOpenScenario(const char *pStageName, s32 scenario);
	static bool existsGameEventFlagOpenScenario(const char *pStageName, s32 scenario);
	static void forceLuigiPlayer();
	static void forceMarioPlayer();
	static bool isLuigiPlayer();

	static bool isOnMessageAlreadyRead(signed char);

	static void setRaceBestTime(const char *pStageName, u32 bestTime);
	static u32 getRaceBestTime(const char *pStageName);
	static void setBestScoreAttackCurrentStage();
	static u32 getBestScoreAttackCurrentStage();
	static void incPlayerMissNum();
	static s32 getPlayerMissNum(); // is s32 correct?
	static void incScenarioMissNum();
	static s32 getScenarioMissNum();

	static void updateStorageSpinDriverPathDrawRange(const char *pStageName, int, int, f32);

	static void onTicoCoinFeed(const char *pStageName);
	static bool isTicoCoinFeed(const char *pStageName);
	static s32 getPlayerLeft();
	static void addPlayerLeft(int);

	static s32 getStocketStarPieceNum();
	static s32 tryOnGameEventFlagStarPieceCounterStop(int);
	static s32 getStockedCoinNum();
	static s32 tryOnGameEventFlagCoinCounterStop(int);

	static void incCumulativePlayTime();
	static s32 getCumulativePlayTime();
	static void resetAllGameData();

	static s32 getCurrentWorldId();

	static bool isOnGameEventFlagWorld1Entered();

	static wchar_t* getUserName();
	static wchar_t* setUserName(const wchar_t *);
};
