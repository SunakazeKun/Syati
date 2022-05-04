#pragma once

#include "Game/LiveActor/ClippingActorHolder.h"
#include "Game/LiveActor/ClippingGroupHolder.h"
#include "Game/LiveActor/ClippingJudge.h"

class LodCtrl;

class ClippingDirector : public NameObj {
public:
    ClippingDirector();

    virtual ~ClippingDirector();
    virtual void movement();

    void endInitActorSystemInfo();
    void registerActor(LiveActor *);
    void initActorSystemInfo(LiveActor *, const JMapInfoIter &);
    void joinToGroupClipping(LiveActor *, const JMapInfoIter &, s32);
    void entryLodCtrl(LodCtrl *, const JMapInfoIter &);

    ClippingJudge* mJudge; // _C
    ClippingActorHolder* mActorHolder; // _10
    ClippingGroupHolder* mGroupHolder; // _14
};

namespace MR {
    ClippingDirector* getClippingDirector();
    void addToClippingTarget(LiveActor *);
    void removeFromClippingTarget(LiveActor *);
};
