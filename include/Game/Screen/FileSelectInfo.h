#pragma once

#include "Game/Screen/LayoutActor.h"
#include "Game/System/NerveExecutor.h"

struct FileSelectFileInfo {
    wchar_t* mUserName;
    s32 mFileID;
    s32 mPowerStarNum;
    s32 mGrandStarNum;
    bool mCompleteSilver;
    bool mIsView120StarsEnding;
    bool mCompleteGold;
    bool mCompletePlatinum;
    wchar_t* mLastPlayDateString;
    wchar_t* mLastPlayTimeString;
    s32 mMissCount;
    wchar_t* mCumulativePlayTimeString;
};

class FileSelectInfo;

namespace FileSelectInfoSub {
    class SlideState : public NerveExecutor {
    public:
        SlideState(FileSelectInfo *pInfo);

        virtual ~SlideState();

        void exeNormalPos();
        void exeSliding();
        void exeSlidePos();
        void exeSlidingBack();

        FileSelectInfo* mFileSelectInfo;
    };

    NERVE(SlideStateNrvNormalPos);
    NERVE(SlideStateNrvSliding);
    NERVE(SlideStateNrvSlidePos);
    NERVE(SlideStateNrvSlidingBack);
};

class FileSelectInfo : public LayoutActor {
public:
    FileSelectInfo(s32 userNameLength, const char *pName);

    virtual ~FileSelectInfo();
    virtual void init(const JMapInfoIter &rIter);
    virtual void appear();
    virtual void control();

    void disappear();
    void slide();
    void slideBack();
    void setInfo(const FileSelectFileInfo &rInfo);
    void exeAppear();
    void exeDisappear();
    void reflectInfo();
    void setMissCounter();
    void setCompleteness();
    void setMessage();

    s32 mFileID;                                // _2C
    s32 mPowerStarNum;                          // _30
    s32 mUserNameLength;                        // _34
    wchar_t* mUserName;                         // _38
    wchar_t mLastPlayDateString[32];            // _3C
    wchar_t mLastPlayTimeString[32];            // _7C
    s32 mMissCount;                             // _BC
    s32 mGrandStarNum;                          // _C0
    bool mCompleteSilver;                       // _C4
    bool mIsView120StarsEnding;                 // _C5
    bool mCompleteGold;                         // _C6
    bool mCompletePlatinum;                     // _C7
    bool mIsGameComplete;                       // _C8
    bool mIsNormalComplete;                     // _C9
    wchar_t mCumulativePlayTimeString[32];      // _CA
    FileSelectInfoSub::SlideState* mSlideState; // _10C
};

namespace NrvFileSelectInfo {
    NERVE(FileSelectInfoNrvAppear);
    NERVE(FileSelectInfoNrvDisplay);
    NERVE(FileSelectInfoNrvDisappear);
};
