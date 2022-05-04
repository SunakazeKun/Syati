#pragma once

#include "revolution.h"
#include "JSystem.h"

class LinearRailPart;
class BezierRailPart;

class RailPart {
public:
    RailPart();

    void init(const TVec3f &, const TVec3f &, const TVec3f &, const TVec3f &);
    void initForBezier(const TVec3f &, const TVec3f &, const TVec3f &, const TVec3f &);
    void calcPos(TVec3f *, f32) const;
    void calcVelocity(TVec3f *, f32) const;
    f32 getLength(f32, f32, s32) const;
    f32 getTotalLength() const;
    f32 getParam(f32) const;
    f32 getNearestParam(const TVec3f &, f32) const;

    LinearRailPart* mLinearRailPart; // _0
    BezierRailPart* mBezierRailPart; // _4
};

class LinearRailPart {
public:
    inline LinearRailPart() { }

    void set(const TVec3f &, const TVec3f &);
    f32 getNearestParam(const TVec3f &, f32) const;

    TVec3f _0;
    TVec3f _C;
    f32 mMagnitude; // _18
};

class BezierRailPart {
public:
    inline BezierRailPart() { }

    void set(const TVec3f &, const TVec3f &, const TVec3f &, const TVec3f &);
    void calcPos(TVec3f *, f32) const;
    void calcVelocity(TVec3f *, f32) const;
    f32 getLength(f32, f32, s32) const;
    f32 getParam(f32) const;
    f32 getNearestParam(const TVec3f &, f32) const;

    const TVec3f _0;
    const TVec3f _C;
    const TVec3f _18;
    const TVec3f _24;
    f32 mLength; // _30
};
