#pragma once

#include "Game/Effect/SimpleEffectObj.h"

/* FINISHED */

class RandomEffectObj : public SimpleEffectObj {
public:
    RandomEffectObj(const char *pName);

    virtual ~RandomEffectObj();
    virtual void init(const JMapInfoIter &rIter);
    virtual void appear();
    virtual void control();

    s32 getRandomTime() const;

    s32 mRandomTime;   // _A0
    s32 _A4;           // useless timer
    s32 mAverageTime;  // _A8
    s32 mTimeDuration; // _AC
};
