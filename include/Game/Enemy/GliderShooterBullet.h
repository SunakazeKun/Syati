#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/LiveActorGroup.h"
#include "Game/Enemy/WalkerStateBindStarPointer.h"

class GliderShooterBullet : public LiveActor {
public:
	GliderShooterBullet();

	virtual ~GliderShooterBullet();
	virtual void init(const JMapInfoIter &rIter);
	virtual void appear();
	virtual void kill();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
	virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

	void exeFly();
	void exeFreeze();

	TVec3f _90;
	TVec3f _9C;
	AnimScaleController* mAnimScaleCtrl; // _A8
	WalkerStateBindStarPointer* mBindStarPointer; // _AC
};

class GliderShooterBulletHolder : public LiveActorGroup {
public:
	GliderShooterBulletHolder();

	virtual ~GliderShooterBulletHolder();
	virtual void init(const JMapInfoIter &rIter);
};

namespace NrvGliderShooterBullet {
	NERVE(GliderShooterBulletNrvFly);
	NERVE(GliderShooterBulletNrvFreeze);
};
