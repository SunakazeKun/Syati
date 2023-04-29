#pragma once

#include "revolution.h"
#include "JSystem.h"

class BloomEffect;
class DepthOfFieldBlur;
class CenterScreenBlur;
class PostFog;
class PostOutline;

namespace MR {
	s32 getScreenWidth();
	s32 getSafetyFrameWidth();
	s32 getSafetyFrameLeft();
	s32 getSafetyFrameRight();

	void convertFrameBufferPosToScreenPos(TVec2f *, const TVec2f &);
	void convertScreenPosToFrameBufferPos(TVec2f *, const TVec2f &);
	void startToCaptureScreen(const char *);
	void endToCaptureScreen(const char *);
	void captureScreenIfAllow(const char *);

	void openWipeCircle(s32);
	void closeWipeCircle(s32);
	void forceOpenWipeCircle();
	void forceCloseWipeCircle();
	void openWipeFade(s32);
	void closeWipeFade(s32);
	void forceOpenWipeFade();
	void forceCloseWipeFade();
	void openWipeWhiteFade(s32);
	void closeWipeWhiteFade(s32);
	void startGameOverWipe();
	void startDownWipe();
	bool isWipeActive();
	bool isWipeBlank();
	bool isWipeOpen();
	void openSystemWipeCircle(s32);

	void closeSystemWipeCircle(s32);
	void forceOpenSystemWipeCircle(s32);
	void forceCloseSystemWipeCircle();
	void openSystemWipeFade(s32);
	void closeSystemWipeFade(s32);
	void forceOpenSystemWipeFade();
	void forceCloseSystemWipeFade();
	void openSystemWipeWhiteFade(s32);
	void closeSystemWipeWhiteFade(s32);
	void forceOpenSystemWipeWhiteFade(s32);
	void forceCloseSystemWipeWhiteFade();
	void openSystemWipeMario(s32);
	void closeSystemWipeMario(s32);
	void forceOpenSystemWipeMario();
	bool isSystemWipeActive();

	void closeSystemWipeCircleWithCaptureScreen(s32);
	void closeSystemWipeFadeWithCaptureScreen(s32);
	void setWipeCircleCenterPos(const TVec3f &);

	void requestMovementOnImageEffect();
	void setImageEffectControlAuto();
	void turnOffDOFInSubjective();
	void turnOnDOFInSubjective();
	void turnOnNormalBloom();
	void turnOnDepthOfField(bool);
	void turnOffImageEffect();
	BloomEffect* createNormalBloom();
	void isNormalBloomOn();
	void isNormalBloomForEachModel();
	void setNormalBloomIntensity(u8);
	void setNormalBloomThreshold(u8);
	void setNormalBloomBlurIntensity1(u8);
	void setNormalBloomBlurIntensity2(u8);
	DepthOfFieldBlur* createDepthOfFieldBlur();
	void setDepthOfFieldBlurIntensity(f32);

	PostFog* createPostFog();
	PostOutline* createPostOutline();
	CenterScreenBlur* createCenterScreenBlur();
	void startCenterScreenBlur(s32, f32, u8, s32, s32);

	void requestPowerUpHPMeter();
	void requestForceAppearHPMeter();
	void startMissLayout();
	bool isMissLayoutAnimEnd();
	void activateDefaultGameLayout();
	void deactivateDefaultGameLayout();
	bool isActiveDefaultGameLayout();
	void forceAppearDefaultGameLayout();

	void pauseOffLensFlare();
	void tryScreenToFrameCinemaFrame();
	void tryFrameToBlankCinemaFrame();
	void tryBlankToFrameCinemaFrame();
	void tryFrameToScreenCinemaFrame();
	void forceToFrameCinemaFrame();
	void forceToBlankCinemaFrame();
	bool isStopCinemaFrame();

	void appearInformationMessageUp(const char *pMessageName, bool);
	void appearInformationMessageCenter(const char *pMessageName, bool);
	void appearInformationMessageDown(const char *pMessageName, bool);
	void appearInformationMessage(const wchar_t *pMessage, bool);
	void setInformationMessageReplaceString(const wchar_t *pReplaceString, s32 index);
	void disappearInformationMessage();
	void disableCloseInformationMessage();
	bool isDeadInformationMessage();

	bool isYesNoSelected();
	bool isYesNoSelectedYes();
	void setYesNoSelectorSE(const char *, const char *, const char *);
	void resetYesNoSelectorSE();
	void forceSyncStarPieceCounter();
	void forceAppearStarPieceCounterForTicoFat();
	void disappearStarPieceCounterForTicoFat();
	void forceSyncCoinCounter();
	void forceAppearCoinCounterForTicoFat();
	void disappearCoinCounterForTicoFat();
	void createPurpleCoinCounter();
	void validatePurpleCoinCounter();

	void requestCounterLayoutAppearanceForTicoEat(bool);
	bool isExecScenarioStarter();
	bool isStageStateScenarioOpeningCamera();

	void requestPowerStarGetDemo();
	void requestGrandStarGetDemo();
	void requestStartGameOverDemo();
	void requestEndGameOverDemo();
	void requestEndMissDemo();
	void executeOnWelcomeAndRetry();
};
