#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/NameObj/NameObjFactory.h"

/* FINISHED */

struct ProductMapEntry {
	const char* mModelName;
	const char* mClassName;
};

class ProductMapCreator : public NameObj {
public:
	ProductMapCreator(const char *pName);

	ProductMapEntry* getProductMapEntry(const char *pModelName);
	CreateActorFunc* getProductMapCreator(const char *pClassName);

	ProductMapEntry** mEntries; // _14
	s32 mCount;                 // _18

	static CreateActorEntry sCreateFuncTable[47];
};

namespace MR {
	CreateActorFunc* getProductMapCreator(const char *pModelName);
	bool hasProductMapCreator(const char *pModelName);
};
