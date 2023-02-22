#pragma once

#include "Game/LiveActor/LiveActor.h"

/* FINISHED */

class WaterFortressRain : public LiveActor {
public:
    WaterFortressRain(const char *pName);

    virtual void init(const JMapInfoIter &rIter);
    virtual void control();

    void exeRain();
    void exeRainSlow();

    TMtx34f mRainEffectMtx; // _90
};

namespace NrvWaterFortressRain {
    NERVE(WaterFortressRainNrvRain);
    NERVE(WaterFortressRainNrvRainSlow);
};
