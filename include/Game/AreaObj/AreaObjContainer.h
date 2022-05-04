#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"
#include "Game/Util/Array.h"

struct ManagerEntry {
    const char* pManagerName; // _0
	s32 mMaxAreas; // _4
    NameObj* (*mCreationFunc)(const char *); // _8
};

class AreaObjContainer : public NameObj {
	AreaObjContainer(const char *pName);

	virtual ~AreaObjContainer(); 
	virtual void init(const JMapInfoIter &rIter);
	
	// there is a jump to getManager before this
	AreaObjMgr* getManager(const char *pName) const;
	AreaObj* getAreaObj(const char *pName) const;
	bool isExistAreaObj(const char *pName) const;

    template<typename T>
    NameObj* createManager(s32 size, const char *pName);

	static ManagerEntry cCreateTable[95];

	MR::AssignableArray<AreaObjMgr*> mManagers; // _14
	s32 mNumManagers; // _1C
};

namespace MR {
	AreaObjContainer* getAreaObjContainer();
};
