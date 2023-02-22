#pragma once

#include "revolution.h"
#include "Game/Effect/SimpleEffectObj.h"

/* FINISHED */

class EffectObj10x10x10SyncClipping : public SimpleEffectObj {
public:
    virtual ~EffectObj10x10x10SyncClipping();

    virtual f32 getClippingRadius() const;
    virtual f32 getFarClipDistance() const;
    virtual const TVec3f& getClippingCenterOffset() const;
    virtual bool isSyncClipping() const;
};
