#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"

/* FINISHED */

class NameObjGroup : public NameObj {
public:
    NameObjGroup(const char *pName, int size);

    virtual ~NameObjGroup();

    void registerObj(NameObj *pActor);
    void clearAllObjs();
    bool isFull() const;
    void pauseOffAll() const;
    void initObjArray(s32 size);

    s32 mMaxObjs;    // _14
    s32 mNumObjs;    // _18
    NameObj** mObjs; // _1C
};
