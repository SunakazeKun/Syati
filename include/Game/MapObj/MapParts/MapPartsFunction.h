#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class MapPartsFunction : public NameObj {
public:
	MapPartsFunction(LiveActor *, const char *);

	virtual ~MapPartsFunction();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
	virtual bool isWorking() const;
	virtual void start();
	virtual void end();
	virtual bool receiveMsg(u32);
	virtual void control();
	
	void initNerve(const Nerve *);
	void setNerve(const Nerve *);
	s32 getStep() const;
	bool isStep(s32) const;
	bool isNerve(const Nerve *) const;
	bool sendMsgToHost(u32);
	f32 getSpeed() const;

	Spine* mSpine;    // _14
	LiveActor* mHost; // _18
	bool mEnabled;    // _1C
	f32 mSpeed;       // _20
	s32 _24;
};
