#pragma once

#include "revolution.h"

/* FINISHED */

namespace MR {
	class BothDirPtrList;	

	class BothDirPtrLink {
		BothDirPtrLink(void *pData);
		~BothDirPtrLink();

		void* mData;               // _0
		BothDirPtrList* mList;     // _4
		BothDirPtrLink* mPrevious; // _8
		BothDirPtrLink* mNext;     // _C
	};

	class BothDirPtrList {
		BothDirPtrList(bool doInit);
		~BothDirPtrList();

		void initiate();
		void setFirst(BothDirPtrLink *pLink);
		void append(BothDirPtrLink *pLink);
		void remove(BothDirPtrLink *pLink);
		
		BothDirPtrLink* mFirst; // _0
		BothDirPtrLink* mLast;  // _4
		s32 mNumElements;       // _8
	};
};
