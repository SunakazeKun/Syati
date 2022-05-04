#pragma once

#include "revolution.h"
#include "Game/MapObj/MapParts/FloaterFloatingForce.h"

class FloaterFloatingForceTypeNormal : public FloaterFloatingForce {
public:
	FloaterFloatingForceTypeNormal(LiveActor *pHost, const char *pName);

	virtual ~FloaterFloatingForceTypeNormal();
	virtual void init(const JMapInfoIter &rIter);
	virtual void start();
	virtual void updateHostTrans(TVec3f *pHostTrans) const;
	virtual TVec3f* getCurrentVelocity() const;

	f32 _48;
	f32 _4C;
	f32 _50;
	f32 _54;
	TVec3f mCurrentVelocity; // _58
	s32 _64; // unknown and unused
};

namespace NrvFloaterFloatingForceTypeNormal {
	NERVE(HostTypeWait);
	NERVE(HostTypeMoveFirst);
	NERVE(HostTypeMoveOffPlayer);
	NERVE(HostTypeMoveOnPlayer);
};
