#pragma once

#include "revolution.h"
#include "Game/Gravity/GravityCreator.h"
#include "Game/LiveActor/LiveActor.h"

/* FINISHED */

class GlobalGravityObj : public LiveActor {
public:
	GlobalGravityObj(const char *pName);

	virtual ~GlobalGravityObj();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual void makeActorAppeared();
	virtual void makeActorDead();

	void updateSwitch();
	PlanetGravity* getGravity();

	GravityCreator* mGravityCreator; // _90
};

namespace MR {
	NameObj* createGlobalBarrelGravityObj(const char *pName);
	NameObj* createGlobalCubeGravityObj(const char *pName);
	NameObj* createGlobalConeGravityObj(const char *pName);
	NameObj* createGlobalDiskGravityObj(const char *pName);
	NameObj* createGlobalDiskTorusGravityObj(const char *pName);
	NameObj* createGlobalPlaneGravityObj(const char *pName);
	NameObj* createGlobalPlaneInBoxGravityObj(const char *pName);
	NameObj* createGlobalPlaneInCylinderGravityObj(const char *pName);
	NameObj* createGlobalPointGravityObj(const char *pName);
	NameObj* createGlobalSegmentGravityObj(const char *pName);
	NameObj* createGlobalWireGravityObj(const char *pName);
	NameObj* createZeroGravitySphereObj(const char *pName);
	NameObj* createZeroGravityBoxObj(const char *pName);
	NameObj* createZeroGravityCylinderObj(const char *pName);
};
