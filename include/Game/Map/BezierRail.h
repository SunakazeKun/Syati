#pragma once

#include "revolution.h"
#include "Game/Map/RailPart.h"

class JMapInfo;
class JMapInfoIter;

class BezierRail {
public:
    BezierRail(const JMapInfoIter &, const JMapInfo *);

    f32 normalizePos(f32, s32) const;
    f32 getRailPosCoord(s32) const;
    f32 getNearestRailPosCoord(const TVec3f &) const;
    void calcPos(TVec3f *, f32) const;
    void calcDirection(TVec3f *, f32) const;
    void calcNearestPos(TVec3f *, f32) const;
    f32 getTotalLength() const;
    f32 getPartLength(s32) const;
    void calcRailCtrlPointIter(JMapInfoIter *, s32) const;

    void calcPosDir(TVec3f *, TVec3f *, f32) const;
    void calcCurrentRailCtrlPointIter(JMapInfoIter *, f32, bool) const;
    static void calcRailDirection(TVec3f *, const RailPart *, f32);
    void getIncludedSection(const RailPart **, f32 *, f32, s32) const;
    s32 getCurrentCtrlPointIndex(f32, bool) const;

    bool mIsLoop; // _0
    u8 _1;
    u8 _2;
    u8 _3;
    s32 mPointNum; // _4
    s32 mPointNumLoop; // _8
    RailPart* mRailParts; // _C
    f32* mSegLengths; // _10
    JMapInfoIter* mIter; // _14
    const JMapInfo* mMapInfo; // _18
};
