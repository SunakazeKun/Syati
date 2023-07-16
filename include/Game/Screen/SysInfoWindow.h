#pragma once
#include "syati.h"

class YesNoController;

class SysInfoWindow : public LayoutActor {
public:
    enum SysInfoWindowType {
        SysInfoWindowType_0,
        SysInfoWindowType_1
    };
    
    enum SysInfoExecuteType {
        SysInfoExecuteType_0,
        SysInfoExecuteType_1
    };

    enum SysInfoType {
        SysInfoType_0,
        SysInfoType_1,
        SysInfoType_2
    };

    enum SysInfoTextPos {
        SysInfoTextPos_0,
        SysInfoTextPos_1
    };

    enum SysInfoMessageType {
        SysInfoMessageType_0,
        SysInfoMessageType_1
    };

    SysInfoWindow(SysInfoWindowType, SysInfoExecuteType);
    virtual void init(const JMapInfoIter&);
    virtual void movement();
    virtual void calcAnim();
    virtual void draw() const;
    virtual void appear();
    void appear(const char*, SysInfoType, SysInfoTextPos, SysInfoMessageType);
    void disappear();
    virtual void kill();
    void forceKill();
    bool isWait() const;
    bool isSelectedYes() const;
    bool isDisappear() const;
    virtual void control();
    const char* getLayoutName() const;
    void exeWait();
    void exeDisappear();
    void setYesNoSelectorSE(const char*, const char*, const char*);
    void resetYesNoSelectorSE();
    void setTextBoxArgString(const wchar_t*, s32);
    ~SysInfoWindow();

    s32 _2C;
    s32 _30;
    YesNoController* mYesNoController; // 0x34
    IconAButton* mIconAButton; // 0x38
    const char* _3C;
    const char* _40;
    bool _44;
};

namespace MR {
    SysInfoWindow* createSysInfoWindow();
    SysInfoWindow* createSysInfoWindowExecuteWithChildren();
    SysInfoWindow* createSysInfoWindowMiniExecuteWithChildren();
}

namespace NrvSysInfoWindow {
    NERVE(SysInfoWindowNrvAppear);
    NERVE(SysInfoWindowNrvWair);
    NERVE(SysInfoWindowNrvDisappear);
}