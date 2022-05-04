#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"

class LiveActor;

class FlashingCtrl : public NameObj {
public:
    FlashingCtrl(LiveActor *pActor, bool toggleDraw);

    virtual ~FlashingCtrl();
    virtual void movement();
    
    void start(int timer);
    void end();
    s32 getCurrentInterval() const;
    bool isNowFlashing() const;
    bool isNowOn() const;
    void updateFlashing();

    LiveActor* mActor;      // _14
    bool mToggleDraw;       // _18
    bool mIsEnded;          // _19
    bool mOverrideInterval; // _1A
    s32 mTimer;             // _1C
    s32 mFlashStartTime;    // _20
    bool mBlink;            // _24
};
