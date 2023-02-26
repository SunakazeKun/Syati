#pragma once

#include "revolution.h"
#include "Game/LiveActor/ActorStateBase.h"

/* FINISHED */

class ActorStateKeeper {
public:
    ActorStateKeeper(int initStateCount);

    void addState(ActorStateBaseInterface *pActorState, const Nerve *pNerve, const char *pName);
    bool updateCurrentState();
    void startState(const Nerve *pNerve);
    bool isDead() const;
    void endState(const Nerve *pNerve);
    Spine* findStateInfo(const Nerve *pNerve);

    s32 mStateSize;                   // _0
    s32 mStateCount;                  // _4
    ActorStateBaseInterface* mStates; // _8
    Spine* mCurrentState;             // _C
};
