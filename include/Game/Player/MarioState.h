#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/LiveActor/HitSensor.h"
#include "Game/Player/MarioModule.h"

#define MARIO_DEFAULT 0x00
#define MARIO_WALL 0x01
#define MARIO_DAMAGE 0x02
#define MARIO_FAINT 0x03
#define MARIO_BLOWN 0x04
#define MARIO_HANG 0x05
#define MARIO_SWIM 0x06
#define MARIO_SLIDER 0x07
#define MARIO_FIRE_DAMAGE 0x08
#define MARIO_FIRE_DANCE 0x09
#define MARIO_FIRE_RUN 0x0A
#define MARIO_PARALYZE 0x0B
#define MARIO_ABYSS_DAMAGE 0x0C
#define MARIO_FREEZE 0x0D
#define MARIO_STUN 0x0E
#define MARIO_CRUSH 0x0F
#define MARIO_STEP 0x10
#define MARIO_MAGIC 0x11
#define MARIO_FPVIEW 0x12
#define MARIO_RECOVERY 0x13
#define MARIO_FLIP 0x14
#define MARIO_SIDE_STEP 0x15
#define MARIO_STICK 0x16
#define MARIO_RABBIT 0x17
#define MARIO_FOO 0x18
#define MARIO_FLOW 0x19
#define MARIO_SUKEKIYO 0x1A
#define MARIO_BURY 0x1B
#define MARIO_WAIT 0x1C
#define MARIO_CLIMB 0x1D
#define MARIO_BUMP 0x1E
#define MARIO_SKATE 0x1F
#define MARIO_FRONT_STEP 0x20
#define MARIO_TERESA 0x21
#define MARIO_TALK 0x22
#define MARIO_DARK_DAMAGE 0x23

#define MARIO_YOSHI_PULL 0x26
#define MARIO_YOSHI_BALLOON 0x27
#define MARIO_YOSHI_SHOT 0x28
#define MARIO_YOSHI_DASH 0x29

class MarioState : public MarioModule
{
public:
	MarioState(MarioActor *, u32);

	virtual void init();
	virtual bool proc(u32);
	virtual bool start();
	virtual bool close();
	virtual bool update();
	virtual bool notice();
	virtual bool keep();
	virtual bool postureCtrl(MtxPtr);
	virtual void hitWall(const TVec3f &, HitSensor *);
	virtual void hitPoly(u8, const TVec3f &, HitSensor *);
	virtual bool passRing(const HitSensor *);
	virtual f32 getBlurOffset() const;
	virtual void draw3D() const;

	s32 _8;
	u32 mIdentifier; // _C
	bool _10;
};
