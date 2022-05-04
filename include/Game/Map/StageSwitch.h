#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/Util/JMapIdInfo.h"

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
    static SwitchIdInfo* createSwitchIdInfo(const char *, const JMapInfoIter &l, bool);
    static void onSwitchBySwitchIdInfo(const SwitchIdInfo &);
    static void offSwitchBySwitchIdInfo(const SwitchIdInfo &);
    static bool isOnSwitchBySwitchIdInfo(const SwitchIdInfo &);
    static void onGlobalSwitchById(int);
};

class StageSwitchCtrl {
public:
    StageSwitchCtrl(const JMapInfoIter &);

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
    bool isOnAllSwitchAfterB(s32) const;
    bool isOnAnyOneSwitchAfterB(s32) const;
    bool isOnSwitchParam() const;
    bool isValidSwitchParam() const;

    SwitchIdInfo* mSW_A; // _0
    SwitchIdInfo* mSW_B; // _4
    SwitchIdInfo* mSW_Appear; // _8
    SwitchIdInfo* mSW_Dead; // _C
    u8 _10;
    SwitchIdInfo* mSW_Param; // _14
};

namespace MR {
    StageSwitchCtrl* createStageSwitchCtrl(NameObj *, const JMapInfoIter &);
};
