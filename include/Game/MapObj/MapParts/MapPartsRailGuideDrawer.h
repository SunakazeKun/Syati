#pragma once

#include "revolution.h"
#include "Game/MapObj/MapParts/MapPartsFunction.h"

class MapPartsRailGuidePoint : public LiveActor {
public:
	MapPartsRailGuidePoint(const LiveActor *pHost, const char *pName, f32 pointCoord, bool hasShadow);
	MapPartsRailGuidePoint(const LiveActor *pHost, const char *pName, int length, bool hasShadow);

	virtual ~MapPartsRailGuidePoint();
	virtual void init(const JMapInfoIter &rIter);

	f32 mRailPointCoord; // _90
	bool mHasShadow; // _94
};

class MapPartsRailGuideDrawer : public MapPartsFunction {
public:
	MapPartsRailGuideDrawer(LiveActor *pHost, const char *pName);

	virtual ~MapPartsRailGuideDrawer();
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isWorking() const;
	virtual void start();
	virtual void end();
	
	void show();
	void hide();
	void initGuidePoints(const JMapInfoIter &rIter);
	void exeDrawForward();

	u8 _90[0x438 - 0x28];
};

namespace NrvMapPartsRailGuideDrawer {
	NERVE(HostTypeHideAll);
	NERVE(HostTypeDrawAll);
	NERVE(HostTypeDrawForward);
};

class MapPartsRailGuideHolder : public NameObj {
public:
	MapPartsRailGuideHolder();

	virtual ~MapPartsRailGuideHolder();
	virtual void init(const JMapInfoIter &rIter);

	MapPartsRailGuideDrawer* createRailGuide(LiveActor *pHost, const char *pName, const JMapInfoIter &rIter);
	MapPartsRailGuideDrawer* find(s32 index);

	MapPartsRailGuideDrawer* mRailGuideDrawers[64]; // _14
	s32 mNumDrawers; // 114
};
