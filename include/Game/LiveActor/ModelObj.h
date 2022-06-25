#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class DemoObj : LiveActor {
public:
    DemoObj(const char *pName, MtxPtr pMtx);

    virtual ~DemoObj();
    virtual void init(const JMapInfoIter &rIter);
    virtual void calcAndSetBaseMtx();

    MtxPtr mMtx; // _90
};

class ModelObj : public LiveActor {
public:
    ModelObj(const char *pName, const char *pModelName, MtxPtr pMtx, int drawBuffer, int movementList, int calcAnimList, bool);

    virtual ~ModelObj();
    virtual void init(const JMapInfoIter &rIter);
    virtual void calcAndSetBaseMtx();

    MtxPtr mMtx; // _90
};

class CollisionObj : public LiveActor {
public:
    CollisionObj(LiveActor *pHost, const char *pName, const char *pCollisionName, bool useBodySensor, MtxPtr pMtx, int movementType);

    virtual void init(const JMapInfoIter &rIter);
    virtual void movement();
    virtual TMtx34f* getBaseMtx() const;

    MtxPtr mMtx; // _90
};
