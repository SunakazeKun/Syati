#pragma once

#include "revolution.h"
#include "Game/Util/JMapInfo.h"

class GameSystemDataHolder {
public:
	GameSystemDataHolder();

	void init();

	JMapInfo* mHeapSizeExcept;              // _0
	JMapInfo* mGalaxyDataTable;             // _4
	JMapInfo* mMarioFaceShipEventDataTable; // _8
	JMapInfo* mMarioFaceShipEventCastTable; // _C
	JMapInfo* mGalaxyWorldOrderList;        // _10
	JMapInfo* mWorldMapHeapGalaxy;          // _14
	JMapInfo* mWorldMapHeapResource;        // _18
};

class GameSystemDataFunction {
public:
	static JMapInfo* getHeapSizeExcept();
	static JMapInfo* getMarioFaceShipEventDataTable();
	static JMapInfo* getMarioFaceShipEventCastTable();
	static JMapInfo* getGalaxyWorldOrderList();
	static JMapInfo* getWorldMapHeapGalaxy();
	static JMapInfo* getWorldMapHeapResource();
};
