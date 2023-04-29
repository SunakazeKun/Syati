#pragma once

#include "revolution.h"
#include "JSystem.h"

class CollisionParts;
class HitSensor;
class JMapInfoIter;

class Triangle {
public:
    Triangle();

    Triangle &operator=(const Triangle &);

    void fillData(CollisionParts *, u32, HitSensor *);
    const char *getHostName() const;
    s32 getHostPlacementZoneID() const;
    bool isHostMoved() const;
    bool isValid() const;
    const TVec3f *getNormal(int) const;
    const TVec3f *getFaceNormal() const;
    const TVec3f *getEdgeNormal(int) const;
    const TVec3f *getPos(int) const;
    const TVec3f *calcAndGetNormal(int);
    const TVec3f *calcAndGetEdgeNormal(int);
    const TVec3f *calcAndGetPos(int);
    void calcForceMovePower(TVec3f *, const TVec3f &) const;
    JMapInfoIter getAttributes() const;
    TMtx34f *getBaseMtx() const;
    TMtx34f *getBaseInvMtx() const;
    TMtx34f *getPrevBaseMtx() const;

    CollisionParts* mColParts; // _0
    u32 mIndex;                // _4
    HitSensor* mSensor;        // _8
    TVec3f mNormals[4];        // _C
    TVec3f mVerts[3];          // _3C
};

class HitInfo {
public:
    HitInfo();

    HitInfo &operator=(const HitInfo &);

    bool isCollisionAtFace() const;
    bool isCollisionAtEdge() const;
    bool isCollisionAtCorner() const;

    Triangle mParentTriangle; // _0
    f32 _60;
    TVec3f _64;
    TVec3f _70;
    TVec3f _7C;
    u8 _88;
};

class TriangleFilterBase {
public:
    virtual bool isInvalidTriangle(const Triangle *) const = 0;
};
