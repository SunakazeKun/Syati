#pragma once

#include "revolution.h"

class HashSortTable {
public:
	HashSortTable(u32);

	bool add(const char *, u32, bool);
	bool add(u32, u32);
	bool addOrSkip(u32, u32);
	void sort();
	bool search(u32, u32 *);
	bool search(const char *, u32 *);
	bool search(const char *, const char *, u32 *);
	void swap(const char *, const char *);

	u8 _0;
	u32* _4;
	u32* _8;
	u32* _C;
	u32* _10;
	s32 mItems; // _14
	s32 mMaxItems; // _18
};

namespace MR {
	u32 getHashCode(const char *);
	u32 getHashCodeLower(const char *);
};
