#pragma once

#include "revolution.h"
#include "JSystem.h"

class NameObj;

namespace MR {
	void incPlayerAndTryScenarioMissNum();
	s32 getPlayerLeft();
	void addPlayerLeft(int);
	void decPlayerLeft();
	void incPlayerMissNum();
	bool isPlayerLuigi();
	s32 getStarPieceNum();
	void addStarPiece(int);
	void incCoin(int, LiveActor *);
	void decCoin(int);
	s32 getCoinNum();
	void incPurpleCoin();
	s32 getPurpleCoinNum();
	bool isPurpleCoinNum100();
	void explainBeeMarioIfAtFirst();
	void explainTeresaMarioIfAtFirst();
	void explainHopperMarioIfAtFirst();
	void explainFireMarioIfAtFirst();
	void explainIceMarioIfAtFirst();
	void explainFlyingMarioIfAtFirst();
	void explainInvincibleMarioIfAtFirst();
	void explainRockMarioIfAtFirst();
	void explainCloudMarioIfAtFirst();
	void explainDrillIfAtFirst();
	void explainLifeUpIfAtFirst();
	void explainOneUpIfAtFirst();
	void explainYoshiIfAtFirst();
	void explainCometMedalIfAtFirst();
	void explainMarioFacePlanetAtFirst();
	void onGameEventFlagBeeMarioAtFirst();
	void onGameEventFlagTeresaMarioAtFirst();
	void onGameEventFlagHopperMarioAtFirst();
	void onGameEventFlagFireMarioAtFirst();
	void onGameEventFlagIceMarioAtFirst();
	void onGameEventFlagFlyingMarioAtFirst();
	void onGameEventFlagInvincibleMarioAtFirst();
	void onGameEventFlagRockMarioAtFirst();
	void onGameEventFlagCloudMarioAtFirst();
	void onGameEventFlagDrillAtFirst();
	void onGameEventFlagLifeUpAtFirst();
	void onGameEventFlagOneUpAtFirst();
	void onGameEventFlagTamakoroTutorialAtFirst();
	void onGameEventFlagGliBirdTutorialAtFirst();
	void onGameEventFlagYoshiAtFirst();
	void onGameEventFlagCometMedalAtFirst();
	void onGameEventFlagSupportTicoAtFirst();
	void onGameEventFlagKinopioBankAtFirst();
	bool isOnGameEventFlagBeeMarioAtFirst();
	bool isOnGameEventFlagTeresaMarioAtFirst();
	bool isOnGameEventFlagHopperMarioAtFirst();
	bool isOnGameEventFlagFireMarioAtFirst();
	bool isOnGameEventFlagIceMarioAtFirst();
	bool isOnGameEventFlagFlyingMarioAtFirst();
	bool isOnGameEventFlagInvincibleMarioAtFirst();
	bool isOnGameEventFlagRockMarioAtFirst();
	bool isOnGameEventFlagCloudMarioAtFirst();
	bool isOnGameEventFlagDrillAtFirst();
	bool isOnGameEventFlagLifeUpAtFirst();
	bool isOnGameEventFlagOneUpAtFirst();
	bool isOnGameEventFlagTamakoroTutorialAtFirst();
	bool isOnGameEventFlagGliBirdTutorialAtFirst();
	bool isOnGameEventFlagYoshiAtFirst();
	bool isOnGameEventFlagCometMedalAtFirst();
	bool isOnGameEventFlagSupportTicoAtFirst();
	bool isOnGameEventFlagKinopioBankAtFirst();
	bool isOnGameEventFlagNormalEnding();
	bool isOnGameEventFlag120PowerStarsEnding();

	bool isAlreadyVisitedCurrentStageAndScenario();
	bool hasPowerStarInCurrentStage(s32);
	bool isPowerStarGreenInCurrentStage(s32);
	bool isPowerStarBronzeInCurrentStage(s32);
	bool isGrandStarInCurrentStage(s32);
	bool hasPowerStarInCurrentStageWithDeclared(const char *, s32);
	bool isPowerStarGreenInCurrentStageWithDeclarer(const char *, s32);
	bool isPowerStarBronzeInCurrentStageWithDeclarer(const char *, s32);
	bool isGrandStarInCurrentStageWithDeclarer(const char *, s32);
	bool isScenarioOpenInCurrentStageWithDeclarer(const char *);

	bool isOnGameEventFlagPowerStarSuccess(const char *, s32);
	bool hasGrandStar(int);
	s32 getPowerStarNumOwnedInStage(const char *);
	bool isPowerStarGreen(const char *, s32);
	bool isPowerStarGreenInCurrentStage();
	bool isPowerStarBronze(const char *, s32);

	s32 getPowerStarNum();

	void setRaceBestTime(int, s32);
	s32 getRaceBestTime(int);
	s32 getRaceCurrentTime();
	s32 registerStorageSpinDriverPathDrawRange(const NameObj *, const JMapInfoIter &, int, f32 *);
	void updateStorageSpinDriverPathDrawRange(int, f32);
	bool isGalaxyDarkCometAppearInCurrentStage();
	bool isGalaxyQuickCometAppearInCurrentStage();
	bool isGalaxyPurpleCometAppearInCurrentStage();
	bool isGalaxyHorrorInCurrentStage();
	bool isGalaxyRainbowInCurrentStage();

	bool isGalaxyCompletedNoGreen(const char *);
	bool isGalaxyCompletedWithGreen(const char *);

	void setRestartMarioNo(const JMapIdInfo &);
	bool isGhostLuigiOpenInStage(const char *, s32);

	bool isIslandFleetGalaxy1FirstTime();
};
