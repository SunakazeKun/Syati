#pragma once

#include "revolution.h"
#include "JSystem.h"

class LiveActor;

class GhostPacketSyncData {
public:
    GhostPacketSyncData();

    void syncWithPlayer();
    void syncWithActor(const LiveActor *pActor, bool syncAnims);

    TVec3f mPositionFloat;  // _0
    TVec3s mPositionInt;    // _C
    TVec3c mRotation;       // _12
    TVec3c mScale;          // _15
    TVec3c mVelocity;       // _18
    const char* mBckName;   // _1C
    u32 mBckHash;           // _20
    bool mUseBckHash;       // _24
    bool mUsePositionFloat; // _25
    s16 mBckFrame;          // _26
    s8 mTrackWeights[4];    // _28
    s8 mBckRate;            // _2C
};
