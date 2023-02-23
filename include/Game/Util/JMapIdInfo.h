#pragma once

#include "revolution.h"
#include "JSystem.h"

/* FINISHED */

class JMapInfoIter;

class JMapIdInfo {
public:
    inline JMapIdInfo() {}
    JMapIdInfo(s32 scenarioNo, s32 zoneID);
    JMapIdInfo(s32, const JMapInfoIter &rIter);
    JMapIdInfo(const JMapIdInfo &rInfo);

    void initialize(s32 scenarioNo, const JMapInfoIter &rIter);

    void operator=(const JMapIdInfo &rInfo);
    bool operator==(const JMapIdInfo &rInfo) const;

    s32 mId;     // _0
    s32 mZoneId; // _4
};
