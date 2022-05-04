#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class ModelObj : public LiveActor {
public:
    ModelObj(const char *pName, const char *pModelName, MtxPtr pMtx, int drawBuffer, int movementList, int calcAnimList, bool);

    virtual ~ModelObj();
    virtual void init(const JMapInfoIter &rIter);
    virtual void calcAndSetBaseMtx();

    MtxPtr mMtx; // _90
};
