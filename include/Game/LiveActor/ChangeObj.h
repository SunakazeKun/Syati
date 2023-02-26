#pragma once

#include "Game/LiveActor/LiveActor.h"

/* FINISHED */

class ChangeObj {
public:
    virtual void doChange(ChangeObj *pOther) = 0;

    void changeTRSVGFromOther(const ChangeObj *pOther);

    LiveActor* mHost; // _4
};
