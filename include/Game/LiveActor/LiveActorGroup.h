#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObjGroup.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/Util/JMapIdInfo.h"

class LiveActorGroup : public NameObjGroup {
public:
	LiveActorGroup(const char *, int);

	virtual ~LiveActorGroup();

	void registerActor(LiveActor *);

	LiveActor* getActor(int) const;
	LiveActor* getDeadActor() const;
	s32 getLivingActorNum() const;

	void killAll();
	void appearAll();
	void makeAllDead();
};

class MsgSharedGroup : public LiveActorGroup {
public:
	MsgSharedGroup(const char *, s32, const JMapInfoIter &);
	
	virtual ~MsgSharedGroup();
	virtual void init(const JMapInfoIter &);
	virtual void movement();

	void sendMsgToGroupMember(u32, HitSensor *, const char *);

	JMapIdInfo* mGroupId;      // _20
	u32 mMessage;              // _24
	HitSensor* mSender;        // _28
	const char* mReceiverName; // _2C
	char _30[0x30];
};

class LiveActorGroupArray : public NameObj {
public:
	LiveActorGroupArray(const char *);

	virtual ~LiveActorGroupArray();
	virtual void init(const JMapInfoIter &);

	MsgSharedGroup* tryCreateGroupForLiveActor(LiveActor *, const JMapInfoIter &);
	MsgSharedGroup* getLiveActorGroup(const LiveActor *) const;
	MsgSharedGroup* createGroup(const JMapInfoIter &, const char *, s32);
	MsgSharedGroup* findGroup(const JMapInfoIter &) const;
	MsgSharedGroup* findGroup(const LiveActor *) const;

	MsgSharedGroup* mGroups[32]; // _14
	s32 mNumGroups;              // _94
};
