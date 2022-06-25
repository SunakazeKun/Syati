#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class SimpleJ3DModelDrawer : public LiveActor {
    SimpleJ3DModelDrawer(NameObj *pHost, const char *pName, const char *pModelName, int drawType);

    virtual ~SimpleJ3DModelDrawer();

    void initDraw() const;

    void* _90; // J3DMaterial
    void* _94; // J3DShape
    s32 _98;
};
