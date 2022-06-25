#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/System/NerveExecutor.h"

class AnimationRandomPlayer : public NerveExecutor {
public:
    AnimationRandomPlayer(const LiveActor *pActor, const char *pWaitAnim, const char *pPlayAnim, s32 averageStep, f32 stepScale);

    virtual ~AnimationRandomPlayer();

    void updateStartStep();
    void exeWait();
    void exePlay();

    const LiveActor* mHost;  // _8
    const char* mPlayAction; // _C
    const char* mWaitAction; // _10
    s32 mStartStep;          // _14
    s32 mAverageStep;        // _18
    f32 mStepScale;          // _1C
};

namespace NrvAnimationRandomPlayer {
    NERVE(HostTypeWait);
    NERVE(HostTypePlay);
};
