#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/LiveActor/LiveActor.h"

class ActorCameraInfo;
class SledRopePoint;
class SwingRopePoint;

class SwingRope : public LiveActor {
public:
	SwingRope(const char *pName);

	virtual void init(const JMapInfoIter &rIter);
	virtual void draw() const;
	virtual void updateHitSensor(HitSensor *pSensor);
	virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
	virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

	void exeStop();
	void exeFree();
	void exeBindSlideDownStart();
	void exeBindSlideDown();
	void exeBindStretch();
	void initPoints();
	f32 calcPointNo(f32) const;
	f32 calcFriction(s32) const;
	void addPointGravity();
	void restrictPointToTail(s32, const TVec3f *, f32);
	void restrictPointToHead(s32, const TVec3f &, f32);
	bool isAllPointsStop() const;
	bool isStretched() const;
	bool tryJump();
	void updateHangPoint();
	void updateRideMtx();
	void updateFootPos();
	void updateStretch();
	void updateLoose();
	void updateLooseUpperPoints();
	void updateSlideDown();
	void updateStretchHangUpperPoints();
	void updateHangLowerPoints();
	void updateHangLowerPointsPos(s32);
	void drawStop() const;
	void drawFree() const;
	void drawBind() const;

	TVec3f _90;
	f32 mClippingRadius; // _9C
	u8 _A0;
	s32 _A4;
	s32 _A8;
	s32 _AC;
	SwingRopePoint** _B0;
	LiveActor* _B4;
	Mtx mRideMtx; // _B8
	f32 _E8;
	f32 _EC;
	f32 _F0;
	SledRopePoint* _F4;
	ActorCameraInfo* mActorCamera; // _F8
	f32 _FC;
	f32 _100;
	f32 _104;
	TVec3f _108;
	TVec3f mShadowDropPos; // _114
	f32 _120;
	s32 _124;
};

class SwingRopeGroup : public NameObj {
public:
	SwingRopeGroup(const char *pName);

	virtual ~SwingRopeGroup();
	virtual void initDraw() const;

	u32* _14;
};

namespace NrvSwingRope {
	NERVE(SwingRopeNrvStop);
	NERVE(SwingRopeNrvFree);
	NERVE(SwingRopeNrvFreeInvalid);
	NERVE(SwingRopeNrvSlideDownStart);
	NERVE(SwingRopeNrvSlideDown);
	NERVE(SwingRopeNrvBindStretch);
	NERVE(SwingRopeNrvBindLoose);
};
