#pragma once

#include "revolution.h"

struct J3DGXColor {
    inline J3DGXColor() {
        rgba = 0;
    }

    void operator=(GXColor color);

    union {
        struct {
            u8 r, g, b, a;
        };
        u32 rgba;
    };
};
