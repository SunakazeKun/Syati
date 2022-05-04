#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActorGroup.h"

class ClipArea;

class StarLightAreaHolder : public LiveActorGroup {
public:
    StarLightAreaHolder(const char *pName);

    virtual ~StarLightAreaHolder();
    virtual void init(const JMapInfoIter &rIter);
    virtual void movement();
    
    bool isInStarLight(const TVec3f &rPosition);
    bool tryRegisterReceiver(HitSensor *pReceiver);

    HitSensor** mReceivers; // _20
    s32 _24; // unused
    s32 mNumReceivers;      // _28
};

namespace MR {
    void registerStarLightArea(ClipArea *pClipArea);
    bool tryRegisterStarLightReceiver(HitSensor *pReceiver);
};
