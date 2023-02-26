#pragma once

#include "revolution.h"

/* FINISHED */

class ActorStateBaseInterface;
class LiveActor;
class Nerve;
class NerveExecutor;

namespace MR {
	void initActorState(LiveActor *pActor, ActorStateBaseInterface *pActorState, const Nerve *pNerve, const char *pName);
	void initActorState(NerveExecutor *pExecutor, ActorStateBaseInterface *pActorState, const Nerve *pNerve, const char *pName);

	bool updateActorState(LiveActor *pExecutor);
	bool updateActorState(LiveActor *pExecutor, ActorStateBaseInterface *pActorState);
	bool updateActorStateAndNextNerve(LiveActor *pActor, const Nerve *pNerve);
	bool updateActorStateAndNextNerve(LiveActor *pActor, ActorStateBaseInterface *pActorState, const Nerve *pNerve);
	bool updateActorState(NerveExecutor *pExecutor);
	bool updateActorState(NerveExecutor *pExecutor, ActorStateBaseInterface *pActorState);
	bool updateActorStateAndNextNerve(NerveExecutor *pExecutor, const Nerve *pNerve);
	bool updateActorStateAndNextNerve(NerveExecutor *pExecutor, ActorStateBaseInterface *pActorState, const Nerve *pNerve);

	bool isActorStateDead(NerveExecutor *pExecutor);
	void endActorState(NerveExecutor *pExecutor);
};
