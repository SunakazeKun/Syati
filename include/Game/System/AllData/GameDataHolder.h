#pragma once

#include "revolution.h"

class GameDataAllGalaxyStorage;
class GameEventFlagStorage;
class GameEventValueChecker;
class GameDataPlayerStatus;
class GameDataTicoFatStorage;
class GameDataWorldMapStorage;
class BinaryDataChunkHolder;

class GameDataHolder {
public:
	GameDataHolder();

	// todo: functions

	GameEventFlagStorage* mEventFlagStorage; // _0
	GameEventValueChecker* mEventValueChecker; // _4
	GameDataPlayerStatus* mPlayerStatus; // _8
	GameDataAllGalaxyStorage* mAllGalaxyStorage; // _C
	GameDataTicoFatStorage* mTicoFatStorage; // _10
	GameDataWorldMapStorage* mWorldMapStorage; // _14
	BinaryDataChunkHolder* mBinaryDataChunkHolder; // _18
};
