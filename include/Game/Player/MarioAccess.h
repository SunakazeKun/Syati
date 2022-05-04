#pragma once

#include "revolution.h"
#include "Game/Player/MarioActor.h"

class BckCtrlData;
class RushEndInfo;

class MarioAccess {
public:
	static void getTakePos(TVec3f *);
	static bool isOnActor(const LiveActor *);
	static bool isOnGround(u32);
	static bool isHipDropFalling();
	static bool isHipDropLand();
	static bool isSwingAction();
	static bool isInRush();
	static bool isRecovering();
	static bool isSquat();
	static bool isParalyzing();
	static bool isTeresaDisappear();
	static bool isFlying();
	static bool isNeedBrakingCamera();
	static bool isSwimming();

	static void forceKill(u32, u32);

	static bool isDisableFpView();
	static bool isFpViewChangingFailure();
	static void stopFpView();
	static bool isHanging();
	static bool isBury();

	static void forceFly(const TVec3f &, const TVec3f &, s32);
	static void setJumpVec(const TVec3f &);
	static void forceJump(const TVec3f &, u32);
	static void freeJump(const TVec3f &, u32);
	static void tornadoJump();
	static void tornadoJumpMini();
	static void becomeNormalJumpStatus();
	static void setFrontVecKeepUp(const TVec3f &, u16);
	static void setFrontVecTarget(const TVec3f &, u16);
	static void getThrowVec(TVec3f *);

	static void setTrans(const TVec3f &, u16);
	static void endRush(const RushEndInfo *);

	static void incLife(u32);
	static bool isConfrontDeath();
	static void incOxygen(u32);
	static void addStarPiece();
	static void getStarPieceDirect(); // dummied-out
	static void scatterStarPiece(u32);
	static MtxPtr getJointMtx(const char *);
	static void concatWithJointMtx(TMtx34f *, const char *);
	static TVec3f* getVelocity();
	static TVec3f* getLastMove();
	static void hide(bool);
	static void show();

	static HitSensor* getTakingSensor();
	static void dropTakingActor();
	static void killTakingActor();
	static f32 getAnimationFrameMax();
	static void changeAnimationJ(const char *);
	static void changeAnimationE(const char *, const char *);
	static void changeAnimationE(const char *, const BckCtrlData &);
	static void keepCurrentAnimation();
	static void progressAnimation();
	static const char* getCurrentBckName();
	static void setAnimationBlendWeight(const f32 *);
	static void setSpot(f32, u32); // dummied-out
	static void startDownWipe();
	static void offControl();
	static void isOffControl();
	static void onControl(bool);
	static void setStateWait();
	static void startTalk(const LiveActor *);
	static void endTalk();
	static void readyRemoteDemo();

	static void setBaseMtx(MtxPtr);
	static MtxPtr getBaseMtx();
	static bool calcSpinPullVelocity(TVec3f *, const TVec3f &);
	static void tryCoinPull();
	static void addVelocity(const TVec3f &);
	static void addVelocityFromArea(const TVec3f &);
	static bool isInWaterMode();
	static bool isOnWaterSurface();
	static bool calcWorldPadDir(TVec3f *, f32, f32);
	static void changeItemStatus(s32);
	static void changePlayerModeYoshi();
	static void changePlayerModeCloud();
	static void changePlayerModeRock();

	static MarioActor* getPlayerActor();
};
