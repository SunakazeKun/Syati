#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class StarPiece : public LiveActor {
public:
    StarPiece(const char *pName);

    virtual ~StarPiece();
    virtual void init(const JMapInfoIter &rIter);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void makeActorDead();
    virtual void startClipped();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

    TVec3f _90;
    f32 _9C;
    f32 _A0;
    f32 _A4;
    f32 _A8;
    TVec3f _AC;
    TVec3f _B8;
    s32 _C4;
    s32 _C8;
    s32 _CC;
    s32 _D0;
    s32 _D4;
    s32 _D8;
    J3DGXColor mColor; // _DC
    s32 mGroupType;    // _E0
    s32 _E4;
    s32 _E8;
    s32 _EC;
    u8 mMiscFlags;     // _F0
};

namespace NrvStarPiece {
    NERVE(HostTypeNrvFloating);
    NERVE(HostTypeNrvHop);
    NERVE(HostTypeNrvFall);
    NERVE(HostTypeNrvFallAfterReflect);
    NERVE(HostTypeNrvToTarget);
    NERVE(HostTypeNrvSpinDrained);
    NERVE(HostTypeNrvToPlayerEnd);
    ENDABLE_NERVE(HostTypeNrvThrow);
    ENDABLE_NERVE(HostTypeNrvThrowNoFall);
    ENDABLE_NERVE(HostTypeNrvThrowFall);
    NERVE(HostTypeNrvFollowPlayer);
    NERVE(HostTypeNrvRailMove);
};
