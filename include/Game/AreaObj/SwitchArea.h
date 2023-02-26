#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class SwitchArea : public AreaObj {
public:
	SwitchArea(const char *pName);

	virtual ~SwitchArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual const char* getManagerName() const;

	void onSwitchA();
	bool isUpdate() const;
	bool checkPlayerDrillRush() const;

	s32 mRiddleSound;   // _48
	bool mRiddlePlayed; // _4C
};
