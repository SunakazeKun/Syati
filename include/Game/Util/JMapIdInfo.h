#pragma once

#include "revolution.h"
#include "JSystem.h"

class JMapInfoIter;

class JMapIdInfo {
public:
    inline JMapIdInfo() { }
    JMapIdInfo(s32 scenarioNo, s32 zoneID);
    JMapIdInfo(s32, const JMapInfoIter &);
    JMapIdInfo(const JMapIdInfo &);

    void initialize(s32, const JMapInfoIter &);

    void operator=(const JMapIdInfo &);
    bool operator==(const JMapIdInfo &) const;

    s32 mScenarioNo; // _0
    s32 mZoneId; // _4
};
