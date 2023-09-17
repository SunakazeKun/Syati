#pragma once

#include "syati.h"
#include "Game/Screen/SysInfoWindow.h"

class PauseMenu : public LayoutActor {
public:
    PauseMenu();
    virtual void init(const JMapInfoIter& rIter);
    virtual void appear();
    virtual void kill();
    virtual void control();
    void forceToWaitAllButton();
    void exeSelecting();
    void exeDecided();
    void exeDisappear();
    void exeConfirm();
    void exeGameDataSave();

    ButtonPaneController* mButtonTop; // 0x2C
    ButtonPaneController* mButtonBottom; // 0x30
    ButtonPaneController* mButtonStarList; // 0x34
    LayoutActor* mAllStarList; // 0x38
    TVec2f mButtonTopFollowPos; // 0x3C
    TVec2f mButtonBottomFollowPos; // 0x44
    TVec2f mButtonStarListFollowPos; // 0x4C
    SysInfoWindow* mSysInfoWindow; // 0x54
    bool unk1; // 0x58
    bool unk2; // 0x59
    bool mIsUsedNewButton; // 0x5A NEW
    s32 unk3; // 0x5C

    #if defined (ALL) || defined (SMSS) || defined (CA)
    ButtonPaneController* mButtonNew; // 0x60 NEW
    TVec2f mButtonNewFollowPos; // 0x64 NEW
    #endif
};

namespace NrvPauseMenu {
    NERVE(PauseMenuNrvSelecting);
    NERVE(PauseMenuNrvDecided);
    NERVE(PauseMenuNrvDisappear);
    NERVE(PauseMenuNrvConfirm);
    NERVE(PauseMenuNrvGameDataSave);
};