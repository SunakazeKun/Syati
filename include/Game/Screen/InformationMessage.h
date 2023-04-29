#pragma once

#include "revolution.h"
#include "Game/Screen/LayoutActor.h"
#include "Game/Screen/IconAButton.h"

/* FINISHED */

class InformationMessage : public LayoutActor {
public:
    enum WINDOW_TYPE {
        InformationMessage_WindowUp,
        InformationMessage_WindowCenter,
        InformationMessage_WindowDown
    };

    InformationMessage(bool connectToScene);

    virtual ~InformationMessage();
    virtual void init(const JMapInfoIter &rIter);
    virtual void movement();
    virtual void draw() const;
    virtual void calcAnim();
    virtual void appear();
    virtual void kill();

    void setAButtonPos();
    void disappear();
    void setMessage(const char *pMessageName);
    void setMessage(const wchar_t *pMessage);
    void setReplaceString(const wchar_t *pReplaceString, s32 index);
    const char* getInfConfirmName() const;
    
    void exeWait();
    void exeDisappear();

    IconAButton* mIconAButton; // _2C
    WINDOW_TYPE mWindowType;   // _30
    bool mConnectToScene;      // _34
    bool mCanClose;            // _35
};

namespace NrvInformationMessage {
    NERVE(InformationMessageNrvAppear);
    NERVE(InformationMessageNrvWait);
    NERVE(InformationMessageNrvDisappear);
};
