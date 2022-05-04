#pragma once

#include "revolution.h"
#include "JSystem.h"

class LiveActor;
class LayoutActor;

namespace MR {
	void initStarPointerGameScene();
	void createStarPointerLayout();
	void onStarPointerSceneOut();
	void setStarPointerModeBase();
	void setStarPointerCameraMtxAtGameScene();
	bool isValidStarPointerTarget(const LiveActor *);

	void initStarPointerTarget(LiveActor *, f32, const TVec3f &);
	void initStarPointerTargetAtPos(LiveActor *, f32, const TVec3f *, const TVec3f &);
	void initStarPointerTargetAtJoint(LiveActor *, const char*, f32, const TVec3f &);
	void addStarPointerTargetCircle(LayoutActor *, const char *, f32, const TVec2f &, const char *);
	bool isStarPointerValid();

	bool isStarPointerPointing(const LiveActor *, s32, bool, const char *);
	bool tryStarPointerCheckWithoutRumble(LiveActor *, bool);
	bool isStarPointerPointingPane(const LayoutActor *, const char *, s32, bool, const char *);
	bool isStarPointerPointingPaneForMeterLayout(const LayoutActor *, const char *, s32, bool, const char *);
	bool isStarPointerPointingTarget(const LayoutActor *, const char *, s32, bool, const char *);
	bool isStarPointerPointing1P(const LiveActor *, const char *, bool, bool);
	bool isStarPointerPointing1PWithoutCheckZ(const LiveActor *, const char *, bool, bool);
	bool isStarPointerPointing2P(const LiveActor *, const char *, bool, bool);
	bool isStarPointerPointing2POnPressButton(const LiveActor *, const char *, bool, bool);
	bool isStarPointerPointing2POnTriggerButton(const LiveActor *, const char *, bool, bool);
	bool isStarPointerPointing2PAttachTarget(const LiveActor *);
	bool isStarPointerPointingFileSelect(const LiveActor *);
	bool isStarPointerPointing1Por2P(const LiveActor *, const char *, bool, bool);
	bool requestBlueStarGuidance();
	bool requestTicoFatGuidance();
	bool requestMarioLauncherGuidance();
	bool requestFileSelectGuidance();
	bool requestYoshiEatGuidance();
	bool requestYoshiCaptureGuidance();
	bool isExistStarPointerGuidance();
	bool isExistStarPointerGuidanceFrame1P();
	void activeStarPointerGuidance();
	void deactiveStarPointerGuidance();
	bool isExistStarPointerTarget(const LiveActor *);
	void setStarPointerTargetRadius3d(LiveActor *, f32);
	bool isStarPointerPointing(const TVec3f &, f32, s32, bool);
	MtxPtr getStarPointerViewMtx();
	MtxPtr getStarPointerProjMtx();
	f32 getStarPointerRadius(s32);
	TVec2f* getStarPointerScreenPosition(s32);
	void getStarPointerScreenPositionOrEdge(s32);
	f32 getStarPointerScreenSpeed(s32);
	bool isStarPointerInScreen(s32);
	bool isStarPointerInScreenAnyPort(s32 *);

	TVec2f* getStarPointerScreenVelocity(s32);
	TVec3f* getStarPointerWorldPosUsingDepth(s32);
	void calcStarPointerWorldPointingPos(TVec3f *, const TVec3f &, s32);
	void calcStarPointerPosOnPlane(TVec3f *, const TVec3f &, const TVec3f &, s32, bool);
	void calcStarPointerWorldVelocityDirectionOnPlane(TVec3f *, const TVec3f &, const TVec3f &, s32);
	f32 calcPointRadius2D(const TVec3f &, f32);
	bool calcStarPointerStrokeRotateMoment(TVec3f *, const TVec3f &, f32, s32);
	bool calcStarPointerScreenDistanceToTarget(const LiveActor *, f32 *, s32);
	void startStarPointerModeTitle(void *);
	void startStarPointerModeFileSelect(void *);
	void startStarPointerModeGame(void *);
	void startStarPointerModeDemo(void *);
	void startStarPointerModeDemoWithStarPointer(void *);
	void startStarPointerModeDemoWithHandPointerFinger(void *);
	void startStarPointerModeDemoMarioDeath(void *);
	void startStarPointerModeMarioLauncher(void *);
	void startStarPointerModeHomeButton(void *);
	void startStarPointerModeChooseYesNo(void *);
	void startStarPointerModePauseMenu(void *);
	void startStarPointerModeScenarioSelectScene(void *);
	void startStarPointerModeBlueStar(void *);
	void startStarPointerModePowerStarGetDemo(void *);
	void startStarPointerModeStarPieceTarget(void *);
	void startStarPointerModeSphereSelectorOnReaction(void *);
	void startStarPointerModeEnding(void *);

	void endStarPointerMode(void *);
	void requestStarPointerModeErrorWindow(void *);
	void requestStarPointerModeSaveLoad(void *);
	void requestStarPointerModeBlueStarReady(void *);

	bool isStarPointerModeBlueStarReady();
	bool isStarPointerModeStarPieceTarget();
	bool isStarPointerModeMarioLauncher();
	bool isStarPointerModeHomeButton();
	bool isStarPointerModeErrorWindow();

	void enableStarPointerShootStarPiece();
	void disableStarPointerShootStarPiece();
	bool isEnableStarPointerShootStarPiece(s32);
	bool isStarPointer2PTransparencyMode();
	bool isStarPointer1PInvalid2PValidMode();
	void setStarPointerDrawSyncToken();
};
