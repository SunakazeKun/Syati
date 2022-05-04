#pragma once

#include "revolution.h"

class ActorStateBaseInterface;
class LiveActor;
class Nerve;
class NerveExecutor;

namespace MR {
	void initActorState(LiveActor *, ActorStateBaseInterface *, const Nerve *, const char *);
	void initActorState(NerveExecutor *, ActorStateBaseInterface *, const Nerve *, const char *);
	void updateActorState(LiveActor *);
	void updateActorState(LiveActor *, ActorStateBaseInterface *);
	void updateActorStateAndNextNerve(LiveActor *, const Nerve *);
	void updateActorStateAndNextNerve(LiveActor *, ActorStateBaseInterface *, const Nerve *);
	void updateActorState(NerveExecutor *);
	void updateActorState(NerveExecutor *, ActorStateBaseInterface *);
	void updateActorStateAndNextNerve(NerveExecutor *, const Nerve *);
	void updateActorStateAndNextNerve(NerveExecutor *, ActorStateBaseInterface *, const Nerve *);
};
