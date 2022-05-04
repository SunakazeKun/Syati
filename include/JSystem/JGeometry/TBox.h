#pragma once

#include "JSystem/JGeometry/TVec.h"

namespace JGeometry {
    template<typename T>
    struct TBox2 {
        inline TBox2() { }

        T _0, _4, _8, _C;
    };

    template<>
    struct TBox2<f32> {
    public:
        inline TBox2() { }
        TBox2(const TBox2<f32> &);
        TBox2(f32, f32, f32, f32);

        void set(const TBox2<f32> &);
        void set(f32, f32, f32, f32);
        void set(const TVec2<f32> &, const TVec2<f32> &);

        void operator=(const TBox2<f32> &);

        f32 _0, _4, _8, _C;
    };
};
