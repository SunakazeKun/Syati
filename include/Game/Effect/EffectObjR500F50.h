#pragma once

#include "revolution.h"
#include "Game/Effect/SimpleEffectObj.h"

/* FINISHED */

class EffectObjR500F50 : public SimpleEffectObj {
public:
    virtual ~EffectObjR500F50();

    virtual f32 getClippingRadius() const;
    virtual f32 getFarClipDistance() const;
};
