#pragma once

#include "revolution.h"
#include "Game/AudioLib/AudSoundObject.h"

class AudAnmSoundObject : public AudSoundObject {
public:
    AudAnmSoundObject(TVec3f*, u8, JKRHeap *);

    u8 _48[0x74-0x48];
};
