#pragma once

#include "JSystem/JGeometry/TVec.h"

namespace JGeometry {
    template<typename T>
    struct TBox2 {
        inline TBox2() { }

        TVec2<T> mPointMin;
        TVec2<T> mPointMax;
    };

    template<typename T>
    struct TBox3 {
        inline TBox3() { }

        TVec3<T> mPointMin;
        TVec3<T> mPointMax;
    };

    template<typename T>
    struct TDirBox3 {
        inline TDirBox3() { }

        TVec3<T> mDirectionX;
        TVec3<T> mDirectionY;
        TVec3<T> mDirectionZ;
        TVec3<T> mCenterPos;
        TVec3<T> mTranslation;
    };

    template<>
    struct TBox2<f32> {
        inline TBox2() { }
        TBox2(const TBox2<f32> &);
        TBox2(f32, f32, f32, f32);

        void set(const TBox2<f32> &);
        void set(f32, f32, f32, f32);
        void set(const TVec2<f32> &, const TVec2<f32> &);

        void operator=(const TBox2<f32> &);

        TVec2<f32> mPointMin;
        TVec2<f32> mPointMax;
    };
};

typedef JGeometry::TBox2<f32> TBox2f;
typedef JGeometry::TBox3<f32> TBox3f;
typedef JGeometry::TDirBox3<f32> TDirBox3f;
