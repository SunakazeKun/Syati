#pragma once

#include "revolution.h"
#include "JSystem.h"

class HitSensor;
class Triangle;
class TriangleFilterBase;
class KC_PrismData;
class HitInfo;
class KCollisionServer;
class CollisionZone;

class CollisionParts {
public:
	CollisionParts();

	TVec3f getTrans();
	void init(const TMtx34f &, HitSensor *, const void *, const void *, s32, bool);
	void addToBelongZone();
	void removeFromBelongZone();
	void initWithAutoEqualScale(const TMtx34f &, HitSensor *, const void *, const void *, s32, bool);
	void initWithNotUsingScale(const TMtx34f &, HitSensor *, const void *, const void *, s32, bool);
	void resetAllMtx(const TMtx34f &);
	void resetAllMtx();
	void resetAllMtxPrivate(const TMtx34f &);
	void setMtx(const TMtx34f &);
	void setMtx();
	void updateMtx();
	f32 makeEqualScale(MtxPtr);
	void updateBoundingSphereRange();
	void updateBoundingSphereRange(TVec3f);
	void updateBoundingSphereRangePrivate(f32);
	const char *getHostName() const;
	s32 getPlacementZoneID() const;
	void checkStrikePoint(HitInfo *, const TVec3f &);
	void checkStrikeBall(HitInfo *, u32, const TVec3f &, f32, bool, const TriangleFilterBase *);
	void checkStrikeBallCore(HitInfo *, u32, const TVec3f &, const TVec3f &, f32, f32, f32, KC_PrismData **, f32 *, u8 *, const TriangleFilterBase *, const TVec3f *);
	void checkStrikeBallWithThickness(HitInfo *, u32, const TVec3f &, f32, f32, const TriangleFilterBase *);
	void calcCollidePosition(TVec3f *, const KC_PrismData &, u8);
	void projectToPlane(TVec3f *, const TVec3f &, const TVec3f &, const TVec3f &);
	void checkStrikeLine(HitInfo *, u32, const TVec3f &, const TVec3f &, const TriangleFilterBase *);
	void createAreaPolygonList(Triangle *, u32, const TVec3f &, const TVec3f &);
	void createAreaPolygonListArray(Triangle *, u32, TVec3f *, u32);
	void calcForceMovePower(TVec3f *, const TVec3f &) const;

	TMtx34f *_0;
	TMtx34f mMatrix;            // _4
	TMtx34f mBaseMatrix;        // _34
	TMtx34f mInvBaseMatrix;     // _64
	TMtx34f mPrevBaseMatrix;    // _94
	KCollisionServer *mServer;  // _C4
	HitSensor *mHitSensor;      // _C8
	bool _CC;
	bool _CD;
	bool _CE;
	bool _CF;
	bool _D0;
	s32 _D4;
	f32 _D8;
	f32 _DC;
	s32 mKeeperIndex;           // _E0
	CollisionZone *mZone;       // _E4
	f32 _E8; // TVec3f?
	f32 _EC;
	f32 _F0;
};
