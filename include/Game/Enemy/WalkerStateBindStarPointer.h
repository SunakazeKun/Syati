#pragma once

#include "revolution.h"
#include "Game/Enemy/AnimScaleController.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/ActorStateBase.h"

class WalkerStateBindStarPointer : public ActorStateBaseInterface {
public:
    WalkerStateBindStarPointer(LiveActor *pActor, AnimScaleController *pAnimScaleCtrl);

    virtual ~WalkerStateBindStarPointer();
    virtual void appear();
    virtual void kill();

    bool tryStartPointBind() const;
    void exeBind();

    LiveActor* mActor; // _C
    AnimScaleController* mAnimScaleCtrl; // _10
    s32 mNoBindStepCount; // _14
    bool mUsePointerTouchEffect; // _18
};

namespace NrvWalkerStateBindStarPointer {
    NERVE(WalkerStateBindStarPointerNrvBind);
};
