#pragma once

#include "syati.h"

class AirBubble : public LiveActor {
public:

    AirBubble(const char*);
    virtual void init(const JMapInfoIter&);
    virtual void initAfterPlacement();
    virtual void control();
    void appearMove(const TVec3f&, s32);
    void exeWait();
    void exeMove();
    void exeBreak();
    virtual bool receiveMsgPush(u32, HitSensor*, HitSensor*);
    virtual bool receiveOtherMsg(u32, HitSensor*, HitSensor*);
    bool canSpinGet();

    s32 _90;
    s32 _94;
    s32 _98;
    s32 _9C;
    s32 _A0;
    s32 _A4;
    s32 _A8;
    s32 _AC;
};

namespace NrvAirBubble {
    NERVE(AirBubbleNrvKillWait);
    NERVE(AirBubbleNrvBreak);
    NERVE(AirBubbleNrvMove);
    NERVE(AirBubbleNrvWait);
};