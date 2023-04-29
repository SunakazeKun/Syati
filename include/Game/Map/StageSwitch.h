#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/Util/JMapIdInfo.h"

class NameObj;

class BitFlag128 {
public:
    inline BitFlag128() {
        mFlags[0] = 0;
        mFlags[1] = 0;
        mFlags[2] = 0;
        mFlags[3] = 0;
    }

    bool get(s32) const;
    void set(s32, bool);

    s32 mFlags[4];
};

class ZoneSwitch : public BitFlag128 {
public:
    ZoneSwitch();
};

class SwitchIdInfo {
public:
    SwitchIdInfo(s32, const JMapInfoIter &);

    JMapIdInfo* mIDInfo; // _0
    bool mIsGlobal;      // _4
};

class StageSwitchFunction {
public:
    static SwitchIdInfo* createSwitchIdInfo(const char *, const JMapInfoIter &rIter, bool);
    static void onSwitchBySwitchIdInfo(const SwitchIdInfo &rInfo);
    static void offSwitchBySwitchIdInfo(const SwitchIdInfo &rInfo);
    static bool isOnSwitchBySwitchIdInfo(const SwitchIdInfo &rInfo);
    static void onGlobalSwitchById(int);
};

class StageSwitchCtrl {
public:
    StageSwitchCtrl(const JMapInfoIter &rIter);

    void onSwitchA();
    void offSwitchA();
    bool isOnSwitchA() const;
    bool isValidSwitchA() const;
    void onSwitchB();
    void offSwitchB();
    bool isOnSwitchB() const;
    bool isValidSwitchB() const;
    bool isOnSwitchAppear() const;
    bool isValidSwitchAppear() const;
    void onSwitchDead();
    void offSwitchDead();
    bool isValidSwitchDead() const;
    bool isOnAllSwitchAfterB(s32 count) const;
    bool isOnAnyOneSwitchAfterB(s32 count) const;
    bool isOnSwitchParam() const;
    bool isValidSwitchParam() const;

    SwitchIdInfo* mSwitchA;      // _0
    SwitchIdInfo* mSwitchB;      // _4
    SwitchIdInfo* mSwitchAppear; // _8
    SwitchIdInfo* mSwitchDead;   // _C
    bool mIsSwitchDeadAuto;      // _10
    SwitchIdInfo* mSwitchParam;  // _14
};

namespace MR {
    StageSwitchCtrl* createStageSwitchCtrl(NameObj *pObject, const JMapInfoIter &rIter);
};
