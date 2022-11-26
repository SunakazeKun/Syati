#pragma once

#include "syati.h"
#include "Game/LiveActor.h"

class AudTamakoroBgmCtrl;
class SphereAccelSensorController;
class TamakoroTutorial;

class Tamakoro : public LiveActor {
public:
    Tamakoro(const char*);
    
    SphereAccelSensorController* mSphereAccelSensorController; // 0x90
    TamakoroTutorial* mTamakoroTutorial; // 0x94
    s32 _98;
    LiveActor* mPurpleCoin; // 0x9C
    TQuat4f _A0;
    TQuat4f _B0;
    TVec3f _C0;
    TVec3f _CC;
    TVec3f _D8;
    TVec3f _E4;
    TVec3f _F0;
    TVec3f _FC;
    TVec3f _108;
    TVec3f _114;
    TVec3f _120;
    TVec3f _12C;
    f32 _138;
    f32 _13C;
    f32 _140;
    f32 _144;
    s32 _148;
    s32 _14C;
    AudTamakoroBgmCtrl* mAudTamakoroBgmCtrl; // 0x150
    bool _154;
    bool _155;
    bool mItem;
};