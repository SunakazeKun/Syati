#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

class BgmVolumeFadeArea : public AreaObj {
public:
	BgmVolumeFadeArea(const char *pName);

	virtual ~BgmVolumeFadeArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual const char* getManagerName() const;

	s32 getFadeTime() const;
	f32 getVolume() const;

	bool _48;
	bool _49;
};
