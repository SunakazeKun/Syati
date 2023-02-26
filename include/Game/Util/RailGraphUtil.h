#pragma once

#include "revolution.h"
#include "JSystem.h"

/* FINISHED */

class JMapInfoIter;
class RailGraph;
class RailGraphIter;
class RailGraphNodeSelecter;

namespace MR {
	RailGraphIter* createRailGraphFromJMap(const JMapInfoIter &rIter);
	RailGraphIter* createRailGraphIter(const RailGraph *pGraph);

	void moveNextNode(RailGraphIter *pGraphIter);
	void moveNodeNearPosition(RailGraphIter *pGraphIter, const TVec3f &rPosition, f32 distance, RailGraphNodeSelecter *pSelector);
	void selectReverseEdge(RailGraphIter *pGraphIter);

	bool isSelectedEdge(const RailGraphIter *pGraphIter);
	bool isWatchedPrevEdge(const RailGraphIter *pGraphIter);

	const TVec3f& getCurrentNodePosition(const RailGraphIter *pGraphIter);
	const TVec3f& getNextNodePosition(const RailGraphIter *pGraphIter);
	void calcWatchEdgeVector(const RailGraphIter *pGraphIter, TVec3f *pWatchEdgeVec);
	void calcWatchEdgeDirection(const RailGraphIter *pGraphIter, TVec3f *pWatchEdgeDir);

	s32 getNearNodeIndex(const RailGraph *pGraph, const TVec3f &, f32 distance, RailGraphNodeSelecter *pSelector);

	s32 getSelectEdgeArg0(const RailGraphIter *pGraphIter);
	s32 getSelectEdgeArg1(const RailGraphIter *pGraphIter);
	s32 getSelectEdgeArg2(const RailGraphIter *pGraphIter);
	s32 getSelectEdgeArg3(const RailGraphIter *pGraphIter);
	s32 getWatchEdgeArg7(const RailGraphIter *pGraphIter);
};
