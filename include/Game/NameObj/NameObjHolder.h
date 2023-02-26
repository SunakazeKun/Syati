#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Util/Array.h"

/* FINISHED */

class NameObjHolder {
public:
    NameObjHolder(int size);

    void add(NameObj *pObj);
    void suspendAllObj();
    void resumeAllObj();
    void syncWithFlags();
    void callMethodAllObj(void (NameObj::*)(const void *, void *));
    void clearArray();
    NameObj* find(const char *pName);

    NameObj** mObjs; // _0
    s32 mObjsSize;   // _4
    s32 mObjsCount;  // _8
    MR::Vector<MR::FixedArray<NameObj*, 16> > mSearchBuffer; // _C
};
