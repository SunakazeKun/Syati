#pragma once

#include "revolution.h"
#include "Game/Player/MarioActor.h"

class MarioHolder : public NameObj {
public:
	MarioHolder();

	virtual ~MarioHolder();

	void setMarioActor(MarioActor *);
	MarioActor* getMarioActor() const;

	MarioActor* mMarioActor; // _14
	bool mCreateBee; // _18
	bool mCreateHopper; // _19
	bool mCreateFire; // _1A
	bool mCreateIce; // _1B
	bool mCreateInvincible; // _1C
	bool mCreateTeresa; // _1D
	bool mCreateTornado; // _1E
	bool _1F;
	bool mCreateYoshi; // _20
	bool mCreateYoshiBalloon; // _21
	bool mCreateCloud; // _22
	bool mCreateRock; // _23
	bool mCreateHairAndHead; // _24
	bool mCreateFreezeIce; // _25
};

namespace MR {
	MarioHolder* getMarioHolder();
	void enablePlayerResourceBee();
	void enablePlayerResourceHopper();
	void enablePlayerResourceFire();
	void enablePlayerResourceIce();
	void enablePlayerResourceInvincible();
	void enablePlayerResourceTeresa();
	void enablePlayerResourceTornado();
	void enablePlayerResourceYoshi();
	void enablePlayerResourceYoshiBaloon();
	void enablePlayerResourceCloud();
	void enablePlayerResourceRock();
	void enablePlayerResourceHairAndHead();
	void enablePlayerResourceFreezeIce();
	bool isCreatePlayerResourceBee();
	bool isCreatePlayerResourceHopper();
	bool isCreatePlayerResourceFire();
	bool isCreatePlayerResourceIce();
	bool isCreatePlayerResourceInvincible();
	bool isCreatePlayerResourceTeresa();
	bool isCreatePlayerResourceTornado();
	bool isCreatePlayerResourceYoshi();
	bool isCreatePlayerResourceYoshiBaloon();
	bool isCreatePlayerResourceCloud();
	bool isCreatePlayerResourceRock();
	bool isCreatePlayerResourceHairAndHead();
	bool isCreatePlayerResourceFreezeIce();
	void enablePlayerResourceHopperComet();
	void enablePlayerResourceInvincibleComet();
	void enablePlayerResourceNoHat();
};
