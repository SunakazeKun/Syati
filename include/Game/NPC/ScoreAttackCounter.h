#pragma once

#include "revolution.h"

class LiveActor;

class ScoreAttackFunction {
public:
	static void score100Points(const LiveActor *pHost);
	static void score10PointsMultiply(const LiveActor *pHost, s32 factor);
	static void score10PointsMultiply(s32 factor);
	static void score1000Points(const LiveActor *pHost);
	static void score300Points(const LiveActor *pHost);
};
