#pragma once

#include "revolution.h"
#include "Game/NameObj.h"
#include "Game/AreaObj/AreaForm.h"
#include "Game/Map/StageSwitch.h"
#include "Game/Util/Array.h"

/* FINISHED */

class AreaObj : public NameObj {
public:
    AreaObj(const char *pName);
    AreaObj(int shapeNo, const char *pName);

    virtual ~AreaObj();
    virtual void init(const JMapInfoIter &rIter);
    virtual bool isInVolume(const TVec3f &rTranslation) const;
    virtual s32 getAreaPriority() const;
    virtual const char* getManagerName() const;

    void validate();
    void invalidate();
    void awake();
    void sleep();

    void initForm(const JMapInfoIter &rIter);
    bool isNotHemisphere() const;

    void onSwitchA();
    void offSwitchA();
    bool isOnSwitchA() const;
    bool isOnSwitchB() const;
    bool isValidSwitchA() const;
    bool isValidSwitchB() const;

    void setFollowMtx(const TMtx34f *pFollowMtx);
    TMtx34f* getFollowMtx() const;

    AreaForm* mAreaForm;               // _14
    int mAreaFormType;                 // _18
    bool mValidate;                    // _1C
    bool mFollowActorAlive;            // _1D
    s32 mObjArg0;                      // _20
    s32 mObjArg1;                      // _24
    s32 mObjArg2;                      // _28
    s32 mObjArg3;                      // _2C
    s32 mObjArg4;                      // _30
    s32 mObjArg5;                      // _34
    s32 mObjArg6;                      // _38
    s32 mObjArg7;                      // _3C
    s32 mPriority;                     // _40
    StageSwitchCtrl* mStageSwitchCtrl; // _44
};

class AreaObjMgr : public NameObj {
public:
    AreaObjMgr(s32 size, const char *pName);

    virtual ~AreaObjMgr();
    
    void entry(AreaObj *pArea);
    bool find_in(const TVec3f &rTranslation) const;
    void requestMovementOnAll();

    MR::Vector<MR::AssignableArray<AreaObj*> > mAreas; // 14
    s32 mMaxAreasArg;                                  // 20
};
