#pragma once

#include "Game/NPC/NPCActor.h"
#include "Game/Util/Color8.h"

class Tico : public NPCActor {
public:
	Tico(const char *pName);

	virtual ~Tico();
	virtual void init(const JMapInfoIter &rIter);
	virtual void initAfterPlacement();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
	virtual bool isReactionNerve() const;

	void initMessage(const char *);

	u32 _164;
	f32 _168;
	f32 _16C;
	f32 _170;
	f32 _174;
	s32 _178;
	s32 _17C;
	s32 _180;
	s32 _184;
	Color8 _188;
	s32 _18C;
	u8 _190[12];
	u8 _19C;
	u8 _19D;
	u8 _19E;
	s32 _1A0;
	s32 _1A4;
	s32 _1A8;
};
