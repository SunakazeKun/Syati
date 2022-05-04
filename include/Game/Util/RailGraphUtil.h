#pragma once

#include "revolution.h"
#include "JSystem.h"

class RailGraph;
class RailGraphIter;
class RailGraphNodeSelecter;

namespace MR {
	RailGraphIter* createRailGraphFromJMap(const JMapInfoIter &);
	RailGraphIter* createRailGraphIter(const RailGraph *);

	void moveNextNode(RailGraphIter *);
	void moveNodeNearPosition(RailGraphIter *, const TVec3f &, f32, RailGraphNodeSelecter *);
	void selectReverseEdge(RailGraphIter *);

	bool isSelectedEdge(const RailGraphIter *);
	bool isWatchedPrevEdge(const RailGraphIter *);

	TVec3f* getCurrentNodePosition(const RailGraphIter *);
	TVec3f* getNextNodePosition(const RailGraphIter *);
	void calcWatchEdgeVector(const RailGraphIter *, TVec3f *);
	void calcWatchEdgeDirection(const RailGraphIter *, TVec3f *);

	s32 getNearNodeIndex(const RailGraph *, const TVec3f &, f32, RailGraphNodeSelecter *);

	s32 getSelectEdgeArg0(const RailGraphIter *);
	s32 getSelectEdgeArg1(const RailGraphIter *);
	s32 getSelectEdgeArg2(const RailGraphIter *);
	s32 getSelectEdgeArg3(const RailGraphIter *);
	s32 getWatchEdgeArg7(const RailGraphIter *);
};
