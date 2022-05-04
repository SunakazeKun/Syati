#pragma once

#include "revolution.h"
#include "JSystem.h"

class HitSensor;
class LiveActor;
class MapPartsRailGuideDrawer;

namespace MR {
	void getMapPartsObjectNameIfExistShapeID(char *, u32, const JMapInfoIter &);
	void initMapPartsClipping(LiveActor *, const JMapInfoIter &, TVec3f *, bool);
	MapPartsRailGuideDrawer* createMapPartsRailGuideDrawer(LiveActor *, const char *, const JMapInfoIter &);
	bool getJMapInfoArgNoInit(const JMapInfoIter &, const char *, s32 *);
	bool getJMapInfoArgNoInit(const JMapInfoIter &, const char *, f32 *);
	bool getMapPartsArgMoveConditionType(s32 *, const JMapInfoIter &);
	bool getMapPartsArgRotateSpeed(f32 *, const JMapInfoIter &);
	bool getMapPartsArgRotateTime(s32 *, const JMapInfoIter &);
	bool getMapPartsArgRotateAngle(f32 *, const JMapInfoIter &);
	bool getMapPartsArgRotateAxis(s32 *, const JMapInfoIter &);
	bool getMapPartsArgRotateAccelType(s32 *, const JMapInfoIter &);
	bool getMapPartsArgRotateStopTime(s32 *, const JMapInfoIter &);
	bool getMapPartsArgRotateType(s32 *, const JMapInfoIter &);
	bool getMapPartsArgShadowType(s32 *, const JMapInfoIter &);
	bool getMapPartsArgSignMotionType(s32 *, const JMapInfoIter &);
	bool getMapPartsArgMovePosture(s32 *, const LiveActor *);
	bool getMapPartsArgMoveStopType(s32 *, const LiveActor *);
	bool getMapPartsArgRailGuideType(s32 *, const LiveActor *);
	bool getMapPartsArgRailInitPosType(s32 *, const LiveActor *);
	// unknown function here
	bool getMapPartsArgMoveSpeed(f32 *, const LiveActor *);
	bool getMapPartsArgStopTime(s32 *, const LiveActor *);
	bool getMapPartsArgAccelTime(s32 *, const LiveActor *);
	bool getMapPartsArgSpeedCalcType(s32 *, const LiveActor *);
	bool getMapPartsArgRailRotateSpeed(f32 *, const LiveActor *, s32);
	bool getMapPartsArgRailRotateTime(s32 *, const LiveActor *, s32);
	bool getMapPartsArgRailRotateAngle(f32 *, const LiveActor *, s32);
	bool getMapPartsArgRailRotateAxis(s32 *, const LiveActor *, s32);
	bool getMapPartsArgRailRotateType(s32 *, const LiveActor *, s32);
	bool getMapPartsArgSpeedCalcType(s32 *, const LiveActor *, s32);
	bool getMapPartsArgMoveTimeToNextPoint(s32 *, const LiveActor *);
	bool isMapPartsSignMotionTypeMoveStart(s32);
	bool isMapPartsSignMotionTypeMoveWait(s32);
	bool hasMapPartsMoveStartSignMotion(s32);
	bool isMapPartsShadowTypeNone(s32);
	bool hasMapPartsShadow(s32);
	bool isMoveStartTypeUnconditional(s32);
	bool isMoveStartTypePlayerOnStopEnd(s32);
	bool isMapPartsRailInitPosTypeRailPos(s32);
	bool isMapPartsRailInitPosTypeRailPoint(s32);
	bool isMapPartsRailInitPosTypePoint0(s32);
	bool isMapPartsRailSpeedCalcTypeTime(s32);
};
