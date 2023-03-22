#pragma once

#include "JSystem/JGeometry/TVec.h"
#include "JSystem/JGeometry/TQuat.h"

namespace JGeometry {
    template<typename T>
    struct SMatrix34C {
        T val[3][4];
    };

    template<typename T>
    struct TMatrix34 : public T { };

    template<typename T>
    struct TRotation3 : public T { };

    template<typename T>
    struct TPosition3 : public TRotation3<T> { };


    template<>
    struct SMatrix34C<f32> {
        void set(const SMatrix34C<f32> &);
        void set(const MtxPtr);
        void set(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);

        inline operator MtxPtr() { return val; }

        f32 val[3][4];
    };

    template<>
    struct TMatrix34<SMatrix34C<f32> > : public SMatrix34C<f32> {
        void identity();
        void scale(f32);
        void concat(const SMatrix34C<f32> &);
        void concat(const SMatrix34C<f32> &, const SMatrix34C<f32> &);
        void invert(const TMatrix34<SMatrix34C<f32> > &);

        void mult(const TVec3f &, TVec3f &) const;
        void multTranspose(const TVec3f &, const TVec3f &) const;
    };

    template<>
    struct TRotation3<TMatrix34<SMatrix34C<f32> > > : public TMatrix34<SMatrix34C<f32> > {
        void identity33();
        void mult33(TVec3f &) const;
        void mult33(const TVec3f &, TVec3f &) const;

        void getXDir(TVec3f &) const;
        void getYDir(TVec3f &) const;
        void getZDir(TVec3f &) const;
        void getXYZDir(TVec3f &, TVec3f &, TVec3f &) const;
        void getEuler(TVec3f &) const;
        void getEulerXYZ(TVec3f &) const;
        void getQuat(TQuat4f &) const;
        void getScale(TVec3f &) const;

        void setRotate(const TVec3f &, const TVec3f &);
        void setRotate(const TVec3f &, f32);
        void setXDir(const TVec3f &);
        void setYDir(const TVec3f &);
        void setZDir(const TVec3f &);
        void setXYZDir(const TVec3f &, const TVec3f &, const TVec3f &) const;
        void setEulerY(f32);
        void setQuat(const TQuat4f &);
        void setScale(f32, f32, f32);
        void setScale(f32);
    };

    template<>
    struct TPosition3<TMatrix34<SMatrix34C<f32> > > : public TRotation3<TMatrix34<SMatrix34C<f32> > > {
        inline TPosition3() { }

        void getTrans(TVec3f &) const;
        void setTrans(const TVec3f &);
        void zeroTrans();

        void makeRotate(const TVec3f &, f32);
    };
};

typedef JGeometry::TPosition3<JGeometry::TMatrix34<JGeometry::SMatrix34C<f32> > > TMtx34f;
