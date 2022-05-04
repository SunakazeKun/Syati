#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Util/HashUtil.h"

struct MatrixValueTable {
	const char* mKey; // _0
	f32 mValue; // _4
};

class MatrixValueGetter : public NameObj {
public:
	MatrixValueGetter(const char *, MatrixValueTable *);

	virtual ~MatrixValueGetter();

	bool getValue(const char *, f32 *);

	MatrixValueTable* mTable; // _14
	HashSortTable* mHashTable; // _18
};
