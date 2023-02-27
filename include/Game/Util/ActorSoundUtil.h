#pragma once

#include "revolution.h"

/* FINISHED */

class LiveActor;

namespace MR {
    void startSoundInPlayerDistance(LiveActor *pActor, const char *pSoundName, s32 pitch, s32 velocity, f32 validDistToPlayer);
    void startSoundInCameraDistance(LiveActor *pActor, const char *pSoundName, s32 pitch, s32 velocity, f32 validDistToCamera);
};
