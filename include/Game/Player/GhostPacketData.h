#pragma once

#include "revolution.h"
#include "JSystem.h"

/* FINISHED */

class GhostPacketData {
public:
    GhostPacketData();

    bool testPosition() const;
    bool testTRMtx() const;
    bool testRotationX() const;
    bool testRotationY() const;
    bool testRotationZ() const;
    bool testScale() const;
    bool testVelocity() const;
    bool testActionName() const;
    bool testActionHash() const;
    bool testBckFrame() const;
    bool testTrackWeight(u32 track) const;
    bool testTrackWeight0() const;
    bool testTrackWeight1() const;
    bool testTrackWeight2() const;
    bool testTrackWeight3() const;
    bool testBckRate() const;

    TVec3f mPosition;     // _0
    TVec3f mRotation;     // _C
    TVec3f mScale;        // _18
    TVec3f mVelocity;     // _24
    char *mActionName;    // _30
    s32 mActionHash;      // _34
    f32 mBckFrame;        // _38
    f32 mTrackWeights[4]; // _3C
    f32 mBckRate;         // _4C
    s32 mPacketFlags;     // _50
};
