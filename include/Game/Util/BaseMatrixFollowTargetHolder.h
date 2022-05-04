#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Util/Array.h"
#include "Game/Util/JMapLinkInfo.h"

class LiveActor;

class BaseMatrixFollowValidater {
public:
	virtual bool isValid(s32) const = 0;
};

class BaseMatrixFollowTarget {
public:
	BaseMatrixFollowTarget(const JMapLinkInfo *);

	void set(LiveActor *, const TMtx34f &, const TMtx34f *, BaseMatrixFollowValidater *);
	MtxPtr getHostBaseMtx() const;

	TMtx34f mMtx;                          // _0
	MtxPtr mHostMtx;                       // _30
	LiveActor* mHost;                      // _34
	const JMapLinkInfo* mLinkInfo;         // _38
	BaseMatrixFollowValidater* mValidater; // _3C
};

class BaseMatrixFollower {
public:
	BaseMatrixFollower(NameObj *, const JMapInfoIter &);

	virtual void setGravityFollowHost(const NameObj *);
	virtual void update();

	NameObj* getFollowTargetActor() const;
	void calcFollowMatrix(TMtx34f *) const;
	bool isEnableFollow() const;
	bool isValid() const;

	JMapLinkInfo* mLinkInfo;         // _4
	NameObj* mHost;                  // _8
	BaseMatrixFollowTarget* mTarget; // _C
	s32 mFollowID;                   // _10
};

class BaseMatrixFollowTargetHolder : public NameObj {
public:
	BaseMatrixFollowTargetHolder(const char *, s32, s32);

	virtual void initAfterPlacement();
	virtual void movement();

	void addFollower(BaseMatrixFollower *);
	void setFollowTargetInfo(LiveActor *, const JMapInfoIter &, const TMtx34f *, BaseMatrixFollowValidater *);
	BaseMatrixFollowTarget* findFollowTarget(const JMapLinkInfo *);
	BaseMatrixFollowTarget* findFollowTarget(const BaseMatrixFollower *);

	MR::Vector<MR::AssignableArray<BaseMatrixFollower*> > mFollowers;   // _14
	MR::Vector<MR::AssignableArray<BaseMatrixFollowTarget*> > mTargets; // _20
};

namespace MR {
	bool isValidFollowID(const JMapInfoIter &);
	void addBaseMatrixFollower(BaseMatrixFollower *);
	void addBaseMatrixFollowTarget(LiveActor *, const JMapInfoIter &, const TMtx34f *, BaseMatrixFollowValidater *);
};
