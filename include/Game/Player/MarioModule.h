#pragma once

#include "revolution.h"
#include "JSystem.h"

class MarioActor;

class MarioModule {
public:
	virtual f32 getStickY() const;
	virtual void addVelocity(const TVec3f &) const;
	virtual void addVelocity(const TVec3f &, f32);

	MarioActor* mMarioActor; // _4
};
