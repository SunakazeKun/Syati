#pragma once

#include "syati.h"

class TimeLimitLayout : public LayoutActor {
public:
    TimeLimitLayout(u32 unk);
    virtual void init(const JMapInfoIter& rIter);
    virtual void appear();
    virtual void kill();
    void setTimeLimit(u32 time);
    void setDisplayModeOnNormal(bool);
    bool isReadyToTimeUp() const;
    void resetFrame();
    void exeAppear();
    void exeCountDown();
    void updateTextBox();
    void exeScaleUp();
    void exeScaleKeep();
    void exeScaleDown();
    void exeFadeout();
    virtual void control();
    s32 getCurrentTiming() const;
    void updateNormal();
    virtual ~TimeLimitLayout();
    
    s32 _2C;
    s32 _30;
    ValueControl* mValueControl;
    s32 _38;
    s32 _3C;
    bool _40;
    bool mDisplayMode;
};

