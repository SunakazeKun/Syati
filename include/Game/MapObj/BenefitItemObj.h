#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class BenefitItemObj : LiveActor {
public:
    BenefitItemObj(const char *, const char *);

    u8 _90[0x154 - 0x90];
};
