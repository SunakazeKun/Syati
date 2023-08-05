#pragma once

#include "Game/LiveActor/LiveActor.h"

class Dossun : public LiveActor {
public:
    Dossun(const char *pName);

    virtual ~Dossun();
    virtual void init(const JMapInfoIter &rIter);
    virtual void movement();
    virtual void appear();
    virtual void control();

    void initMapToolInfo(const JMapInfoIter &rIter);
    void initCollision(const JMapInfoIter &rIter);
    void initShadow();
    void calcParameters();

    s32 getUpperFrame() const;
    s32 getStepUntilRising() const;

    void exeUpper();
    void exeFallSign();
    void exeFalling();
    void exeOnGround();
    void exeRising();

    s32 _90;                           // _90
    TVec3f _94;                        // _94
    TVec3f _A0;                        // _A0
    s32 _AC;                           // _AC
    s32 _B0;                           // _B0
    f32 mMovementDistance;             // _B4
    s32 mUpperFrame;                   // _B8
    s32 mStepUntilRaising;             // _BC
    s32 mShadowType;                   // _C0
    bool mIsCollisionEnemyStrongLight; // _C4
};

namespace NrvDossun {
    NERVE(DossunNrvReady);
    NERVE(DossunNrvUpper);
    NERVE(DossunNrvFallSign);
    NERVE(DossunNrvFalling);
    NERVE(DossunNrvOnGround);
    NERVE(DossunNrvRising);
};
