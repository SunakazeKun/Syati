#pragma once

#include "revolution.h"
#include "Game/LiveActor/ModelObj.h"

class BlackHole : public LiveActor {
public:
    BlackHole(const char *);

    virtual ~BlackHole();
    virtual void init(const JMapInfoIter &);
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void makeActorDead();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *, HitSensor *);

    bool tryStartDemoCamera();
    void initMapToolInfo(const JMapInfoIter &);
    void initModel();
    void initCubeBox();
    bool isInCubeBox(const TVec3f &);
    void updateModelScale(f32, f32);
    void exeWait();
    void exeDisappear();

    ModelObj* mBlackHoleModel; // _90
    f32 _94;
    f32 _98;
    f32 _9C;
    f32 _A0;
    f32 _A4;
    s32 _A8;
    Mtx _AC;
    Mtx _DC;
    s32 _10C;
};

namespace NrvBlackHole {
    NERVE(BlackHoleWait);
    NERVE(BlackHoleDemo);
    NERVE(BlackHoleDisappear);
};
