#pragma once

#include "Game/Screen/LayoutActor.h"

class IconAButton : public LayoutActor {
public:
    IconAButton(bool, bool);

    virtual ~IconAButton();
    virtual void init(const JMapInfoIter &rIter);
    virtual void control();

    void setFollowActorPane(LayoutActor *, const char *);
    bool isOpen();
    void openWithTalk();
    void openWithRead();
    void openWithoutMessage();
    void term();
    void exeOpen();
    void exeTerm();
    void updateFollowPos();

    TVec2f _2C;
    LayoutActor* _34;
    bool _38;
    u8 _39[0x17];
};

namespace NrvIconAButton {
    NERVE(IconAButtonNrvOpen);
    NERVE(IconAButtonNrvWait);
    NERVE(IconAButtonNrvTerm);
};
