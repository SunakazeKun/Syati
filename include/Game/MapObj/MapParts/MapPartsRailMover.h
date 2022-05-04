#pragma once

#include "revolution.h"
#include "Game/MapObj/MapParts/MapPartsRailPointPassChecker.h"

class MapPartsRailMover : public MapPartsFunction {
public:
	MapPartsRailMover(LiveActor *);

	virtual ~MapPartsRailMover();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
	virtual bool isWorking() const;
	virtual void start();
	virtual void end();
	virtual bool receiveMsg(u32);
	// one new virtual function

	void moveToInitPos();
	void cancelSignalMotion();
	void tryResetPositionRepeat();
	void resetToInitPos();

	void passPoint();
	void reachedEnd();
	void reachedEndPlayerOn();
	bool isStarting() const;
	bool isReachedEnd() const;
	bool isDone() const;
	void setStateStopAtEndBeforeRotate();
	void calcTimeToNextRailPoint(f32 *) const;
	void endRotateAtPoint();
	void calcMoveSpeed(f32 *) const;
	void calcMoveSpeedDirect(f32 *) const;
	void calcMoveSpeedTime(f32 *) const;
	void updateAccel();
	bool tryPassPoint();
	bool tryRestartAtEnd();
	void restartAtEnd();
	void exeWaitForRestart();
	void exeMove();
	void exeMoveStart();
	void exeStopAtPoint();
	void exeStopAtEnd();
	void exeStopAtEndWithPlayerOn();

	MapPartsRailPointPassChecker* mPointPassChecker; // _28
	s32 mMoveConditionType; // _2C
	s32 mMoveStopType; // _30
	s32 mSignMotionType; // _34
	TVec3f mTranslation;
	TVec3f _44;
	f32 _50;
	s32 _54;
	f32 _58;
	s32 _5C;
	f32 _60;
	f32 _64;
	s32 _68;
	s32 _6C;
	u8 _70;
	s32 _74;
	u8 _78;
};

namespace NrvMapPartsRailMover {
	NERVE(HostTypeWait);
	NERVE(HostTypeMove);
	NERVE(HostTypeMoveStart);
	NERVE(HostTypeStopAtPointBeforeRotate);
	NERVE(HostTypeStopAtPointAfterRotate);
	NERVE(HostTypeStopAtEndBeforeRotate);
	NERVE(HostTypeStopAtEndAfterRotate);
	NERVE(HostTypeStopAtEndWithPlayerOn);
	NERVE(HostTypeWaitForRestartByPlayerOn);
	NERVE(HostTypeRotateAtPoint);
	NERVE(HostTypeRotateAtEndPoint);
	NERVE(HostTypeVanish);
};
