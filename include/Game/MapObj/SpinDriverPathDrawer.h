#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class SpinDriverShootPath;

class SpinDriverPathDrawInit : public NameObj {
public:
	SpinDriverPathDrawInit();

	virtual ~SpinDriverPathDrawInit();

	void initDraw();

	u32* mTexBlue;
	u32* mTexGreen;
	u32* mTexPink;
	u32* mTexMask;
	bool mDrawAtOpa;
};

namespace MR {
	void setSpinDriverPathColorNormal();
	void setSpinDriverPathColorGreen();
	void setSpinDriverPathColorPink();
	void isDrawSpinDriverPathAtOpa();
	void onDrawSpinDriverPathAtOpa();
	void offDrawSpinDriverPathAtOpa();
};

class SpinDriverPathDrawer : public LiveActor {
public:
	SpinDriverPathDrawer(SpinDriverShootPath *);

	virtual ~SpinDriverPathDrawer();
	virtual void init(const JMapInfoIter &);
	virtual void draw() const;

	void calcPositionCount(f32, f32) const;
	void initPositionList(f32, f32);
	void initClipping();
	void initPathEnd();
	void calcDrawCode() const;
	void calcDrawBaseCode() const;
	void setCoord(f32);
	void setColorNormal();
	void setColorPink();
	void setMaskLength(f32);
	void setFadeScale(f32);
	void sendPoint(const TVec3f &, f32, f32) const;

	s32 _90;
	s32 _94;
	s32 _98;
	s32 _9C;
	s32 _A0;
	s32 _A4;
	s32 _A8;
	s32 _AC;
	f32 _B0;
	f32 _B4;
	s32 mColor;
	f32 _BC;
	f32 _C0;
	f32 _C4;
};
