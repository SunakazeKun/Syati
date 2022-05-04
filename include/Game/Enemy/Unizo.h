#pragma once

#include "Game/LiveActor/ModelObj.h"

#define UNIZO 0
#define UNIZO_LAND 1
#define UNIZO_SHOAL 2

class Unizo : public LiveActor {
public:
	Unizo(const char *pActor);

	virtual ~Unizo();
	virtual void init(const JMapInfoIter &rIter);
	virtual void initAfterPlacement();
	virtual void appear();
	virtual void makeActorAppeared();
	virtual void kill();
	virtual void makeActorDead();
	virtual TMtx34f* getBaseMtx() const;
	virtual void startClipped();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
	virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
	virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

	void initType(const JMapInfoIter &rIter);
	void exeWait();
	void exeJump();
	void exeChase();
	void exeAttack();
	void exeCollideEnemy();
	void exeBreak();
	void exeFireDown();
	void exeJumpDown();
	void updateRotate();
	void updateVelocity();
	void udpateInfluence();
	void udpateBlink();
	void updateSurfaceEffect();
	void deleteEffect();
	void doJump();
	void doAttack(HitSensor *pReceiver);
	void doJumpDown();
	void doFireDown(u32 msg, const TVec3f & rDir);
	void doBreak(u32 msg, HitSensor *pSender);
	void doSpin();
	bool isBreakGround();
	bool isBreakNow() const;
	bool tryPointBind();
	bool isEnablePointBind() const;
	void appearBreakModel();
	void startWallHitSound();
	void startNeedleSound();

	s32 mType; // 90
	TQuat4f _94;
	Mtx _A4;
	Mtx _D4;
	u32 _104;
	u32 _108;
	u32 _10C;
	u32 _110;
	f32 _114;
	ModelObj* mBreakModel; // 118
	u32 _11C;
	u32 _120;
	u32 _124;
	u32 _128;
	f32 _12C;
	f32 _130;
	u32 _134;
};

namespace NrvUnizo {
	NERVE(UnizoNrvWait);
	NERVE(UnizoNrvJump);
	NERVE(UnizoNrvChase);
	NERVE(UnizoNrvAttack);
	NERVE(UnizoNrvCollidePlayer);
	NERVE(UnizoNrvCollideEnemy);
	NERVE(UnizoNrvBreak);
	NERVE(UnizoNrvFireDown);
	NERVE(UnizoNrvJumpDown);
	NERVE(UnizoNrvPointing);
};
