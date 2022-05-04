#pragma once

#include "revolution.h"
#include "Game/MapObj/MapParts/MapPartsFunction.h"

class MapPartsRailPointPassChecker : public MapPartsFunction {
public:
	MapPartsRailPointPassChecker(LiveActor *);

	virtual ~MapPartsRailPointPassChecker();
	virtual void movement();
	virtual bool isWorking() const;
	virtual void start();
	virtual void end();

	bool isPassed() const;
	bool isReachedEnd() const;

	s32 mCurrentRailPointNo; // _28
};
