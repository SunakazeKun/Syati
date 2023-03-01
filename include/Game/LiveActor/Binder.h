#pragma once

#include "revolution.h"
#include "Game/Map/CollisionParts.h";
#include "Game/Map/HitInfo.h";
#include "Game/Util/CollisionPartsFilter.h"

class Binder {
public:
    Binder(MtxPtr, const TVec3f *, const TVec3f *, f32, f32, u32);

    void setTriangleFilter(TriangleFilterBase *);
    void setCollisionPartsFilter(CollisionPartsFilterBase *);
    void clear();
    HitInfo* getPlane(int) const;
    s32 copyPlaneArrayAndSortingSensor(HitInfo **, u32);
    static bool compSensor(const HitInfo *, const HitInfo *);
    TVec3f bind(const TVec3f &);
    void moveAlongHittedPlanes(TVec3f *, TVec3f *, TVec3f *, const TVec3f &, const TVec3f &, HitInfo *, u32, bool *);
    s32 findBindedPlanes(TVec3f *, TVec3f *, bool *, HitInfo *, u32, bool, bool);
    bool moveWithCollisionParts(TVec3f *, TVec3f *);
    s32 storeCurrentHitInfo(HitInfo *, u32, bool);
    void obtainMomentFixReaction(HitInfo *, u32, TVec3f *, u32);
    void storeContactPlane(HitInfo *, u32);

    TriangleFilterBase* mTriangleFilter; // _0
    CollisionPartsFilterBase* mCollisionPartsFilter; // _4
    s32 _8;
    MtxPtr _C;
    TVec3f* _10;
    TVec3f* _14;
    f32 _18;
    f32 _1C;
    s32 _20;
    u32 _24;
    s32 _28;
    u32* _2C;
    TVec3f _30;
    HitInfo _3C;
    HitInfo _CC;
    HitInfo _15C;
    u8 _1EC;
};
