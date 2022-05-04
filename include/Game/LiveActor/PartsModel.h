#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/Util/FixedPosition.h"

class PartsModel : public LiveActor {
public:
    PartsModel(LiveActor *pHost, const char *pName, const char *pModelName, MtxPtr pMtx, s32, bool);

    virtual ~PartsModel();
    virtual void init(const JMapInfoIter &);
    virtual void movement();
    virtual void calcAnim();
    virtual void calcViewAndEntry();
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void calcAndSetBaseMtx();

    void initFixedPosition(const TVec3f &, const TVec3f &, const char *);
    void initFixedPosition(const char *);
    void initFixedPosition(MtxPtr, const TVec3f &, const TVec3f &);
    void loadFixedPosition(const char*, const LiveActor*);
    void offFixedPosNormalizeScale();

    LiveActor* mHost;         // _90
    FixedPosition* mFixedPos; // _94
    MtxPtr mMtx;              // _98
    bool mCalcOwnMatrix;      // _9C
    bool _9D;
    bool mIsDead;             // _9E
};
