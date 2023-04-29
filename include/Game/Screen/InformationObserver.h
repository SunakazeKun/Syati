#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

/* FINISHED */

class InformationObserver : public LiveActor {
public:
    enum TYPE {
        InformationObserver_Bee,
        InformationObserver_Teresa,
        InformationObserver_Hopper,
        InformationObserver_Fire,
        InformationObserver_Ice,
        InformationObserver_Flying,
        InformationObserver_Invincible,
        InformationObserver_Rock,
        InformationObserver_Cloud,
        InformationObserver_Drill,
        InformationObserver_LifeUp,
        InformationObserver_OneUp,
        InformationObserver_Yoshi,
        InformationObserver_CometMedal,
        InformationObserver_MarioFacePlanet
    };

    InformationObserver();

    virtual ~InformationObserver();
    virtual void init(const JMapInfoIter &rIter);

    void entry(TYPE type, LiveActor *pHost, bool pauseTimeKeepHostDemo);

    void exeDisp();
    void exeEnd();

    TYPE mType;                  // _90
    bool mPauseTimeKeepHostDemo; // _94
    LiveActor* mHost;            // _98
    s32 mAButtonDelay;           // _9C
};

class InformationObserverFunction {
public:
    static bool isActive();

    static void explainBee();
    static void explainTeresa();
    static void explainHopper();
    static void explainFire();
    static void explainIce();
    static void explainFlying();
    static void explainInvincible();
    static void explainRock();
    static void explainCloud();
    static void explainDrill();
    static void explainLifeUp();
    static void explainOneUp();
    static void explainYoshi(LiveActor *pHost);
    static void explainCometMedal(LiveActor *pHost);
    static void explainMarioFacePlanet(LiveActor *pHost);
};

namespace NrvInformationObserver {
    NERVE(InformationObserverNrvWait);
    NERVE(InformationObserverNrvDisp);
    NERVE(InformationObserverNrvEnd);
};
