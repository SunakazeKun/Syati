#pragma once

#include "revolution.h"
#include "Game/LiveActor/ActionBgmCtrl.h"

class LiveActor;
class ActorAnimKeeper;
class ActionFlagCtrl;
class ActorPadAndCameraCtrl;
class ActorHitReactionCtrl;
class ActorItemGenerator;
class ActorParam;
class ActionScreenBlurCtrl;
class ActionFootPrintCtrl;

class ActorActionKeeper {
public:
    ActorActionKeeper(LiveActor *pActor, ActorAnimKeeper *pAnimKeeper, ActionFlagCtrl *pFlagCtrl, ActorPadAndCameraCtrl *pPadAndCameraCtrl,
        ActorHitReactionCtrl *pHitReactionCtrl, ActorItemGenerator *pItemGenerator, ActorParam *pActorParam, ActionScreenBlurCtrl *pScreenBlurCtrl,
        ActionFootPrintCtrl *pFootPrintCtrl, ActionBgmCtrl *pBgmCtrl);

    static ActorActionKeeper* tryCreate(LiveActor *pActor, const char *);

    void startAction(const char *pName);
    void initFlagCtrl();
    void updateAnimKeeper(); // stubbed
    void update();

    LiveActor* mHost;                         // _0
    ActorAnimKeeper* mAnimKeeper;             // _4
    ActionFlagCtrl* mFlagCtrl;                // _8
    ActorPadAndCameraCtrl* mPadAndCameraCtrl; // _C
    ActorHitReactionCtrl* mHitReactionCtrl;   // _10
    ActorItemGenerator* mItemGenerator;       // _14
    ActorParam* mActorParam;                  // _18
    ActionScreenBlurCtrl* mScreenBlurCtrl;    // _1C
    ActionFootPrintCtrl* mFootPrintCtrl;      // _20
    ActionBgmCtrl* mBgmCtrl;                  // _24
};
