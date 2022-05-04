#pragma once

#include "revolution.h"
#include "JSystem.h"

class LiveActor;
class JUTTexture;

namespace MR {
    // two unknown functions here
    void processInitFunction(LiveActor * pActor, const JMapInfoIter & rIter, bool unk2);
    void processInitFunction(LiveActor * pActor, const JMapInfoIter & rIter, const char * modelName, bool unk2);
    void processInitFunction(LiveActor * pActor, const JMapInfoIter & rIter, const char * modelName, const char * funcName, bool unk2);
    void processInitFunction(LiveActor * pActor, const char * modelName, bool unk2);
    void processInitFunction(LiveActor * pActor, const char * modelName, const char * funcName, bool unk2);
    
    // ??? makeInitActorPath(const char *, const char *);
    bool isValidInitActorPath(const char *, const char *);

    void processInitFunction(LiveActor * pActor, const JMapInfoIter & rIter, const char * modelName, bool unk1, const char * funcName, bool unk2);
    void processInitFunction(LiveActor * pActor, const char * modelName, bool unk1, bool unk2);
    void processInitFunction(LiveActor * pActor, const char * modelName, bool unk1, const char * funcName, bool unk2);

    void initDefaultPos(LiveActor * pActor, const JMapInfoIter & rIter);
    void getDefaultPos(LiveActor * pActor, const JMapInfoIter & rIter);
    bool tryInitFromRestartPos(LiveActor * pActor, const JMapInfoIter & rIter);
    // unknown function here
    void initSensors(LiveActor * pActor, const char * modelName, const char * funcName);
    void initSwitches(LiveActor * pActor, const JMapInfoIter & rIter, const char * modelName, const char * funcName);

    JUTTexture* loadTexFromArc(LiveActor * pActor, const char *, const char *);
    JUTTexture* loadTexFromArc(LiveActor * pActor, const char *);
};
