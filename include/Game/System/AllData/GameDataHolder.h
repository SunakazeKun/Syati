#pragma once

#include "revolution.h"
#include "Game/System/GameData/GameDataGalaxyStorage.h"

class BinaryDataChunkHolder;
class GameEventFlagStorage;
class GameEventValueChecker;
class GameDataPlayerStatus;
class GameDataTicoFatStorage;
class GameDataWorldMapStorage;

class GameDataHolder {
public:
    GameDataHolder();

    bool isOnGameEventFlag(const char *pEventFlagName) const;
    void onGameEventFlag(const char *pEventFlagName);
    void offGameEventFlag(const char *pEventFlagName);
    u16 getGameEventValue(const char *pEventValueName) const;
    void setGameEventValue(const char *pEventValueName, u16 value);
    void incPlayerMissNum();
    void getPlayerMissNum() const;
    void calcCurrentPowerStarNum() const;
    void calcNormalPowerStarNum() const;
    void hasGrandStar(int) const;
    s32 calcTicoCoinNum() const;
    s32 getStocketStarPieceNum() const;
    void addStockedStarPieceNum(int count);
    void incCumulativePlayTime();
    s32 getCumulativePlayTime() const;
    void resetAllData();
    void makeFileBinary(u8 *pDest, u32);
    void loadFromFileBinary(const char *pName, const u8 *pSrc, u32);

    GameEventFlagStorage* mEventFlagStorage;       // _0
    GameEventValueChecker* mEventValueChecker;     // _4
    GameDataPlayerStatus* mPlayerStatus;           // _8
    GameDataAllGalaxyStorage* mAllGalaxyStorage;   // _C
    GameDataTicoFatStorage* mTicoFatStorage;       // _10
    GameDataWorldMapStorage* mWorldMapStorage;     // _14
    BinaryDataChunkHolder* mBinaryDataChunkHolder; // _18
};
