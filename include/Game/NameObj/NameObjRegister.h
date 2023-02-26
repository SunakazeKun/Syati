#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObjHolder.h"

/* FINISHED */

class NameObjRegister {
public:
	NameObjRegister();

	void setCurrentHolder(NameObjHolder *pHolder);
	void add(NameObj *pActor);

	NameObjHolder* mHolder; // _0
};
