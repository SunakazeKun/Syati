#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class FireMarioBall : public LiveActor {
public:
	FireMarioBall(const char *);

	virtual ~FireMarioBall();
	virtual void init(const JMapInfoIter &);
	virtual void appear();
	virtual void kill();
	virtual void attackSensor(HitSensor *, HitSensor *);

	void appearAndThrow(const TVec3f &, const TVec3f &);
	void attackFire(HitSensor *);
	void initSensor();

	bool isBindedAny() const;
	bool tryToKill();

	void exeThrow();

	s32 _90; // unused
	s16 _94;
};
