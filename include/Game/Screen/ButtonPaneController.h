#pragma once

#include "Game/System/NerveExecutor.h"
#include "Game/Screen/LayoutActor.h"

class ButtonPaneController : public NerveExecutor {
public:
    ButtonPaneController(LayoutActor *pHost, const char *, const char *, u32, bool);

    virtual ~ButtonPaneController();

    void update();
    void appear();
    void disappear();
    bool trySelect();

    bool isHidden() const;
    bool isPointing() const;
    bool isPointingTrigger() const;

    bool isTimingForSelectedSe() const;

    bool isAppearing() const;
    bool isDisappearing() const;
    void forceToWait();
    void forceToHide();
    bool isFirstStepWait() const;
    bool isWait() const;
    bool isDecidedWait() const;
    bool startAnimAtFirstStep(const char *);
    bool startPointingAnimAtFirstStep(const char *);
    void setNerveAtAnimStopped(const Nerve *);
    bool isPointingPane() const;
    bool tryPointing(bool);
    bool tryNotPointing(bool);
    f32 calcPointingAnimStartFrame() const;
    void exeHidden();
    void exeAppear();
    void exeWait();
    void exePointing();
    void exeNotPointing();
    void exeDecided();
    void exeDecidedToDisappear();

    LayoutActor* mHost;
    const char* mPaneName1;
    const char* mPaneName2;
    u32 _14;
    s32 _18;
    bool _1C;
    f32 _20;
    bool _24;
    bool _25;
    bool _26;
    bool _27;
    bool _29;
    s32 _2C;
    const char* mAnimNameAppear; // 0x30
    const char* mAnimNameWait; // 0x34
    const char* mAnimNameDecide; // 0x38
    const char* mAnimNameSelectIn; // 0x3C
    const char* mAnimNameSelectOut; // 0x40
    const char* mAnimNameEnd; // 0x44
    s32 _48;
    s32 _4C;
};
