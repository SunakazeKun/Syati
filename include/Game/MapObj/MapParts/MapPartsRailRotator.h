#pragma once

#include "revolution.h"
#include "Game/MapObj/MapParts/MapPartsFunction.h"

class MapPartsRailRotator : public MapPartsFunction {
public:
	enum AxisType {
		AxisType_X,
		AxisType_Y,
		AxisType_Z
	};

	MapPartsRailRotator(LiveActor *pHost);

	virtual ~MapPartsRailRotator();
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isWorking() const;
	virtual void start();
	virtual void end();
	virtual f32 getJMapArgAngleFactor() const;

	bool hasRotation(s32) const;
	void rotateAtPoint(s32);
	bool hasRotationBetweenPoints(s32) const;
	void rotateBetweenPoints(s32, f32);
	void updateHostRotateMtx();
	void updateInfo(s32);
	bool isReachedTargetAngle() const;
	void calcRotateAxisDir(AxisType axisType, TVec3f *) const;
	void updateRotateMtx(AxisType axisType, f32);
	void exeRotate();

	s32 _28;
	s32 _2C;
	f32 _30;
	f32 _34;
	f32 _38;
	Mtx _3C;
	Mtx _6C;
	s32 _9C;
};

namespace NrvMapPartsRailRotator {
	NERVE(HostTypeWait);
	NERVE(HostTypeRotateAtPoint);
	NERVE(HostTypeRotateBetweenPoints);
	NERVE(HostTypeDone);
};
