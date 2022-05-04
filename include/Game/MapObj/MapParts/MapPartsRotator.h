#pragma once

#include "revolution.h"
#include "Game/MapObj/MapParts/MapPartsFunction.h"

class MapPartsRotatorBase : public MapPartsFunction {
public:
	virtual ~MapPartsRotatorBase();
	virtual TMtx34f* getRotateMtx() const = 0;
	virtual bool isMoving() const = 0;
	virtual bool isOnReverse() const;
	virtual f32 getRotateSpeed() const;
};

class MapPartsRotator : public MapPartsRotatorBase {
public:
	enum AxisType {
		AxisType_X,
		AxisType_Y,
		AxisType_Z
	};

	MapPartsRotator(LiveActor *pHost);

	virtual ~MapPartsRotator();
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isWorking() const;
	virtual void start();
	virtual void end();
	virtual TMtx34f* getRotateMtx() const;
	virtual bool isMoving() const;
	virtual bool isOnReverse() const;
	virtual f32 getRotateSpeed() const;

	void startWithSignalMotion();
	void cancelSignalMotion();
	void updateBaseHostMtx();
	void updateVelocity();
	void updateAngle();
	void updateTargetAngle();
	void restartAtEnd();
	void initRotateSpeed(const JMapInfoIter &rIter);
	bool isReachedTargetAngle() const;
	void updateRotateMtx(AxisType axisType, f32);
	void calcRotateAxisDir(AxisType axisType, TVec3f *) const;
	void exeRotate();
	void exeStopAtEnd();
	void exeRotateStart();

	f32 _28;
	f32 _2C;
	s32 _30;
	s32 _34;
	f32 _38;
	f32 _3C;
	f32 _40;
	s32 _44;
	s32 _48;
	s32 _4C;
	s32 _50;
	TMtx34f _54;
	TMtx34f _84;
	f32 _B4;
	bool mIsOnReverse;
};

namespace NrvMapPartsRotator {
	NERVE(HostTypeNeverMove);
	NERVE(HostTypeWait);
	NERVE(HostTypeRotateStart);
	NERVE(HostTypeRotate);
	NERVE(HostTypeStopAtEnd);
};
