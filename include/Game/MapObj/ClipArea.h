#pragma once

#include "Game/LiveActor/LiveActor.h"

class ClipAreaShape;

class ClipArea : public LiveActor {
public:
    ClipArea(const char *pName);

    virtual ~ClipArea();
    virtual void init(const JMapInfoIter &rIter);
    virtual void draw() const;
    virtual TMtx34f* getBaseMtx() const;
    virtual bool isInArea(const TVec3f &, f32) const;

    void initBaseMatrix(const JMapInfoIter &rIter);
    void setShape(ClipAreaShape *pShape);

    TMtx34f mBaseMtx;      // _90
    ClipAreaShape* mShape; // _C0
};

namespace MR {
    void setClipSphereArea(ClipArea *pArea);
    void setClipCenterBoxArea(ClipArea *pArea);
    void setClipBottomBoxArea(ClipArea *pArea);
    void setClipCylinderArea(ClipArea *pArea);
    void setClipTopConeArea(ClipArea *pArea);
    void setClipBottomConeArea(ClipArea *pArea);
};
