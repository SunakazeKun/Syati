#pragma once

#include "Game/LiveActor/LiveActor.h"

class AnimationRandomPlayer;
class JointRumbler;
class YoshiLockOnTarget;
class BenefitItemOneUp;

class Kanina : public LiveActor {
public:
	enum KaninaType {
		KaninaType_Blue = 0,
		KaninaType_Red = 1
	};

	Kanina(const char *pName);

	virtual ~Kanina();
	virtual void init(const JMapInfoIter &rIter);
	virtual void initAfterPlacement();
	virtual void kill();
	virtual void makeActorDead();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
	virtual bool receiveMsgPush(HitSensor *pSender, HitSensor *pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
	virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

	// Various functions...

	KaninaType mKaninaType; // _90
	u32* _94;
	JointRumbler* mJointRumbler; // _98
	BenefitItemOneUp* mOneUp; // _9C
	AnimationRandomPlayer* mAnimRandomPlayer; // _A0
	YoshiLockOnTarget* mYoshiLockOnTarget; // _A4
	TVec3f mOriginalPosition; // _A8
	TQuat4f _B4;
	s32 _C0; // ???
	s32 _C4;
	s32 _C8;
	f32 _CC;
	f32 _D0;
	f32 _D4;
	f32 _D8;
	f32 _DC;
	f32 _E0;
	f32 _E4;
	s32 _E8;
	s32 _EC;
	s32 _F0;
	bool mObjArg0; // _F4
};
