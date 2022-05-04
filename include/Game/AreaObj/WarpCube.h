#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"
#include "Game/LiveActor/ActorCameraInfo.h"

class WarpCube : public AreaObj {
public:
	inline WarpCube(const char *pName) : AreaObj(pName), mLinkInfo(NULL) {}

	virtual ~WarpCube();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual void draw();

	JMapIdInfo* mLinkInfo; // _48
	ActorCameraInfo* mCameraInfo; // _4C
	const char* mCameraName; // _50
	u16 mInvalidateTimer; // _54
};

class WarpCubeMgr : public AreaObjMgr {
public:
	inline WarpCubeMgr(s32 size, const char *pName) : AreaObjMgr(size, pName), mEventCameraArea(NULL) {}

	virtual ~WarpCubeMgr();

	AreaObj* getPairCube(const AreaObj *);
	void setInvalidateTimer(AreaObj*, u16);
	void startEventCamera(const AreaObj *);
	void endEventCamera();

	AreaObj* mEventCameraArea; // _24
};
