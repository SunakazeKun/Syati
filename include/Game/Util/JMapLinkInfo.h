#pragma once

#include "revolution.h"

/* FINISHED */

class JMapInfoIter;

class JMapLinkInfo {
public:
	JMapLinkInfo();
	JMapLinkInfo(const JMapInfoIter &rIter, bool isLinked);

	bool isValid() const;
	void invalidate();
	void setLinkInfo(const JMapInfoIter &rIter);
	void setLinkedInfo(const JMapInfoIter &rIter);

	s16 mLinkId;  // _0
	s16 mZoneId;  // _2
	s16 mContext; // _4
};
