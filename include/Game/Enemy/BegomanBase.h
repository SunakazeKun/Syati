#pragma once

#include "Game/LiveActor/ChangeObj.h"

#define BEGOMAN_TYPE_BOSS 0
#define BEGOMAN_TYPE_SPIKE 1
#define BEGOMAN_TYPE_SPRING 2
#define BEGOMAN_TYPE_BABY 3

namespace MR {
    struct ActorMoveParam;
    class FunctorBase;
}

class JointController;
struct JointControllerInfo;
class BegomanBaby;
struct BegomanSound;

struct BegomanSound {
    const char* mSoundLabel;
};

class BegomanBase : public LiveActor, public ChangeObj {
public:
    BegomanBase(const char *pName);

    virtual ~BegomanBase();
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void kill();
    virtual void makeActorDead();
    virtual void startClipped();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void doChange(ChangeObj *pOther);

    virtual u32 getKind() const = 0;
    virtual bool onTouchElectric(const TVec3f &, const TVec3f &);
    virtual bool setNerveReturn() = 0;
    virtual void setNerveLaunch();
    virtual Nerve* getNerveWait() = 0;
    virtual void addVelocityOnPushedFromElectricRail(const TVec3f &, const TVec3f &);
    virtual bool requestAttack();

    BegomanSound& getSoundNormal();
    void initCore(const JMapInfoIter &rIter, const char *rModelName, bool);
    void initEffectAndStarPointerBind();
    void initShadow(f32 radius, const char *pJointName);
    void initEffect(s32 effectKeeperSize);
    void initSensor(s32 sensorKeeperSize, f32, f32, const char *pJointName);
    void initUseSwitchB(const JMapInfoIter &rIter, const MR::FunctorBase &rFunctor);

    void exeNoCalcWaitCore(f32, const Nerve *);
    void finishNoCalcWait();
    void exeWaitCore(const MR::ActorMoveParam &, const Nerve *, const Nerve *, const Nerve *);
    void exeSignAttackCore(const MR::ActorMoveParam &, const Nerve *);
    void exePursueCore(const MR::ActorMoveParam &, const Nerve *, const Nerve *, const BegomanSound &rBegoSound, f32);
    void exeTurnCore(const MR::ActorMoveParam &, const Nerve *, const Nerve *, bool);
    void exeBrakeCore(const Nerve *);
    void exeStepBackCore(const MR::ActorMoveParam &, const Nerve *);
    void exeProvokeCore(const MR::ActorMoveParam &, const Nerve *);
    void exeHitReactionCore(const MR::ActorMoveParam &, const Nerve *);
    void exeTiredCore(const MR::ActorMoveParam &, const Nerve *);
    void exeReturnCore(const Nerve *);
    void exeKeepDistanceCore(const Nerve *, const Nerve *, const Nerve *, f32, f32);
    void addVelocityEscapeToSide(f32);
    void exeLaunch();
    void exeBindStarPointer();

    bool tryAndSetStarPointerBind(const Nerve *);
    bool isNearInitPos();
    bool trySetReturnNerve();
    bool incAndCheckTiredCounter();
    void launchBegomanCore(LiveActor *, BegomanBase **, s32, f32, f32, f32, const TVec3f *);
    void launchBegomanBabyLauncher(LiveActor *, BegomanBaby **, s32, f32, f32, f32, const TVec3f *);
    void updateRotateY(f32, f32);
    void updateTargetVec();
    bool reboundPlaneWithEffect(const TVec3f &, f32, f32, const char *);
    void reboundWallAndGround(TVec3f *, bool);
    bool isFallNextMove(f32, f32);
    void calcDirectionAwayFromRail(TVec3f *, const TVec3f &, const TVec3f &);
    bool checkTouchElectricRail(bool);
    void pushedFromElectricRail(HitSensor *, const TVec3f &, const TVec3f &, f32, f32, bool);
    void preventSwingby(f32);
    void preventSlopeBlow(f32);
    void dampingVerticalAndParallelVelocity(f32, f32);
    bool isInWaterAndSetWaterNerve(const Nerve *, TMtx34f *);
    void calcBlowReaction(const TVec3f &, const TVec3f &, f32, f32);
    void calcAnimCore(TMtx34f *);
    bool calcJointLocator1(TMtx34f *, const JointControllerInfo &);

    s32 _98;
    TVec3f _9C;
    TVec3f _A8;
    TVec3f _B4;
    TVec3f _C0;
    f32 _CC[4];
    f32 _DC[4];
    s32 mTiredCounter; // _EC
    s32 _F0;
    TVec3f _F4;
    s32 _100;
    s32 _104;
    u8 _108;
    u8 _109;
};
