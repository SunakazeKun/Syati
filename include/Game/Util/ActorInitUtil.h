#pragma once

#include "revolution.h"
#include "JSystem.h"

/* FINISHED */

class JMapInfo;
class JMapInfoIter;
class JUTTexture;
class LiveActor;

namespace MR {
    bool isInitFunctionBoolSet(const JMapInfo *pCsvData, const char *pIdentifier);
    bool getInitSwitchType(const char **pSwitchType, const JMapInfo *pCsvData, const char *pIdentifier);

    void processInitFunction(LiveActor *pActor, const JMapInfoIter &rIter, bool unk);
    void processInitFunction(LiveActor *pActor, const JMapInfoIter &rIter, const char *pModelName, bool unk);
    void processInitFunction(LiveActor *pActor, const JMapInfoIter &rIter, const char *pModelName, const char *pFuncName, bool unk);
    void processInitFunction(LiveActor *pActor, const char *pModelName, bool unk);
    void processInitFunction(LiveActor *pActor, const char *pModelName, const char *pFuncName, bool unk);
    
    JMapInfo* createInitActorCsvParser(const char *pModelName, const char *pFuncName);
    bool isValidInitActorCsv(const char *pModelName, const char *pFuncName);

    void processInitFunctionWithAnimArc(LiveActor *pActor, const JMapInfoIter &rIter, const char *pModelName, const char *pAnimArcName, const char *pFuncName, bool unk);
    void processInitFunctionWithAnimArc(LiveActor *pActor, const char *pModelName, const char *pAnimArcName, bool unk);
    void processInitFunctionWithAnimArc(LiveActor *pActor, const char *pModelName, const char *pAnimArcName, const char *pFuncName, bool unk);

    void initDefaultPos(LiveActor *pActor, const JMapInfoIter &rIter);
    void initDefaultPosNoRepeat(LiveActor *pActor, const JMapInfoIter &rIter);
    bool tryInitDefaultPosFromRestartPos(LiveActor *pActor, const JMapInfoIter &rIter);
    void getDefaultRotation(TVec3f *pDest, const JMapInfoIter &rIter);

    void initSensors(LiveActor *pActor, const char *pModelName, const char *pFuncName);
    void initSwitches(LiveActor *pActor, const JMapInfoIter &rIter, const char *pModelName, const char *pFuncName);

    JUTTexture* loadTexFromArc(LiveActor *pActor, const char *pArcName, const char *pBtiName);
    JUTTexture* loadTexFromArc(LiveActor *pActor, const char *pBtiName);
};
