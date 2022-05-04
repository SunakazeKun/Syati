#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

#define MORPH_HOPPER 1
#define MORPH_BEE 2
#define MORPH_TERESA 3
#define MORPH_ICE 4
#define MORPH_FIRE 5
#define MORPH_FOO 6
#define MORPH_CLOUD 7
#define MORPH_ROCK 8

class MorphItemObjNeo : public LiveActor {
public:
	MorphItemObjNeo(const char *);

	virtual ~MorphItemObjNeo();
	virtual void init(JMapInfoIter const &);
	virtual void initAfterPlacement();
	virtual void appear();
	virtual void makeActorAppeared();
	virtual void kill();
	virtual void makeActorDead();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
	virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);
	virtual bool isDemo() const;
	virtual u32 getPowerUp();
	virtual void emitAppearEffects();
	virtual void appearTransformation();
	virtual void killTransformation();

	// class functions?

	u16 _90;
	u16 _92;
	u8 _94;
	u8 _95;
	u8 _96;
	u8 _97;
	u8 _98;
	u8 _99;
	u8 _9A;
	u8 _9B;
	u8 _9C;
	u8 _9D;
	f32 _A0;
	f32 _A4;
	f32 _A8;
	f32 _AC;
	TVec3f _B0;
	u32 _BC;
	u32 _C0;
	u32 _C4;
	u32 _C8;
	f32 _CC;
	f32 _D0;
	f32 _D4;
	f32 _D8;
	f32 _DC;
	f32 _E0;
};
