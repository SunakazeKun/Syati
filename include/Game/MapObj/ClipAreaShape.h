#pragma once

#include "JSystem.h"


class ClipAreaShape {
public:
    ClipAreaShape(const char *pModel);

    virtual bool isInArea(const TVec3f &rPosition) const;
    virtual void calcVolumeMatrix(TMtx34f *pVolumeMtx, const TVec3f &, const TVec3f &) const;

    void* mModelData; // _4
};

class ClipAreaShapeSphere : public ClipAreaShape {
public:
    ClipAreaShapeSphere();

    virtual bool isInArea(const TVec3f &rPosition) const;
    virtual void calcVolumeMatrix(TMtx34f *pVolumeMtx, const TVec3f &, const TVec3f &) const;

    f32 mRadius; // _C
};

class ClipAreaShapeBox : public ClipAreaShape {
public:
    ClipAreaShapeBox(const char *pModel, s32);

    virtual bool isInArea(const TVec3f &rPosition) const;
    virtual void calcVolumeMatrix(TMtx34f *pVolumeMtx, const TVec3f &, const TVec3f &) const;
};

class ClipAreaShapeCylinder : public ClipAreaShape {
public:
    ClipAreaShapeCylinder();

    virtual bool isInArea(const TVec3f &rPosition) const;
    virtual void calcVolumeMatrix(TMtx34f *pVolumeMtx, const TVec3f &, const TVec3f &) const;
};

class ClipAreaShapeCone : public ClipAreaShape {
public:
    ClipAreaShapeCone(s32);

    virtual bool isInArea(const TVec3f &rPosition) const;
    virtual void calcVolumeMatrix(TMtx34f *pVolumeMtx, const TVec3f &, const TVec3f &) const;
};
