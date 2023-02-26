#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/Util/JMapInfo.h"
#include "Game/Util/JMapLinkInfo.h"

/* FINISHED */

#define NAMEOBJ_FLAG_MOVEMENT 1
#define NAMEOBJ_FLAG_RESUME 2
#define NAMEOBJ_FLAG_SUSPEND 4

class NameObj {
public:
    NameObj(const char *pName);

    virtual ~NameObj();
    virtual void init(const JMapInfoIter &rIter);
    virtual void initAfterPlacement();
    virtual void movement();
    virtual void draw() const;
    virtual void calcAnim();
    virtual void calcViewAndEntry();
    virtual void startMovement();
    virtual void endMovement();

    void initWithoutIter();
    void setName(const char *pName);
    void setLinkedInfo(const JMapInfoIter &rIter);

    void executeMovement();
    void requestSuspend();
    void requestResume();
    void syncWithFlags();

    const char* mName;        // _4
    vu16 mFlags;              // _8
    s16 mExecuteIdx;          // _A
    JMapLinkInfo mLinkedInfo; // _C
};

class NameObjFunction {
public:
    static void requestMovementOn(NameObj *pActor);
    static void requestMovementOff(NameObj *pActor);
};
