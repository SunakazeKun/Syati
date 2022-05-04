#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/System/NerveExecutor.h"

class LiveActor;

struct AnimScaleParam {
    AnimScaleParam();

    f32 _0;
    f32 _4;
    f32 _8;
    f32 _C;
    f32 _10; // dpdvib
    f32 _14; // dpdvib
    f32 _18; // dpdvib
    f32 _1C; // dpdvib
    f32 _20; // hitreac
    f32 _24; // hitreac
    f32 _28; // hitreac
    s32 _2C;
    f32 _30;
};

class AnimScaleController : public NerveExecutor {
public:
    AnimScaleController(AnimScaleParam *pAnimScaleParam);

    virtual ~AnimScaleController();

    void setParamTight();
    void startAnim();
    void startDpdHitVibration();
    void startHitReaction();
    void startScaleVelocityY(f32);
    void startAndAddScaleVelocityY(f32);
    void startCrush();
    void stopAndReset();
    void stop();
    void resetScale();
    void exeHitReaction();
    void exeDpdVibration();
    void exeCrush();
    bool isHitReaction(s32) const;
    bool tryStop();
    void update();
    void updateScale(f32, f32);

    AnimScaleParam* mAnimScaleParam;
    TVec3f mScale; // _C;
    f32 _18;
};

namespace NrvAnimScaleController {
    NERVE(AnimScaleControllerNrvAnim);
    NERVE(AnimScaleControllerNrvStop);
    NERVE(AnimScaleControllerNrvDpdVibration);
    NERVE(AnimScaleControllerNrvHitReaction);
    NERVE(AnimScaleControllerNrvCrush);
};

namespace MR {
    void updateBaseScale(LiveActor *, AnimScaleController *);
};
