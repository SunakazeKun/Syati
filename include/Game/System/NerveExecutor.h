#pragma once

#include "revolution.h"
#include "Game/LiveActor/Spine.h"

class NerveExecutor {
public:
    NerveExecutor(const char *pName);

    virtual ~NerveExecutor();

    void initNerve(const Nerve *pNerve);
    void updateNerve();
    void setNerve(const Nerve *pNerve);
    bool isNerve(const Nerve *pNerve) const;
    u32 getNerveStep() const;

    Spine* mSpine; // _4
};
