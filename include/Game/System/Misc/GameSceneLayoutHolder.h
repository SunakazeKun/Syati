#pragma once

#include "syati.h"
#include "Game/NameObj.h"
#include "Game/Screen/LayoutActor.h"

class InformationMessage;
class YesNoLayout;
class CameraInfo;
class MarioMeter;
class MissLayout;
class OneUpBoard;
class NoteCounter;
class CounterLayoutController;
class PlayerLeft;

class SubMeterLayout : public LayoutActor {
public:
    SubMeterLayout(const char*, const char*);

    virtual void init(const JMapInfoIter&);
    virtual void control();
    void setLifeRatio(f32);
    void requestDeactivate();
    void requestAppear();
    void requestFrameIn();
    void requestFrameOut();
};

class MarioSubMeter : public NameObj {
public:
    MarioSubMeter(const char*);

    virtual ~MarioSubMeter();
    virtual void init(const JMapInfoIter&);
    void setBeeLifeRatio(f32);
    void setWaterLifeRatio(f32);
    void activeSubMeterBee();
    void activeSubMeterWater();
    void frameOutSubMeter();
    void activate();
    void deactivate();

    SubMeterLayout* mBeeMeter;
    SubMeterLayout* mAirMeter;
    s32 _1C;
};

class GameSceneLayoutHolder : public NameObj {
public:
    GameSceneLayoutHolder();
    void setLifeCount(u32);
    void setOxygenRatio(f32);
    void setBeePowerRatio(f32);
    void requestPowerUpHPMeter();
    void requestForceAppearHPMeter();
    void startMiss();
    bool isMissAnimEnd();
    void activateDefaultGameLayout();
    void deactivateDefaultGameLayout();
    void createPurpleCoinCounter();
    LayoutActor* getPurpleCoinCounter() const;

    InformationMessage* mInformationMessage; // 0x14
    YesNoLayout* mYesNoLayout; // 0x18
    CameraInfo* mCameraInfo; // 0x1C
    MarioMeter* mMarioMeter; // 0x20
    MarioSubMeter* mMarioSubMeter; // 0x24
    MissLayout* mMissLayout; // 0x28
    OneUpBoard* mOneUpBoard; // 0x2C
    NoteCounter* mNoteCounter; // 0x30
    CounterLayoutController* mCounterLayoutController; // 0x34
};

namespace MR {
    GameSceneLayoutHolder* getGameSceneLayoutHolder();
};
