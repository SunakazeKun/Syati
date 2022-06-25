#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"

namespace {
    // getVertexFormat(const J3DModelData *, GXAttr);
};

class MirrorCamera : public NameObj {
public:
    MirrorCamera(const char *pName);

    virtual void init(const JMapInfoIter &rIter);
    virtual void movement();

    void setMirrorMapInfo(const TVec3f &, const TVec3f &);
    void setMirrorMapInfo(J3DModelData *);
    void updateViewMtx();
    void updateModelTexMtx();
    f32 getDistance(const TVec3f &rPosition) const;

    TVec3f _14;
    TVec3f _20;
    f32 _2C;
    TMtx34f mViewMtx;     // _30
    TMtx34f mModelTexMtx; // _60
};

namespace MR {
    MirrorCamera* getMirrorCamera();
    f32 getDistanceToMirror(const TVec3f &rPosition);
};
