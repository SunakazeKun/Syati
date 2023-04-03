#pragma once

#include "revolution.h"

class JMapIdInfo;
class GameSequenceInGame;
class PlayInStageResultHolder;

class GameSequenceFunction {
public:
	static GameSequenceInGame* getGameSequenceInGame();

	static bool isActiveSaveDataHandleSequence();
	static void startGameDataSaveSequence(bool, bool, bool);

	static void changeSceneStageMarioFaceShipGalaxy(s32 spawnId, s32 scenario);
	static void restartCurrentStageAndClearAfterMiss();
	static void changeToScenarioSelect(const char *pStageName);

	static bool hasStageResultSequence();

	static bool isResultNotifyTicoCoin();

	static const char* getClearedStageName();
	static s32 getClearedPowerStarId();
	static s32 getClearedStarPieceNum();
	static s32 getClearedCoinNum();

	static PlayInStageResultHolder* getPlayInStageResultHolder();

	static s32 getCurrentClearedScenariosCount();
	static void incCurrentClearedScenariosCount();
	static void clearCurrentClearedScenariosCount();

	static void setPadModeDreamer();
	static void setPadModeSuperDreamer();
	static void clearPadModeDreamer();
	static void clearPadModeSuperDreamer();
	static bool isPadModeDreamer();
	static bool isPadModeSuperDreamer();
	static bool isPadMode();
	static bool isPadMode2();
	static bool isAllowDreamerMissNum(s32 missNum);
	static bool isAllowDreamerInStage();

	static void forcePlayerLuigiAndGotoMarioFaceShipGalaxy();
	static void forcePlayerMarioAndGotoMarioFaceShipGalaxy();

	static void collectTicoCoinInStage();
	static bool isCollectTicoCoinInStage();
	static bool isCollectTicoCoinSaved();
	static void collectTicoCoinIfSaved();

	static void changeSceneStage(const char *pStageName, s32 scenarioNo, s32, const JMapIdInfo &rStartIdInfo);

	static void requestChangeScene(const char *pSceneName);
};
