#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/Util/Color8.h"

class VolumeDrawer : public LiveActor {
public:
    VolumeDrawer(char const *pName, char const *pModelName, MtxPtr pMtx, int drawType);

    virtual ~VolumeDrawer();
    virtual void init(const JMapInfoIter &rIter);
    virtual void draw() const;
    virtual void control();
    virtual void calcAndSetBaseMtx();

    void setHost(const LiveActor *pHost);
    void setColor(const Color8 &rColor);
    void setDrawPasses(s32 drawPasses);
    void setScale(const TVec3f &rFullScale);
    void setScaleUpRate(s32 scaleUpSteps);
    void setScaleDownRate(s32 scaleDownSteps);

    bool isShowVolume() const;
    void preScaleDrawPass(s32 drawPass) const;

    MtxPtr mMtx;            // _90
    const LiveActor *mHost; // _94
    Color8 mVolumeColor;    // _98
    s32 mDrawPasses;        // _9C
    TVec3f mFullScale;      // _A0
    f32 mScaleFactor;       // _AC
    f32 mScaleRate;         // _B0
    bool _B4;               // unused
};

namespace MR {
    VolumeDrawer* createVolumeDrawer(const char *pName, const char *pModelName, MtxPtr pMtx);
};
