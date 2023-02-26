#pragma once

#include "revolution.h"
#include "JSystem.h"

class OceanBowl;
class OceanRing;
class OceanSphere;
class WaterArea;
class WaterStream;

class WaterInfo {
    WaterInfo();

    bool isInWater() const;
    void clear();

    f32 mCameraWaterDepth;
    f32 _4;
    TVec3f _8;
    f32 _14;
    f32 _18;
    f32 _1C;
    f32 _20;
    TVec3f _24;
    f32 _30;
    TVec3f _34;
    WaterArea* mWaterArea;
    OceanBowl* mOceanBowl;
    OceanRing* mOceanRing;
    OceanSphere* mOceanSphere;
    WaterStream* mWaterStream;
};
