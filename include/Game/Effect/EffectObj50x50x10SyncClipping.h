#pragma once

#include "revolution.h"
#include "Game/Effect/SimpleEffectObj.h"

/* FINISHED */

class EffectObj50x50x10SyncClipping : public SimpleEffectObj {
public:
    virtual ~EffectObj50x50x10SyncClipping();

    virtual f32 getClippingRadius() const;
    virtual f32 getFarClipDistance() const;
    virtual const TVec3f& getClippingCenterOffset() const;
    virtual bool isSyncClipping() const;
};
