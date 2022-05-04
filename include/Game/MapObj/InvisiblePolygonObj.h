#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class InvisiblePolygonObj : public LiveActor {
public:
	InvisiblePolygonObj(const char *);

	virtual ~InvisiblePolygonObj();
	virtual void init(const JMapInfoIter &);
	virtual TMtx34f* getBaseMtx() const;

	void initBaseMtx();
	void initCollision(const JMapInfoIter &);

	TMtx34f mMatrix; // 90
};
