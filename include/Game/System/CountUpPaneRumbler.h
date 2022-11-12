#pragma once

#include "syati.h"

class CountUpPaneRumbler {
public:
    CountUpPaneRumbler(LayoutActor*, const char*);
    void update();
    void start();
    void reset();
    bool isRumbling();
    void connectPane(LayoutActor*, const char*);
};