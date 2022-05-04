#pragma once

#include "revolution.h"
#include "Game/LiveActor/ModelManager.h"

struct ActionBgmInfo {
    ActionBgmInfo();

    const char* mBckName;   // _0
    f32 mBckStartFrame;     // _4
    const char* mBgmName;   // _8
    s32 mBgmStateNo;        // _C
    bool mIsBgmStop;        // _10
    s32 mBgmFadeStep;       // _14
    const char* mStageName; // _18
    s32 mStageScenarioNo;   // _1C
    bool _20;
    bool _21;
};

class ActionBgmCtrl {
    ActionBgmCtrl(const ModelManager *pModelMgr);

    static ActionBgmCtrl* tryCreate(const ModelManager *pModelMgr);

    void update();
    void findAndUpdateBgm();
    void updateBgm(const ActionBgmInfo &rInfo);

    const ModelManager* mModelManager; // _0
    const char* mCurrentBck;           // _4
    s32 mNumInfos;                     // _8
    ActionBgmInfo* mBgmInfos;          // _C
};
