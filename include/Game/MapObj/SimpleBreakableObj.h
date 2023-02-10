#pragma once

#include "revolution.h"
#include "Game/MapObj/MapObjActor.h"
#include "Game/MapObj/MapObjActorInitInfo.h"
#include "Game/MapObj/BenefitItemObj.h"

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

	//Unknown nullsub at 0x802FE0B0 USA

	void setStateBreak();
	void startBreak();
	void endBreak();
	bool isStateBreaking();
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
