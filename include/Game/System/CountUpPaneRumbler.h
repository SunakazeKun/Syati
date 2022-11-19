#pragma once

#include "syati.h"

class RumbleCalculatorCosMultLinear;

class CountUpPaneRumbler {
public:
    CountUpPaneRumbler(LayoutActor*, const char*);
    void update();
    void start();
    void reset();
    bool isRumbling();
    void connectPane(LayoutActor*, const char*);
    
    RumbleCalculatorCosMultLinear* mRumbleCalculatorCosMultLinear;
    f32 _04;
    f32 _08;
};