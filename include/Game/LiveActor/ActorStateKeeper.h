#pragma once

#include "revolution.h"
#include "Game/LiveActor/ActorStateBase.h"

class ActorStateKeeper {
public:
    ActorStateKeeper(s32);

    void addState(ActorStateBaseInterface *pState, const Nerve *pNerve, const char *pName);
    bool updateCurrentState();
    void startState(const Nerve *);
    void endState(const Nerve *);
    Spine* findStateInfo(const Nerve *);

    s32 mStateCount;                  // _0
    u32 _4;
    ActorStateBaseInterface* mStates; // _8
    Spine* mCurrentState;             // _C
};
