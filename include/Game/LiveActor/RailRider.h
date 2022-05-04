#pragma once

#include "revolution.h"
#include "Game/Map/BezierRail.h"

class RailRider {
public:
    RailRider(const JMapInfoIter &rIter);
    RailRider(s32, s32);

    void move();
    void moveToNearestPos(const TVec3f &rPoint);
    void moveToNearestPoint(const TVec3f &rPoint);
    void moveToNextPoint();
    void reverse();
    void calcPosAtCoord(TVec3f *pDest, f32 coord) const;
    void calcDirectionAtCoord(TVec3f *pDest, f32 coord) const;
    f32 calcNearestPos(const TVec3f &rPoint) const;
    f32 getTotalLength() const;
    f32 getPartLength(s32 partIndex) const;
    bool isLoop() const;
    bool isReachedGoal() const;
    bool isReachedEdge() const;
    void setCoord(f32 coord);
    void setSpeed(f32 speed);
    bool getRailArgWithInit(const char *pArgName, s32 *pDest) const;
    bool getRailArgNoInit(const char *pArgName, s32 *pDest) const;
    f32 getNextPointCoord() const;
    f32 getCurrentPointCoord() const;
    s32 getPointNum() const;
    void copyPointPos(TVec3f *pDest, s32 pointIndex) const;
    f32 getPointCoord(s32) const;
    void initBezierRail(const JMapInfoIter &rIter, const JMapInfo *);
    bool getPointArgS32NoInit(const char *pArgName, s32 *pDest, s32 pointIndex) const;
    bool getPointArgS32WithInit(const char *pArgName, s32 *pDest, s32 pointIndex) const;
    bool getCurrentPointArgS32NoInit(const char *pArgName, s32 *pDest) const;
    bool getCurrentPointArgS32WithInit(const char *pArgName, s32 *pDest) const;
    bool getNextPointArgS32NoInit(const char *pArgName, s32 *pDest) const;
    bool getNextPointArgS32WithInit(const char *pArgName, s32 *pDest) const;
    s32 getNextPointNo() const;
    void syncPosDir();

    BezierRail* mBezierRail; // _0
    f32 mCoord;              // _4
    f32 mSpeed;              // _8
    bool mIsNotReverse;      // _C
    TVec3f mCurrentPos;      // _10
    TVec3f mCurrentDir;      // _1C
    TVec3f mStartPos;        // _28
    TVec3f mEndPos;          // _34
    s32 mCurPoint;           // _40
};
