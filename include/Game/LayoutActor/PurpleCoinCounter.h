#pragma once

#include "syati.h"

class PurpleCoinCounter : public LayoutActor {
public:
    PurpleCoinCounter(char const *);
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    void validate();
    virtual void control();
    void updateCounter();
    void exeAppear();

    s32 _2C;
    s32 _30;
    s32 _34;
    CounterLayoutAppearer* mCounterLayoutAppearer;
    s32 _3C; // CountUpPaneRumbler
    s32 _40;
};