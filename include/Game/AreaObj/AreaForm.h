#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/Util/JMapInfo.h"

/* FINISHED */

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

	void calcWorldPos(TVec3f *pPosition) const;
	void calcWorldRotate(TVec3f *pRotation) const;
	void calcWorldBox(TDirBox3f *pWorldBox) const;
	void calcLocalPos(TVec3f *pPosition, const TVec3f &rPosition) const;
	void calcLocalRotate(TVec3f *pRotation, const TVec3f &rRotation) const;

	f32 getBaseSize();
	void updateBoxParam();
	void calcWorldMtx(TMtx34f *pWorldMtx) const;

	int mCentered;       // _8
	TVec3f mTranslation; // _C
	TVec3f mRotation;    // _18
	TVec3f mScale;       // _24
	TBox3f mLocalBox;    // _30
	TMtx34f mWorldMtx;   // _48
};

class AreaFormSphere : public AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isInVolume(const TVec3f &rTranslation) const;

	void calcUpVec(TVec3f *pUpVec) const;
	void calcFrontUpVec(TVec3f *pFrontVec) const;
	void calcPos(TVec3f *pPosition) const;
	
	TVec3f mTranslation; // _8
	f32 mRadius;         // _14
	TVec3f mUpVec;       // _18
	TVec3f mFrontVec;    // _24
};

class AreaFormBowl : public AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isInVolume(const TVec3f &rTranslation) const;

	void calcUpVec(const TVec3f &rEulerRot);
	
	TVec3f mTranslation; // _8
	TVec3f mUpVec;       // _14
	f32 mRadius;         // _20
};

class AreaFormCylinder : public AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isInVolume(const TVec3f &rTranslation) const;
	
	void calcPos(TVec3f *pPosition) const;
	void calcCenterPos(TVec3f *pCenterPos) const;
	void calcUpVec(TVec3f *pUpVec) const;
	void calcDir(TVec3f &rEulerRot);
	
	TVec3f mTranslation; // _8
	TVec3f mUpVec;       // _14
	f32 mRadius;         // _20
	f32 mHeight;         // _24
};

namespace MR {
	AreaForm* createAreaForm(int shapeNo);
};
