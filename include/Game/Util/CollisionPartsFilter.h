#pragma once

#include "revolution.h"

/* FINISHED */

class CollisionParts;
class HitSensor;
class LiveActor;


class CollisionPartsFilterBase {
public:
    virtual bool isInvalidParts(const CollisionParts *pCollisionParts) const = 0;
};


class CollisionPartsFilterSensor : public CollisionPartsFilterBase {
public:
    virtual bool isInvalidParts(const CollisionParts *pCollisionParts) const;

    const HitSensor* mFilterSensor; // _4
};


class CollisionPartsFilterSensorType : public CollisionPartsFilterBase {
public:
    virtual bool isInvalidParts(const CollisionParts *pCollisionParts) const;

    u32 mFilterSensorType; // _4
};


class CollisionPartsFilterActor : public CollisionPartsFilterBase {
public:
    virtual bool isInvalidParts(const CollisionParts *pCollisionParts) const;

    const LiveActor* mFilterActor; // _4
};


typedef bool (*TCollisionPartsFilterFunc)(const CollisionParts *);

class CollisionPartsFilterDelegator : public CollisionPartsFilterBase {
public:
    virtual bool isInvalidParts(const CollisionParts *pCollisionParts) const;

    TCollisionPartsFilterFunc mDelegateFunc; // _4
};

namespace MR {
    CollisionPartsFilterDelegator* createCollisionPartsFilterDelegator(TCollisionPartsFilterFunc delegateFunc);
};
