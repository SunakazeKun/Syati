#pragma once

#include "Game/NameObj/NameObj.h"

class MyFirstActor : public NameObj {
public:
	// actor constructor
	MyFirstActor(const char *pName) : NameObj(pName) {
		
	}
	
	// actor initialization, reads from BCSV entry
	virtual void init(const JMapInfoIter &rIter) {
		OSReport("Init!\n");
	}
};
