#pragma once

#include "revolution.h"

/* FINISHED */

class TriggerChecker {
public:
	TriggerChecker();

	void update(bool);
	void setInput(bool);
	bool getLevel() const;
	bool getOnTrigger() const;
	bool getOffTrigger() const;

	bool mState;
	bool mLevel;
};
