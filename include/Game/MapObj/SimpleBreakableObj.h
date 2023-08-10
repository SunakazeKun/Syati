#pragma once

#include "revolution.h"
#include "Game/MapObj/MapObjActor.h"
#include "Game/MapObj/MapObjActorInitInfo.h"
#include "Game/MapObj/BenefitItemObj.h"

#define BREAKABLE_OBJ_COND_SPIN_ATTACK 2
#define BREAKABLE_OBJ_COND_HIP_DROP_FLOOR 4
#define BREAKABLE_OBJ_COND_EXPLOSION_ATTACK 8
#define BREAKABLE_OBJ_COND_JET_TURTLE_ATTACK 16
#define BREAKABLE_OBJ_COND_FIRE_BALL_ATTACK 32
#define BREAKABLE_OBJ_COND_ENEMY_ATTACK 64
#define BREAKABLE_OBJ_COND_TAMAKORO_DASH_WALL 128
#define BREAKABLE_OBJ_COND_TAMAKORO_DASH_GROUND 256
#define BREAKABLE_OBJ_COND_DRILL_ATTACK 512
#define BREAKABLE_OBJ_COND_ROCK_ATTACK 1024

class ActorCameraInfo;

class SimpleBreakableObj : public MapObjActor {
public:
	SimpleBreakableObj(const char *);

	virtual ~SimpleBreakableObj();
	virtual void init(const JMapInfoIter &);
	virtual void control();
	virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
	virtual bool receiveMsgEnemyAttack(u32, HitSensor *, HitSensor *);
	virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);
	virtual void initCaseUseSwitchA(const MapObjActorInitInfo &);
	virtual void initCaseNoUseSwitchA(const MapObjActorInitInfo &);
	virtual void initCaseUseSwitchB(const MapObjActorInitInfo &);
	virtual void initCaseNoUseSwitchB(const MapObjActorInitInfo &);

	void setStateBreak();
	void startBreak();
	void controlBreak();
	void endBreak();
	bool isStateBreaking() const;
	void appearItem();
	void exeTryStartDemo();
	void exeDemo();

	ActorCameraInfo* mActorCameraInfo; //_D0
	u32 arg5; //_D4
	u32 _D8;
	u32 _DC;
	u16 _E0;
	u32 _E4;
	u32 _E8;
	BenefitItemObj* mOneUpKinokio; //_EC
	u8 _F0;
	u8 _F1;
	u8 _F2;
};

namespace NrvSimpleBreakableObj {
	NERVE(HostTypeWait);
	NERVE(HostTypeTryStartDemo);
	NERVE(HostTypeDemo);
};
