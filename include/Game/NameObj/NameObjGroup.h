#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"

class NameObjGroup : public NameObj {
public:
    NameObjGroup(const char *pName, int size);	

    virtual ~NameObjGroup();

    void registerObj(NameObj *pActor);

    void pauseOffAll() const;
    void initObjArray(s32 size);

    s32 mMaxObjs; // _14
    s32 mNumObjs; // _18
    NameObj** mObjs; // _1C
};
