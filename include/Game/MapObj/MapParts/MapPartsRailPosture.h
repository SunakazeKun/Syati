#pragma once

#include "revolution.h"
#include "Game/MapObj/MapParts/MapPartsFunction.h"

class MapPartsRailPosture : public MapPartsFunction {
public:
	MapPartsRailPosture(LiveActor *pHost);

	virtual ~MapPartsRailPosture();
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isWorking() const;
	virtual void start();
	virtual void end();

	bool isPostureTypeRailDirRailUseShadowGravity() const;
	void exeMove();
	
	TMtx34f mPoseMtx; // _28
	s32 mPostureType; // _58
};

namespace NrvMapPartsRailPosture {
	NERVE(HostTypeDoNothing);
	NERVE(HostTypeMove);
};
