#pragma once

#include "revolution.h"

struct TalkMessageInfo {
    TalkMessageInfo();

    bool isNormalTalk() const;
    bool isShortTalk() const;
    bool isEventTalk() const;
    bool isAutoEventTalk() const;
    bool isGlobalEventTalk() const;
    bool isBalloonCall() const;
    bool isBalloonSign() const;
    bool isBalloonIcon() const;
    bool isCameraNormal() const;
    bool isCameraEvent() const;

    wchar_t* mMessage;
    u16 mCameraId;
    u8 mSoundId;
    u8 mCameraType;
    u8 mTalkType;
    u8 mBalloonType;
    u8 mMessageLinkId;
    u8 mUnk7;
};
