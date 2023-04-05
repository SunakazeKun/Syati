#pragma once

#include "revolution.h"
#include "JSystem.h"

class GameSequenceInGame;
class GameSequenceEnding;
class JMapIdInfo;
class NameObj;
class PlayResultInStageHolder;
class SaveDataHandleSequence;
class UserFile;

class GameSequenceFunction {
public:
	// -------------------------------------------------------------------------------------------------------------------
	// (Anonymous) helper functions

	static GameSequenceInGame* getGameSequenceInGame();
	static GameSequenceEnding* getGameSequenceEnding();
	static SaveDataHandleSequence* getSaveDataHandleSequence();
	// getNWC24Messenger
	static void closeWipeCircleToPlayerHead();
	static void closeWipeCircleAndPrepareDreamer(const NameObj *pDreamer, s32 spawnId);
	static void prepareStageResetLuigiIntrusively(bool isLuigi, const TVec3f &rWipePos);
	static void prepareStageResetChangeRoom(s32 spawnId, bool isLuigi);
	static bool isClearedPowerStar(const char *pStageName, s32 scenarioId);
	static bool isClearedGrandStarVsKoopaLv3GalaxyFirstTime();


	// -------------------------------------------------------------------------------------------------------------------
	// SaveDataHandleSequence

	static void startPreLoadSaveDataSequence();
	static void startGameDataSaveSequence(bool, bool, bool);
	// unknown functions
	void startCreateUserFileSequence(int);
	void startDeleteUserFileSequence(int);
	// unknown function
	static bool isActiveSaveDataHandleSequence();
	static bool isSuccessSaveDataHandleSequence();
	static void restoreUserFile(UserFile *pUserFile, int);
	// unknown functions


	// -------------------------------------------------------------------------------------------------------------------
	// NWC24

	static bool tryNANDErrorSequence(s32);
	static void requestPrepareResetNWC24();
	static bool isEnableToResetNWC24();
	static void resetNWC24();


	// -------------------------------------------------------------------------------------------------------------------
	// Scene changes

	static void notifyToGameSequenceProgressToEndScene();
	static void requestChangeStageAfterFileSelect();
	static void requestChangeStageMarioFaceShip(s32 spawnId, s32 scenarioId);
	static void requestChangeStageWorldMap();

	static void requestChangeStageAfterMiss();
	static void restartCurrentStageAndClearAfterMiss();
	static void requestChangeScenarioSelect(const char *pStageName);
	static void requestChangeStageMarioFaceShipBeforeKoopaVs3();
	static void requestChangeStageStaffRoll();
	static void requestChangeStageChildRoom();


	// -------------------------------------------------------------------------------------------------------------------
	// PlayResultInStage
	
	// unknown functions
	static void setClearedPowerStarNum(s32);
	static bool hasStageResultSequence();
	// unknown functions
	static bool isResultNotifyTicoCoin();
	// unknown function
	static const char* getClearedStageName();
	static s32 getClearedPowerStarId();
	static s32 getClearedStarPieceNum();
	static s32 getClearedCoinNum();
	static u32 getResultBestTime();
	static bool isResultNewBestTime();
	// unknown functions
	static bool isResultUnlockGhostLuigi();
	static bool isClearedIslandFleetGalaxyFirstTime();
	static bool isClearedVsKoopaLv3GalaxyFirstTime();
	static bool isClearedVsKoopaLv3Galaxy1();
	static PlayResultInStageHolder* getPlayResultInStageHolder();

	// unknown functions

	static bool hasRetryGalaxySequence();

	// unknown functions

	static void resetPlayResultInStage();
	
	// unknown PlayResultWorldMapHolder functions


	// -------------------------------------------------------------------------------------------------------------------
	// PlayResultMarioFaceShip
	
	// unknown functions
	static bool isFaceShipRespondGameOver();
	static void setFaceShipRespondGameOver();
	static void clearFaceShipRespondGameOver();
	static bool isFaceShipSkipBankInfo();
	static void setFaceShipSkipBankInfo();
	static s32 getFaceShipClearedScenariosCount();
	static void incFaceShipClearedScenariosCount();
	static void clearFaceShipClearedScenariosCount();
	// unknown functions
	

	// -------------------------------------------------------------------------------------------------------------------
	// PlayResult reset

	static void resetPlayResultHolders();
	

	// -------------------------------------------------------------------------------------------------------------------
	// PAD playback

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


	// -------------------------------------------------------------------------------------------------------------------
	// Player changing
	
	// unknown functions
	static void prepareStageResetLuigiIntrusivelyLuigi(const TVec3f &rWipePos);
	static void prepareStageResetLuigiIntrusivelyMario(const TVec3f &rWipePos);
	static void prepareStageResetChangeRoomLuigi(s32 spawnId);
	static void prepareStageResetChangeRoomMario(s32 spawnId);


	// -------------------------------------------------------------------------------------------------------------------
	// Ghost Luigi

	static bool checkAppearGhostLuigi(const char *pStageName, s32 scenarioNo);
	static s32 getPlacedGreenStarScenario(const char *pStageName, s32 greenStarNo);


	// -------------------------------------------------------------------------------------------------------------------
	// Comet Medal

	static void collectTicoCoinInStage();
	static bool isCollectTicoCoinInStage();
	static bool isCollectTicoCoinSaved();
	static void collectTicoCoinIfSaved();


	// -------------------------------------------------------------------------------------------------------------------
	// Miscellaneous
	
	// unknown functions
	static void requestChangeStage(const char *pStageName, s32 scenarioNo, s32, const JMapIdInfo &rStartIdInfo);
	// unknown functions
	static void requestChangeScene(const char *pSceneName);
	// unknown functions
};
