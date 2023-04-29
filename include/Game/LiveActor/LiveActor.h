#pragma once

#include "revolution.h"
#include "Game/LiveActor/ActorActionKeeper.h"
#include "Game/LiveActor/ActorLightCtrl.h"
#include "Game/LiveActor/ActorPadAndCameraCtrl.h"
#include "Game/LiveActor/ActorSoundHolder.h"
#include "Game/LiveActor/Binder.h"
#include "Game/LiveActor/EffectKeeper.h"
#include "Game/LiveActor/ModelManager.h"
#include "Game/LiveActor/RailRider.h"
#include "Game/LiveActor/HitSensor.h"
#include "Game/LiveActor/HitSensorKeeper.h"
#include "Game/LiveActor/ShadowController.h"
#include "Game/LiveActor/Spine.h"
#include "Game/Map/CollisionParts.h"
#include "Game/Map/StageSwitch.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Screen/StarPointerTarget.h"

class ResourceHolder;

class LiveActorFlag {
public:
    LiveActorFlag();

    bool mIsDead;                 // _0
    bool mIsNotReleasedAnimFrame; // _1
    bool mIsOnCalcAnim;           // _2
    bool mIsNoCalcView;           // _3
    bool mIsNoEntryDrawBuffer;    // _4
    bool mIsOnBind;               // _5
    bool mIsCalcGravity;          // _6
    bool mIsClipped;              // _7
    bool mIsClippingInvalid;      // _8
};

class LiveActor : public NameObj {
public:
    LiveActor(const char *pName);

    virtual ~LiveActor();
    virtual void init(const JMapInfoIter &rIter);
    virtual void movement();
    virtual void calcAnim();
    virtual void calcViewAndEntry();

    virtual void appear();
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void makeActorDead();
    virtual bool receiveMessage(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual TMtx34f* getBaseMtx() const;
    virtual TMtx34f* getTakingMtx() const;
    virtual void startClipped();
    virtual void endClipped();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void updateHitSensor(HitSensor *pSensor);
    virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPush(HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

    void initModelManagerWithAnm(const char *, const char *, const char *, bool);
    void initNerve(const Nerve *pNerve, s32);
    void initHitSensor(s32 sensorCount);
    void initBinder(f32, f32, u32);
    void initRailRider(const JMapInfoIter &rIter);
    void initEffectKeeper(s32 effectCount, const char *pGroupName, bool);
    void initSound(s32 soundCount, const char *pObjectName, const TVec3f *pSoundPos, const TVec3f &rSoundOffset);
    void initShadowControllerList(u32);
    void initActorCollisionParts(const char *, HitSensor *, ResourceHolder *, MtxPtr, bool, bool);
    void initStageSwitch(const JMapInfoIter &rIter);
    void initActorStarPointerTarget(f32, const TVec3f *, MtxPtr, TVec3f);
    void initActorLightCtrl();

    void setNerve(const Nerve *pNerve);
    bool isNerve(const Nerve *pNerve) const;
    s32 getNerveStep() const;

    HitSensor* getSensor(const char *pSensorName) const;

    void calcAnmMtx();
    void updateBinder();

    TVec3f mTranslation;                     // _14
    TVec3f mRotation;                        // _20
    TVec3f mScale;                           // _2C
    TVec3f mVelocity;                        // _38
    TVec3f mGravity;                         // _44
    ActorActionKeeper* mActionKeeper;        // _50
    ModelManager* mModelManager;             // _54
    Spine* mSpine;                           // _58
    HitSensorKeeper* mSensorKeeper;          // _5C
    Binder* mBinder;                         // _60
    RailRider* mRailRider;                   // _64
    EffectKeeper* mEffectKeeper;             // _68
    ActorSoundHolder* mSoundHolder;          // _6C
    LiveActorFlag mFlags;                    // _70
    ShadowControllerList* mShadowController; // _7C
    CollisionParts* mCollisionParts;         // _80
    StageSwitchCtrl* mStageSwitchCtrl;       // _84
    StarPointerTarget* mPointerTarget;       // _88
    ActorLightCtrl* mLightCtrl;              // _8C
};
