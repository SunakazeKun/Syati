#pragma once

#include "revolution.h"
#include "Game/MapObj/MapObjActor.h"
#include "Game/MapObj/MapObjActorInitInfo.h"

class RailMoveObj : public MapObjActor {
public:
	RailMoveObj(const char *);

	virtual ~RailMoveObj();

	virtual void startClipped();
	virtual void endClipped();

	virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);

	virtual void initCaseUseSwitchB(const MapObjActorInitInfo &);
	virtual void initCaseNoUseSwitchB(const MapObjActorInitInfo &);

	virtual void initDemoAction();
	virtual void setupInitInfo(const JMapInfoIter &, MapObjActorInitInfo &);
	virtual void tryStartMove();
	virtual void startMoveInner();
	virtual void move();
	virtual void doAtEndPoint();
	virtual void endMove();
	virtual void getSoundCalcPos();

	void exeDemo();
	void exeWait();
	void exeMove();

	TVec3f _D0;
	bool mIsRailMoverWorking;
};

namespace NrvRailMoveObj {
	class NrvWait : public Nerve
	{
	public:
		virtual void execute(Spine *) const;

		static NrvWait sInstance;
	};

	class NrvWaitForPlayerOn : public Nerve
	{
	public:
		virtual void execute(Spine *) const;

		static NrvWaitForPlayerOn sInstance;
	};

	class NrvMove : public Nerve
	{
	public:
		virtual void execute(Spine *) const;

		static NrvMove sInstance;
	};

	class NrvDone : public Nerve
	{
	public:
		virtual void execute(Spine *) const;

		static NrvDone sInstance;
	};

	class NrvDemoPlay : public Nerve
	{
	public:
		virtual void execute(Spine *) const;

		static NrvDemoPlay sInstance;
	};
}