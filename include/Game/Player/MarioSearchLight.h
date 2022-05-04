#pragma once

#include "revolution.h"
#include "Game/LiveActor/PartsModel.h"

class MarioSearchLight : public PartsModel {
public:
	MarioSearchLight(LiveActor *);
	
	virtual ~MarioSearchLight();
	virtual void init(const JMapInfoIter &);
	virtual void initAfterPlacement();
	virtual void appear();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void updateHitSensor(HitSensor *);
	virtual void attackSensor(HitSensor *, HitSensor *);

	// more class functions;

	s16 _A0;
	s32 _A4;
	u8 _A8;
	f32 _AC;
	f32 _B0;
	f32 _B4;
	u8 _B8;
	f32 _BC;
	f32 _C0;
	s32 _C4;
};
