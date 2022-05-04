#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class MessageSensorHolder : public LiveActor {
public:
	MessageSensorHolder(const char *pName);

	virtual ~MessageSensorHolder();
	virtual void init(const JMapInfoIter &rIter);
};
