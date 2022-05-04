#pragma once

#include "revolution.h"
#include "Game/AreaObj/ImageEffectArea.h"

class BloomArea : public ImageEffectArea {
public:
	BloomArea(const char *pName);

	virtual ~BloomArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual const char* getManagerName() const;

	s8 _4C;
	s8 _4D;
	s32 _50;
	s32 _54;
};
