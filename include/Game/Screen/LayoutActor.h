#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/LiveActor/Spine.h"

class LayoutManager;
class EffectSystem;
class PaneEffectKeeper;
class StarPointerLayoutTargetKeeper;

class LayoutActorFlag {
public:
	bool mIsDead;          // _0
	bool mIsStopAnimFrame; // _1
	bool mIsHidden;        // _2
	bool mIsOnCalcAnim;    // _3
};

class LayoutActor : public NameObj {
public:
	LayoutActor(const char *, bool);

	virtual ~LayoutActor();
	virtual void movement();
	virtual void draw() const;
	virtual void calcAnim();
	virtual void appear();
	virtual void kill();
	virtual void control();

	void setNerve(const Nerve *) const;
	bool isNerve(const Nerve *) const;
	s32 getNerveStep() const;
	void updateSpine();

	// get trans
	void setTrans(const TVec2f &);
	// createPaneMtxRef
	// getPaneMtxRef

	LayoutManager* getLayoutManager() const;

	void initLayoutManager(const char *, u32);
	void initLayoutManagerNoConvertFilename(const char *, u32);
	void initLayoutManager(const char *, u32, u32);
	void initNerve(const Nerve *);
	void initEffectKeeper(int, const char *, const EffectSystem *);
	void initPointingTarget(int);

	LayoutManager* _mManager;                                // _14
	Spine* mSpine;                                           // _18
	PaneEffectKeeper* mPaneEffectKeeper;                     // _1C
	StarPointerLayoutTargetKeeper* mStarPointerTargetKeeper; // _20
	LayoutActorFlag mLayoutActorFlag;                        // _24
	s32 _28;
};
