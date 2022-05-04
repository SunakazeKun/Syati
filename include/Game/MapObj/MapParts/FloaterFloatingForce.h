#pragma once

#include "revolution.h"
#include "Game/MapObj/MapParts/MapPartsFunction.h"

class FloaterFloatingForce : public MapPartsFunction {
public:
	FloaterFloatingForce(LiveActor *pHost, const char *pName);

	virtual ~FloaterFloatingForce();
	virtual void init(const JMapInfoIter &rIter);
	virtual void start();
	virtual void updateHostTrans(TVec3f *pHostTrans) const;
	virtual void updateHostVelocity(TVec3f *pHostVelocity) const;
	virtual TVec3f* getCurrentVelocity() const;

	s32 _28;
	TVec3f _2C;
	TVec3f _38;
	f32 _44;
};
