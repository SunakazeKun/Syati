#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

#define MARIO_ALL_MODEL_MARIO 0
#define MARIO_ALL_MODEL_BONE 1
#define MARIO_ALL_MODEL_BEE 2
#define MARIO_ALL_MODEL_ICE 3
#define MARIO_ALL_MODEL_INVINCIBLE 4
#define MARIO_ALL_MODEL_HOPPER 5
#define MARIO_ALL_MODEL_HORROR 6
#define MARIO_ALL_MODEL_CLOUD 7
#define MARIO_ALL_MODEL_ROCK 8

class MarioActor;

class MarioAllModel {
public:
	MarioAllModel(MarioActor *);

	void registerModel(s32, LiveActor *, bool, bool);
	// more methods here
	J3DModel* getJ3DModel() const;
	// even more methods here

	MarioActor* mMarioActor; // _0
	s32 mDisplayedModel; // _4
	s32 mNextModel; // _8
	J3DModel* mModels[9]; // _C
	u32* _30[9];
};
