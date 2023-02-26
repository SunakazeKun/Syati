#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class CancelBeeMorphArea : public AreaObj {
public:
	CancelBeeMorphArea(const char *pName);

	virtual ~CancelBeeMorphArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
};
