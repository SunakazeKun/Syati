#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"

class ClippingJudge : public NameObj {
public:
    ClippingJudge(const char *pName);

    virtual ~ClippingJudge();
    virtual void init(const JMapInfoIter &rIter);
    virtual void movement();

    bool isJudgedToClipFrustum(const TVec3f &, f32, s32) const;
    void calcViewingVolume(THex3f *, f32);

    THex3f _14;
    THex3f _74[8];
};

namespace MR {
    ClippingJudge* getClippingJudge();
};
