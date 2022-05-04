#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

class BgmChangeArea : public AreaObj {
public:
	BgmChangeArea(const char *pName);

	virtual ~BgmChangeArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual const char* getManagerName() const;

	s32 getFadeTime() const;

	bool _48;
};
