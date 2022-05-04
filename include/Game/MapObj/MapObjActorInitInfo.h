#pragma once

#include "revolution.h"
#include "JSystem.h"

class MapObjActorInitInfo {
public:
	MapObjActorInitInfo();

	void setupHioNode(const char *);
	void setupDefaultPos();
	void setupModelName(const char *);
	void setupConnectToScene();
	void setupBinder(f32, f32);
	void setupEffect(const char *, s32);
	void setupSound(s32, s32);
	void setupSoundPos(TVec3f *);
	void setupHitSensor();
	void setupHitSensorParam(u16, f32, const TVec3f &);
	void setupNerve(const Nerve *);
	// unknown function at 802CBDA0, takes s32 and stores it in mNerveArg
	void setupShadow(const char *);
	void setGroupClipping(s32);
	void setupClippingRadius(f32);
	void setupFarClipping(f32);
	void setupProjmapMtx(bool, bool);
	void setupMultiFur(s32);
	void setupRailMover();
	void setupRotator();
	void setupRailRotator();
	void setupRailPosture();
	void setupBaseMtxFollowTarget();
	void setupAffectedScale();
	void setupSeAppear();
	void setupLightCtrl();
	void setupNoUseLodCtrl();

	bool mInitDefaultPos; // 0
	bool mInitConnectToScene; // 1
	bool mInitBinder; // 2
	bool mInitEffect; // 3
	bool mInitHitSensor; // 4
	bool mInitShadow; // 5
	bool mInitCalcGravity; // 6
	bool mInitProjmapMtx; // 7
	bool mInitMultiFur; // 8
	bool mInitRailMover; // 9
	bool mInitRotator; // A
	bool mInitRailRotator; // B
	bool mInitSeesaw1AxisRotator; // C
	bool mInitSeesaw2AxisRotator; // D
	bool mInitSeesaw2AxisRollerRotator; // E
	bool mInitRailPosture; // F
	bool mInitBaseMtxFollowTarget; // 10
	bool mInitAffectedScale; // 11
	bool mInitMirrorReflection; // 12
	const char* mModelName; // 14
	const char* mHioNode; // 18
	s16 mHitSensorMessage; // 1C
	f32 mHitSensorRadius; // 20
	TVec3f mHitSensorOffset; // 24
	bool mInitHitSensorCallback; // 30
	f32 mBinderArg1; // 34
	f32 mBinderArg2; // 38
	const char* mEffectGroupName; // 3C
	s32 mNumEffects; // 40
	s32 mNumSounds; // 44
	const char* mSoundObjName; // 48
	TVec3f* mSoundPos; // 4C
	bool mProjmapMtxArg2; // 50
	bool mProjmapMtxArg1; // 51
	Nerve* mNerve; // 54
	s32 mNerveArg; // 58
	s32 mGroupClipping; // 5C
	f32 mClippingRadius; // 60
	f32 mFarClipping; // 64
	s32 mMultiFurArg; // 68
	s32 mColorChangeArg; // 6C
	s32 mTextureChangeArg; // 70
	bool mUseSeAppear; // 74
	const char* mSeesawName; // 78
	f32 mSeesawRotatorArg; // 7C
	bool mMirrorReflectionArg; // 80
	const char* mShadowName; // 84
	f32 mShadowLength; // 88
	const char* mBreakModelName; // 8C
	const char* mCollisionName; // 90
	s32 mLodCtrlArg; // 94
	bool mInitLightCtrl; // 98
	bool mNoUseLodCtrl; // 99
};

namespace MapObjActorUtil {
	void setupInitInfoSimpleMapObj(MapObjActorInitInfo *);
	void setupInitInfoPlanet(MapObjActorInitInfo *);
	void setupInitInfoTypical(MapObjActorInitInfo *, const char *);
	void setupInitInfoColorChangeArg0(MapObjActorInitInfo *, const JMapInfoIter &);
	void setupInitInfoTextureChangeArg1(MapObjActorInitInfo *, const JMapInfoIter &);
	void setupInitInfoShadowLengthArg2(MapObjActorInitInfo *, const JMapInfoIter &);
	void setupInitInfoSeesaw(MapObjActorInitInfo *, const JMapInfoIter &, const char *, f32);
};
