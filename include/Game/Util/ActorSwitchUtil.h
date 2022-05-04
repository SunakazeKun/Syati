#pragma once

#include "revolution.h"
#include "Game/Util/Functor.h"

class LiveActor;
class JMapInfoIter;

namespace MR {
	bool useStageSwitchReadA(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchReadB(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchReadAppear(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchWriteA(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchWriteB(LiveActor *, const JMapInfoIter &);
	bool initUseStageSwitchReadA(LiveActor *, const JMapInfoIter &);
	bool initUseStageSwitchReadB(LiveActor *, const JMapInfoIter &);
	bool initUseStageSwitchReadAppear(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchAwake(LiveActor *, const JMapInfoIter &);
	bool initUseStageSwitchWriteA(LiveActor *, const JMapInfoIter &);
	bool initUseStageSwitchWriteB(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchWriteDead(LiveActor *, const JMapInfoIter &);
	bool initUseStageSwitchWriteDead(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchWriteAutoDead(LiveActor *, const JMapInfoIter &);
	bool needStageSwitchReadA(LiveActor *, const JMapInfoIter &);
	bool needStageSwitchReadB(LiveActor *, const JMapInfoIter &);
	bool needStageSwitchReadAppear(LiveActor *, const JMapInfoIter &);
	bool needStageSwitchWriteA(LiveActor *, const JMapInfoIter &);
	bool needStageSwitchWriteB(LiveActor *, const JMapInfoIter &);
	bool needStageSwitchWriteDead(LiveActor *, const JMapInfoIter &);
	bool needStageSwitchWriteAutoDead(LiveActor *, const JMapInfoIter &);
	bool isValidSwitchA(const LiveActor *);
	bool isValidSwitchB(const LiveActor *);
	bool isValidSwitchAppear(const LiveActor *);
	bool isValidSwitchDead(const LiveActor *);
	bool isOnSwitchA(const LiveActor *);
	bool isOnSwitchB(const LiveActor *);
	bool isOnSwitchAppear(const LiveActor *);
	bool onSwitchA(LiveActor *);
	bool onSwitchB(LiveActor *);
	bool onSwitchDead(LiveActor *);
	bool offSwitchA(LiveActor *);
	bool offSwitchB(LiveActor *);
	bool offSwitchDead(LiveActor *);
	void syncStageSwitchAppear(LiveActor *);
	bool useStageSwitchSyncAppear(LiveActor *, const JMapInfoIter &);
	void syncStageSwitchAppearAndSync(LiveActor *, const JMapInfoIter &);
	void listenStageSwitchOnAppear(LiveActor *, const MR::FunctorBase &);
	void listenStageSwitchOnOffAppear(LiveActor *, const MR::FunctorBase &);
	void listenStageSwitchOnA(LiveActor *, const MR::FunctorBase &);
	void listenStageSwitchOnOffA(LiveActor *, const MR::FunctorBase &, const MR::FunctorBase &);
	void listenStageSwitchOnB(LiveActor *, const MR::FunctorBase &);
	void listenStageSwitchOffB(LiveActor *, const MR::FunctorBase &);
	void listenStageSwitchOnOffB(LiveActor *, const MR::FunctorBase &, const MR::FunctorBase &);
	bool useStageSwitchReadParam(LiveActor *, const JMapInfoIter &);
	bool isValidSwitchParam(const LiveActor *);
	bool isOnSwitchParam(const LiveActor *);
};
