#pragma once

#include "revolution.h"
#include "JSystem.h"

/* FINISHED */

class HitSensor;
class JMapInfoIter;
class LiveActor;
class MapPartsRailGuideDrawer;

namespace MR {
	void getMapPartsObjectNameIfExistShapeID(char *pDest, u32 size, const JMapInfoIter &rIter);
	void initMapPartsClipping(LiveActor *pActor, const JMapInfoIter &rIter, TVec3f *pClipping, bool noRailClipping);
	MapPartsRailGuideDrawer* createMapPartsRailGuideDrawer(LiveActor *pActor, const char *pModelName, const JMapInfoIter &rIter);
	bool getJMapInfoArgNoInit(const JMapInfoIter &rIter, const char *pFieldName, s32 *pDest);
	bool getJMapInfoArgNoInit(const JMapInfoIter &rIter, const char *pFieldName, f32 *pDest);
	bool getMapPartsArgMoveConditionType(s32 *pDest, const JMapInfoIter &rIter);
	bool getMapPartsArgRotateSpeed(f32 *pDest, const JMapInfoIter &rIter);
	bool getMapPartsArgRotateTime(s32 *pDest, const JMapInfoIter &rIter);
	bool getMapPartsArgRotateAngle(f32 *pDest, const JMapInfoIter &rIter);
	bool getMapPartsArgRotateAxis(s32 *pDest, const JMapInfoIter &rIter);
	bool getMapPartsArgRotateAccelType(s32 *pDest, const JMapInfoIter &rIter);
	bool getMapPartsArgRotateStopTime(s32 *pDest, const JMapInfoIter &rIter);
	bool getMapPartsArgRotateType(s32 *pDest, const JMapInfoIter &rIter);
	bool getMapPartsArgShadowType(s32 *pDest, const JMapInfoIter &rIter);
	bool getMapPartsArgSignMotionType(s32 *pDest, const JMapInfoIter &rIter);
	bool getMapPartsArgMovePosture(s32 *pDest, const LiveActor *pActor);
	bool getMapPartsArgMoveStopType(s32 *pDest, const LiveActor *pActor);
	bool getMapPartsArgRailGuideType(s32 *pDest, const LiveActor *pActor);
	bool getMapPartsArgRailInitPosType(s32 *pDest, const LiveActor *pActor);
	bool getMapPartsArgMoveSnap(s32 *pDest, const LiveActor *pActor);
	bool getMapPartsArgMoveSpeed(f32 *pDest, const LiveActor *pActor);
	bool getMapPartsArgStopTime(s32 *pDest, const LiveActor *pActor);
	bool getMapPartsArgAccelTime(s32 *pDest, const LiveActor *pActor);
	bool getMapPartsArgSpeedCalcType(s32 *pDest, const LiveActor *pActor);
	bool getMapPartsArgRailRotateSpeed(f32 *pDest, const LiveActor *pActor, s32 pointIndex);
	bool getMapPartsArgRailRotateTime(s32 *pDest, const LiveActor *pActor, s32 pointIndex);
	bool getMapPartsArgRailRotateAngle(f32 *pDest, const LiveActor *pActor, s32 pointIndex);
	bool getMapPartsArgRailRotateAxis(s32 *pDest, const LiveActor *pActor, s32 pointIndex);
	bool getMapPartsArgRailRotateType(s32 *pDest, const LiveActor *pActor, s32 pointIndex);
	bool getMapPartsArgSpeedCalcType(s32 *pDest, const LiveActor *pActor, s32 pointIndex);
	bool getMapPartsArgMoveTimeToNextPoint(s32 *pDest, const LiveActor *pActor);
	bool isMapPartsSignMotionTypeMoveStart(s32 signMotionType);
	bool isMapPartsSignMotionTypeMoveWait(s32 signMotionType);
	bool hasMapPartsMoveStartSignMotion(s32 signMotionType);
	bool isMapPartsShadowTypeNone(s32 shadowType);
	bool hasMapPartsShadow(s32 shadowType);
	bool isMoveStartTypeUnconditional(s32 moveStartType);
	bool isMoveStartTypePlayerOnStopEnd(s32 moveStartType);
	bool isMapPartsRailInitPosTypeRailPos(s32 initPosType);
	bool isMapPartsRailInitPosTypeRailPoint(s32 initPosType);
	bool isMapPartsRailInitPosTypePoint0(s32 initPosType);
	bool isMapPartsRailSpeedCalcTypeTime(s32 speedCalcType);
};
