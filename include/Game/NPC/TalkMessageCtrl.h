#pragma once

#include "revolution.h"

struct CustomTagArg {
    union {
        int mNumberArg;
        const wchar_t* mStringArg;
    };
    s32 mType;
};

class TalkMessageCtrl {
public:
    void setMessageArg(const CustomTagArg &rTagArg);

    u8 _0[0x74];
};
