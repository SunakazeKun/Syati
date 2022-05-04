#pragma once

#include "revolution.h"
#include "JSystem.h"

class LiveActor;
class NameObj;
class JMapLinkInfo;

namespace MR {
	s32 getCurrentScenarioNo();
	s32 getCurrentSelectedScenarioNo();
	void setCurrentScenarioNo(s32, s32);
	bool isScenarioDecided();

	const char* getCurrentStageName();
	bool isEqualSceneName(const char *);
	bool isEqualStageName(const char *);

	bool isStageNoPauseMenuStars();
	bool isStageMarioFaceShipAfterFinalKoopa();
	bool isStageMarioFaceShipAfterGrandStar();

	bool isStageStaffRoll();
	bool isStageStarPieceFollowGroupLimit();
	bool isStageFileSelect();
	bool isBeginScenarioStarter();
	bool isStageSuddenDeathDodoryu();
	bool isStageScoreAttack();
	bool isStageMarioFaceShip();
	bool isStageWorldMap();
	bool isStageMarioFaceShipOrWorldMap();
	bool isStageDisablePauseMenu();
	bool isStageStoryBook();
	bool isStageMarioFaceShipNormal();
	bool isStageBossParade();
	bool isStageDimensionBigCastle(const char *);
	bool isStagePurpleCoinsMoreThan100(const char *);
	bool isStagePlayStarChance(s32);

	bool isStageGlider();
	bool isStageJungleGliderGalaxyExplainDemo();

	bool isStageKoopaVs3();
	bool isStageKoopaVs();

	void setInitializeStatePlacementPlayer();
	void setInitializeStatePlacementHighPriority();
	void setInitializeStatePlacement();
	void setInitializeStateAfterPlacement();
	bool isInitializeStateEnd();
	bool isInitializeStatePlacementSomething();
	void stopSceneForScenarioOpeningCamera();
	void playSceneForScenarioOpeningCamera();

	s32 getStartPosNum();
	s32 getCurrentStartZoneId();
	
	s32 getGeneralPosNum();
	void getGeneralPosData(const char **, TVec3f *, TVec3f *, JMapLinkInfo **, int);
	void getRestartPosData(TVec3f *, TVec3f *, const JMapInfoIter &);
	s32 getChildObjNum(const JMapInfoIter &);
	void getChildObjName(const char **, const JMapInfoIter &, int);

	void initChildObj(NameObj *, const JMapInfoIter &, int);
	const char* getAppearPowerStarObjName(s32);
	s32 getCurrentStagePowerStarNum();
	s32 getZoneNum();
	const char* getZoneNameFromZoneId(s32);
	s32 getZoneIdFromZoneName(const char *);
	s32 getPlacedHiddenStarScenarioNo(const char *, s32);

	bool isPlacementLocalStage();
	s32 getPlacedZoneId(const JMapInfoIter &);
	MtxPtr getZonePlacementMtx(const JMapInfoIter &);
	MtxPtr getZonePlacementMtx(s32);

	const char* getJapaneseObjectName(const char *);
	void setCurrentPlacementZoneId(s32);
	void clearCurrentPlacementZoneId();
	s32 getCurrentPlacementZoneId();
};
