#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObjGroup.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/Util/JMapIdInfo.h"

class LiveActorGroup : public NameObjGroup {
public:
	LiveActorGroup(const char *pGroupName, int size);

	virtual ~LiveActorGroup();

	void registerActor(LiveActor *pActor);

	LiveActor* getActor(int) const;
	LiveActor* getDeadActor() const;
	s32 getLivingActorNum() const;

	void killAll();
	void appearAll();
	void makeAllDead();
};

class MsgSharedGroup : public LiveActorGroup {
public:
	MsgSharedGroup(const char *pGroupName, s32 size, const JMapInfoIter &rIter);
	
	virtual ~MsgSharedGroup();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();

	void sendMsgToGroupMember(u32 msg, HitSensor *pSender, const char *pReceiverName);

	JMapIdInfo* mGroupId;      // _20
	u32 mMessage;              // _24
	HitSensor* mSender;        // _28
	const char* mReceiverName; // _2C
	char mGroupName[48];       // _30
};

class LiveActorGroupArray : public NameObj {
public:
	LiveActorGroupArray(const char *);

	virtual ~LiveActorGroupArray();
	virtual void init(const JMapInfoIter &rIter);

	MsgSharedGroup* tryCreateGroupForLiveActor(LiveActor *pActor, const JMapInfoIter &rIter);
	MsgSharedGroup* getLiveActorGroup(const LiveActor *pActor) const;
	MsgSharedGroup* createGroup(const JMapInfoIter &rIter, const char *pName, s32 size);
	MsgSharedGroup* findGroup(const JMapInfoIter &rIter) const;
	MsgSharedGroup* findGroup(const LiveActor *pActor) const;

	MsgSharedGroup* mGroups[32]; // _14
	s32 mNumGroups;              // _94
};
