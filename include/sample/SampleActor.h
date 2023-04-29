#pragma once

#include "Game/LiveActor/LiveActor.h"

class SampleActor : public LiveActor {
public:
    SampleActor(const char *pName);

    virtual void init(const JMapInfoIter &rIter);
    virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
};
