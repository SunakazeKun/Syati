#pragma once

#include "revolution.h"

/* FINISHED */

namespace MR {
    class BitArray {
    public:
        BitArray(int flagCount);

        bool isOn(int flag) const;
        void set(int flag, bool state);

        u8* mFlags;
        int mFlagCount;
    };
};
