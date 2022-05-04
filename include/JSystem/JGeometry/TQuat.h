#pragma once

#include "JSystem/JGeometry/TVec.h"

namespace JGeometry {
    template<typename T>
    struct TQuat4 : public TVec4<T> {
    };

    template<>
    struct TQuat4<f32> : public TVec4<f32> {
        /* Constructors */
        inline TQuat4() { }

        template<typename T>
        TQuat4(T, T, T, T);

        /* Getters and setters */
        void getXDir(const TVec3<f32> &) const;
        void getYDir(const TVec3<f32> &) const;
        void getZDir(const TVec3<f32> &) const;

        void getEuler(const TVec3<f32> &) const;
        void setEuler(f32, f32, f32);

        void setRotate(const TVec3<f32> &, f32);
        void setRotate(const TVec3<f32> &, const TVec3<f32> &);
        void setRotate(const TVec3<f32> &, const TVec3<f32> &, f32);

        /* Arithmetic and algebraic operations */
        void transform(const TVec3<f32> &) const;
        void transform(const TVec3<f32> &, const TVec3<f32> &) const;

        void rotate(const TVec3<f32> &) const;

        void normalize();
        void normalize(const TQuat4<f32> &);
        void slerp(const TQuat4<f32> &, f32);

        /* Operators */
        void operator=(const TQuat4<f32> &);

        inline operator Quaternion*() { return (Quaternion*)&x; }
        inline operator const Quaternion*() const { return (Quaternion*)&x; }
    };
};

typedef JGeometry::TQuat4<f32> TQuat4f;
