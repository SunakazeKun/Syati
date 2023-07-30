#pragma once

#include "revolution.h"

class MarioActor;

class Mario {
public:
    Mario(MarioActor *pMarioActor);

    void initMember();
    
    bool isStatusActive(u32 statusCode) const;

    u8 _0[0xA9C];
};
