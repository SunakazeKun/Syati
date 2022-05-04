#pragma once

#include "Game/Enemy/BegomanBase.h"

class BegomanBaby : public BegomanBase {
public:
    BegomanBaby(const char *pName);
    BegomanBaby(NameObj *pHost, const char *pName);

    virtual ~BegomanBaby();
    virtual void init(const JMapInfoIter &rIter);
    virtual void appear();
    virtual void kill();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPush(HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual u32 getKind() const;
    virtual bool onTouchElectric(const TVec3f &, const TVec3f &);
    virtual bool setNerveReturn();
    virtual Nerve* getNerveWait();

    void appearFromLaunch(const TVec3f &, const TVec3f &);
    void killWithGenItem();
    void exeSignAttack();
    void exePursue();
    void exeTrample();
    void exeBlow();
    void exeAfterLaunch();
    void exeAfterLaunchOnGround();
    void exeLaunchTurn();
    void exeInWater();

    bool receiveMsgTrample(HitSensor *pSender, HitSensor *pReceiver);
    bool calcHeadJoint(TMtx34f *pMtx, const JointControllerInfo &rJointCtrlInfo);

    JointController* mJointCtrl; // _10C
    TMtx34f mWaterColumnMtx;     // _110
    NameObj* mHost;              // _140
    bool mDrop3StarPiece;        // _144
};

namespace NrvBegomanBaby {
    ENDABLE_NERVE(HostTypeNrvNoCalcWait);
    NERVE(HostTypeNrvWait);
    NERVE(HostTypeNrvSignAttack);
    NERVE(HostTypeNrvPursue);
    NERVE(HostTypeNrvTurn);
    NERVE(HostTypeNrvBrake);
    NERVE(HostTypeNrvStepBack);
    NERVE(HostTypeNrvReturn);
    NERVE(HostTypeNrvProvoke);
    NERVE(HostTypeNrvTrample);
    NERVE(HostTypeNrvHitReaction);
    NERVE(HostTypeNrvTired);
    NERVE(HostTypeNrvBlow);
    NERVE(HostTypeNrvAfterLaunch);
    NERVE(HostTypeNrvAfterLaunchOnGround);
    NERVE(HostTypeNrvLaunchFromGuarder);
    NERVE(HostTypeNrvLaunchTurn);
    NERVE(HostTypeNrvInWater);
    NERVE(HostTypeNrvKeepDistance);
    NERVE(HostTypeNrvBindStarPointer);
};
