#pragma once

#include "revolution.h"
#include "Game/Effect/SimpleEffectObj.h"

/* FINISHED */

class EffectObjR1500F400 : public SimpleEffectObj {
public:
    virtual ~EffectObjR1500F400();

    virtual f32 getClippingRadius() const;
    virtual f32 getFarClipDistance() const;
};
