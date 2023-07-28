#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class PowerStar : public LiveActor {
public:
    PowerStar(const char *pName);

    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

    void initMapToolInfo(const JMapInfoIter &rIter);

    void calcAppearDemoRiseTrans(TVec3f *pDest, f32 yOffset) const;
    void applyAppearDemoRiseTrans(const TVec3f &rDest, f32 yOffset, f32);

    void processWait(f32);
    bool isEndAppearDemo() const;

    s32 mPowerStarId; //_90
    u8 _94[0x178 - 0x94];
};
