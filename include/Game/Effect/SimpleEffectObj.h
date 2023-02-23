#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

/* FINISHED */

namespace {
    struct EffectDataEntry {
        const char* mObjName;
        const char* mEffectEmitStartSound;
        const char* mEffectEmittingSound;
        s32 mShakeCameraType;
        const char* mPadRumblePattern;
        s32 mPadRumbleDelay;
    };

    const EffectDataEntry* findDataElement(const char *pEffectName);
};

class SimpleEffectObj : public LiveActor {
public:
    SimpleEffectObj(const char *pName);

    virtual ~SimpleEffectObj();
    virtual void init(const JMapInfoIter &rIter);
    virtual void startClipped();
    virtual void endClipped();

    virtual f32 getClippingRadius() const;
    virtual f32 getFarClipDistance() const;
    virtual const TVec3f& getClippingCenterOffset() const;
    virtual bool isSyncClipping() const;

    void setStateWait();
    void setStateMove();

    const char* mObjName; // _90
    TVec3f mClipping;     // _94
};

namespace NrvSimpleEffectObj {
    NERVE(HostTypeWait);
    NERVE(HostTypeMove);
};
