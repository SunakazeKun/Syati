#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class JetTurtle : public LiveActor {
public:
	JetTurtle(const char *);

	virtual ~JetTurtle();
	virtual void init(const JMapInfoIter &);
	virtual void initAfterPlacement();
	virtual void appear();
	virtual void control();
	virtual void attackSensor(HitSensor *, HitSensor *);
	virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
	virtual bool receiveMsgEnemyAttack(u32, HitSensor *, HitSensor *);
	virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);
	virtual void exeThrowing();
	virtual void resetPosition();
	virtual void reset(u32);

	void init2(const JMapInfoIter &);
	void appearAndTryTaken();
	// three unknown functions between this
	bool isWait() const;
	bool isRestart() const;
	void becomeSlowType();
	void becomeFastType();
	void exeWait();
	void exeThrowWait();
	void exeTakenReserve();
	void exeTakenStart();
	void exeRestart();
	void exeDrop();
	void resetPositionAndVanish();
	void bound();
	void boundDrop();
	// one unknown function here

	f32 _90;
	s16 _94;
	s16 _96;
	s32 _98;
	s32 _9C;
	TVec3f _A0;
	TVec3f _AC;
	TVec3f _B8;
	TVec3f _C4;
	TVec3f _D0;
	s16 _DC;
	s32 _E0; // unused
	u8 _E4;
	u8 _E5;
	u8 _E6;
	u8 _E7;
	u32* _E8;
	u8 _EC;
};

class GoldenTurtle : public JetTurtle {
public:
	inline GoldenTurtle(const char * pName) : JetTurtle(pName) {}

	virtual ~GoldenTurtle();
	virtual void init(const JMapInfoIter &);
	virtual void exeThrowing();
	virtual void resetPosition();
	virtual void reset(u32);
};
