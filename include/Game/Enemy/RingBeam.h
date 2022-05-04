#pragma once

#include "revolution.h"
#include "Game/LiveActor/ModelObj.h"
#include "Game/LiveActor/ActorStateParamScale.h"

class RingBeamShadowDrawer;

class RingBeam : public LiveActor {
public:
	RingBeam(const char *pName, LiveActor *pHost, bool followGravity, bool useShadow, bool, bool, const char *pModelName);

	virtual ~RingBeam();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual void appear();
	virtual void kill();
	virtual void makeActorDead();
	virtual void control();
	virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

	void initWithParamScale(const JMapInfoIter &rIter, const ActorStateParamScale *pParamScale);

	void setSpeed(f32 speed);
	void setLife(s32 life);
	void setColor(f32 color);

	LiveActor* mHost; // _90
	ModelObj* mBloomModel; // _94
	const char* mModelName; // _98
	f32 mSpeed; // _9C
	s32 mLife; // _A0
	bool mFollowGravity; // _A4
	bool mUseShadow; // _A5
	bool _A6;
	bool _A7;
	RingBeamShadowDrawer* mShadowDrawer; // _A8
	ModelObj* mShadowModel; // _AC
	ActorStateParamScale* mParamScale; // _B0
	TVec3f _B4;
	TVec3f _C0;
	TVec3f _CC;
	TVec3f _D8;
	f32 mColor; // _E4
	f32 _E8;
	f32 _EC;
};

namespace NrvRingBeam {
	NERVE(RingBeamNrvSpread);
};
