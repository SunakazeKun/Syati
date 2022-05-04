#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/MapObj/SpinDriverPathDrawer.h"

#define SUPER_SPIN_DRIVER_YELLOW 0
#define SUPER_SPIN_DRIVER_GREEN 1
#define SUPER_SPIN_DRIVER_PINK 2

class SuperSpinDriver : public LiveActor {
public:
	SuperSpinDriver(const char *, s32);

	void initColor();

	s32 _90;
	s32 _94;
	s32 _98;
	SpinDriverPathDrawer* mSpinDriverPathDrawer; // _9C
	s32 _A0;
	s32 _A4;
	Mtx _A8;
	TQuat4f _D8;
	TQuat4f _E8;
	TVec3f _F8;
	TVec3f _104;
	TVec3f _110;
	TVec3f _11C;
	TVec3f _128;
	TVec3f _134;
	TVec3f _140;
	TVec3f _14C;
	TVec3f _158;
	s32 _164;
	f32 _168;
	f32 _16C;
	f32 _170;
	f32 _174;
	f32 _178;
	f32 _17C;
	f32 _180;
	s32 _184;
	s32 _188;
	s32 _18C;
	s32 _190;
	s32 _194;
	f32 _198;
	u8 _19C;
	s32 _1A0;
	s32 mColor;
	s32 _1A8;
	u8 _1AC;
	s32 _1B0;
	u8 _1B4;
	u8 _1B5;
	u8 _1B6;
	u8 _1B7;
};
