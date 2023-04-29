#pragma once

#include "revolution.h"
#include "Game/AudioLib/AudAnmSoundObject.h"

class ActorSoundHolder {
public:
    ActorSoundHolder(LiveActor *pActor, s32 soundCount, const TVec3f *pSoundPos, const TVec3f &rSoundOffset);

    AudAnmSoundObject* getSoundObj();

    void update();

    AudAnmSoundObject mSoundObj; // _0
    u32* mSoundInfo;             // _4
    TVec3f* mSoundPos;           // _8
    MtxPtr mFollowMtx;           // _C
    TVec3f* mSoundOffset;        // _10
};
