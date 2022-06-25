#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/Util/JMapInfo.h"

class MapObjActorInitInfo {
public:
    MapObjActorInitInfo();

    void setupHioNode(const char *pDebugName);
    void setupDefaultPos();
    void setupModelName(const char *pModelName);
    void setupConnectToScene();
    void setupBinder(f32, f32);
    void setupEffect(const char *pGroupName, s32 effectCount);
    void setupSound(s32 soundObjsCount, const char *pSoundObjName);
    void setupSoundPos(TVec3f *pSoundPos);
    void setupHitSensor();
    void setupHitSensorParam(u16 sensorCount, f32 sensorRadius, const TVec3f &rSensorOffset);
    void setupNerve(const Nerve *pNerve);
    void setupState(s32 stateCount);
    void setupShadow(const char *pShadowName);
    void setGroupClipping(s32 clippingGroupSize);
    void setupClippingRadius(f32 radius);
    void setupFarClipping(f32 distance);
    void setupProjmapMtx(bool, bool);
    void setupMultiFur(s32 type);
    void setupRailMover();
    void setupRotator();
    void setupRailRotator();
    void setupRailPosture();
    void setupBaseMtxFollowTarget();
    void setupAffectedScale();
    void setupSeAppear();
    void setupLightCtrl();
    void setupNoUseLodCtrl();

    // These functions no longer exist in SMG2 so they have been added back
    inline void setupNoAppearRiddleSE() {
        mUseSeAppear = false;
    }

    inline void setupHitSensorCallBack() {
        mUseBodySensorCallback = true;
    }

    inline void setupMirrorReflection(bool mirrorReflectionModelInfo) {
        mUseMirrorReflectionModelInfo = mirrorReflectionModelInfo;
        mUseMirrorReflection = true;
    }

    inline void setupPrepareChangeDummyTexture(const char *pTexName) {
        mChangeDummyTexture = pTexName;
    }

    bool mUseDefaultPos;				// _0
    bool mUseConnectToScene;			// _1
    bool mUseBinder;					// _2
    bool mUseEffectKeeper;				// _3
    bool mUseHitSensor;					// _4
    bool mUseShadow;					// _5
    bool mUseCalcGravity;				// _6
    bool mUseProjmapMtx;				// _7
    bool mUseMultiFur;					// _8
    bool mUseRailMover;					// _9
    bool mUseRotator;					// _A
    bool mUseRailRotator;				// _B
    bool mUseSeesaw1AxisRotator;		// _C
    bool mUseSeesaw2AxisRotator;		// _D
    bool mUseSeesaw2AxisRollerRotator;	// _E
    bool mUseRailPosture;				// _F
    bool mUseBaseMtxFollowTarget;		// _10
    bool mUseAffectedScale;				// _11
    bool mUseMirrorReflection;			// _12
    const char* mModelName;				// _14
    const char* mDebugName;				// _18
    s16 mBodySensorCount;				// _1C
    f32 mBodySensorRadius;				// _20
    TVec3f mBodySensorOffset;			// _24
    bool mUseBodySensorCallback;		// _30
    f32 mBinderArg0;					// _34
    f32 mBinderArg1;					// _38
    const char* mEffectGroupName;		// _3C
    s32 mEffectCount;					// _40
    s32 mSoundObjsCount;				// _44
    const char* mSoundObjName;			// _48
    TVec3f* mSoundObjPos;				// _4C
    bool _50;							// _50
    bool _51;							// _51
    Nerve* mNerve;						// _54
    s32 mStateCount;					// _58
    s32 mClippingGroupSize;				// _5C
    f32 mClippingRadius;				// _60
    f32 mFarClipDistance;				// _64
    s32 mMultiFurType;					// _68
    s32 mColorChange;					// _6C
    s32 mTextureChange;					// _70
    bool mUseSeAppear;					// _74
    const char* mSeesawSeName;			// _78
    f32 mSeesawSeRate;					// _7C
    bool mUseMirrorReflectionModelInfo;	// _80
    const char* mShadowName;			// _84
    f32 mShadowLength;					// _88
    const char* mBreakModelName;		// _8C
    const char* mChangeDummyTexture;	// _90
    int mLodModelMovementList;			// _94
    bool mUseLightCtrl;					// _98
    bool mNoUseLodCtrl;					// _99
};

namespace MapObjActorUtil {
    void setupInitInfoSimpleMapObj(MapObjActorInitInfo *pInfo);
    void setupInitInfoPlanet(MapObjActorInitInfo *pInfo);
    void setupInitInfoTypical(MapObjActorInitInfo *pInfo, const char *pObjName);
    void setupInitInfoColorChangeArg0(MapObjActorInitInfo *pInfo, const JMapInfoIter &rIter);
    void setupInitInfoTextureChangeArg1(MapObjActorInitInfo *pInfo, const JMapInfoIter &rIter);
    void setupInitInfoShadowLengthArg2(MapObjActorInitInfo *pInfo, const JMapInfoIter &rIter);
    void setupInitInfoSeesaw(MapObjActorInitInfo *pInfo, const JMapInfoIter &rIter, const char *pSeName, f32 seRate);
};
