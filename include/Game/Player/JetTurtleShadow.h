#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class JetTurtleShadow : public LiveActor {
public:
	JetTurtleShadow(const char *);

	virtual ~JetTurtleShadow();
	virtual void init(const JMapInfoIter &);

	void calcType0(MtxPtr);
	void drawType0() const;
};
