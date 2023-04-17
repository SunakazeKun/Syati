#pragma once

#include "revolution.h"

namespace JGeometry {
    void negateInternal(const f32 *rSrc, f32 *rDest);

    template<typename T>
    struct TVec2 {
        T x;
        T y;
    };

    template<typename T>
    struct TVec3 {
        T x;
        T y;
        T z;
    };

    template<typename T>
    struct TVec4 {
        T x;
        T y;
        T z;
        T w;
    };

    template<>
    struct TVec2<f32> {
        /* Constructors */
        inline TVec2() { }
        TVec2(const TVec2<f32> &);

        template<typename T>
        TVec2(T, T);

        /* Getters and setters */
        template<typename T>
        void set(const TVec2<T> &);

        template<typename T>
        void set(T, T);

        void setMin(const TVec2<f32> &);
        void setMax(const TVec2<f32> &);

        void zero();

        /* Arithmetic and algebraic operations */
        void sub(const TVec2<f32> &);

        f32 distance(const TVec2<f32> &) const;
        f32 length() const;
        f32 squared(const TVec2<f32> &) const;
        f32 dot(const TVec2<f32> &) const;

        /* Operators */
        void operator=(const TVec2<f32> &);
        TVec2<f32> operator+(const TVec2<f32> &) const;
        TVec2<f32> operator-(const TVec2<f32> &) const;
        TVec2<f32> operator*(f32) const;

        f32 x;
        f32 y;
    };

    template<>
    struct TVec3<f32> {
        /* Constructors */
        inline TVec3() { }
        TVec3(const TVec3<f32> &);
        TVec3(const Vec &);
        TVec3(f32);

        template<typename T>
        TVec3(T, T, T); // supports int and f32

        /* Getters and setters */
        void set(const Vec &);

        template<typename T>
        void set(const TVec3<T> &);

        template<typename T>
        void set(T, T, T); // supports int and f32

        template<typename T>
        void setAll(T);

        void zero();
        void negate();
        void negate(const TVec3<f32> &);

        /* Arithmetic and algebraic operations */
        void add(const TVec3<f32> &);
        void add(const TVec3<f32> &, const TVec3<f32> &);
        void sub(const TVec3<f32> &);
        void sub(const TVec3<f32> &, const TVec3<f32> &);
        void mul(const TVec3<f32> &);
        void mul(const TVec3<f32> &, const TVec3<f32> &);
        void scale(f32);
        void scale(f32, const TVec3<f32> &);

        void setLength(f32);
        void setLength(const TVec3<f32> &, f32);

        f32 squared() const;
        f32 squared(const TVec3<f32> &) const;
        f32 dot(const TVec3<f32> &) const;
        f32 normalize(const TVec3<f32> &);

        f32 angle(const TVec3<f32> &) const;

        /* Checkers */
        bool epsilonEquals(const TVec3<f32> &, f32) const;
        bool isZero() const;

        /* Operators */
        void operator=(const TVec3<f32> &);
        TVec3<f32> operator+(const TVec3<f32> &) const;
        void operator+=(const TVec3<f32> &);
        TVec3<f32> operator-(const TVec3<f32> &) const;
        TVec3<f32> operator-() const;
        void operator-=(const TVec3<f32> &);
        TVec3<f32> operator*(f32) const;
        void operator*=(f32);
        TVec3<f32>operator/(f32) const;
        bool operator==(const TVec3<f32> &) const;

        inline operator Vec*() { return (Vec*)&x; }
        inline operator const Vec*() const { return (Vec*)&x; }
        inline operator f32*() { return (f32*)&x; }
        inline operator const f32*() const { return (f32*)&x; }

        f32 x;
        f32 y;
        f32 z;
    };

    template<>
    struct TVec3<s8> {
        /* Constructors */
        inline TVec3() { }

        template<typename T>
        TVec3(T);

        s8 x;
        s8 y;
        s8 z;
    };

    template<>
    struct TVec3<s16> {
        /* Constructors */
        inline TVec3() { }

        template<typename T>
        TVec3(T, T, T);

        /* Operators */
        inline operator S16Vec*() { return (S16Vec*)&x; }
        inline operator const S16Vec*() const { return (S16Vec*)&x; }

        s16 x;
        s16 y;
        s16 z;
    };

    template<>
    struct TVec4<f32> {
        /* Constructors */
        inline TVec4() { }

        template<typename T>
        TVec4(T, T, T, T);

        /* Getters and setters */
        template<typename T>
        void set(const TVec4<T> &);

        template<typename T>
        void set(T, T, T, T);

        /* Arithmetic and algebraic operations */
        void scale(f32);

        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
};

typedef JGeometry::TVec2<f32> TVec2f;
typedef JGeometry::TVec3<s8> TVec3c;
typedef JGeometry::TVec3<f32> TVec3f;
typedef JGeometry::TVec3<s16> TVec3s;
typedef JGeometry::TVec4<f32> TVec4f;
