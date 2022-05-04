#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class DiceBase : public LiveActor {
public:
	DiceBase(const char *);

	virtual ~DiceBase();
	virtual void init(const JMapInfoIter &);
	virtual void appear();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor *, HitSensor *);
	virtual bool receiveMsgPush(HitSensor *, HitSensor *);
	virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);

	virtual const char* getModelName() const = 0;
	virtual void initItems() = 0;
	virtual void setAnimFrame() = 0;
	virtual void setResultFrame(u32) = 0;
	virtual bool makeResult(u32) = 0;
	virtual bool isGoodResult(u32) const = 0;

	// Todo: More class functions
	void exeSpin();
	void exeThrow();
	void exeLand();

	bool tryThrow();

	s32 _90;
	TVec3f _94;
	TVec3f _A0;
	f32 _AC;
	f32 _B0;
	s32 _B4;
	s32 _B8;
	s32 _BC;
	s32 _C0;
	Mtx _C4;
	s32 _F4;
	s32 _F8;
	TVec3f _FC;
	bool _108;
	bool _109;
};

class MultipleChoiceDice : public DiceBase {
public:
	inline MultipleChoiceDice(const char* pName) : DiceBase(pName) {}

	virtual const char* getModelName() const;
	virtual void initItems();
	virtual void setAnimFrame();
	virtual void setResultFrame(u32);
	virtual bool makeResult(u32);
	virtual bool isGoodResult(u32) const;
};
