#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/Enemy/WalkerStateBindStarPointer.h"
#include "Game/Player/YoshiLockOnTarget.h"

#define KAMECK_BEAM_FIRE 1
#define KAMECK_BEAM_TURTLE 2
#define KAMECK_BEAM_KURIBO_MINI 3
#define KAMECK_BEAM_MERAMERA 4

class KameckBeamEventListener;
class KameckBeamHolder;

class Kameck : public LiveActor {
public:
    Kameck(const char *pName);

    virtual ~Kameck();
    virtual void init(const JMapInfoIter &rIter);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void kill();
    virtual void makeActorDead();
    virtual void startClipped();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgOtherAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

    void initBeam();
    void initJMapParam(const JMapInfoIter &rIter);
    void initDemo(const JMapInfoIter &rIter);

    s32 _90;
    KameckBeamHolder* mBeamHolder;                // _94
    KameckBeamEventListener* mEventListener;      // _98
    AnimScaleController* mAnimScaleCtrl;          // _9C
    WalkerStateBindStarPointer* mBindStarPointer; // _A0
    f32 _A4;
    f32 _A8;
    f32 _AC;
    f32 _B0;
    f32 _B4;
    f32 _B8;
    f32 _BC;
    s32 _C0;
    f32 _C4;
    f32 _C8;
    s32 mBeamType;                                // _CC
    s32 mProjCount;                               // _D0
    s32 _D4;
    f32 _D8;
    YoshiLockOnTarget* mYoshiTarget;              // _DC
};

namespace NrvKameck {
    NERVE(KameckNrvOpeningDemo);
    NERVE(KameckNrvDemoAppear);
    NERVE(KameckNrvNonActive);
    NERVE(KameckNrvAppear);
    NERVE(KameckNrvWait);
    NERVE(KameckNrvHide);
    // one more here
    NERVE(KameckNrvAttackWait);
    NERVE(KameckNrvAttack);
    NERVE(KameckNrvGuard);
    NERVE(KameckNrvHit);
    NERVE(KameckNrvMoveHide);
    NERVE(KameckNrvMove);
    NERVE(KameckNrvBindStarPointer);
    NERVE(KameckNrvDown);
    NERVE(KameckNrvPressDown);
    // one more here
};
