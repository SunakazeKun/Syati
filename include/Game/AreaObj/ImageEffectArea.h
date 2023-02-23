#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

#define IMAGE_EFFECT_BLOOM 0
#define IMAGE_EFFECT_SCREEN_BLUR 1
#define IMAGE_EFFECT_DOF 2
#define IMAGE_EFFECT_POST_FOG 3
#define IMAGE_EFFECT_POST_OUTLINE 4

class ImageEffectArea : public AreaObj {
public:
	ImageEffectArea(int screenType, const char *pName);

	virtual ~ImageEffectArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isSyncWithPlayer() const;

	s32 mEffectType; // _48
};

class ImageEffectAreaMgr : public AreaObjMgr {
public:
	ImageEffectAreaMgr(s32 size, const char *pName);

	virtual ~ImageEffectAreaMgr();
};
