#pragma once

#include "revolution.h"
#include "JSystem.h"

class AreaObj;
class AreaObjMgr;
class WaterArea;
class WaterInfo;

namespace MR {
	bool isAreaFormCube(const AreaObj *pArea);
	bool isAreaFormCylinder(const AreaObj *pArea);

	AreaObjMgr* getAreaObjManager(const char *pAreaName);
	AreaObj* getAreaObj(const char *pAreaName, const TVec3f &rPosition);
	AreaObj* getAreaObjAtPlayerPos(const char *pAreaObj);
	bool isInAreaObj(const char *pAreaName, const TVec3f &rPosition);
	bool isExistAreaObj(const char *pAreaName);
	s32 getAreaObjArg(const AreaObj *pArea, s32 argIndex);

	void tryToUpdatePlayerRestartIdInfo(const TVec3f &rPosition); // dummied-out

	void requestMovementOnAreas(const char *pAreaName);
	void requestmovementOnSoundAreas();

	bool getWaterAreaObj(WaterInfo *pWaterInfo, const TVec3f &rPosition);
	void getWaterAreaInfo(WaterInfo *pWaterInfo, const TVec3f &rPosition);
	bool calcWhirlPoolAccelInfo(const TVec3f &rPosition, TVec3f *pAccel); // dummied-out
	bool intersectsWaterAreaInfo(const WaterInfo *pWaterInfoA, const WaterInfo *pWaterInfoB);
	bool hasNoWaterAreaCube(const WaterInfo *pWaterInfo);
	// four more water-related functions here

	bool calcAreaMoveVelocity(TVec3f *pVelocity, const TVec3f &rPosition);
	void calcCubePos(const AreaObj *pArea, TVec3f *pPosition);
	void calcCubeRotate(const AreaObj *pArea, TVec3f *pRotation);
	void calcCubeAxisZ(const AreaObj *pArea, TVec3f *pAxisZ);
	void calcCubeWorldBox(TDirBox3f *pWorldBox, const AreaObj *pArea);
	const TBox3f* getCubeLocalBox(const AreaObj *pArea);
	void calcCubeLocalPos(TVec3f *pLocalPos, const AreaObj *pArea, const TVec3f &rPosition);

	void calcSpherePos(TVec3f *pPosition, const AreaObj *pArea);
	f32 getSphereRadius(const AreaObj *pArea);
	void calcSphereFrontVec(TVec3f *pFrontVec, const AreaObj *pArea);

	void calcCylinderPos(TVec3f *pPosition, const AreaObj *pArea);
	void calcCylinderCenterPos(TVec3f *pCenterPos, const AreaObj *pArea);
	void calcCylinderUpVec(TVec3f *pUpVec, const AreaObj *pArea);
	void calcCylinderFrontVec(TVec3f *pFrontVec, const AreaObj *pArea);
	f32 getCylinderRadius(const AreaObj *pArea);

	void calcHemisphereFrontVec(TVec3f *pFrontVec, const AreaObj *pArea);

	bool isInPlaneModeCube(const TVec3f &rPosition);
	bool isInTowerModeCylinder(const TVec3f &rPosition, TVec3f *pCenterPos, TVec3f *pUpVec, f32 *pRadius);

	void getAreaFrontVec(TVec3f *pFrontVec, const AreaObj *pArea);
	void getAreaCenterPos(TVec3f *pCenterPos, const AreaObj *pArea);
};
