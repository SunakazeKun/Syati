#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/Util/JMapInfo.h"

enum AreaFormType {
	AreaForm_Cube,
	AreaForm_CenteredCube,
	AreaForm_Sphere,
	AreaForm_Cylinder,
	AreaForm_Bowl
};

class AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter) = 0;
	virtual bool isInVolume(const TVec3f &rTranslation) const = 0;

	TMtx34f* mFollowMtx; // _4
};

class AreaFormCube : public AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isInVolume(const TVec3f &rTranslation) const;

	void calcWorldPos(TVec3f *) const;
	void calcWorldRotate(TVec3f *) const;
	//void calcWorldBox(TDirBox3f *) const;
	void calcLocalPos(TVec3f *, const TVec3f &) const;
	void calcLocalRotate(TVec3f *, const TVec3f &) const;

	f32 getBaseSize();
	void updateBoxParam();
	void calcWorldMtx(TMtx34f *) const;

	int mCentered;       // _8
	TVec3f mTranslation; // _C
	TVec3f mRotation;    // _18
	TVec3f mScale;       // _24
	TVec3f _30;
	TVec3f _3C;
	TMtx34f mWorldMtx;   // _48
};

class AreaFormSphere : public AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isInVolume(const TVec3f &rTranslation) const;

	void calcUpVec(const TVec3f *);

	void calcPos(const TVec3f *);
	
	TVec3f mTranslation; // _8
	f32 mRadius;         // _14
	TVec3f mUpVec;       // _18
	TVec3f _24;
};

class AreaFormBowl : public AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isInVolume(const TVec3f &rTranslation) const;

	void calcUpVec(const TVec3f &);
	
	TVec3f mTranslation; // _8
	TVec3f mUpVec;       // _14
	f32 mRadius;
};

class AreaFormCylinder : public AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isInVolume(const TVec3f &rTranslation) const;
	
	void calcPos(const TVec3f *);
	void calcCenterPos(const TVec3f *);
	void calcUpVec(const TVec3f *);
	void calcDir(const TVec3f &);
	
	TVec3f mTranslation; // _8
	TVec3f mUpVec;       // _14
	f32 mRadius;         // _20
	f32 mHeight;         // _24
};

namespace MR {
	AreaForm* createAreaForm(int shapeNo);
};
