#pragma once

#include "Game/MapObj/ClipArea.h"

class LightFruitClipArea : public ClipArea {
public:
    LightFruitClipArea(const char *pName);

    virtual void init(const JMapInfoIter &rIter);
    virtual void control();

    void killGlow();
    void exeAppear();
    void exeDisappear();
    void playTimerSound();
};

namespace MR {
    void createLightFruitClipArea();
    void startYoshiLightFruit();
    void endYoshiLightFruit();
};

namespace NrvLightFruitClipArea {
    NERVE(LightFruitClipAreaNrvAppear);
    NERVE(LightFruitClipAreaNrvTimer);
    NERVE(LightFruitClipAreaNrvDisappear);
};
