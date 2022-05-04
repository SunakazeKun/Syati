#pragma once

#include "revolution.h"
#include "Game/System/ResourceHolder.h"

class XanimePlayer;

class BckCtrlData {
public:
    BckCtrlData();

    void operator=(const BckCtrlData &);

    const char* _0;
    s16 mPlayFrame;     // _4
    s16 mStartFrame;    // _6
    s16 mEndFrame;      // _8
    s16 mRepeatFrame;   // _A
    s16 mInterpole;     // _C
    bool _E;
    s32 _10;
};


class BckCtrlFunction {
public:
    static void reflectBckCtrlData(const BckCtrlData &, XanimePlayer *);
};

class BckCtrl {
public:
    BckCtrl(ResourceHolder *, const char *);

    BckCtrlData* find(const char *) const;
    void add(const BckCtrlData &);
    void overWrite(const BckCtrlData &);
    void changeBckSetting(const char *, XanimePlayer *) const;

    BckCtrlData mDefaultCtrlData;   // _0
    BckCtrlData* mControlData;      // _14
    u32 mControlDataCount;          // _18
    u32 _1C;
};
