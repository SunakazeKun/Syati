#pragma once

#include "Game/NPC/NPCActor.h"

class TakeOutStar;
class TurnJointCtrl;

class Rosetta : public NPCActor {
public:
	Rosetta(const char *pName);

	virtual ~Rosetta();
	virtual void init(const JMapInfoIter &rIter);
	virtual void calcAndSetBaseMtx();
	virtual void control();

	bool canUpdateStarePos() const;

	TurnJointCtrl* mTurnJointCtrl; // _164
	bool mHasPowerStar;            // _168
	TakeOutStar* mTakeOutStar;     // _16C
};

namespace NrvRosetta {
	NERVE(RosettaNrvWait);
};
