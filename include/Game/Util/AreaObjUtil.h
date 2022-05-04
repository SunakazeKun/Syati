#pragma once

#include "revolution.h"
#include "JSystem.h"

class AreaObj;
class AreaObjMgr;
class WaterArea;
class WaterInfo;

namespace MR {
	AreaObjMgr* getAreaObjManager(const char *);
	AreaObj* getAreaObj(const char *, const TVec3f &);
	AreaObj* getAreaObjAtPlayerPos(const char *);
	bool isInAreaObj(const char *, const TVec3f &);
	bool isExistAreaObj(const char *);
	s32 getAreaObjArg(const AreaObj *, s32);
	void tryToUpdatePlayerRestartIdInfo(const TVec3f &);
	void requestMovementOnAreas(const char *);
	void requestmovementOnSoundAreas(const char *);
	WaterArea* getWaterAreaObj(WaterInfo *, const TVec3f &);
	void getWaterAreaInfo(WaterInfo *, const TVec3f &);

	bool calcAreaMoveVelocity(TVec3f *, const TVec3f &);
	void calcCubePos(const AreaObj *, TVec3f *);
	void calcCubeRotate(const AreaObj *, TVec3f *);
	void calcCubeAxisZ(const AreaObj *, TVec3f *);
	//void calcCubeWorldBox(TDirBox3f *, const AreaObj *);
	TVec3f* getCubeLocalBox(const AreaObj *);
	void calcCubeLocalPos(TVec3f *, const AreaObj *, const TVec3f &);
	void calcSpherePos(TVec3f *, const AreaObj *);

	void calcCylinderPos(TVec3f *, const AreaObj *);
	void calcCylinderCenterPos(TVec3f *, const AreaObj *);
	void calcCylinderUpVec(TVec3f *, const AreaObj *);

	f32 getCylinderRadius(const AreaObj *);

	bool isInPlaneModeCube(const TVec3f &);

	void getAreaCenterPos(TVec3f *, const AreaObj *);
};
