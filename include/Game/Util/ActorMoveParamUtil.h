#pragma once

#include "revolution.h"

class LiveActor;

namespace MR {
    struct ActorMoveParam {
        f32 _0;
        f32 _4;
        f32 _8;
        f32 _C;
    };

    struct ActorSightParam {
        f32 _0;
        f32 _4;
        f32 _8;
    };

    struct ActorJumpParam {
        f32 mSpeedToDir;   // _0
        f32 mSpeedUpwards; // _4
    };

    bool hasActorParam(const LiveActor *pActor);

    const f32* getActorParamF32(const LiveActor *pActor);
    const s32* getActorParamS32(const LiveActor *pActor);

    const ActorMoveParam* getActorParamMove(const LiveActor *pActor);
    const ActorSightParam* getActorParamSight(const LiveActor *pActor);
    const ActorJumpParam* getActorParamJump(const LiveActor *pActor);
};
