#pragma once

#include "revolution.h"
#include "Game/Effect/SimpleEffectObj.h"

/* FINISHED */

class EffectObj20x20x10SyncClipping : public SimpleEffectObj {
public:
    virtual ~EffectObj20x20x10SyncClipping();

    virtual f32 getClippingRadius() const;
    virtual f32 getFarClipDistance() const;
    virtual const TVec3f& getClippingCenterOffset() const;
    virtual bool isSyncClipping() const;
};
