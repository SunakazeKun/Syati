#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"

class HitSensor;

class SensorGroup {
public:
    SensorGroup(int size, const char *pGroupName);

    void add(HitSensor *pSensor);
    void remove(HitSensor *pSensor);
    void clear() const;

    s32 mMaxSensors;      // _0
    s32 mNumSensors;      // _4
    HitSensor** mSensors; // _8
};

class SensorHitChecker : public NameObj {
public:
    SensorHitChecker(const char *pName);

    virtual ~SensorHitChecker();
    virtual void init(const JMapInfoIter &rIter);
    virtual void movement();

    void initGroup(HitSensor *pSensor);
    void doObjColGorup(SensorGroup *pGroupA, SensorGroup *pGroupB) const;
    void doObjColInSameGroup(SensorGroup *pGroup) const;
    void checkAttack(HitSensor *pSensorA, HitSensor *pSensorB) const;

    SensorGroup* mPlayerGroup;    // _14
    SensorGroup* mRideGroup;      // _18
    SensorGroup* mEyeGroup;       // _1C
    SensorGroup* mSimpleGroup;    // _20
    SensorGroup* mMapObjGroup;    // _24
    SensorGroup* mCharacterGroup; // _28
};

namespace MR {
    void initHitSensorGroup(HitSensor *pSensor);
};
