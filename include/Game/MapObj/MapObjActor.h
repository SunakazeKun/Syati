#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/LodCtrl.h"
#include "Game/MapObj/MapObjActorInitInfo.h"

class MapObjActor : public LiveActor {
public:
	MapObjActor(const char *);
	MapObjActor(const char *, const char *);

	virtual ~MapObjActor();
	virtual void init(const JMapInfoIter &);
	virtual void initAfterPlacement();
	virtual void appear();
	virtual void kill();
	virtual void startClipped();
	virtual void endClipped();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void setPlayAppearSe();
	virtual void connectToScene(const MapObjActorInitInfo &);
	virtual void initCaseUseSwitchA(const MapObjActorInitInfo &);
	virtual void initCaseNoUseSwitchA(const MapObjActorInitInfo &);
	virtual void initCaseUseSwitchB(const MapObjActorInitInfo &);
	virtual void initCaseNoUseSwitchB(const MapObjActorInitInfo &);
	virtual void makeSubModels(const JMapInfoIter &, const MapObjActorInitInfo &);
	virtual void updateProjmapMtx();
	virtual bool tryEmitWaitEffect();
	virtual bool tryDeleteWaitEffect();

	void initialize(const JMapInfoIter &, const MapObjActorInitInfo &);
	void isObjectName(const char *) const;
	bool tryCreateBreakModel(const MapObjActorInitInfo &);
	bool initStageEffectCamera();
	bool initStageEffectPad();

	void startMapPartsFunctions();
	void endMapPartsFunctions();
	void pauseMapPartsFunctions();
	void resumeMapPartsFunctions();
	void setStateWait();

	void exeWait();
	void exeMove();

	const char* mObjName;
	LodCtrl* mLodCtrl;
	u32* mBloomModel;
	u32* _9C;
	u32* mProjmapEffectMtxSetter;
	u32* mRailMover;
	u32* mRotator;
	u32* mRailRotator;
	u32* mRailPosture;
	u32* mRailGuideDrawer;
	bool _B8;
	bool _B9;
	bool _BA;
	bool mPlayAppearSe;
	Nerve* mNrvWait;
	Nerve* mNrvMove;
	Nerve* mNrvDone;
	s32 _C8;
	s32 _CC;
};

namespace MapObjActorUtil {
	void startAllMapPartsFunctions(const MapObjActor *);
	void endAllMapPartsFunctions(const MapObjActor *);
	void pauseAllMapPartsFunctions(const MapObjActor *);
	void resumeAllMapPartsFunctions(const MapObjActor *);
	bool isRotatorMoving(const MapObjActor *);
	bool isRailMoverWorking(const MapObjActor *);
	f32 getSeesaw1AxisAngularSpeed(const MapObjActor *);
	void startRotator(const MapObjActor *);
	void startRailMover(const MapObjActor *);
	// unknown function at 802CB810, possibly stopRailMover?
	void pauseRotator(const MapObjActor *);
	void resetRailMoverToInitPos(const MapObjActor *);
	bool tryStartBreak(const MapObjActor*);
	bool isBreakStopped(const MapObjActor *);
	void killBloomModel(const MapObjActor *);
	void appearBloomModel(const MapObjActor *);
};

namespace NrvMapObjActor {
	NERVE(HostTypeWait);
	NERVE(HostTypeMove);
	NERVE(HostTypeDone);
};
