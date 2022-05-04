#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/Util/JMapIdInfo.h"

class LiveActor;

class ClippingActorInfo {
public:
    ClippingActorInfo(LiveActor *pHost);

    void judgeClipping();
    bool isJudgedToClip() const;
    bool isGroupClipping() const;
    void setTypeToSphere(f32, const TVec3f *);
    void setGroupClippingNo(const JMapInfoIter &rIter);

    LiveActor* mHost; // _0
    TVec3f* _4;
    f32 mRadius; // _8
    JMapIdInfo* mClippingGroupId; // _C
    s16 _10;
    s16 _12;
    s32 _14;
};
