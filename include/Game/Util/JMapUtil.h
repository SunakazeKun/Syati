#pragma once

#include "revolution.h"
#include "JSystem.h"

class JMapInfoIter;

/* FINISHED */

namespace MR {
    bool isValidInfo(const JMapInfoIter &rIter);
    void getObjectName(const char **pDest, const JMapInfoIter &rIter);
    bool isObjectName(const JMapInfoIter &rIter, const char *pName);

    bool getJMapInfoArgNoInit(const JMapInfoIter &rIter, const char *pField, s32 *pDest);
    bool getJMapInfoArgNoInit(const JMapInfoIter &rIter, const char *pField, f32 *pDest);
    bool getJMapInfoArgNoInit(const JMapInfoIter &rIter, const char *pField, bool *pDest);
    bool isExistJMapInfoArg0(const JMapInfoIter &rIter);

    bool getJMapInfoShapeIdWithInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoAreaIdWithInit(const JMapInfoIter &rIter, s32 *pDest);

    bool getJMapInfoTransLocal(const JMapInfoIter &rIter, TVec3f *pDest);
    bool getJMapInfoTrans(const JMapInfoIter &rIter, TVec3f *pDest);
    bool getJMapInfoRotateLocal(const JMapInfoIter &rIter, TVec3f *pDest);
    bool getJMapInfoRotate(const JMapInfoIter &rIter, TVec3f *pDest);
    bool getJMapInfoScale(const JMapInfoIter &rIter, TVec3f *pDest);
    bool getJMapInfoMatrixFromRT(const JMapInfoIter &rIter, TMtx34f *pDest);
    bool getJMapInfoV3f(const JMapInfoIter &rIter, const char *, TVec3f *pDest);

    bool getJMapInfoArg0WithInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg0WithInit(const JMapInfoIter &rIter, f32 *pDest);
    bool getJMapInfoArg0WithInit(const JMapInfoIter &rIter, bool *pDest);
    bool getJMapInfoArg1WithInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg1WithInit(const JMapInfoIter &rIter, f32 *pDest);
    bool getJMapInfoArg1WithInit(const JMapInfoIter &rIter, bool *pDest);
    bool getJMapInfoArg2WithInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg2WithInit(const JMapInfoIter &rIter, f32 *pDest);
    bool getJMapInfoArg2WithInit(const JMapInfoIter &rIter, bool *pDest);
    bool getJMapInfoArg3WithInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg3WithInit(const JMapInfoIter &rIter, bool *pDest);
    bool getJMapInfoArg4WithInit(const JMapInfoIter &rIter, bool *pDest);
    bool getJMapInfoArg5WithInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg6WithInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg7WithInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg7WithInit(const JMapInfoIter &rIter, bool *pDest);

    bool getJMapInfoArg0NoInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg0NoInit(const JMapInfoIter &rIter, f32 *pDest);
    bool getJMapInfoArg0NoInit(const JMapInfoIter &rIter, bool *pDest);
    bool getJMapInfoArg1NoInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg1NoInit(const JMapInfoIter &rIter, f32 *pDest);
    bool getJMapInfoArg1NoInit(const JMapInfoIter &rIter, bool *pDest);
    bool getJMapInfoArg2NoInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg2NoInit(const JMapInfoIter &rIter, f32 *pDest);
    bool getJMapInfoArg2NoInit(const JMapInfoIter &rIter, bool *pDest);
    bool getJMapInfoArg3NoInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg3NoInit(const JMapInfoIter &rIter, f32 *pDest);
    bool getJMapInfoArg3NoInit(const JMapInfoIter &rIter, bool *pDest);
    bool getJMapInfoArg4NoInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg4NoInit(const JMapInfoIter &rIter, f32 *pDest);
    bool getJMapInfoArg4NoInit(const JMapInfoIter &rIter, bool *pDest);
    bool getJMapInfoArg5NoInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg5NoInit(const JMapInfoIter &rIter, f32 *pDest);
    bool getJMapInfoArg5NoInit(const JMapInfoIter &rIter, bool *pDest);
    bool getJMapInfoArg6NoInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg6NoInit(const JMapInfoIter &rIter, f32 *pDest);
    bool getJMapInfoArg6NoInit(const JMapInfoIter &rIter, bool *pDest);
    bool getJMapInfoArg7NoInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoArg7NoInit(const JMapInfoIter &rIter, f32 *pDest);
    bool getJMapInfoArg7NoInit(const JMapInfoIter &rIter, bool *pDest);

    bool getJMapInfoFollowID(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoGroupID(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoClippingGroupID(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoDemoGroupID(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoLinkID(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoPriorityWithInit(const JMapInfoIter &rIter, s32 *pDest);

    bool isConnectedWithRail(const JMapInfoIter &rIter);
    bool isExistStageSwitchA(const JMapInfoIter &rIter);
    bool isExistStageSwitchB(const JMapInfoIter &rIter);
    bool isExistStageSwitchAppear(const JMapInfoIter &rIter);
    bool isExistStageSwitchDead(const JMapInfoIter &rIter);
    bool isExistStageSwitchAwake(const JMapInfoIter &rIter);
    bool isExistStageSwitchParam(const JMapInfoIter &rIter);
    bool isExistMessageId(const JMapInfoIter &rIter);
    bool isEqualObjectName(const JMapInfoIter &rIter, const char *pName);

    bool getJMapInfoCameraSetID(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoViewGroupID(const JMapInfoIter &rIter, s32 *pDest);
    bool getJMapInfoMessageID(const JMapInfoIter &rIter, s32 *pDest);
    bool getParamScale(const JMapInfoIter &rIter, f32 *pDest);

    s32 getDemoCastID(const JMapInfoIter &rIter);
    const char* getDemoName(const JMapInfoIter &rIter);
    const char* getTimeSheetName(const JMapInfoIter &rIter);
    s32 getDemoGroupID(const JMapInfoIter &rIter);
    s32 getDemoGroupLinkID(const JMapInfoIter &rIter);
    bool getDemoSkip(const JMapInfoIter &rIter);

    bool getJMapInfoRailArg(const JMapInfoIter &rIter, const char *pField, s32 *pDest);
    bool getJMapInfoRailArg0NoInit(const JMapInfoIter &rIter, s32 *pDest);
    bool getRailId(const JMapInfoIter &rIter, s32 *pDest);
    bool getNextLinkRailId(const JMapInfoIter &rIter, s32 *pDest);
    bool isEqualRailUsage(const JMapInfoIter &rIter, const char *pName);
    void getRailPointPos0(const JMapInfoIter &rIter, TVec3f *pDest);
    void getRailPointPos1(const JMapInfoIter &rIter, TVec3f *pDest);
    void getRailPointPos2(const JMapInfoIter &rIter, TVec3f *pDest);
    bool isLoopRailPathIter(const JMapInfoIter &rIter);

    void getLinkObjID(const JMapInfoIter &rIter, s32 *pDest);
    void getMapPartsID(const JMapInfoIter &rIter, s32 *pDest);
    void getGeneratorID(const JMapInfoIter &rIter, s32 *pDest);
};
