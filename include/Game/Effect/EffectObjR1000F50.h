#pragma once

#include "revolution.h"
#include "Game/Effect/SimpleEffectObj.h"

/* FINISHED */

class EffectObjR1000F50 : public SimpleEffectObj {
public:
    virtual ~EffectObjR1000F50();

    virtual f32 getClippingRadius() const;
    virtual f32 getFarClipDistance() const;
};
