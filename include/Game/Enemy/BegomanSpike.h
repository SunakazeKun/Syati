#pragma once

#include "Game/Enemy/BegomanBase.h"

class BegomanSpike : public BegomanBase {
public:
    BegomanSpike(const char *pName);

    virtual ~BegomanSpike();
    virtual void init(const JMapInfoIter &rIter);
    virtual void calcAnim();
    virtual void appear();
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void control();
    virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPush(HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual u32 getKind() const;
    virtual bool onTouchElectric(const TVec3f &, const TVec3f &);
    virtual bool setNerveReturn();
    virtual Nerve* getNerveWait();

    s32 _10C;
    TMtx34f _110;
    s32 _140;
    TMtx34f _144;
    bool _174;
};
